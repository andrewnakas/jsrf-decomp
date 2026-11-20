/* sym: ??0Object_00050B70@@QAE@PAUNode@@HIPAX1@Z = 0x00050AB0 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

    char unknown_04[0x40];
};

struct Game {
    void func_000126D0(int value);
    void func_000126F0(int value);
    void func_000127C0(int id, int value);
    int func_000127E0(int id);
    int func_000128E0(int first, int second);
};

extern Game *data_0022FCE0;

// The class whose table is at 0x1CACA0 (constructor 0x50AB0, destructor 0x50B70; 0x58 bytes).
struct Object_00050B70 : Node {
    Object_00050B70(Node *owner, int id, unsigned int flags, void *first, void *second);
    virtual ~Object_00050B70();

    char unknown_44[0x14];
};

// A record of the stage data (0x2c bytes).
struct Record_000568F0 {
    char unknown_00[0x8];
    char first[0xc];
    char second[0x18];
};

struct Stage_000568F0 {
    char unknown_00[0x3c];
    Record_000568F0 *records;
};

struct Object_0004ABA0 : Node {
    char unknown_044[0x18];
    unsigned int state;
    char unknown_060[0xf68];
    int handle;
    char unknown_fcc[0x74];
    Stage_000568F0 *stage;

    void func_00053D40();
};

// State handler 111 of the table at 0x1F9888: the game's func_000126D0 (0) and func_000126F0 (1), a handle from
// func_000128E0 (0xd2, 0xe6), an Object_00050B70 under this object from the stage record setting 0x198 picks, that
// record's index as setting 0x4d, and state 0x70.
void Object_0004ABA0::func_00053D40()
{
    data_0022FCE0->func_000126D0(0);
    data_0022FCE0->func_000126F0(1);
    handle = data_0022FCE0->func_000128E0(0xd2, 0xe6);
    int index = data_0022FCE0->func_000127E0(0x198);
    new Object_00050B70(this, handle, 0, stage->records[index].first, stage->records[index].second);
    data_0022FCE0->func_000127C0(0x4d, index);
    state = 0x70;
}
