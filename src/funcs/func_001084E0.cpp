struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern int data_0021C510[];

struct Node {
    virtual ~Node();

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
};

// The player under the owner object (only the fields read here).
struct Player_001084E0 {
    char unknown_000[0xcd4];
    float value_cd4;
    float value_cd8;
    char unknown_cdc[0x2bc];
    int value_f98;
    int value_f9c;
    int value_fa0;
    int value_fa4;
    int value_fa8;
    char unknown_fac[8];
    int value_fb4;
    char unknown_fb8[4];
    int value_fbc;
    char unknown_fc0[4];
    int value_fc4;
    int value_fc8;
    char unknown_fcc[4];
    int value_fd0;
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    char unknown_0000[0x16b8];
    int ownerId;
    char unknown_16bc[8];
    int value_16c4;
    int value_16c8;
    int value_16cc;
    int value_16d0;
    int value_16d4;

    int func_001084E0(int index);
};

// Value `index` (0 to 16) of the player under the owner object (the floats 2 and 3 as their bits; 9 is one past
// the field; 12 is 0 while it is unset with 0xfa0 at 10 or more; 16 looks the field up in data_0021C510) or of this
// object (10, 11, 13, 14, 15); -1 without the player or for any other index.
int Object_00107FE0::func_001084E0(int index)
{
    Node *owner = (Node *)data_0022FCE0->func_000128C0(ownerId);
    if (owner && owner->parent) {
        Player_001084E0 *player = (Player_001084E0 *)owner->parent;
        switch (index) {
        case 0:
            return player->value_f9c;
        case 1:
            return player->value_f98;
        case 2: {
            float value = player->value_cd8;
            return *(int *)&value;
        }
        case 3: {
            float value = player->value_cd4;
            return *(int *)&value;
        }
        case 4:
            return player->value_fa4;
        case 5:
            return player->value_fa0;
        case 6:
            return player->value_fa8;
        case 7:
            return player->value_fd0;
        case 8:
            return player->value_fc4;
        case 9:
            return player->value_fc8 + 1;
        case 10:
            return value_16c4;
        case 11:
            return value_16c8;
        case 12:
            if (player->value_fb4 == -1 && player->value_fa0 >= 10) {
                return 0;
            }
            return player->value_fb4;
        case 13:
            return value_16cc;
        case 14:
            return value_16d0;
        case 15:
            return value_16d4;
        case 16:
            return data_0021C510[player->value_fbc];
        }
    }
    return -1;
}
