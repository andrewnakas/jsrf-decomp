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
    char unknown_0000[0xca0];
    int unknown_ca0;
    char unknown_0ca4[0x318];
    int voice;
};

// Object 9.
struct Object_0004ABA0 {
    void func_0004D810(int sound, int key, int argument);
};

// Called by func_00054750 (it does not use `this`). Finds the first of the four slots (objects 0xc-0xf) whose player
// has `key` at +0xca0 and passes `sound`, the player's +0xfbc and `argument` to func_000FE4E0.
void Object_0004ABA0::func_0004D810(int sound, int key, int argument)
{
    for (unsigned int i = 0; i < 4; i++) {
        Owner_0004D7C0 *owner = (Owner_0004D7C0 *)data_0022FCE0->func_000128C0(i + 0xc);
        if (owner) {
            Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(owner->player);
            if (player && player->unknown_ca0 == key) {
                func_000FE4E0(sound, player->voice, argument);
                return;
            }
        }
    }
}
