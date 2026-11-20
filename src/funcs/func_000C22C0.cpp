/* sym: ?func_000C2AA0@Object_000C20A0@@UAEHXZ = 0x000C22C0 */
struct Data_000C2700;

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Direction_000C3BE0 {
    Vector3 vector;
    float unknown_0c;
};

struct Object_00066980 {
    unsigned int value;

    float func_00066950();
};

// The object at data_00257CEC: four points at 0x8 with a range each at 0x38, four directions at 0x78 and its random
// value at 0xbc.
struct Object_000C3BE0 {
    char unknown_00[8];
    Vector3 points[4];
    float ranges[4];
    char unknown_48[0x30];
    Direction_000C3BE0 directions[4];
    char unknown_b8[4];
    Object_00066980 random;
};

extern Object_000C3BE0 *data_00257CEC;

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470); slot 9 is the
// destructor.
struct Object_000C2420 {
    Object_000C2420(Data_000C2700 *data);
    virtual void func_000C2630();
    virtual void func_000C2700();
    virtual void func_000C3800();
    virtual void func_000C30C0();
    virtual void func_000C3100();
    virtual void func_000C3140();
    virtual void func_000C31B0();
    virtual void func_000C3350();
    virtual void func_000C33C0();
    virtual ~Object_000C2420();
    virtual void func_000C2480();
    virtual void func_000C36F0();
    virtual void func_000C2FE0();
    virtual void func_000C2500();
    virtual void func_000C2560();
    virtual void func_000C25D0();
    virtual int func_000C2AA0();

    Vector3 position;
    char unknown_10[0x34];
    float distance;
    char unknown_48[0x14];
    float value_5c;
    char unknown_60[8];
    int point;
};

// The class whose table is at 0x1CDC60 (constructor func_000C2010, destructor func_000C2030): overrides slots 5,
// 6, 11 and 16 of its base, and slots 14 and 15 with empty functions.
struct Object_000C20A0 : Object_000C2420 {
    Object_000C20A0(Data_000C2700 *data);
    virtual void func_000C3140();
    virtual void func_000C31B0();
    virtual ~Object_000C20A0();
    virtual void func_000C36F0();
    virtual void func_000C2560();
    virtual void func_000C25D0();
    virtual int func_000C2AA0();
};

// Overrides slot 16: like the base, but the reach is 30 ranges times a random value plus 0.3, and the way to the point
// is made unit length (func_0014C410) first. With a range for the point, returns 1 at once when the distance at 0x44
// is at most 12; otherwise 0 when the distance is beyond the reach or the way is more than 30 degrees off the point's
// direction (dot below 0.866), else 0x5c takes the y of their cross product and it returns 1.
int Object_000C20A0::func_000C2AA0()
{
    float range = data_00257CEC->ranges[point];
    if (range == 0.0f) {
        return 0;
    }
    if (distance > 12.0f) {
        Direction_000C3BE0 way;
        func_0014C4C0(&way.vector, &position, &data_00257CEC->points[point]);
        func_0014C410(&way.vector, &way.vector);
        if (distance > (data_00257CEC->random.func_00066950() + 0.3f) * range * 30.0) {
            return 0;
        }
        if (func_0014C800(&way.vector, &data_00257CEC->directions[point].vector) < 0.866f) {
            return 0;
        }
        func_0014C3B0(&way.vector, &way.vector, &data_00257CEC->directions[point].vector);
        value_5c = way.vector.y;
    }
    return 1;
}
