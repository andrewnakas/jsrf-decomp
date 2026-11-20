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

// The event handler func_000E7D70 installs: event 3 gives the count 5, event 0x10 four times the clock's value of
// data_00257CE4, event 0x2A the count 4, of the kind func_000C1810(15) names, passed with the position to
// func_000C1160; other events (or a count of -1) give -1.
int func_000E7670(int event, Vector3 *position)
{
    int kind = data_00257CE8->func_000C1810(15);
    int count = -1;
    switch (event) {
    case 0x2a:
        count = 4;
        break;
    case 0x10:
        count = (int)(data_00257CE4->clock->func_00066950() * 4.0f);
        break;
    case 3:
        count = 5;
        break;
    }
    if (count != -1) {
        return data_00257CE4->func_000C1160(kind, count, position);
    }
    return -1;
}
