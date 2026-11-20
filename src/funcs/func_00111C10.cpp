struct Object_001118F0 {
    char unknown_000[0x170];
    int active;
    int ticks;
    int count;
    int index;
    int enabled;

    void func_00111C10();
};

// While both flags are set, steps the index every 6 ticks through count values.
void Object_001118F0::func_00111C10()
{
    if (active != 0 && enabled != 0) {
        if (++ticks >= 6) {
            ticks = 0;
            if (++index >= count) {
                index = 0;
            }
        }
    }
}
