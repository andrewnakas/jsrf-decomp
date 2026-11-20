struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Objects 0xc-0x2b: a word at +0x8ac (-1 when unused), the mode at +0x8b4 and the player's id at +0x8d4.
struct Owner_0004CC80 {
    char unknown_000[0x8ac];
    int unknown_8ac;
    char unknown_8b0[4];
    int mode;
    char unknown_8b8[0x1c];
    int player;
};

// The player (table 0x1CCFF8).
struct Object_000A1C50 {
    char unknown_0000[0xfd0];
    int unknown_fd0;
};

// Object 9.
struct Object_0004ABA0 {
    char unknown_0000[0x1048];
    int unknown_1048;

    int func_0004CC80();
};

// Called by func_00056990: gives each player of objects 0xc-0x2b the word at +0x1048 (into +0xfd0). Returns 0 as soon
// as an object in use (+0x8ac not -1) has a mode other than 0xb or 0xc, otherwise 1.
int Object_0004ABA0::func_0004CC80()
{
    for (int i = 0xc; i <= 0x2b; i++) {
        Owner_0004CC80 *owner = (Owner_0004CC80 *)data_0022FCE0->func_000128C0(i);
        if (owner) {
            if (owner->unknown_8ac != -1 && owner->mode != 0xb && owner->mode != 0xc)
                return 0;
            Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(owner->player);
            if (player)
                player->unknown_fd0 = unknown_1048;
        }
    }
    return 1;
}
