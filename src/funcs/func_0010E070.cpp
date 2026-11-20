int func_00119540(int group, int index, void *position);

struct Object_0010E070 {
    char unknown_00[0x4c];
    int value_4c;
    char unknown_50[0x9c];
    int mode;

    void func_0010E070();
};

// Asks func_00119540 for entry 5 of group 8 with no position, clears the field at 0x4c and sets the mode at
// 0xec to 2.
void Object_0010E070::func_0010E070()
{
    func_00119540(8, 5, 0);
    value_4c = 0;
    mode = 2;
}
