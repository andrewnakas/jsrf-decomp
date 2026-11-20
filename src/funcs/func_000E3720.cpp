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

// The event handler func_000E4E10 installs, for the kind func_000C1810(16) names: event 0xC gives three times the
// clock's value of data_00257CE4, event 0x14 the count 8, event 0x11 the count 11, events 0x25 and 0x27 the counts 4
// and 5 of the kind 0x22; the count goes with the position to func_000C1160, other events (or a count of -1) give -1.
int func_000E3720(int event, Vector3 *position)
{
    int kind = data_00257CE8->func_000C1810(16);
    int count = -1;
    switch (event) {
    case 0xc:
        count = (int)(data_00257CE4->clock->func_00066950() * 3.0f);
        break;
    case 0x14:
        count = 8;
        break;
    case 0x11:
        count = 11;
        break;
    case 0x25:
        kind = 0x22;
        count = 4;
        break;
    case 0x27:
        kind = 0x22;
        count = 5;
        break;
    }
    if (count != -1) {
        return data_00257CE4->func_000C1160(kind, count, position);
    }
    return -1;
}
