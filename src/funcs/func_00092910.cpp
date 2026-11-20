struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000149B0 {
    void func_000149F0(int value);
};

struct Object_00014A80 : Object_000149B0 {
    int func_00014AA0(int index, int value);
};

extern Object_00014A80 data_001EB938;

// The player's parent (table 0x1CD570): its owner id at 0x8d4.
struct Object_000A6980 {
    char unknown_000[0x8d4];
    int ownerId;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xe50];
    int value_e50;
    char unknown_e54[0x160];
    int value_fb4;

    void func_00092810();
    void func_00092910(int index, int value);
};

// Hands mark 10 at 0xfb4 on to the player of stage slot index (object index + 0xc, its player by the owner id at
// 0x8d4) unless that player is in move 0x15, and tells data_001EB938 (func_000149F0(1), func_00014AA0); without
// such a player (or without mark 10, or for index -1) it runs func_00092810 instead.
void Object_000A1C50::func_00092910(int index, int value)
{
    if (index != -1 && value_fb4 == 10) {
        Object_000A6980 *stage = (Object_000A6980 *)data_0022FCE0->func_000128C0(index + 0xc);
        if (stage) {
            Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(stage->ownerId);
            if (player && player->value_e50 != 0x15) {
                player->value_fb4 = 10;
                value_fb4 = -1;
                data_001EB938.func_000149F0(1);
                data_001EB938.func_00014AA0(index, value);
                return;
            }
        }
    }
    func_00092810();
}
