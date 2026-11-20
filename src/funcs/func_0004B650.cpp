void func_00107320(int *value);

struct Object_00039BE0 {
    void func_00039C80(int value);
    void func_00039C90(int value);
};

extern Object_00039BE0 data_001EFFB0;

struct Object_0003E750 {
    void func_0003E930();
};

extern Object_0003E750 data_002314B0;

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;

    void func_0004B650();
};

// State handler 64 of the tables at 0x1F9888 and 0x1F9C48: func_00039C80(0) and func_00039C90(0) of 0x1EFFB0,
// func_0003E930 of 0x2314B0, func_00107320 with a 2, then state 0x41.
void Object_0004ABA0::func_0004B650()
{
    data_001EFFB0.func_00039C80(0);
    data_001EFFB0.func_00039C90(0);
    data_002314B0.func_0003E930();
    int value = 2;
    func_00107320(&value);
    state = 0x41;
}
