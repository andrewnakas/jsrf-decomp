struct Target_000C0A20 {
    char unknown_00[0x98];
    int timer;
    char unknown_9c[8];
    unsigned int flags;
};

struct Message_000C0A20 {
    char unknown_00[0xc];
    int value;
};

struct Object_000C0A20 {
    void func_000C0A20(Target_000C0A20 *target, Message_000C0A20 *message);
};

// Sets the timer at 0x98 of the target from the message; a value of 0 or less clears it and sets the
// target's flags 0x2020. Does not read `this` (`ret 8`).
void Object_000C0A20::func_000C0A20(Target_000C0A20 *target, Message_000C0A20 *message)
{
    target->timer = message->value;
    if (target->timer <= 0) {
        target->timer = 0;
        target->flags |= 0x2020;
    }
}
