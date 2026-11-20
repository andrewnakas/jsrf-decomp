struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_000FE4E0(int sound, int voice, int argument);

// The object 0xc after a player slot's id: the player's id at +0x8d4.
struct Owner_0004D7C0 {
    char unknown_000[0x8d4];
    int player;
};

// The player (table 0x1CCFF8).
struct Object_000A1C50 {
    char unknown_0000[0xfbc];
    int voice;
};

// Object 9.
struct Object_0004ABA0 {
    void func_0004D7C0(int sound, int slot, int argument);
};

// Called by func_00054750 (it does not use `this`). For a slot other than -1 whose object (slot + 0xc) knows a player,
// passes `sound`, the player's +0xfbc and `argument` to func_000FE4E0.
void Object_0004ABA0::func_0004D7C0(int sound, int slot, int argument)
{
    if (slot != -1) {
        Owner_0004D7C0 *owner = (Owner_0004D7C0 *)data_0022FCE0->func_000128C0(slot + 0xc);
        if (owner) {
            Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(owner->player);
            if (player) {
                func_000FE4E0(sound, player->voice, argument);
            }
        }
    }
}
