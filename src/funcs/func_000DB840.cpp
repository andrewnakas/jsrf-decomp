struct Vector3;

struct Object_000C1810 {
    int func_000C1810(int index);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1810.
struct Object_00157F10 : Object_000C1810 {
};

extern Object_00157F10 *data_00257CE8;

struct Object_000C1270 {
    int func_000C1160(int kind, int count, Vector3 *position);
};

extern Object_000C1270 *data_00257CE4;

// The event handler func_000DC3D0 installs: events 0x24, 0x23, 0x25, 0x27 and 0x26 give the counts 0, 1, 2, 4 and 3 of
// the kind func_000C1810(7) names, event 3 the count 3 of the kind 0x22; the count goes with the position to
// func_000C1160, other events give -1.
int func_000DB840(int event, Vector3 *position)
{
    int kind = data_00257CE8->func_000C1810(7);
    int count;
    switch (event) {
    case 0x24:
        count = 0;
        break;
    case 0x23:
        count = 1;
        break;
    case 0x25:
        count = 2;
        break;
    case 0x27:
        count = 4;
        break;
    case 3:
        kind = 0x22;
    case 0x26:
        count = 3;
        break;
    default:
        return -1;
    }
    return data_00257CE4->func_000C1160(kind, count, position);
}
