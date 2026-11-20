// Three 0x1c-byte records; the value at +0x18 of each is set.
struct Record_00044BA0 {
    char unknown_00[0x18];
    int value;
};

struct Object_00044AE0 {
    char unknown_00[0x48];
    int state;
    char unknown_4c[0x28];
    int shown;
    char unknown_78[0x64];
    Record_00044BA0 *records;
    int timer;

    void func_00044BA0();
};

// 6 less `time`, kept at 0 or above; 6 while `time` is below 0.
inline int fade_00044BA0(int time)
{
    int value = 6;
    if (time >= 0) {
        value -= time;
        if (value < 0) {
            value = 0;
        }
    }
    return value;
}

// Counts the timer at +0xe0 down; when it runs out, states 3 and 4 become 1 and 2. While +0x74 is set, the three
// records follow the timer 0, 10 and 20 steps apart.
void Object_00044AE0::func_00044BA0()
{
    if (timer == 0) {
        return;
    }
    timer--;
    if (timer <= 0) {
        if (state == 3) {
            state = 1;
        }
        if (state == 4) {
            state = 2;
        }
    }
    if (shown == 0) {
        return;
    }
    records[0].value = fade_00044BA0(timer);
    records[1].value = fade_00044BA0(timer - 10);
    records[2].value = fade_00044BA0(timer - 20);
}
