struct Vector3;

struct Object_000C1810 {
    int func_000C1810(int index);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1810.
struct Object_00157F10 : Object_000C1810 {
};

extern Object_00157F10 *data_00257CE8;

struct Object_00066980 {
    float func_00066950();
};

struct Object_000C1270 {
    char unknown_00[0x78];
    Object_00066980 *clock;

    int func_000C1160(int kind, int count, Vector3 *position);
};

extern Object_000C1270 *data_00257CE4;

// The event handler func_000E1E40 installs, for the kind func_000C1810(0) names: events 0, 1 and 2 give the counts
// 0, 1 and 2 of the kind 0x22; event 8 three times the clock's value of data_00257CE4, event 0xC the count 14, event
// 0x10 20 less -5 times the clock, event 0x11 25 less -3 times it; the count goes with the position to
// func_000C1160, other events (or a count of -1) give -1.
int func_000E1B00(int event, Vector3 *position)
{
    int kind = data_00257CE8->func_000C1810(0);
    int count = -1;
    switch (event) {
    case 0:
        kind = 0x22;
        count = 0;
        break;
    case 1:
        kind = 0x22;
        count = 1;
        break;
    case 2:
        kind = 0x22;
        count = 2;
        break;
    case 8:
        count = (int)(data_00257CE4->clock->func_00066950() * 3.0f);
        break;
    case 0xc:
        count = 14;
        break;
    case 0x10:
        count = 20 - (int)(data_00257CE4->clock->func_00066950() * -5.0f);
        break;
    case 0x11:
        count = 25 - (int)(data_00257CE4->clock->func_00066950() * -3.0f);
        break;
    }
    if (count != -1) {
        return data_00257CE4->func_000C1160(kind, count, position);
    }
    return -1;
}
