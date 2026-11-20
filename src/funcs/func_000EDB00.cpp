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

// The event handler func_000EF890 installs, for the kind func_000C1810(8) names: events 0, 0x25 and 0x26 give the
// counts 0, 1 and 2, event 0x11 6 less -3 times the clock's value of data_00257CE4, events 0x27, 0x28 and 0x29 the
// counts 3, 4 and 5 (events 3, 4 and 5 the same counts of the kind 0x22); the count goes with the position to
// func_000C1160, other events (or a count of -1) give -1.
int func_000EDB00(int event, Vector3 *position)
{
    int kind = data_00257CE8->func_000C1810(8);
    int count = -1;
    switch (event) {
    case 0:
        count = 0;
        break;
    case 0x25:
        count = 1;
        break;
    case 0x26:
        count = 2;
        break;
    case 0x11:
        count = 6 - (int)(data_00257CE4->clock->func_00066950() * -3.0f);
        break;
    case 3:
        kind = 0x22;
    case 0x27:
        count = 3;
        break;
    case 4:
        kind = 0x22;
    case 0x28:
        count = 4;
        break;
    case 5:
        kind = 0x22;
    case 0x29:
        count = 5;
        break;
    }
    if (count != -1) {
        return data_00257CE4->func_000C1160(kind, count, position);
    }
    return -1;
}
