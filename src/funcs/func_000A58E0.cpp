struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    Node *func_00011BD0();
};

// The camera's parent (the player): a request at 0xe5c.
struct Player_000A58E0 {
    char unknown_000[0xe5c];
    int request;
};

struct Object_000A4D80 {
    char unknown_000[0x1e4];
    Vector3 eye;
    Vector3 target;
    char unknown_1fc[0xc];
    unsigned int mode;
    char unknown_20c[0x1c];
    int value_228;
    char unknown_22c[8];
    int value_234;
    int stored;

    void func_000A32B0(Vector3 *eye, Vector3 *target);
    void func_000A4BD0();
    void func_000A58E0();
};

// A handler of the member-function table at 0x215534: by the mode at 0x208 does nothing (0, 4-7, 15), calls
// func_000A4BD0 (9, 10), places the camera with func_000A32B0 when the player asks (14) or always, keeping the value
// at 0x228 the first time (the rest); the player's request at 0xe5c is cleared.
void Object_000A4D80::func_000A58E0()
{
    Player_000A58E0 *player = (Player_000A58E0 *)((Node *)this)->func_00011BD0();
    switch (mode) {
    case 0:
    case 4:
    case 5:
    case 6:
    case 7:
    case 15:
        break;
    case 9:
    case 10:
        func_000A4BD0();
        break;
    case 14:
        if (player->request) {
            func_000A32B0(&eye, &target);
        }
        break;
    default:
        func_000A32B0(&eye, &target);
        if (!stored) {
            value_234 = value_228;
            stored = 1;
        }
        break;
    }
    player->request = 0;
}
