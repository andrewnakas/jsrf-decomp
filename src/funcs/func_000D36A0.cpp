struct Vector3 {
    float x;
    float y;
    float z;
};

struct Rotation_000D2B90 {
    Vector3 axis;
    int angle;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC70(Rotation_000D2B90 *rotation);
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
void __fastcall func_0014CD50(Vector3 *out, const Vector3 *in);
int func_0014C7A0(float cosine);
float func_0014C7F0(float value);

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1450.
struct Object_00157F10 : Object_000C1440 {
};

extern Object_00157F10 *data_00257CE8;

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);
    void func_000C5B40(int handle, void *data);
    int func_000C5B70(int handle);
};

// The class (constructor func_000D27F0) whose slot 0 runs the member-function table at 0x2169e0.
struct Object_000D27F0 {
    char unknown_000[0x4];
    Object_000C5B50 *owner;
    char unknown_008[0x88];
    Vector3 points[300];
    Vector3 direction;
    char unknown_eac[0xc];
    unsigned int count;
    char unknown_ebc[0x24];
    float speed;
    char unknown_ee4[0x118];
    int handle;

    void func_000D27A0();
    int func_000D2220();
    int func_000D36A0(Vector3 *position, int flags);
};

// Lays the next point of the trail at 0x90: turns the direction at 0xea0 toward `position` (from the last point, by at
// most func_000C1450's step 0x222 of the angle between them; straight back when they are nearly opposed), puts the new
// point 2.78 along it (the speed at 0xee0 grows by 1/36 up to 2.78) and moves the owner's kind-0x26 item there. Returns
// 2 when the trail is full (299 points) and 3 when func_000D2220 says so (both run func_000D27A0), 1 within 30 of
// `position`, else 0.
int Object_000D27F0::func_000D36A0(Vector3 *position, int flags)
{
    Vector3 offset;
    func_0014C4C0(&offset, position, &points[count - 1]);
    float length = func_0014C460(&offset, &offset);
    if (0.0f < length) {
        float cosine = func_0014C800(&offset, &direction);
        if (func_0014C7F0(cosine) < 0.999f) {
            Rotation_000D2B90 rotation;
            func_0014C3B0(&rotation.axis, &direction, &offset);
            func_0014C410(&rotation.axis, &rotation.axis);
            int angle = func_0014C7A0(cosine);
            rotation.angle = data_00257CE8->func_000C1450(0, angle & 0xffff, 0x222);
            func_001BA9C0();
            func_001BAC70(&rotation);
            func_001BAC00(&direction, &direction);
            func_001BAA50();
        } else if (cosine < 0.0f) {
            func_0014CD50(&direction, &direction);
        }
    }
    points[count] = points[count - 1];
    speed += 0.027777778f;
    if (speed > 2.7777777f) {
        speed = 2.7777777f;
    }
    func_0014C730(&points[count], &direction, 2.7777777f);
    if (owner->func_000C5B70(handle)) {
        owner->func_000C5B40(handle, &points[count]);
    } else {
        handle = owner->func_000C5B10(0x26, &points[count]);
    }
    if (++count >= 299) {
        count = 299;
        func_000D27A0();
        return 2;
    }
    if (func_000D2220()) {
        func_000D27A0();
        return 3;
    }
    if (length < 30.0f) {
        return 1;
    }
    return 0;
}
