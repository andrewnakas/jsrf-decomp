struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

struct Data_000C2700 {
    unsigned char type;
    unsigned char mode;
    char unknown_02[2];
    Vector3 *point;
    Vector3 direction;
};

struct Object_00066980 {
    unsigned int value;

    float func_00066950();
};

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int argument);
};

extern Object_00046670 data_001F93C8;

struct Object_000C3BE0 {
    char unknown_00[0xbc];
    Object_00066980 random;
    void **models;
    Motion_0005F060 **motions;
};

extern Object_000C3BE0 *data_00257CEC;

// The pair of floats per mode.
struct Range_00216008 {
    float first;
    float second;
};

extern Range_00216008 data_00216008[];

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470).
struct Object_000C2420 {
    virtual void func_000C2630();

    Vector3 position;
    Vector3 start;
    Vector3 direction;
    float value_28;
    float value_2c;
    unsigned int flags;
    int value_34;
    int value_38;
    int value_3c;
    char unknown_40[0x2c];
    float value_6c;
    char unknown_70[8];
    Data_000C2700 *data;
    Motion_0005F060 *motion;
    float time;
};

// Slot 0: starts at the data's point (position and 0x10), takes its direction (0x1c), the first value of the
// mode's pair (data_00216008), flag 2 and three 1s; the motion of the mode (data_00257CEC's list at 0xc4) at a
// random time (func_00066950); 0x6c from func_000466C0 of data_001F93C8 at the position.
void Object_000C2420::func_000C2630()
{
    position = *data->point;
    start = *data->point;
    direction = data->direction;
    value_28 = data_00216008[data->mode].first;
    value_2c = 0.0f;
    flags = 2;
    value_34 = 1;
    value_38 = 1;
    value_3c = 1;
    motion = data_00257CEC->motions[data->mode];
    time = data_00257CEC->random.func_00066950() * (motion->frames - 1.0f);
    value_6c = data_001F93C8.func_000466C0(&position, -1);
}
