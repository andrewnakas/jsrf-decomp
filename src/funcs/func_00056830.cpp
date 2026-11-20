/* sym: ??0Object_00050EC0@@QAE@PAUNode@@HIPAX1@Z = 0x00056080 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

    char unknown_04[0x40];
};

int func_00025680();
int func_000256A0(unsigned int index, int argument);

struct Game {
    int func_000127E0(int id);
    int func_000128E0(int first, int second);
};

extern Game *data_0022FCE0;

// The class whose table is at 0x1CAD60 (constructor 0x56080, destructor 0x50EC0; 0x74 bytes).
struct Object_00050EC0 : Node {
    Object_00050EC0(Node *owner, int id, unsigned int flags, void *first, void *second);
    virtual ~Object_00050EC0();

    char unknown_44[0x30];
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

    void func_00056830();
};

// State handler 113 of the table at 0x1F9888: unless func_00025680 says to wait, once func_000256A0 (1, 0) says so,
// takes a handle from the game's func_000128E0 (0xd2, 0xe6), makes an Object_00050EC0 under this object with it and
// the two parts of the stage record setting 0x198 picks, and goes to state 0x72.
void Object_0004ABA0::func_00056830()
{
    if (!func_00025680() && func_000256A0(1, 0)) {
        handle = data_0022FCE0->func_000128E0(0xd2, 0xe6);
        int index = data_0022FCE0->func_000127E0(0x198);
        new Object_00050EC0(this, handle, 0, stage->records[index].first, stage->records[index].second);
        state = 0x72;
    }
}
