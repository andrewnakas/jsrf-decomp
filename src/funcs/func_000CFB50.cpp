struct Object_000CFB50 {
    char unknown_00[0x44];
    int state;
    char unknown_48[0x28];
    unsigned int flags;

    void func_000CFB50();
};

void Object_000CFB50::func_000CFB50()
{
    if (state == 0) {
        state = 1;
    }
    flags |= 2;
}
