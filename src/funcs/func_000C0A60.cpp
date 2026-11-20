struct Target_000C0A20 {
    char unknown_00[0x98];
    int timer;
    char unknown_9c[8];
    unsigned int flags;
};

struct Message_000C0A20;

struct Object_000C0A20 {
    void func_000C0A60(Target_000C0A20 *target, Message_000C0A20 *message);
};

// Clears the timer at 0x98 of the target and sets its flags 0x2020. Reads neither `this` nor the message;
// func_000C0B30 calls it like func_000C0A20, with `ecx` loaded and two values pushed (`ret 8`).
void Object_000C0A20::func_000C0A60(Target_000C0A20 *target, Message_000C0A20 *)
{
    target->timer = 0;
    target->flags |= 0x2020;
}
