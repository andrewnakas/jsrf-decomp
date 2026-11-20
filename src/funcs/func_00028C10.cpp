struct Object_000265A0 {
    char unknown_0000[0x10bc];
    int values[1];

    int func_00028C10(int index);
};

// Returns a word of the table at +0x10bc.
int Object_000265A0::func_00028C10(int index)
{
    return values[index];
}
