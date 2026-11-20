struct Data_000C2700;

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00066980 {
    unsigned int value;

    unsigned int func_00066930();
};

// One of the four entries at 0x48 of data_00257CEC: an angle at 4.
struct Entry_000C36F0 {
    int unknown_00;
    int angle;
    int unknown_08;
};

// The object at data_00257CEC: four points at 0x8 with a range each at 0x38, an entry each at 0x48 and its random
// value at 0xbc.
struct Object_000C3BE0 {
    char unknown_00[8];
    Vector3 points[4];
    float ranges[4];
    Entry_000C36F0 entries[4];
    char unknown_78[0x44];
    Object_00066980 random;
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

    char unknown_04[0x24];
    float speed;
    char unknown_2c[8];
    unsigned int state;
    char unknown_38[0xc];
    float distance;
    char unknown_48[0x1c];
    unsigned int kind;
    int point;
    char unknown_6c[4];
    unsigned int last;

    void func_000C2B70(int angle);
    void func_000C3410();
};

// Slot 11: in state 6, func_000C3410. Otherwise, past states 0 and 1 and when slot 16 reports true, the state
// becomes 5 and a new kind is drawn (a random 0..2, plus 2 under the distance 18) other than the last one at 0x70;
// func_000C2B70 takes the angle of the point's entry, and the speed is the point's range times 3.5 (kind 3), 3.2
// (kind 4) or 1.1, kept between 25/108 and 25/36.
void Object_000C2420::func_000C36F0()
{
    unsigned int base = 0;
    if (state == 6) {
        func_000C3410();
        return;
    }
    if (state > 1 && func_000C2AA0()) {
        state = 5;
        if (distance < 18.0f) {
            base = 2;
        }
        while (kind == last) {
            kind = data_00257CEC->random.func_00066930() % 3 + base;
        }
        last = kind;
        func_000C2B70(data_00257CEC->entries[point].angle);
        if (kind == 3) {
            speed = data_00257CEC->ranges[point] * 3.5f;
        } else if (kind == 4) {
            speed = data_00257CEC->ranges[point] * 3.2f;
        } else {
            speed = data_00257CEC->ranges[point] * 1.1f;
        }
        if (speed < 0.23148148f) {
            speed = 0.23148148f;
        }
        if (speed > 0.69444442f) {
            speed = 0.69444442f;
        }
    }
}
