struct Data_000C2700;

struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

// The object in data_00257CEC: its points at 8 (count at 4).
struct Object_000C3BE0 {
    char unknown_00[4];
    unsigned int count;
    Vector3 points[1];
};

extern Object_000C3BE0 *data_00257CEC;

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
    char unknown_10[0x10];
    int value_20;
    char unknown_24[0xc];
    unsigned int flags;
    unsigned int state;
    char unknown_38[8];
    int value_40;
    float nearest;
    char unknown_48[0x20];
    unsigned int point;
};

// The handlers by state.
extern void (Object_000C2420::*data_00215E50[])();

// Slot 10: finds the point of data_00257CEC nearest the position (func_0014C530), its distance at 0x44 (from
// 1000) and index at 0x68; outside states 5 and 6, copies 0x20 to 0x40; runs the handler of the state at 0x34
// (data_00215E50); clears flag 0x10.
void Object_000C2420::func_000C2480()
{
    nearest = 1000.0f;
    point = 0;
    for (unsigned int i = 0; i < data_00257CEC->count; i++) {
        float distance = func_0014C530(&position, &data_00257CEC->points[i]);
        if (distance < nearest) {
            nearest = distance;
            point = i;
        }
    }
    if (state != 6 && state != 5) {
        value_40 = value_20;
    }
    (this->*data_00215E50[state])();
    flags &= ~0x10;
}
