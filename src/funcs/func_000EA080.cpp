struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

struct Owner_000EA080 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
};

struct Object_000E7F50 {
    char unknown_000[4];
    Owner_000EA080 *owner;
    char unknown_008[0x10c];
    Object_00047470 *model;
    char unknown_118[0x10];
    void *pose;

    void func_000EA080(Vector3 *out);
};

extern Vector3 data_00219218;

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

// Places the model at +0x114 at the owner's position and angles (turned half way round) with the pose at +0x128,
// and gives in `out` where the point data_00219218 of the model lands (func_001BAB20).
void Object_000E7F50::func_000EA080(Vector3 *out)
{
    func_001BAA00();
    func_001BAAA0(&owner->position.x);
    func_001BB330(owner->angles.y + 0x8000);
    func_001BB2E0(owner->angles.x);
    func_001BB380(owner->angles.z);
    model->func_00047970(pose, 0);
    model->func_000480C0(0);
    func_001BAB20(out, &data_00219218);
    func_001BAA50();
}
