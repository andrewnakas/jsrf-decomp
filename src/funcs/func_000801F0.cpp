struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The object found by the id of an Object_000800D0: the player's id at +0x8d4.
struct Owner_000800D0 {
    char unknown_000[0x8d4];
    int player;
};

// The player (table 0x1CCFF8).
struct Object_000A1C50 {
    char unknown_0000[0x9d8];
    int unknown_9d8;
};

// What +0xc of Object_00022990's entries points at: its id at +8 names an object that knows a player.
struct Object_000800D0 {
    char unknown_00[8];
    int id;

    int func_000801F0();
};

// Called by 0x22200: the player's word at +0x9d8, or 0 without a player.
int Object_000800D0::func_000801F0()
{
    Owner_000800D0 *owner = (Owner_000800D0 *)data_0022FCE0->func_000128C0(id);
    if (owner) {
        Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(owner->player);
        if (player) {
            return player->unknown_9d8;
        }
    }
    return 0;
}
