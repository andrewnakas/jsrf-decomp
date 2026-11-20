struct Vector3 {
    float x;
    float y;
    float z;
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);
    void func_000C5B40(int id, void *position);
    void func_000C5B50(int *handle);
    int func_000C5B70(int handle);
};

// The class of func_000EDC30; its handlers sit in the table at 0x21A900.
struct Object_000EDC30 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    char unknown_008[0x374];
    Vector3 point;
    char unknown_388[0x38];
    int handle_3c0;
    int handle_3c4;

    void func_000EF7C0(int shown);
};

// Shown: moves the owner's two marks (handles 0x3c0 and 0x3c4) to the point at 0x37c, making them (messages 4 and
// 5) when the owner does not know them (func_000C5B70); hidden: releases the ones it knows (func_000C5B50). Called
// by func_000F0310.
void Object_000EDC30::func_000EF7C0(int shown)
{
    if (shown) {
        if (owner->func_000C5B70(handle_3c0)) {
            owner->func_000C5B40(handle_3c0, &point);
        } else {
            handle_3c0 = owner->func_000C5B10(4, &point);
        }
        if (owner->func_000C5B70(handle_3c4)) {
            owner->func_000C5B40(handle_3c4, &point);
        } else {
            handle_3c4 = owner->func_000C5B10(5, &point);
        }
    } else {
        if (owner->func_000C5B70(handle_3c0)) {
            owner->func_000C5B50(&handle_3c0);
        }
        if (owner->func_000C5B70(handle_3c4)) {
            owner->func_000C5B50(&handle_3c4);
        }
    }
}
