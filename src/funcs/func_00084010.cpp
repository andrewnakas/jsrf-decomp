/* sym: ??0Object_000800D0@@QAE@HPAMPAHH@Z = 0x00084010 */
void __cdecl operator delete(void *memory);

struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void func_00080230(int *angles);

struct Game {
    void func_000127C0(int id, int value);
    int func_000127E0(int id);
    int func_00012910(int id);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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

// The 0x34-byte block an Object_000800D0 hands to the game's slot table.
struct Block_00084010 {
    int kind;
    int unknown_04;
    int unknown_08;
    Vector3 position;
    int angles[3];
    int unknown_24;
    int unknown_28;
    int unknown_2c;
    int unknown_30;
};

// The class whose table at 0x1CD088 holds only its scalar deleting destructor 0x84160 (constructor 0x84010); its
// methods 0x800D0, 0x80110, 0x80150, 0x801F0 and 0x841C0 work on the game object named by the id at +8.
struct Object_000800D0 {
    Object_000800D0(int value, float *position, int *rotation, int unused);
    virtual ~Object_000800D0()
    {
        Node *node = (Node *)data_0022FCE0->func_000128C0(id);
        if (node) {
            node->func_00011BE0(node);
            node->func_00011C20(node->child);
        }
        operator delete(block);
    }

    Block_00084010 *block;
    int id;
};

// Called by 0x50AB0, 0x561C0 and 0x22E50 with the game's value 0xd, a position, three angles and 0 (unused): builds
// a kind-0xd block with the transformed origin and its angles (func_00080230), then takes the first free slot i
// (4-31) whose game id i+0xc exists and whose id i+0x6d is clear, setting ids i+0x2d (value), i+0x6d (block),
// i+0xad (-1), i+0x8d (0) and i+0xcd (1).
Object_000800D0::Object_000800D0(int value, float *position, int *rotation, int unused)
{
    id = -1;
    block = (Block_00084010 *)operator new(0x34);
    block->kind = 0xd;
    block->unknown_04 = 0;
    block->unknown_08 = 0;
    func_001BAA00();
    func_001BAAA0(position);
    func_001BB2E0(rotation[0]);
    func_001BB330(rotation[1]);
    func_001BB380(rotation[2]);
    func_001BAB20(&block->position, 0);
    func_00080230(block->angles);
    func_001BAA50();
    block->unknown_24 = 0x1b;
    block->unknown_28 = 0;
    block->unknown_2c = 0;
    block->unknown_30 = 0;
    for (unsigned int i = 4; i < 0x20; i++) {
        if (data_0022FCE0->func_00012910(i + 0xc) && !data_0022FCE0->func_000127E0(i + 0x6d)) {
            id = i + 0xc;
            data_0022FCE0->func_000127C0(i + 0x2d, value);
            data_0022FCE0->func_000127C0(i + 0x6d, (int)block);
            data_0022FCE0->func_000127C0(i + 0xad, -1);
            data_0022FCE0->func_000127C0(i + 0x8d, 0);
            data_0022FCE0->func_000127C0(i + 0xcd, 1);
            return;
        }
    }
}
