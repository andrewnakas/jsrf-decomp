struct Game {
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;

struct Sound_001FBCA8 {
    int unknown_00;
    int unknown_04;
};

extern Sound_001FBCA8 *data_001FBCA8[];

void func_0006F450(int sound, int argument1, int flags, int argument3);
void func_0006F520(int value);

// By func_000127E0 (0x1b2) of the game: 1 runs func_0006F520 (-1), 2 plays the sound at +0x4 of the current entry of
// 0x1FBCA8 (func_0006F450 with 0x28000000).
void func_0006F760()
{
    switch (data_0022FCE0->func_000127E0(0x1b2)) {
    case 1:
        func_0006F520(-1);
        break;
    case 2:
        func_0006F450(data_001FBCA8[data_001FC724.func_00043700()]->unknown_04, -1, 0x28000000, -1);
        break;
    }
}
