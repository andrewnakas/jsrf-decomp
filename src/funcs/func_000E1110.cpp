struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// The object in data_00257CE8; it also answers func_000C1450.
struct Object_00157F10 : Object_000C1440 {
};

extern Object_00157F10 *data_00257CE8;

// The object in data_00257CE4.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC50(int *angles, int order);
void func_001BB5E0();
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
int func_0014C7D0(float y, float x);
float func_0014C820(float value);

// The object a behaviour serves (at 0x4).
struct Owner_000E1110 {
    char unknown_00[0x44];
    Vector3 position;
    int angles[3];
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

struct Object_000CD1E0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CD1E0();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0() = 0;
    virtual void func_000D7880() = 0;
    virtual float func_000CD440();
    virtual float func_000CD4F0();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    Owner_000E1110 *owner;
    char unknown_08[0x64];
};

// The class whose table is at 0x1CE804; slot 6 is empty (folded with Node's).
struct Object_000E0440 : Object_000CD1E0 {
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000E0440();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    void func_000E1110();

    char unknown_06c[0x28];
    int pitch;
    int turn;
};

// Aims at the point at 0x7c of data_00257CE4: takes it into the frame of the owner (placed and turned, the point
// (0, -18, -18) in it as the origin, lifted by 1), turns the angle at 0x98 toward its heading by at most 0xb6, and
// the pitch at 0x94 toward it once that angle is past 0x2000, else back to 0.
void Object_000E0440::func_000E1110()
{
    Vector3 origin;
    origin.x = 0.0f;
    origin.y = -18.0f;
    origin.z = -18.0f;
    func_001BA9C0();
    func_001BAAA0(&owner->position.x);
    func_001BAC50(owner->angles, 0);
    func_001BAB20(&origin, &origin);
    Vector3 delta;
    func_0014C4C0(&delta, &data_00257CE4->position, &origin);
    delta.y += 1.0f;
    func_001BB5E0();
    func_001BAC00(&delta, &delta);
    func_001BAA50();
    float length = func_0014C820(delta.x * delta.x + delta.z * delta.z);
    int angle = func_0014C7D0(delta.y, length);
    turn = data_00257CE8->func_000C1450(turn, -angle, 0xb6);
    if (turn > 0x2000) {
        angle = func_0014C7D0(length, delta.y);
        angle = -0x2000 - angle;
        pitch = data_00257CE8->func_000C1450(pitch, -angle, 0xb6);
    } else {
        pitch = data_00257CE8->func_000C1450(pitch, 0, 0xb6);
    }
}
