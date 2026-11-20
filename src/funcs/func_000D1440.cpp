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

// The event handler func_000D39C0 installs, for the kind func_000C1810(11) names: event 8 gives twice the clock's value
// of data_00257CE4, event 0xA 2 less -2 times it, events 0xC, 0xE and 0xF the counts 4, 5 and 6, event 0x10 9 less -2
// times the clock, events 0x11, 0x26 and 0x27 the counts 11, 12 and 13; the count goes with the position to
// func_000C1160, other events (or a count of -1) give -1.
int func_000D1440(int event, Vector3 *position)
{
    int kind = data_00257CE8->func_000C1810(11);
    int count = -1;
    switch (event) {
    case 8:
        count = (int)(data_00257CE4->clock->func_00066950() * 2.0f);
        break;
    case 0xa:
        count = 2 - (int)(data_00257CE4->clock->func_00066950() * -2.0f);
        break;
    case 0xc:
        count = 4;
        break;
    case 0xe:
        count = 5;
        break;
    case 0xf:
        count = 6;
        break;
    case 0x10:
        count = 9 - (int)(data_00257CE4->clock->func_00066950() * -2.0f);
        break;
    case 0x11:
        count = 11;
        break;
    case 0x26:
        count = 12;
        break;
    case 0x27:
        count = 13;
        break;
    }
    if (count != -1) {
        return data_00257CE4->func_000C1160(kind, count, position);
    }
    return -1;
}
