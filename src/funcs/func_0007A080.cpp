int func_00119540(int group, int index, void *position);

// Built by 0x7A8B0 (state at +0xf0; +0x98 is the first of the handles 0x25700 gives it).
struct Object_00079B50 {
    char unknown_000[0x98];
    int handle;
    char unknown_09c[0x54];
    int state;

    void func_0007A080();
};

// Not referenced. In state 3 with no handle at +0x98: state 5 and sound 8 / 2.
void Object_00079B50::func_0007A080()
{
    if (state == 3 && handle == 0) {
        state = 5;
        func_00119540(8, 2, 0);
    }
}
