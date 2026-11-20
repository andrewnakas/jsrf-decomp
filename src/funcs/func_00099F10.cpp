struct Vector3 {
    float x;
    float y;
    float z;
};

struct Entry_00015090;

struct Object_00015130 {
    void func_00015010(Entry_00015090 *entry, const Vector3 *position, int kind, int flag);
};

extern Object_00015130 data_001EB994;

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x420];
    Entry_00015090 *entry;
    char unknown_424[0x674];
    float height;
    char unknown_a9c[8];
    int ground;
    char unknown_aa8[0x1fc];
    Vector3 position;

    void func_000A0610(int move);
    void func_00099F10();
};

// Picks the landing move: 8, 9 or 10 for grounds 2 to 4 (0xaa4), otherwise by the fall from 0xa98 to the position's
// y: below 5 move 1, below 20 move 4, below 40 move 3, else 2. Plays sound 7 at the position (func_00015010 of
// data_001EB994) and starts the move (func_000A0610).
void Object_000A1C50::func_00099F10()
{
    int move;
    switch (ground) {
    case 2:
        move = 8;
        break;
    case 3:
        move = 9;
        break;
    case 4:
        move = 10;
        break;
    default: {
        float fall = height - position.y;
        if (fall < 5.0f) {
            move = 1;
        } else if (fall < 20.0f) {
            move = 4;
        } else if (fall < 40.0f) {
            move = 3;
        } else {
            move = 2;
        }
        break;
    }
    }
    data_001EB994.func_00015010(entry, &position, 7, 0);
    func_000A0610(move);
}
