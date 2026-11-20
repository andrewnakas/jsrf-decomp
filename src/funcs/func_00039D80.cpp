struct Object_00039BE0 {
    void func_00039BE0(int value);
    void func_00039D80(int *values, unsigned int count);
};

void Object_00039BE0::func_00039D80(int *values, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++) {
        func_00039BE0(values[i]);
    }
}
