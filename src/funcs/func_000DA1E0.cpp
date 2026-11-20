/* sym: ??0Object_000DA3E0@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x000DA1E0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_000DA3E0@@UAE@XZ = 0x000DA360 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000DA3E0@@UAEXXZ = 0x000DA8D0 */
/* sym: ?func_00011C90_1@Object_000DA3E0@@UAEXXZ = 0x000DA700 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Mesh_00017F60;

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_002174A4;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Object_000C1270 {
    int func_000C1160(int kind, int count, Vector3 *position);
};

extern Object_000C1270 *data_00257CE4;

void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

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

// One of the sixty slots at 0x64 (16 bytes): a position and a state (0, 1, 2 free, 4).
struct Slot_000DA5B0 {
    Vector3 position;
    unsigned int state;
};

// The 0x44-byte block at 0x424; the constructor sets only its kind.
struct Block_000DA1E0 {
    int kind;
    char unknown_04[0x40];
};

// One of the sixteen mesh copies at 0x468 (36 bytes).
struct Entry_000DA360 {
    int kind;
    int size;
    Mesh_00017F60 *pointer;
    int unknown_0c;
    char unknown_10[0x14];
};

// The child of Node whose table is at 0x1CE658 (0x6c4 bytes; destructor func_000DA360): overrides slots 1 and 2.
struct Object_000DA3E0 : Node {
    Object_000DA3E0(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *heading);
    virtual ~Object_000DA3E0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();

    int full;
    int value_48;
    int value_4c;
    Vector3 direction;
    unsigned int end;
    unsigned int start;
    Slot_000DA5B0 slots[60];
    Block_000DA1E0 block;
    Entry_000DA360 entries[16];
    char unknown_6a8[0x18];
    int handle;
};

// Keeps the flat direction of `heading` (y cleared, func_0014C410), frees the sixty slots (state 2) and fills the
// first with `position`, where object 0xe8 starts kind 0x48 pointing up (func_000651E0); clears the block at 0x424
// to kind 0x3f, makes sixteen copies of the mesh at data_002174A4 (kind 7, size 0x400) and keeps the handle of a
// kind-0x2e effect at `position` (func_000C1160) at 0x6c0.
Object_000DA3E0::Object_000DA3E0(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *heading)
    : Node(owner, id, flags)
{
    full = 0;
    value_48 = 0;
    value_4c = 0;
    end = 0;
    start = 0;
    direction = *heading;
    direction.y = 0.0f;
    func_0014C410(&direction, &direction);
    memset(slots, 0, sizeof(slots));
    for (int i = 0; i < 60; i++) {
        slots[i].state = 2;
    }
    slots[end].position = *position;
    Vector3 up;
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        object->func_000651E0(0x48, position, &up);
    }
    end++;
    memset(&block, 0, sizeof(block));
    block.kind = 0x3f;
    for (int j = 0; j < 16; j++) {
        entries[j].pointer = data_0022FCE8.func_00019680(&data_002174A4);
        entries[j].kind = 7;
        entries[j].size = 0x400;
        entries[j].unknown_0c = 0;
    }
    handle = data_00257CE4->func_000C1160(0x2e, 0xe, position);
}
