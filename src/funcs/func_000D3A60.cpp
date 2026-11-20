struct Vector3 {
    float x;
    float y;
    float z;
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);

    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x20];
    float value_70;
    char unknown_74[0x30];
    unsigned int flags;
};

// The class (constructor func_000D27F0) whose slot 0 runs the member-function table at 0x2169e0.
struct Object_000D27F0 {
    char unknown_000[0x4];
    Object_000C5B50 *owner;
    int state;
    char unknown_00c[4];
    int timer;
    char unknown_014[0x70];
    unsigned int round;
    char unknown_088[4];
    int value_8c;

    void func_000D34B0();
    void func_000D3A60();
};

// Entry 1 of the member-function table at 0x2169e0: after 60 frames, the first round (0x84 at 0) goes to state 2 as
// round 1; later rounds, while the owner's 0x70 is below 400, go to state 0xc with 0x168 at 0x8c and the next round
// (wrapping after 3), giving the owner the flag 0x10000000 and message 8 at its position once; otherwise after 600
// frames the round goes back to 0. Then func_000D34B0.
void Object_000D27F0::func_000D3A60()
{
    int frames = ++timer;
    if (frames >= 60) {
        if (round != 0) {
            if (owner->value_70 < 400.0f) {
                state = 0xc;
                value_8c = 0x168;
                if (round < 3) {
                    round++;
                } else {
                    round = 0;
                }
                timer = 0;
                if (!(owner->flags & 0x10000000)) {
                    owner->flags |= 0x10000000;
                    owner->func_000C5B10(8, &owner->position);
                }
            } else if (frames >= 600) {
                round = 0;
            }
        } else {
            state = 2;
            round = 1;
            timer = 0;
        }
    }
    func_000D34B0();
}
