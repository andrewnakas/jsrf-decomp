struct Vector3 {
    float x;
    float y;
    float z;
};

// A face: a point on it, its distance and its normal (+0x10).
struct Plane_0007F030 {
    Vector3 point;
    float distance;
    Vector3 normal;
};

float __fastcall func_0014BD00(Vector3 *out, const Vector3 *point, const Plane_0007F030 *plane);

// What func_00089950 hands its helpers: a direction at +0x10 and a length at +0x20.
struct Move_0007F110 {
    char unknown_00[0x10];
    Vector3 direction;
    char unknown_1c[0x4];
    float length;
};

// The player.
struct Object_000A1C50 {
    void func_0007F110(Vector3 *out, const Move_0007F110 *move);
    void func_0007F140(Vector3 *out, const Move_0007F110 *move);
    void func_0007F340(Vector3 *out, const Move_0007F110 *move, int kind);
    void func_00082FB0(Vector3 *out, const Move_0007F110 *move);
    void func_00089950(Vector3 *out, const Move_0007F110 *move, int kind, const Plane_0007F030 *plane);
};

// The step for a move by its kind (1 func_0007F110, 2 func_0007F140, 3 func_00082FB0, 4 and up func_0007F340; 0
// leaves `out` alone), laid onto the face when there is one (the difference of the feet of the step and of the
// origin, func_0014BD00).
void Object_000A1C50::func_00089950(Vector3 *out, const Move_0007F110 *move, int kind, const Plane_0007F030 *plane)
{
    Vector3 step;
    switch (kind) {
    case 0:
        return;
    case 1:
        func_0007F110(&step, move);
        break;
    case 2:
        func_0007F140(&step, move);
        break;
    case 3:
        func_00082FB0(&step, move);
        break;
    default:
        func_0007F340(&step, move, kind);
        break;
    }
    if (plane) {
        Vector3 origin = {0.0f, 0.0f, 0.0f};
        Vector3 point = step;
        Vector3 base;
        func_0014BD00(&base, &origin, plane);
        Vector3 foot;
        func_0014BD00(&foot, &point, plane);
        step.x = foot.x - base.x;
        step.y = foot.y - base.y;
        step.z = foot.z - base.z;
    }
    *out = step;
}
