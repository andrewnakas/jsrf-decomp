struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

// The class whose table is at 0x1CE6E0 (built inline by func_000DAB10; deleting destructor func_000DAC00).
struct Object_000DAAB0 {
    virtual void func_000DAA70();
    virtual void func_000DAAB0();
    virtual void func_000DAAE0();
    virtual void func_000DAB00();
    virtual ~Object_000DAAB0();
    virtual void func_000DAA40();

    const Vector3 *point;
    int state;
    float distance;
};

extern void (Object_000DAAB0::*data_002174BC[])();

// Slot 5: the distance from its point to the position of the object in data_00257CE4 (func_0014C530) into 0xc,
// then the handler of the state from the table at 0x2174bc.
void Object_000DAAB0::func_000DAA40()
{
    distance = func_0014C530(point, &data_00257CE4->position);
    (this->*data_002174BC[state])();
}
