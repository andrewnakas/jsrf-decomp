struct Data_000C2700;

struct Vector3 {
    float x;
    float y;
    float z;
};

// One row of data_00215E90 (8 bytes): the sound at 2.
struct Row_000C3140 {
    short unknown_00;
    short sound;
    int unknown_04;
};

extern Row_000C3140 data_00215E90[];

int func_00119540(int group, int index, void *position);

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
    char unknown_10[0x24];
    unsigned int state;
    char unknown_38[0x28];
    int index;
    int kind;
    char unknown_68[0xc];
    float value_74;
    char unknown_78[8];
    float time;

    void func_000C2730();
};

// Slot 5: time 0 and state 6; the field at 0x74 by the kind at 0x64 (1: 27, 4: 34, 0 and 2: 18); plays sound 50 of the
// row at 0x60 of data_00215E90 at the position (func_00119540), then func_000C2730.
void Object_000C2420::func_000C3140()
{
    time = 0.0f;
    state = 6;
    if (kind == 0) {
        value_74 = 18.0f;
    } else if (kind == 1) {
        value_74 = 27.0f;
    } else if (kind == 4) {
        value_74 = 34.0f;
    } else if (kind == 2) {
        value_74 = 18.0f;
    }
    func_00119540(50, data_00215E90[index].sound, &position);
    func_000C2730();
}
