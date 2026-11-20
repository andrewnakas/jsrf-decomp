struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Objects 0xc-0xf: the mode at +0x8b4 and the player's id at +0x8d4.
struct Owner_0004CDC0 {
    char unknown_000[0x8b4];
    int mode;
    char unknown_8b8[0x1c];
    int player;
};

// The player (table 0x1CCFF8).
struct Object_000A1C50 {
    char unknown_0000[0xca0];
    int key;
};

// Object 9.
struct Object_0004ABA0 {
    char unknown_0000[0xfcc];
    int keys[4];
    unsigned int keyCount;

    void func_0004CDC0();
};

// Called by func_00054150 and func_00056990: collects into +0xfcc (count at +0xfdc) the different keys (+0xca0) of
// the players of slots 0xc-0xf whose mode is not 0xb.
void Object_0004ABA0::func_0004CDC0()
{
    keyCount = 0;
    for (unsigned int i = 0; i < 4; i++) {
        Owner_0004CDC0 *owner = (Owner_0004CDC0 *)data_0022FCE0->func_000128C0(i + 0xc);
        if (owner) {
            Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(owner->player);
            if (player && owner->mode != 0xb) {
                unsigned int count = keyCount;
                unsigned int j;
                for (j = 0; j < keyCount; j++) {
                    if (keys[j] == player->key)
                        break;
                }
                if (j >= count) {
                    keys[count] = player->key;
                    keyCount++;
                }
            }
        }
    }
}
