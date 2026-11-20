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

// The event handler func_000E27F0 installs, for the kind func_000C1810(5) names: events 8, 0x2B, 0x2C, 0xC, 0x2D, 0x11,
// 0x12, 0, 1, 2 and 0x13 give the counts 0, 5, 11, 12, 15, 19, 20, 21, 22, 23 and 24; events 0xA and 0x10 give 6 less
// -2 times and 16 less -3 times the clock's value of data_00257CE4; the count goes with the position to func_000C1160,
// other events (or a count of -1) give -1.
int func_000E2070(int event, Vector3 *position)
{
    int kind = data_00257CE8->func_000C1810(5);
    int count = -1;
    switch (event) {
    case 8:
        count = 0;
        break;
    case 0x2b:
        count = 5;
        break;
    case 0xa:
        count = 6 - (int)(data_00257CE4->clock->func_00066950() * -2.0f);
        break;
    case 0x2c:
        count = 11;
        break;
    case 0xc:
        count = 12;
        break;
    case 0x2d:
        count = 15;
        break;
    case 0x10:
        count = 16 - (int)(data_00257CE4->clock->func_00066950() * -3.0f);
        break;
    case 0x11:
        count = 19;
        break;
    case 0x12:
        count = 20;
        break;
    case 0:
        count = 21;
        break;
    case 1:
        count = 22;
        break;
    case 2:
        count = 23;
        break;
    case 0x13:
        count = 24;
        break;
    }
    if (count != -1) {
        return data_00257CE4->func_000C1160(kind, count, position);
    }
    return -1;
}
