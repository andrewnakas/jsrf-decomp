struct Source_000C3DA0 {
    char unknown_00[8];
    int value;
};

struct Owner_000C3DA0 {
    char unknown_00[0xd0];
    int value;
};

struct Object_000C3DA0 {
    int unknown_00;
    Owner_000C3DA0 *owner;
    int state;
    int value_0c;
    int value_10;
    Source_000C3DA0 *source;

    void func_000C3DA0();
};

void Object_000C3DA0::func_000C3DA0()
{
    state = 1;
    value_0c = source->value;
    value_10 = owner->value;
}
