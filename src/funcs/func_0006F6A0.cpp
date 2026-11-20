/* const: 0x200000 */
struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;

struct Sound_001FBCA8 {
    char unknown_00[0x2c];
    int unknown_2c;
    int unknown_30;
    int unknown_34;
    int unknown_38;
};

extern Sound_001FBCA8 *data_001FBCA8[];

void func_0006F450(int sound, int first, int flags, int value);

// Plays sound +0x30 of the set func_00043700 picks (func_0006F450 with -1, 0x200000 and -1).
void func_0006F6A0()
{
    func_0006F450(data_001FBCA8[data_001FC724.func_00043700()]->unknown_30, -1, 0x200000, -1);
}
