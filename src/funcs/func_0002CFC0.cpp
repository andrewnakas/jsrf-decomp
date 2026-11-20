struct Game {
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

struct Object_000265A0 {
    char unknown_0000[0x18b0];
    int unknown_18b0;
    int unknown_18b4;
    int unknown_18b8;

    int func_0002CFC0(int value);
};

// Handler 26 of the table at 0x1EC068: clears +0x18b0 and +0x18b8, keeps `value` at +0x18b4; when func_000127E0 (0x1c5) of
// the game says so, 1 into +0x18b0 and 4 into +0x18b8. Returns 1.
int Object_000265A0::func_0002CFC0(int value)
{
    unknown_18b8 = 0;
    unknown_18b0 = 0;
    unknown_18b4 = value;
    if (data_0022FCE0->func_000127E0(0x1c5)) {
        unknown_18b0 = 1;
        unknown_18b8 = 4;
    }
    return 1;
}
