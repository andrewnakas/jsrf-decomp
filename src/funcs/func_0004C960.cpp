struct Game {
    void func_000127C0(int first, int second);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Info_0004C960 {
    int unknown_00;
    int unknown_04;
};

struct Other_0004AFC0 {
    char unknown_000[0x8d8];
    int unknown_8d8;
};

struct Object_000A4D80 {
    void func_000A4B80();
};

struct Object_0004ABA0 {
    char unknown_0000[0x1040];
    Info_0004C960 *info;

    void func_0004C960();
};

// Called from state handler 31 (0x52950): the word at +4 of the block at +0x1040 to func_000127C0 of the game as 0x19e,
// then func_000A4B80 on the object each of objects 0xc to 0x2b keeps the id of at +0x8d8.
void Object_0004ABA0::func_0004C960()
{
    data_0022FCE0->func_000127C0(0x19e, info->unknown_04);
    for (int i = 0xc; i <= 0x2b; i++) {
        Other_0004AFC0 *other = (Other_0004AFC0 *)data_0022FCE0->func_000128C0(i);
        if (other) {
            Object_000A4D80 *owner = (Object_000A4D80 *)data_0022FCE0->func_000128C0(other->unknown_8d8);
            if (owner)
                owner->func_000A4B80();
        }
    }
}
