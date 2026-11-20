struct Object_00106590 {
    char unknown_00[0x48];
    int state;
    char unknown_4c[0x10];
    float scale;
    int offset;

    void func_00106590(int fast);
};

// Unless the state at 0x48 is 6: the field at 0x5c becomes 2 and the one at 0x60 -0xe800 for a true
// argument, 1 and -0x2a00 otherwise.
void Object_00106590::func_00106590(int fast)
{
    if (state != 6) {
        if (fast) {
            scale = 2.0f;
            offset = -0xe800;
        } else {
            scale = 1.0f;
            offset = -0x2a00;
        }
    }
}
