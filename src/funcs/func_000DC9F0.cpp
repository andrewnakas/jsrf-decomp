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

// The event handler func_000DDF50 installs, for the kind func_000C1810(1) names: event 8 gives the count 0, events 0xC,
// 9 and 0x10 1, 5 and 9 less -2 times the clock's value of data_00257CE4, events 0xE, 0xF, 0x11, 0, 0x17, 0x18, 0x19
// and 0x1A the counts 3, 4, 11, 12, 13, 14, 15 and 16; the count goes with the position to func_000C1160, other events
// (or a count of -1) give -1.
int func_000DC9F0(int event, Vector3 *position)
{
    int kind = data_00257CE8->func_000C1810(1);
    int count = -1;
    switch (event) {
    case 8:
        count = 0;
        break;
    case 0xc:
        count = 1 - (int)(data_00257CE4->clock->func_00066950() * -2.0f);
        break;
    case 0xe:
        count = 3;
        break;
    case 0xf:
        count = 4;
        break;
    case 9:
        count = 5 - (int)(data_00257CE4->clock->func_00066950() * -2.0f);
        break;
    case 0x10:
        count = 9 - (int)(data_00257CE4->clock->func_00066950() * -2.0f);
        break;
    case 0x11:
        count = 11;
        break;
    case 0:
        count = 12;
        break;
    case 0x17:
        count = 13;
        break;
    case 0x18:
        count = 14;
        break;
    case 0x19:
        count = 15;
        break;
    case 0x1a:
        count = 16;
        break;
    }
    if (count != -1) {
        return data_00257CE4->func_000C1160(kind, count, position);
    }
    return -1;
}
