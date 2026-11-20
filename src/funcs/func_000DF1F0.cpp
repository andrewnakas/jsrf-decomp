struct Node {
    virtual ~Node();
};

struct Object_000DF2E0 : Node {
    char unknown_004[0x40];
    int done;
    char unknown_048[0x14];
    float timer;

    void func_000DF1F0();
};

// A handler of the member-function table that holds func_000DF2E0: counts the timer at 0x5c up by 1/30;
// at 1 it stops there and the field at 0x44 is set.
void Object_000DF2E0::func_000DF1F0()
{
    timer += 0.033333335f;
    if (timer >= 1.0f) {
        timer = 1.0f;
        done = 1;
    }
}
