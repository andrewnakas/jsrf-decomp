/* const: 0x20034 */
struct Game {
    void func_000127C0(int index, int value);
    int func_000127E0(int index);
    void *func_000128C0(int index);
};

extern Game *data_0022FCE0;

// Object 9; func_00051780 starts it (1) or carries it on (0).
struct Object_0004ABA0 {
    char unknown_00[0x48];
    unsigned int unknown_48;

    void func_00051780(int restart);
};

void func_0004E930(int first, int second, int third);
void *__stdcall func_00145A2F(void *address, unsigned long size, unsigned long type, unsigned long protect);

// A record of object 0xb's table at +0x544 (0x34 bytes).
struct Record_000556D0 {
    int kind;
    char unknown_04[0x24];
    int unknown_28;
    char *cursor;
    int unknown_30;
};

// A record and the 0x20000 bytes it fills.
struct Block_000556D0 {
    Record_000556D0 header;
    char data[0x20000];
};

struct Object_000556D0 {
    char unknown_000[0x544];
    Record_000556D0 records[4];
};

inline Object_0004ABA0 *stage_000556D0()
{
    return (Object_0004ABA0 *)data_0022FCE0->func_000128C0(9);
}

// As func_00055530.
inline int start_000556D0(int restart)
{
    Object_0004ABA0 *stage = stage_000556D0();
    if (stage) {
        if (restart) {
            stage->func_00051780(1);
            return 1;
        }
        if (stage->unknown_48 >= 2) {
            stage->func_00051780(0);
            return 1;
        }
    }
    return 0;
}

struct Object_0004EF90 {
    char unknown_00[0x44];
    int next;
    char unknown_48[0x18];
    unsigned int counts[4];
    Block_000556D0 *made[4];
    char unknown_80[0x10];
    Block_000556D0 *blocks[4];

    void func_000556D0();
};

// A state handler (table 0x1FA008): when object 9 does not exist yet, clears game values 0x4d to 0x50, gives each of
// the four players with a count a block (a copy of object 0xb's record and 0x20000 bytes, allocated once) as game value
// 0x14d + i, starts object 9 and goes to state 15.
void Object_0004EF90::func_000556D0()
{
    if (stage_000556D0()) {
        return;
    }
    unsigned int i;
    for (i = 0; i < 4; i++) {
        data_0022FCE0->func_000127C0(i + 0x4d, -1);
    }
    Object_000556D0 *source = (Object_000556D0 *)data_0022FCE0->func_000128C0(0xb);
    for (i = 0; i < 4; i++) {
        if (counts[i] > 0) {
            if (made[i] == 0) {
                Block_000556D0 *block = (Block_000556D0 *)func_00145A2F(0, sizeof(Block_000556D0), 0x3000, 4);
                blocks[i] = block;
                block->header = source->records[i];
                block->header.kind = 2;
                block->header.unknown_28 = 0;
                block->header.cursor = blocks[i]->data;
                block->header.unknown_30 = 0;
            }
            data_0022FCE0->func_000127C0(i + 0x14d, (int)blocks[i]);
        }
    }
    data_0022FCE0->func_000127C0(0xb, 3);
    func_0004E930(data_0022FCE0->func_000127E0(2), data_0022FCE0->func_000127E0(3), 0);
    start_000556D0(1);
    next = 15;
}
