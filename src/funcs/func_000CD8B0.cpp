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

// The event handler for the kind func_000C1810(0x13) names: event 8 gives twice the clock's value of
// data_00257CE4, events 0x40..0x49, 0xE, 0xF and 0x11 the counts 2..13 (0x43 and 0x44 both 5); the count goes with
// the position to func_000C1160, other events (or a count of -1) give -1.
int func_000CD8B0(int event, Vector3 *position)
{
    int kind = data_00257CE8->func_000C1810(0x13);
    int count = -1;
    switch (event) {
    case 8:
        count = (int)(data_00257CE4->clock->func_00066950() * 2.0f);
        break;
    case 0x40:
        count = 2;
        break;
    case 0x41:
        count = 3;
        break;
    case 0x42:
        count = 4;
        break;
    case 0x43:
    case 0x44:
        count = 5;
        break;
    case 0xe:
        count = 6;
        break;
    case 0xf:
        count = 7;
        break;
    case 0x45:
        count = 8;
        break;
    case 0x46:
        count = 9;
        break;
    case 0x47:
        count = 10;
        break;
    case 0x48:
        count = 11;
        break;
    case 0x49:
        count = 12;
        break;
    case 0x11:
        count = 13;
        break;
    }
    if (count != -1) {
        return data_00257CE4->func_000C1160(kind, count, position);
    }
    return -1;
}
