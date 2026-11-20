struct Body_000F02F0 {
    char unknown_00[0x70];
    float height;
};

struct Limit_000F02F0 {
    char unknown_00[8];
    float height;
};

struct Object_000EDC30 {
    char unknown_000[4];
    Body_000F02F0 *body;
    char unknown_008[0xcc];
    Limit_000F02F0 *limit;

    void func_000EF5F0();
    void func_000F02F0();
};

// One of the handlers in the table at 0x21A900: runs func_000EF5F0 while the body's +0x70 is below the limit's +8.
void Object_000EDC30::func_000F02F0()
{
    if (body->height < limit->height) {
        func_000EF5F0();
    }
}
