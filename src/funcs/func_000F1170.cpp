/* sym: ?func_00011C80_1@Object_000F1820@@UAEXH@Z = 0x000F1170 */
struct Motion_0005F060;

// The owner: its flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0xa4];
    unsigned int flags;
};

// The models at 0x78, 0x7c and 0x80: slot 5 poses them; four weights at 0x74 and four keys at 0x88.
struct Model_000F1170 {
    virtual void func_00();
    virtual void func_04();
    virtual void func_08();
    virtual void func_0C();
    virtual void func_10();
    virtual void func_14(Motion_0005F060 *motion, float time);

    char unknown_04[0x70];
    float weights[4];
    char unknown_84[4];
    int keys[4];
};

// The base of the owner's behaviours (table 0x1CE304): slot 0 is pure, slots 2 and 3 take an argument, slot 4 is
// the destructor.
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
};

// The state machine whose table is at 0x1CF02C (constructor func_000F1820), made by func_000F1FC0.
struct Object_000F1820 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C80_1(int argument);

    Object_000C5B50 *owner;
    char unknown_008[0x70];
    Model_000F1170 *part;
    Model_000F1170 *first;
    Model_000F1170 *second;
    Motion_0005F060 **motions;
    char unknown_088[0x20];
    Motion_0005F060 *motion;
    char unknown_0ac[0xd0];
    float values[4];
    int seconds[4];
};

// Slot 3: on message 0, gives the model at 0x7c (or 0x80 once the owner has flag 0x2000) twice the four values at
// 0x17c and the four keys at 0x18c, and draws the part at 0x78 with the motion at 0xa8 and that model (or the part
// and the model at 0x80 with motions 20 and 21).
void Object_000F1820::func_00011C80_1(int argument)
{
    if (argument) {
        return;
    }
    if (!(owner->flags & 0x2000)) {
        first->weights[0] = values[0] * 2.0f;
        first->keys[0] = seconds[0];
        first->weights[1] = values[1] * 2.0f;
        first->keys[1] = seconds[1];
        first->weights[2] = values[2] * 2.0f;
        first->keys[2] = seconds[2];
        first->weights[3] = values[3] * 2.0f;
        first->keys[3] = seconds[3];
        part->func_14(motion, 0.0f);
        first->func_14(0, 0.0f);
    } else {
        second->weights[0] = values[0] * 2.0f;
        second->keys[0] = seconds[0];
        second->weights[1] = values[1] * 2.0f;
        second->keys[1] = seconds[1];
        second->weights[2] = values[2] * 2.0f;
        second->keys[2] = seconds[2];
        second->weights[3] = values[3] * 2.0f;
        second->keys[3] = seconds[3];
        part->func_14(motions[20], 0.0f);
        second->func_14(motions[21], 0.0f);
    }
}
