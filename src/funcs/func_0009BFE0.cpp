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
    void func_0009BFE0(int kind);
};

// Scores a trick of a kind: repeating the last kind (0xc50), or following kind 1, raises the level at 0xc4c (at most
// 8); a new kind becomes the last one. The points from data_0020E6F8 (second column for kind 3), times 500 with 0x1b8
// set or 10 otherwise, go to the sound of the object kept by id at 0xc98 (func_00106E50, kind 2) and are added to
// 0x104c and 0xfa8; then func_0009BB40.
void Object_000A1C50::func_0009BFE0(int kind)
{
    if (kind == this->kind) {
        level++;
    } else {
        if (this->kind == 1) {
            level++;
        }
        this->kind = kind;
    }
    if (level > 8) {
        level = 8;
    }
    int scale = value_1b8 ? 500 : 10;
    int points;
    if (this->kind == 3) {
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
