/* sym: ??0Object_00044AE0@@QAE@PAUNode@@HIHHPAUVector3@@HH@Z = 0x00044940 */
/* sym: ??1Object_00044AE0@@UAE@XZ = 0x00044AE0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

extern "C" void *memset(void *destination, int value, unsigned int size);

float __fastcall func_0014C640(int angle);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A Direct3D texture: slot 2 releases it, slot 8 fills it.
struct Resource_00044AE0 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8(const void *data, int count);
};

struct Interface_00251D74 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5(int first, int second, int third, Resource_00044AE0 **result);
};

extern Interface_00251D74 *data_00251D74;

// A 0x1c-byte record: the kinds' table at 0x1F9260 and the three parts at 0x1F9148, 0x1F9164 and 0x1F9180.
struct Record_00044940 {
    int unknown_00[7];
};

extern Record_00044940 data_001F9260[];
extern Record_00044940 data_001F9148;
extern Record_00044940 data_001F9164;
extern Record_00044940 data_001F9180;
extern int data_001F92D8;

// What +0xdc points at (0x54 bytes): three records.
struct Parts_00044940 {
    Record_00044940 first;
    Record_00044940 second;
    Record_00044940 third;
};

// What +0x138 points at (0x60 bytes).
struct Block_00044940 {
    int unknown_00[0x18];
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

// The node class whose table is at 0x1CA788 (destructor 0x44AE0; 0x948 bytes).
struct Object_00044AE0 : Node {
    Object_00044AE0(Node *owner, int id, unsigned int flags, int kind, int record, Vector3 *position, int value,
                    int mode);
    virtual ~Object_00044AE0();

    char unknown_044[8];
    int mode;
    char unknown_050[0xc];
    Record_00044940 info;
    int kind;
    Resource_00044AE0 *texture;
    int placed;
    Vector3 position;
    char unknown_090[0x38];
    float unknown_c8;
    float unknown_cc;
    unsigned char unknown_d0;
    int value;
    int unknown_d8;
    Parts_00044940 *parts;
    char unknown_0e0[0x58];
    Block_00044940 *block;
    char unknown_13c[0x804];
    int unknown_940;
    int unknown_944;
};

// Looks up object 7, clears everything after the node, keeps its arguments (a position only when one is given),
// makes the 5x5 texture at +0x7c from 0x1F92D8 when it has none, copies the kind's record from 0x1F9260, makes the
// three parts at +0xdc and the cleared block at +0x138, and sets +0xc8 / +0xcc from func_0014C640 and +0x940.
Object_00044AE0::Object_00044AE0(Node *owner, int id, unsigned int flags, int kind, int record, Vector3 *position,
                                 int value, int mode)
    : Node(owner, id, flags)
{
    data_0022FCE0->func_000128C0(7);
    memset(unknown_044, 0, 0x904);
    this->kind = kind;
    this->mode = mode;
    this->value = value;
    unknown_d0 = 0;
    if (position) {
        placed = 1;
        this->position.x = position->x;
        this->position.y = position->y;
        this->position.z = position->z;
    }
    if (!texture) {
        data_00251D74->slot5(5, 5, 0, &texture);
        texture->slot8(&data_001F92D8, 1);
    }
    info = data_001F9260[record];
    parts = new Parts_00044940;
    memset(parts, 0, sizeof(Parts_00044940));
    parts->first = data_001F9148;
    parts->second = data_001F9164;
    parts->third = data_001F9180;
    block = new Block_00044940;
    memset(block, 0, sizeof(Block_00044940));
    unknown_c8 = func_0014C640(0x271c);
    unknown_cc = func_0014C640(0x38e3);
    unknown_940 = 1;
}
