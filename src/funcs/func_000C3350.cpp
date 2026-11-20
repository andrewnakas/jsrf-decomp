struct Data_000C2700;

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

// The motions at 0xc8 of data_00257CEC.
struct Motions_000C3350 {
    char unknown_00[8];
    Motion_0005F060 *third;
};

struct Object_000C3BE0 {
    char unknown_00[0xc8];
    Motions_000C3350 *motions;
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

    char unknown_04[0x2c];
    unsigned int flags;
    unsigned int state;
    char unknown_38[0x44];
    Motion_0005F060 *motion;
    float time;
};

// Slot 7: without flag 1 at 0x30, state 0; otherwise advances the time at 0x80 by 0.5 up to the motion's last
// frame, then starts the motion at 8 of 0xc8 of data_00257CEC from 0 in state 8.
void Object_000C2420::func_000C3350()
{
    if (!(flags & 1)) {
        state = 0;
        return;
    }
    if (motion->frames - 1.0f > time) {
        time += 0.5f;
        return;
    }
    motion = data_00257CEC->motions->third;
    time = 0.0f;
    state = 8;
}
