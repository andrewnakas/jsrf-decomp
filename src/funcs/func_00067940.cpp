struct Object_00039BE0 {
    int func_0003A920(int value);
};

extern Object_00039BE0 data_001EFFB0;

struct Object_00067980 {
    char unknown_000[0x67c];
    int values[1];

    int func_00067940(int index);
};

// Says whether the object at 0x1EFFB0 accepts (func_0003A920) the value `index` of the table at +0x67c.
int Object_00067980::func_00067940(int index)
{
    return data_001EFFB0.func_0003A920(values[index]) != 0;
}
