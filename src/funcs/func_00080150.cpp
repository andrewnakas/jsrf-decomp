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
    char unknown_0000[0x1108];
    int unknown_1108[3];
};

// What +0xc of Object_00022990's entries points at: its id at +8 names an object that knows a player.
struct Object_000800D0 {
    char unknown_00[8];
    int id;

    void func_00080150(int first, int second, int third);
};

// Called by 0x21D90: stores the three words at +0x1108 of the player.
void Object_000800D0::func_00080150(int first, int second, int third)
{
    Owner_000800D0 *owner = (Owner_000800D0 *)data_0022FCE0->func_000128C0(id);
    if (owner) {
        Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(owner->player);
        if (player) {
            player->unknown_1108[0] = first;
            player->unknown_1108[1] = second;
            player->unknown_1108[2] = third;
        }
    }
}
