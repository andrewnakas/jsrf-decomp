struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The object the player keeps by id at 0xc98: a sound id at 0x23c.
struct Owner_0009C350 {
    char unknown_000[0x23c];
    unsigned int sound;
};

void func_00106E50(unsigned int id, unsigned int kind, int first, int second, int third);

// The points of a trick by level (0 to 8): plain and for kind 3.
struct Points_0009C240 {
    int plain;
    int special;
};

extern Points_0009C240 data_0020E6F8[];

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x1b8];
    int value_1b8;
    char unknown_1bc[0xa90];
    unsigned int level;
    int kind;
    char unknown_c54[0x44];
    int ownerId;
    char unknown_c9c[0x30c];
    int total;
    char unknown_fac[0xa0];
    int score;

    void func_0009BB40();
    void func_0009C240();
};

// Scores a trick: the level at 0xc4c (at most 8) picks its points from data_0020E6F8 (the second column for kind 3 at
// 0xc50), times 1500 with 0x1b8 set or 30 otherwise; tells the sound of the object kept by id at 0xc98
// (func_00106E50, kind 2), adds the score to 0x104c and 0xfa8 and runs func_0009BB40.
void Object_000A1C50::func_0009C240()
{
    if (level > 8) {
        level = 8;
    }
    int scale = value_1b8 ? 1500 : 30;
    int points;
    if (kind == 3) {
        points = data_0020E6F8[level].special;
    } else {
        points = data_0020E6F8[level].plain;
    }
    Owner_0009C350 *owner = (Owner_0009C350 *)data_0022FCE0->func_000128C0(ownerId);
    if (owner) {
        func_00106E50(owner->sound, 2, scale, points, score);
    }
    total += points * scale;
    score += points * scale;
    func_0009BB40();
}
