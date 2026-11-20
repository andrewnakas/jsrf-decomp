struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB380(int angle);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *position, Vector3 *direction);
};

// The player.
struct Object_000A1C50 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0xc];
    int angles[3];

    void func_0007EB10();
};

// Hands object 0xe8 (func_000651E0, kind 1) the player's position and its up axis turned by its x and z angles.
void Object_000A1C50::func_0007EB10()
{
    Vector3 axisY = {0.0f, 1.0f, 0.0f};
    func_001BAA00();
    func_001BB2E0(angles[0]);
    func_001BB380(angles[2]);
    Vector3 up;
    func_001BAC00(&up, &axisY);
    func_001BAA50();
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        object->func_000651E0(1, &position, &up);
    }
}
