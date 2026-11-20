struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern int data_0020CE40[];

int func_000F7BE0(unsigned int stage);

// Object 9.
struct Object_0004ABA0 {
    char unknown_0000[0x104c];
    unsigned int stage;
};

// The node class whose table is at 0x1CCB68 (constructor 0x73500, made by 0x109300; destructor 0x73AD0).
struct Object_00073AD0 {
    char unknown_00[0x84];
    unsigned int stage;
    char unknown_88[4];
    unsigned int kind;

    int func_000733F0();
};

// Called by the constructor 0x73500: keeps object 9's stage (+0x104c) at +0x84 and, for kinds 9 and up, returns the
// word of data_0020CE40 for the stage's index (func_000F7BE0) in the kind's row of 14; else 0.
int Object_00073AD0::func_000733F0()
{
    Object_0004ABA0 *object = (Object_0004ABA0 *)data_0022FCE0->func_000128C0(9);
    if (object) {
        stage = object->stage;
        if (kind >= 9) {
            return data_0020CE40[func_000F7BE0(stage) + (kind - 9) * 14];
        }
    }
    return 0;
}
