struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_00106F40(unsigned int id, int value);

// Objects 0xc-0xf: the mode at +0x8b4, the player's id at +0x8d4 and another object's id at +0x8d8.
struct Owner_0004CDC0 {
    char unknown_000[0x8b4];
    int mode;
    char unknown_8b8[0x1c];
    int player;
    int other;
};

// What +0x8d8 names: a handle at +0x23c.
struct Other_0004CCF0 {
    char unknown_000[0x23c];
    unsigned int handle;
};

// The player (table 0x1CCFF8).
struct Object_000A1C50 {
    char unknown_0000[0xca0];
    int key;
    char unknown_0ca4[0x320];
    int unknown_fc4;
};

// Object 9.
struct Object_0004ABA0 {
    unsigned int func_0004CCF0();
};

// Called by func_00054150 and func_00056990 (it does not use `this`): the number of different keys (+0xca0) among the
// players of slots 0xc-0xf whose mode is not 0xb; for a slot in mode 0xb whose player's +0xfc4 is not negative, runs
// func_00106F40 (8) on the handle of the object at +0x8d8 (when it exists) and sets +0xfc4 to -1.
unsigned int Object_0004ABA0::func_0004CCF0()
{
    int keys[4];
    unsigned int count = 0;
    for (unsigned int i = 0; i < 4; i++) {
        Owner_0004CDC0 *owner = (Owner_0004CDC0 *)data_0022FCE0->func_000128C0(i + 0xc);
        if (owner) {
            Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(owner->player);
            if (player) {
                if (owner->mode == 0xb) {
                    if (player->unknown_fc4 >= 0) {
                        Other_0004CCF0 *other = (Other_0004CCF0 *)data_0022FCE0->func_000128C0(owner->other);
                        if (other)
                            func_00106F40(other->handle, 8);
                        player->unknown_fc4 = -1;
                    }
                } else {
                    unsigned int j;
                    for (j = 0; j < count; j++) {
                        if (keys[j] == player->key)
                            break;
                    }
                    if (j >= count) {
                        keys[count] = player->key;
                        count++;
                    }
                }
            }
        }
    }
    return count;
}
