struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    Node *func_00011BD0();
};

// The player (the camera node's parent): its position at 0xca4 and its angles at 0xcbc to 0xcc4.
struct Object_000A1C50 {
    char unknown_000[0xca4];
    float position[3];
    char unknown_cb0[0xc];
    int yaw;
    int roll;
    int pitch;
};

void func_001BA9C0();
void func_001BAA00();
void __fastcall func_001BAA50();
void func_001BAA60(float x, float y, float z);
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

// The camera node (a child of the player).
struct Object_000A4D80 : Node {
    char unknown_000[0xe4];
    int value_e4;
    char unknown_0e8[0x114];
    int value_1fc;
    int value_200;

    void func_000A32B0(Vector3 *first, Vector3 *second);
};

// From the player's position and angles (yaw 0xcbc, pitch 0xcc4, roll 0xcc0), puts the point (0, 18, -38) into
// `first` and (0, 14, 0) into `second`; clears 0x1fc and 0xe4 and sets 0x200 to 0x3555.
void Object_000A4D80::func_000A32B0(Vector3 *first, Vector3 *second)
{
    Object_000A1C50 *player = (Object_000A1C50 *)func_00011BD0();
    func_001BAA00();
    func_001BAAA0(player->position);
    func_001BB2E0(player->yaw);
    func_001BB380(player->pitch);
    func_001BB330(player->roll);
    func_001BA9C0();
    func_001BAA60(0.0f, 14.0f, 0.0f);
    func_001BAB20(second, 0);
    func_001BAA50();
    func_001BA9C0();
    func_001BAA60(0.0f, 18.0f, -38.0f);
    func_001BAB20(first, 0);
    func_001BAA50();
    func_001BAA50();
    value_1fc = 0;
    value_e4 = 0;
    value_200 = 0x3555;
}
