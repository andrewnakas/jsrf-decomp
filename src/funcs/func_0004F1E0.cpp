struct Game {
    void func_000127C0(int index, int value);
    int func_000127E0(int index);
    void *func_000128C0(int index);
};

extern Game *data_0022FCE0;

struct Object_0004EF90 {
    char unknown_00[0x44];
    int next;
    char unknown_48[0x0c];
    int unknown_54;
    int unknown_58;
    int unknown_5c;
    unsigned int counts[4];
    void *made[4];

    void func_0004F1E0();
};

// A state handler (table 0x1FA008, slot 10): takes the four counts from game values 13 to 16 (plus one), clears the
// blocks made for them and three words, and goes to state 11.
void Object_0004EF90::func_0004F1E0()
{
    counts[0] = data_0022FCE0->func_000127E0(0xd) + 1;
    counts[1] = data_0022FCE0->func_000127E0(0xe) + 1;
    counts[2] = data_0022FCE0->func_000127E0(0xf) + 1;
    counts[3] = data_0022FCE0->func_000127E0(0x10) + 1;
    made[0] = 0;
    made[1] = 0;
    made[2] = 0;
    made[3] = 0;
    unknown_54 = 0;
    unknown_58 = 0;
    unknown_5c = 0;
    next = 11;
}
