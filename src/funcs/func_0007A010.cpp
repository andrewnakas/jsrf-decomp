struct Game {
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;

int func_00119540(int group, int index, void *position);

// Built by 0x7A8B0 (state at +0xf0, cursor at +0xd4; +0x98 is the first of the handles 0x25700 gives it).
struct Object_00079B50 {
    char unknown_000[0x98];
    int handle;
    char unknown_09c[0x38];
    int cursor;
    char unknown_0d8[0x18];
    int state;

    void func_0007A010();
};

// Not referenced. In state 3: sets game value 0x19b, 0x19c or (with the handle at +0x98 equal to 1) 0x19d to 1 for
// cursor 0, 2 or 1 and goes to state 5; plays sound 8 / 0 whenever the state was 3.
void Object_00079B50::func_0007A010()
{
    if (state == 3) {
        if (cursor == 0) {
            data_0022FCE0->func_000127C0(0x19b, 1);
            state = 5;
        } else if (cursor == 2) {
            data_0022FCE0->func_000127C0(0x19c, 1);
            state = 5;
        } else if (cursor == 1) {
            if (handle == 1) {
                data_0022FCE0->func_000127C0(0x19d, 1);
            }
            state = 5;
        }
        func_00119540(8, 0, 0);
    }
}
