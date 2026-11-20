struct Object_00066980 {
    int value;

    void func_00066980(int newValue);
};

void Object_00066980::func_00066980(int newValue)
{
    value = newValue & 0x7fff;
}
