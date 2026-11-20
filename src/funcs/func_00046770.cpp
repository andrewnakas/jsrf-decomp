struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
int func_0014C7D0(float first, float second);
float func_0014C7F0(float value);

// A vector kept in a 16-byte slot.
struct Vector4_00046770 {
    Vector3 v;
    float w;
};

struct Light_00046920 {
    char unknown_00[0x20];
    Vector3 direction;
};

// The context at 0x251D7C: two vectors at +0x578 and +0x588.
struct Context_00251D7C {
    virtual ~Context_00251D7C();

    char unknown_004[0x574];
    Vector3 first;
    char unknown_584[4];
    Vector3 second;
};

extern Context_00251D7C *data_00251D7C;
extern Vector3 data_001F9644;
extern Vector3 data_001F9654;

// The light stack at 0x1F93C8: the current light at +0x274.
struct Object_00046670 {
    char unknown_000[0x274];
    Light_00046920 *current;

    void func_00046770();
};

// Turns the two vectors at 0x1F9644 and 0x1F9654 by the current light's direction (+0x20) into +0x578 and +0x588
// of 0x251D7C: the turns about Y, X and Z that bring the direction round (each angle from func_0014C7D0, or a
// quarter turn when the divisor is 0) are found with the matrix stack and then applied.
void Object_00046670::func_00046770()
{
    Vector3 *direction = &current->direction;
    Vector4_00046770 turned;
    int yaw;
    int pitch;
    int roll;
    func_001BAA00();
    if (direction->y != 0.0f)
        yaw = -func_0014C7D0(direction->x, direction->y);
    else if (direction->x > 0.0f)
        yaw = -0x4000;
    else if (direction->x < 0.0f)
        yaw = 0x4000;
    else
        yaw = 0;
    func_001BB380(-yaw);
    func_001BAC00(&turned.v, direction);
    if (turned.v.z != 0.0f)
        pitch = func_0014C7D0(turned.v.x, turned.v.z);
    else if (turned.v.x > 0.0f)
        pitch = 0x4000;
    else if (turned.v.x < 0.0f)
        pitch = -0x4000;
    else
        pitch = 0;
    func_001BB330(-pitch);
    func_001BAC00(&turned.v, &turned.v);
    if (turned.v.z != 0.0f)
        roll = func_0014C7D0(turned.v.y, func_0014C7F0(turned.v.z));
    else if (turned.v.y > 0.0f)
        roll = 0x4000;
    else if (turned.v.y < 0.0f)
        roll = -0x4000;
    else
        roll = 0;
    func_001BAA50();
    func_001BA9C0();
    func_001BB380(yaw);
    func_001BB330(pitch);
    func_001BB2E0(roll);
    func_001BAC00(&data_00251D7C->first, &data_001F9644);
    func_001BAC00(&data_00251D7C->second, &data_001F9654);
    func_001BAA50();
}
