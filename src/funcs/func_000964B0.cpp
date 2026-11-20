/* sym: ??1Object_000963E0@@UAE@XZ = 0x000964B0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
// A device buffer: slot 2 releases it.
struct Buffer_000963E0 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall Release();
};

struct Object_000607B0 {
    void func_000607B0(int key);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Vector3 {
    float x;
    float y;
    float z;
};

// A segment (0x18 bytes): two points.
struct Segment_000963E0 {
    Vector3 start;
    Vector3 end;
};

// Two words kept with each segment.
struct Pair_000963E0 {
    int first;
    int second;
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
};

// A node (table 0x1CD320, destructor 0x964B0) with two 240-byte buffers from the device, two sets of up to 120
// segments with their pairs and counts, and a 2x2 grid of keys it frees from the game's object 0xe8 when it goes.
struct Object_000963E0 : Node {
    Object_000963E0(Node *owner, int id, unsigned int flags);
    virtual ~Object_000963E0();

    char unknown_44[0x30];
    Buffer_000963E0 *buffers[2];
    Segment_000963E0 segments[2][120];
    Pair_000963E0 pairs[2][120];
    unsigned int counts[2];
    int unknown_1e84;
    int unknown_1e88;
    int keys[2][2];
};

// Releases both buffers until their counts reach zero, then frees every key in use from the game's object 0xe8.
Object_000963E0::~Object_000963E0()
{
    for (unsigned int i = 0; i < 2; i++) {
        while (buffers[i]->Release() != 0) {
        }
    }
    Object_000607B0 *table = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (table) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                if (keys[j][k] >= 0) {
                    table->func_000607B0(keys[j][k]);
                }
            }
        }
    }
}
