struct Owner_000F2AA0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

// The motions of the body.
struct Set_000F2AA0 {
    char unknown_00[8];
    Motion_0005F060 *motions[4];
};

// The body at 0x80 (an Object_000F1820).
struct Body_000F2AA0 {
    char unknown_00[0x84];
    Set_000F2AA0 *set;
    Motion_0005F060 *motions[4];
    char unknown_98[0x1c];
    float ends[4];
};

extern int data_0021B204[];

struct Object_000F2AA0 {
    int unknown_00;
    Owner_000F2AA0 *owner;
    int state;
    int timer;
    char unknown_10[8];
    int busy[4];
    char unknown_28[8];
    unsigned int count;
    int value_34;
    char unknown_38[0x48];
    Body_000F2AA0 *body;

    void func_000F2420(int index, int value);
    void func_000F2970(int index, int value);
    void func_000F3320();
};

// A handler of the table at 0x21B0F0 (entry at 0x21B120): while the timer runs, func_000F2420(+0x34, 0) from 30 on.
// When it runs out, part +0x34 of the body takes its motion from the set (its end frame too when busy is 2) and is
// marked 3; the next part from the list at 0x21B204 (by the count at 0x30) gets func_000F2970(part, 0) and state 9,
// or state 13 at the end of the list (-1).
void Object_000F2AA0::func_000F3320()
{
    if (--timer <= 0) {
        int index = value_34;
        if (busy[index]) {
            body->motions[index] = body->set->motions[index];
            if (busy[index] == 2) {
                body->ends[index] = body->motions[index]->frames - 1.0f;
            }
            busy[index] = 3;
        }
        value_34 = data_0021B204[++count];
        if (value_34 != -1) {
            state = 9;
            func_000F2970(value_34, 0);
        } else {
            state = 0xd;
        }
    } else if (timer >= 0x1e) {
        func_000F2420(value_34, 0);
    }
}
