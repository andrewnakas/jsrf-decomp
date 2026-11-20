// The owner at +4.
struct Owner_000C42A0 {
    char unknown_00[0x6c];
    int value_6c;
    char unknown_70[0x34];
    unsigned int flags;
    char unknown_a8[0x28];
    int value_d0;
    char unknown_d4[0xc];
    int value_e0;
};

struct Source_000C42A0 {
    char unknown_00[0x14];
    int value;
};

// The state machine whose table is at 0x1CDDCC (constructor func_000C44D0); its slot 0 (func_000C41B0) runs entry
// `state` of the member-function table at 0x21615C.
struct Object_000C41B0 {
    int unknown_00;
    Owner_000C42A0 *owner;
    int state;
    int count;
    int value;
    Source_000C42A0 *source;
    int unknown_18;

    void func_000C42A0();
};

// Entry 2 of that table: when the owner's 0xe0 is 0, gives it the source's value at 0x6c, sets its flag 8 and keeps
// its 0xd0; then clears 0x18 and goes to state 3.
void Object_000C41B0::func_000C42A0()
{
    if (owner->value_e0 == 0) {
        owner->value_6c = source->value;
        owner->flags |= 8;
        value = owner->value_d0;
    }
    unknown_18 = 0;
    state = 3;
}
