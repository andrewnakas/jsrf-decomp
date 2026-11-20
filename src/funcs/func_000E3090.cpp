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

// The event handler func_000E32C0 installs: events 0, 1 and 2 give the counts 0, 1 and 2 of the kind 0x22 with the
// position to func_000C1160 (the kind func_000C1810(0x1c) names is fetched but not used); other events give -1.
int func_000E3090(int event, Vector3 *position)
{
    int kind = data_00257CE8->func_000C1810(0x1c);
    int count = -1;
    switch (event) {
    case 0:
        count = 0;
        break;
    case 1:
        count = 1;
        break;
    case 2:
        count = 2;
        break;
    }
    if (count != -1) {
        return data_00257CE4->func_000C1160(0x22, count, position);
    }
    return -1;
}
