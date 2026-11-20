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

// The event handler func_000E9150 installs: events 0x1B-0x22 give the counts 0, 1, 2, 3, 4, 5, 6, 7 of the kind
// func_000C1810(2) names, passed with the position to func_000C1160; other events give -1.
int func_000E7EC0(int event, Vector3 *position)
{
    int kind = data_00257CE8->func_000C1810(2);
    int count;
    switch (event) {
    case 0x1b:
        count = 0;
        break;
    case 0x1c:
        count = 1;
        break;
    case 0x1d:
        count = 2;
        break;
    case 0x1e:
        count = 3;
        break;
    case 0x1f:
        count = 4;
        break;
    case 0x20:
        count = 5;
        break;
    case 0x21:
        count = 6;
        break;
    case 0x22:
        count = 7;
        break;
    default:
        return -1;
    }
    return data_00257CE4->func_000C1160(kind, count, position);
}
