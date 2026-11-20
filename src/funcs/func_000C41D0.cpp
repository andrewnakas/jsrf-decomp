struct Owner_000C41D0 {
    char unknown_00[0xd0];
    int value;
};

// The state machine whose table is at 0x1CDDCC (constructor func_000C44D0): this is entry 0 of the member-function
// table at 0x21615C that its slot 0 (func_000C41B0) runs.
struct Object_000C41B0 {
    int unknown_00;
    Owner_000C41D0 *owner;
    int state;
    int unknown_0c;
    int value;

    void func_000C41D0();
};

void Object_000C41B0::func_000C41D0()
{
    state = 1;
    value = owner->value;
}
