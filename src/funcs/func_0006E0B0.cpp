struct Object_0006E0B0 {
    char unknown_000[0xfec];
    int values[10];

    void func_0006E0B0(unsigned int index, int value);
};

// Stores a value in the ten-entry table at +0xfec; other indices are ignored.
void Object_0006E0B0::func_0006E0B0(unsigned int index, int value)
{
    if (index < 10) {
        values[index] = value;
    }
}
