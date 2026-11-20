// The player object: this handler sits in the table func_00097D60 dispatches, and func_000A24F0 calls
// func_000A22F0 and func_000A1CF0 with its own `this`.
struct Object_000A1C50 {
    void func_000A24F0(int mode);
    int func_00099D70();
};

int Object_000A1C50::func_00099D70()
{
    func_000A24F0(0);
    return 1;
}
