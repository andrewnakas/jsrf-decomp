// The player object: this handler sits in the table func_00098D80 dispatches, and func_0009C690 calls
// func_0007F880 with its own `this`.
struct Object_000A1C50 {
    int func_0009C690(int mode);
    int func_00099D60();
};

int Object_000A1C50::func_00099D60()
{
    func_0009C690(0);
    return 1;
}
