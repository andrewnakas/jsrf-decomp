struct Owner_000C41D0 {
    char unknown_00[0xd0];
    int value;
};

struct Object_000C41D0 {
    int unknown_00;
    Owner_000C41D0 *owner;
    int state;
    int unknown_0c;
    int value;

    void func_000C41D0();
};

void Object_000C41D0::func_000C41D0()
{
    state = 1;
    value = owner->value;
}
