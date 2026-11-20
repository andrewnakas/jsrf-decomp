// The player object: this handler sits in the table func_000A0860 dispatches, and func_000A08B0 calls
// func_0007F880, func_000992D0 and func_0009B190 with its own `this`.
struct Object_000A1C50 {
    int func_000A08B0(int mode);
    int func_000A0F00();
};

int Object_000A1C50::func_000A0F00()
{
    return func_000A08B0(1);
}
