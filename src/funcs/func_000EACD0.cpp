struct Owner_000EACD0 {
    char unknown_00[0x5c];
    float value_5c;
};

struct Object_000EAB40 {
    char unknown_000[4];
    Owner_000EACD0 *owner;
    int state;
    char unknown_00c[0x138];
    int busy;

    int func_000EAB40();
    void func_000EACD0();
};

// When func_000EAB40 reports true: state 2, busy, and the owner's value at 0x5c cleared.
void Object_000EAB40::func_000EACD0()
{
    if (func_000EAB40()) {
        state = 2;
        busy = 1;
        owner->value_5c = 0.0f;
    }
}
