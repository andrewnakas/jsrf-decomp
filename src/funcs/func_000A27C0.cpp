/* const: 0x10000 */
// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xb64];
    int value_b64;

    int func_0007F880();
    void func_0009B190(int kind);
    int func_0009C690(int value);
    void func_000A2680();
    int func_000A27C0();
};

// A handler of the player's tables: with flag 0x10000 of func_0007F880, func_0009B190(1); with nothing left at
// 0xb64, func_0009B190(6); otherwise func_0009C690(1), the speed limit (func_000A2680), and one less at 0xb64.
// Returns 1.
int Object_000A1C50::func_000A27C0()
{
    if (func_0007F880() & 0x10000) {
        func_0009B190(1);
        return 1;
    }
    if (value_b64 <= 0) {
        func_0009B190(6);
        return 1;
    }
    func_0009C690(1);
    func_000A2680();
    value_b64--;
    return 1;
}
