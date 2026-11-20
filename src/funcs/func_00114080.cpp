struct Object_00114080 {
    char unknown_000[0x180];
    int active;
    int ticks;
    int count;
    int index;
    int enabled;

    void func_00114080();
};

// While both flags are set, steps the index every 6 ticks through count values.
void Object_00114080::func_00114080()
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
