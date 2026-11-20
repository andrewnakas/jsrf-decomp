struct Game {
    void func_000127C0(int first, int second);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Other_0004AFC0 {
    char unknown_000[0x8d8];
    int unknown_8d8;
};

struct Object_000A4D80 {
    void func_000A4B80();
};

struct Object_0004ABA0 {
    void func_0004C9C0();
};

// Called from state handler 30 (0x52780): 0 to func_000127C0 of the game as 0x19e, then func_000A4B80 on the object
// each of objects 0xc to 0x2b keeps the id of at +0x8d8 (as func_0004C960).
void Object_0004ABA0::func_0004C9C0()
{
    data_0022FCE0->func_000127C0(0x19e, 0);
    for (int i = 0xc; i <= 0x2b; i++) {
        Other_0004AFC0 *other = (Other_0004AFC0 *)data_0022FCE0->func_000128C0(i);
        if (other) {
            Object_000A4D80 *owner = (Object_000A4D80 *)data_0022FCE0->func_000128C0(other->unknown_8d8);
            if (owner)
                owner->func_000A4B80();
        }
    }
}
