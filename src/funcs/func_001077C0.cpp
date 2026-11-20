struct Object_001077C0 {
    char unknown_00[0x44];
    int slots[1];

    void func_001077C0(int index);
};

void Object_001077C0::func_001077C0(int index)
{
    slots[index] = -1;
}
