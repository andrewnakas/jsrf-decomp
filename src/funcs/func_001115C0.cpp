/* sym: ??0Object_000F98B0@@QAE@PAUNode@@HIPAH1HPBDH@Z = 0x000F98B0 */
struct Game {
    void *func_000128C0(int id);
};

struct Block_001115C0 {
    char unknown_00[0x1c];
    int busy;
};

// Object 9 (its block at +0x1040).
struct Stage_001115C0 {
    char unknown_0000[0x1040];
    Block_001115C0 *block;
};

// The four controller ports (64 bytes each): flags (1: connected) and a word at +0x34.
struct Entry_00251DE8 {
    unsigned char flags;
    char unknown_01[0x33];
    int unknown_34;
    char unknown_38[8];
};

struct Object_00043700 {
    int func_00043700();
};

struct Node {
    virtual ~Node();
    virtual void func_00011C90();

    char unknown_04[0x40];
};

// The child that func_000F98B0 constructs (destructor func_000F9A80).
struct Object_000F98B0 {
    Object_000F98B0(Node *owner, int id, unsigned int flags, int *first, int *second, int value, const char *text,
                    int kind);

    char unknown_00[0xd8];
};

// The class whose table is at 0x1D2788.
struct Object_001112A0 : Node {
    virtual void func_00011C90();

    unsigned int flags_44;
    char unknown_48[0x34];
    int state;
    int previous;
    char unknown_84[4];
    int value_88;
    int value_8c;

    void func_001115C0();
};

extern Game *data_0022FCE0;
extern Entry_00251DE8 data_00251DE8[];
extern unsigned int data_00251EE8;
extern Object_00043700 data_001FC724;
extern const char *data_00221954[];

int func_00119540(int group, int index, void *position);

// In state 1, once object 9 exists and a button is pressed (bits 4 or 1 of port 4 when its block's word at +0x1c
// is clear, else bits 5 of any of the four ports): plays sound 8/0; then state 4 when bit 31 of +0x44 is clear,
// otherwise state 2 with +0x88 cleared and an Object_000F98B0 under this node that reports to +0x88/+0x8c,
// with the text data_00221954 holds for the language func_00043700 gives.
void Object_001112A0::func_001115C0()
{
    if (state != 1) {
        return;
    }
    Stage_001115C0 *stage = (Stage_001115C0 *)data_0022FCE0->func_000128C0(9);
    if (!stage) {
        return;
    }
    if (!stage->block->busy) {
        unsigned char flags = *(unsigned char *)&data_00251EE8;
        if (!(flags & 4) && !(flags & 1)) {
            return;
        }
    } else {
        if (!(data_00251DE8[0].flags & 5) && !(data_00251DE8[1].flags & 5) && !(data_00251DE8[2].flags & 5) &&
            !(data_00251DE8[3].flags & 5)) {
            return;
        }
    }
    func_00119540(8, 0, 0);
    if (!(flags_44 & 0x80000000)) {
        state = 4;
        return;
    }
    state = 2;
    value_88 = 0;
    new Object_000F98B0(this, -1, 0x100, &value_88, &value_8c, 0, data_00221954[data_001FC724.func_00043700()], 0);
}
