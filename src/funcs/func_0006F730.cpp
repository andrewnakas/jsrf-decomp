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

// Plays sound +0x2c of the set func_00043700 picks (func_0006F450 with -1, 0x400000 and 0).
void func_0006F730()
{
    func_0006F450(data_001FBCA8[data_001FC724.func_00043700()]->unknown_2c, -1, 0x400000, 0);
}
