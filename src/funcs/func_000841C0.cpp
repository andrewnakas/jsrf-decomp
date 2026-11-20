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
    void func_00083F50(float *position, int *angles, float scale, int flags);
};

// What +0xc of Object_00022990's entries points at: its id at +8 names an object that knows a player.
struct Object_000800D0 {
    char unknown_00[8];
    int id;

    void func_000841C0(float *position, int *angles, float scale, int flags);
};

// Called by 0x22530: hands the arguments to the player's func_00083F50.
void Object_000800D0::func_000841C0(float *position, int *angles, float scale, int flags)
{
    Owner_000800D0 *owner = (Owner_000800D0 *)data_0022FCE0->func_000128C0(id);
    if (owner) {
        Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(owner->player);
        if (player) {
            player->func_00083F50(position, angles, scale, flags);
        }
    }
}
