struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014CB60(const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

struct Owner_000D2120 {
    char unknown_00[0x44];
    Vector3 position;
};

// The class (constructor func_000D27F0) whose slot 0 runs the member-function table at 0x2169e0.
struct Object_000D27F0 {
    char unknown_000[0x4];
    Owner_000D2120 *owner;
    char unknown_008[0x7c];
    Vector3 points[300];
    char unknown_e94[0x24];
    int count;

    int func_000D2220();
};

// 1 when the owner stands within 4 of the newest point (index 0xeb8 of the points at 0x84) and less than 4 above
// or 20 below it, or when the newest point lies within 2 of one of the older ones (from the second up to ten
// before it); else 0. Called by func_000D36A0.
int Object_000D27F0::func_000D2220()
{
    if (func_0014CB60(&owner->position, &points[count]) < 4.0f) {
        float rise = points[count].y - owner->position.y;
        if (rise > -4.0f && rise < 20.0f) {
            return 1;
        }
    }
    for (int i = 0; i < count - 10; i++) {
        if (func_0014C530(&points[i + 1], &points[count]) < 2.0f) {
            return 1;
        }
    }
    return 0;
}
