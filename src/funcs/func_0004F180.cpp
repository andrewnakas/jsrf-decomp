int func_00025680();
int func_000256A0(unsigned int index, int argument);

struct Object_000667D0 {
    void func_000666F0(int first, int second);
};

extern Object_000667D0 *data_00251F24;

struct Object_0004EF90 {
    char unknown_00[0x44];
    int next;

    void func_0004F180();
};

// A state handler (table 0x1FA008, slot 8): when func_00025680 says no and handler 0x19 answers 2, goes to state 9.
void Object_0004EF90::func_0004F180()
{
    if (func_00025680() == 0 && func_000256A0(0x19, 2)) {
        next = 9;
        data_00251F24->func_000666F0(0, 1);
    }
}
