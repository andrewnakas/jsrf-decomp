struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xe60];
    unsigned int value_e60;
};

struct Object_000C1270 {
    char unknown_00[0xb0];
    unsigned int value_b0;
};

extern Object_000C1270 *data_00257CE4;

// 0 while the player exists with its field at 0xe60 set; otherwise whether the field at 0xb0 of data_00257CE4 is
// at most 2.
int func_000C1630()
{
    Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(0x2c);
    if (player && player->value_e60 > 0) {
        return 0;
    }
    return data_00257CE4->value_b0 <= 2;
}
