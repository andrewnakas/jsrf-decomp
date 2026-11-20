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

// The event handler func_000D9390 installs, for the kind func_000C1810(10) names: event 8 gives the count 0 (events 0,
// 1 and 2 the counts 0, 1 and 2 of the kind 0x22); events 0xA, 0xC, 0xE, 9 and 0x10 give 1, 3, 5, 8 and 10 less -2
// times the clock's value of data_00257CE4, events 0xF, 0x11, 0x19 and 0x1A the counts 7, 12, 13 and 14; the count goes
// with the position to func_000C1160, other events (or a count of -1) give -1.
int func_000D7CF0(int event, Vector3 *position)
{
    int kind = data_00257CE8->func_000C1810(10);
    int count = -1;
    switch (event) {
    case 0:
        kind = 0x22;
    case 8:
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
    case 0xa:
        count = 1 - (int)(data_00257CE4->clock->func_00066950() * -2.0f);
        break;
    case 0xc:
        count = 3 - (int)(data_00257CE4->clock->func_00066950() * -2.0f);
        break;
    case 0xe:
        count = 5 - (int)(data_00257CE4->clock->func_00066950() * -2.0f);
        break;
    case 0xf:
        count = 7;
        break;
    case 9:
        count = 8 - (int)(data_00257CE4->clock->func_00066950() * -2.0f);
        break;
    case 0x10:
        count = 10 - (int)(data_00257CE4->clock->func_00066950() * -2.0f);
        break;
    case 0x11:
        count = 12;
        break;
    case 0x19:
        count = 13;
        break;
    case 0x1a:
        count = 14;
        break;
    }
    if (count != -1) {
        return data_00257CE4->func_000C1160(kind, count, position);
    }
    return -1;
}
