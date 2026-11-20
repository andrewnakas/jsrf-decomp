struct Timer_001325B0 {
    bool active;
    char unknown_01[0x17];
    unsigned short delay;
    unsigned short count;
};

struct Object_00120420 {
    char unknown_000[0xbe0];
    Timer_001325B0 timers[16];

    void func_00130DD0(int index);
    void func_001325B0();
};

// Steps the 16 timers at +0xbe0: an active timer counts its delay down, then fires func_00130DD0 once per count,
// then stops.
void Object_00120420::func_001325B0()
{
    for (int i = 0; i < 16; i++) {
        if (timers[i].active) {
            if (timers[i].delay == 0) {
                if (timers[i].count == 0) {
                    timers[i].active = false;
                } else {
                    timers[i].count--;
                    func_00130DD0(i);
                }
            } else {
                timers[i].delay--;
            }
        }
    }
}
