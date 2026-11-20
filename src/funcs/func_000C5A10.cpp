struct Vector3 {
    float x;
    float y;
    float z;
};

// A box of the table at data_00257CE0 (0x2c bytes): its centre at 0x18.
struct Box_000CBE60 {
    char unknown_00[0x18];
    Vector3 center;
    char unknown_24[8];
};

struct Boxes_000CBE60 {
    int count;
    Box_000CBE60 *boxes;
};

// Where an object is: its box, the box's centre, a value and the next entry.
struct Entry_000C5EA0 {
    int key;
    Vector3 *center;
    int unknown_08;
    Entry_000C5EA0 *next;
};

// The table of boxes at data_00257CE0.
struct Object_000BFF60 {
    Boxes_000CBE60 *data;

    int func_000BFF80(Vector3 *position);
    void func_000C02D0(Entry_000C5EA0 *entry, int from, int to);
};

extern Object_000BFF60 *data_00257CE0;

// The object a behaviour serves.
struct Object_000C5B50 {
    char unknown_00[0x64];
    int area;
    char unknown_68[0x40];
    Vector3 *target;
    char unknown_ac[0xc];
    int targetArea;
    Entry_000C5EA0 *entry;

    int func_000C5A10();
};

// Looks up the box of the target at 0xa8 (func_000BFF80) and keeps it at 0xb8. None: the entry at 0xbc gets -1 and
// the answer is 2. The object's own box (0x64): the entry is set to it (its centre, the next entry -1), answer 0.
// Another box: unless it is the one already kept and the entry holds a box, func_000C02D0 routes the entry from
// the object's box to it; answer 1.
int Object_000C5B50::func_000C5A10()
{
    int index = data_00257CE0->func_000BFF80(target);
    if (index < 0) {
        entry->key = -1;
        targetArea = index;
        return 2;
    }
    if (index == area) {
        entry->key = index;
        entry->unknown_08 = 0;
        entry->center = &data_00257CE0->data->boxes[index].center;
        entry->next->key = -1;
        targetArea = index;
        return 0;
    }
    if (targetArea != index || entry->key < 0) {
        data_00257CE0->func_000C02D0(entry, area, index);
    }
    targetArea = index;
    return 1;
}
