void func_00106F10(unsigned int id, int value);
void func_00060C90();

struct Game {
    void func_000127C0(int id, int value);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Stage_00056540 {
    char unknown_00[0x14];
    int unknown_14;
    int unknown_18;
    int unknown_1c;
};

struct Other_0004AFC0 {
    char unknown_000[0x8d4];
    int unknown_8d4;
    int unknown_8d8;
};

struct Owner_0004AD10 {
    char unknown_000[0x23c];
    unsigned int unknown_23c;
};

struct Object_000A1C50 {
    char unknown_000[0xfd0];
    int unknown_fd0;
};

// A 0x34-byte record: a kind and six words at +0xc that a pick (0x2c bytes, its six words at +0x8) can replace.
struct Record_00052640 {
    int kind;
    int unknown_04[2];
    int values[6];
    int unknown_24[4];
};

struct Pick_00052640 {
    int unknown_00[2];
    int values[6];
    int unknown_20[3];
};

// Object 0xb: the records at +0x544.
struct Table_00052640 {
    char unknown_000[0x544];
    Record_00052640 records[1];
};

// What +0x1040 points at: its picks at +0x3c.
struct Picks_00052640 {
    char unknown_00[0x3c];
    Pick_00052640 *picks;
};

struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;
    char unknown_0060[0x8d8];
    Record_00052640 records[1];
    char unknown_096c[0x64c];
    Stage_00056540 *stage;
    char unknown_0fbc[0x84];
    Picks_00052640 *picks;
    char unknown_1044[4];
    int unknown_1048;

    void func_0004D740();
    void func_00052640();
};

// State handler 28 of the table at 0x1F9888: when object +0xc after the stage's +0x14 exists, copies record +0x14 of
// object 0xb into its own records at +0x938 (kind 10 with the six words of pick +0x18 of +0x1040 when there is one),
// hands it to the game's func_000127C0 (id +0x6d, and 0 for id +0x8d), +0x1048 into +0xfd0 of the player it keeps at
// +0x8d4 and func_00106F10 (+0x23c of the object it keeps at +0x8d8, the stage's +0x1c), each if it exists; then
// func_00060C90, func_0004D740 and state 0x1d.
void Object_0004ABA0::func_00052640()
{
    Other_0004AFC0 *other = (Other_0004AFC0 *)data_0022FCE0->func_000128C0(stage->unknown_14 + 0xc);
    if (other) {
        int index = stage->unknown_14;
        int pick = stage->unknown_18;
        Table_00052640 *table = (Table_00052640 *)data_0022FCE0->func_000128C0(0xb);
        Record_00052640 *record = &records[index];
        *record = table->records[index];
        if (pick >= 0) {
            Pick_00052640 *from = &picks->picks[pick];
            record->kind = 10;
            record->values[0] = from->values[0];
            record->values[1] = from->values[1];
            record->values[2] = from->values[2];
            record->values[3] = from->values[3];
            record->values[4] = from->values[4];
            record->values[5] = from->values[5];
        }
        data_0022FCE0->func_000127C0(index + 0x6d, (int)record);
        data_0022FCE0->func_000127C0(index + 0x8d, 0);
        Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(other->unknown_8d4);
        if (player) {
            player->unknown_fd0 = unknown_1048;
        }
        Owner_0004AD10 *owner = (Owner_0004AD10 *)data_0022FCE0->func_000128C0(other->unknown_8d8);
        if (owner) {
            func_00106F10(owner->unknown_23c, stage->unknown_1c);
        }
    }
    func_00060C90();
    func_0004D740();
    state = 0x1d;
}
