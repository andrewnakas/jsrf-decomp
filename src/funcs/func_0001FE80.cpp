struct Object_00066980 {
    float func_00066950();
};

extern Object_00066980 data_00251F28;

struct Entry_0001FE80 {
    char unknown_00[0x7c];
    int timer;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990); its slot 4 (0x23790) runs the member-pointer table
// at 0x1EBCF0 by each entry's kind.
struct Object_00022990 {
    char unknown_00[0xe0];
    Entry_0001FE80 **entries;

    void func_0001FE80(int index);
};

// Kinds 2 and 3 of the table at 0x1EBCF0: one time in 120 (func_00066950 of 0x251F28) sets entry `index`'s timer to
// 5; the timer then counts down to 0.
void Object_00022990::func_0001FE80(int index)
{
    if ((int)(data_00251F28.func_00066950() * 120.0f) == 0)
        entries[index]->timer = 5;
    if (entries[index]->timer > 0)
        entries[index]->timer--;
}
