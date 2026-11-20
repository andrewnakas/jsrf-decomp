struct Owner_000DC1A0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000DC1A0 {
    int unknown_00;
    Owner_000DC1A0 *owner;
    char unknown_08[8];
    int timer;
    char unknown_14[0x84];
    int mode;

    void func_000DC1A0();
};

void Object_000DC1A0::func_000DC1A0()
{
    owner->flags |= 0x2000000;
    timer = 0;
    mode = 2;
}
