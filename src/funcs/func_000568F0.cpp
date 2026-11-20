/* sym: ??0Object_000511B0@@QAE@PAUNode@@HIPAX1@Z = 0x000561C0 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

    char unknown_04[0x40];
};

struct Game {
    int func_000127E0(int id);
    int func_000128E0(int first, int second);
};

extern Game *data_0022FCE0;

// The class whose table is at 0x1CADE8 (constructor 0x561C0, destructor 0x511B0; 0x58 bytes).
struct Object_000511B0 : Node {
    Object_000511B0(Node *owner, int id, unsigned int flags, void *first, void *second);
    virtual ~Object_000511B0();

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

    void func_000568F0();
};

// State handler 115 of the table at 0x1F9888: takes a handle from the game's func_000128E0 (0xd2, 0xe6) and makes
// an Object_000511B0 under this object with it and the two parts of the stage record setting 0x198 picks; state 0x74.
void Object_0004ABA0::func_000568F0()
{
    handle = data_0022FCE0->func_000128E0(0xd2, 0xe6);
    int index = data_0022FCE0->func_000127E0(0x198);
    new Object_000511B0(this, handle, 0, stage->records[index].first, stage->records[index].second);
    state = 0x74;
}
