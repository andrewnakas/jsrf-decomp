struct Owner_000CC020 {
    char unknown_00[0x54];
    int limit;
};

struct Object_000CC020 {
    char unknown_00[8];
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0x1c];
    Owner_000CC020 *owner;

    void func_000CC020();
};

// Counts up and moves to state 2 once the count passes the owner's limit.
void Object_000CC020::func_000CC020()
{
    if (++count > owner->limit) {
        state = 2;
    }
}
