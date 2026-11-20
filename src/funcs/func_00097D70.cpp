struct Object_0009B190 {
    char unknown_0000[0xe04];
    int value_e04;

    void func_0009B190(int index);
    int func_00097D70();
};

// A handler of the member-function table at 0x20e4a4 (eight slots, next to func_00097DA0): runs
// func_0009B190(3) when the field at 0xe04 is set, func_0009B190(5) otherwise; returns 1.
int Object_0009B190::func_00097D70()
{
    if (value_e04) {
        func_0009B190(3);
        return 1;
    }
    func_0009B190(5);
    return 1;
}
