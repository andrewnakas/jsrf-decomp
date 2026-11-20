struct Game {
    void *func_000128C0(int id);
    void func_000127C0(int index, int value);
};

struct Block_000FF100 {
    char unknown_00[0x1c];
    int busy;
};

// Object 9 (its block at +0x1040).
struct Stage_000FF100 {
    char unknown_0000[0x1040];
    Block_000FF100 *block;
};

struct Course_000FF100 {
    int kind;
};

// The block func_0004EA50 fills in.
struct Info_0004D460 {
    char unknown_000[0x114];
    Course_000FF100 *course;
};

// Object 0x1163 (constructor func_000FF230, destructor func_000FEC60).
struct Object_000FEDB0 {
    void func_000FF100();
};

extern Game *data_0022FCE0;

void func_0004EA50(Info_0004D460 *info);

// When object 9 exists and the word at +0x1c of its block is 0: for course kind 4 sets the game values 0x1b6 = 5,
// 0x1bc = 1, 0x1bd-0x1bf = 0 and 0x1ba = 4; for kind 7 the same with 6 and 1. It does not use `this`.
void Object_000FEDB0::func_000FF100()
{
    Stage_000FF100 *stage = (Stage_000FF100 *)data_0022FCE0->func_000128C0(9);
    if (stage && stage->block->busy == 0) {
        Info_0004D460 info;
        func_0004EA50(&info);
        if (info.course) {
            switch (info.course->kind) {
            case 4:
                data_0022FCE0->func_000127C0(0x1b6, 5);
                data_0022FCE0->func_000127C0(0x1bc, 1);
                data_0022FCE0->func_000127C0(0x1bd, 0);
                data_0022FCE0->func_000127C0(0x1be, 0);
                data_0022FCE0->func_000127C0(0x1bf, 0);
                data_0022FCE0->func_000127C0(0x1ba, 4);
                break;
            case 7:
                data_0022FCE0->func_000127C0(0x1b6, 6);
                data_0022FCE0->func_000127C0(0x1bc, 1);
                data_0022FCE0->func_000127C0(0x1bd, 0);
                data_0022FCE0->func_000127C0(0x1be, 0);
                data_0022FCE0->func_000127C0(0x1bf, 0);
                data_0022FCE0->func_000127C0(0x1ba, 1);
                break;
            }
        }
    }
}
