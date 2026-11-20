struct Object_0006E0B0 {
    char unknown_000[0x1014];
    int values[10];

    void func_0006E0D0(unsigned int index, int value);
};

// Stores a value in the ten-entry table at +0x1014; other indices are ignored.
void Object_0006E0B0::func_0006E0D0(unsigned int index, int value)
{
    if (index < 10) {
        values[index] = value;
    }
}
