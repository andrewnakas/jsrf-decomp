/* sym: ??0Object_000B40F0@@QAE@PAUNode@@HIPAUParams_000BAC60@@H@Z = 0x000B4330 */
/* sym: ??1Object_000B40F0@@UAE@XZ = 0x000B4490 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
extern "C" void *memset(void *destination, int value, unsigned int size);

void *func_00025700(unsigned int index, int first, int second, int third);

struct Vector3 {
    float x;
    float y;
    float z;
};

// Where func_000BAC60 places the object: position, angles, scale and a model code (bank << 10 | index).
struct Params_000BAC60 {
    Vector3 position;
    int angles[3];
    Vector3 scale;
    unsigned int model;
};

// A 0x68-byte model entry (bank 7): two point-set ids at 0x8, ten keys at 0x18 with their values at 0x40.
struct Entry_000B4330 {
    int unknown_00[2];
    int pointSets[2];
    int unknown_10[2];
    int keys[10];
    int values[10];
};

// A point count.
struct Header_000B4000 {
    unsigned int count;
};

// A source point (0x10 bytes).
struct Source_000B4000 {
    int unknown_00;
    float x;
    float y;
    float z;
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    char unknown_34[0x10];

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Resource_000B4490;

// The class whose table is at 0x1CD8C8 (0x144 bytes; func_000BAC60 makes it, destructor func_000B4490).
struct Object_000B40F0 : Node {
    Object_000B40F0(Node *owner, int id, unsigned int flags, Params_000BAC60 *placement, int build);
    virtual ~Object_000B40F0();

    int bank;
    Params_000BAC60 placement;
    char unknown_70[4];
    Resource_000B4490 *buffers[2];
    char unknown_7c[8];
    void *blocks[2];
    int ids[10];
    Source_000B4000 *sources[2];
    int count;
    Resource_000B4490 *objects[2];
    void *points[2];
    unsigned int state;
    Entry_000B4330 entry;
    Header_000B4000 *headers[2];

    void func_000B4000();
    void func_000B4290(int clear);
};

// Copies the placement, finds the model entry (bank 7, group from the code's high bits) and both point sets; with no
// first point set the node leaves the draw links and is marked at 0xd0, otherwise func_000B4000 builds the points and,
// when `build` is 1, func_000B4290 makes the children.
Object_000B40F0::Object_000B40F0(Node *owner, int id, unsigned int flags, Params_000BAC60 *placement, int build)
    : Node(owner, id, flags)
{
    if (placement) {
        count = 0;
        state = 0;
        for (int i = 0; i < 2; i++) {
            headers[i] = 0;
            points[i] = 0;
            objects[i] = 0;
            buffers[i] = 0;
            blocks[i] = 0;
        }
        for (int k = 0; k < 10; k++) {
            ids[k] = 0;
        }
        this->placement = *placement;
        unsigned int code = this->placement.model;
        unsigned int group = code >> 10;
        if (group < 5) {
            bank = group + 1;
        } else {
            bank = 0;
        }
        unsigned int index = code - group * 0x400;
        Entry_000B4330 *entries = (Entry_000B4330 *)func_00025700(7, bank, 7, 0);
        entry = entries[index];
        for (int j = 0; j < 2; j++) {
            if (entry.pointSets[j] != -1) {
                void *set = func_00025700(7, bank, 0, entry.pointSets[j]);
                headers[j] = (Header_000B4000 *)set;
                sources[j] = (Source_000B4000 *)((char *)set + 8);
            }
        }
        if (headers[0] == 0) {
            func_00011BE0(this);
            func_00011C20(child);
            state |= 0x80000000;
        } else {
            func_000B4000();
            if (build == 1) {
                func_000B4290(1);
            }
        }
    }
}
