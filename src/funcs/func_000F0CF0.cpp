struct Vector3;

struct Object_000C1810 {
    int func_000C1810(int index);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1810.
struct Object_00157F10 : Object_000C1810 {
};

extern Object_00157F10 *data_00257CE8;

// The object at data_00257CE4.
struct Object_000C1270 {
    int func_000C1160(int kind, int count, Vector3 *position);
};

extern Object_000C1270 *data_00257CE4;

// The event handler func_000F1FC0 gives its object (at 0xe8): event 3 passes kind 0x22 and 3, events 0x37 to 0x3f
// pass func_000C1810(0xd) and 0 to 8, with the position, to func_000C1160 of data_00257CE4; other events give -1.
int func_000F0CF0(int event, Vector3 *position)
{
    int kind = data_00257CE8->func_000C1810(0xd);
    int count;
    switch (event) {
    case 0x37:
        count = 0;
        break;
    case 0x38:
        count = 1;
        break;
    case 0x39:
        count = 2;
        break;
    case 0x3a:
        count = 3;
        break;
    case 0x3b:
        count = 4;
        break;
    case 0x3c:
        count = 5;
        break;
    case 0x3d:
        count = 6;
        break;
    case 0x3e:
        count = 7;
        break;
    case 0x3f:
        count = 8;
        break;
    case 3:
        kind = 0x22;
        count = 3;
        break;
    default:
        return -1;
    }
    return data_00257CE4->func_000C1160(kind, count, position);
}
