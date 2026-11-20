struct Owner_000DCBC0 {
    char unknown_00[0x5c];
    float speed;
    float climb;
};

struct Object_000DCBC0 {
    char unknown_000[0x4];
    Owner_000DCBC0 *owner;
    int state;
    char unknown_00c[0x1b4];
    int next;

    void func_000DDB90();
};

// A handler of the table at 0x217A20: a slow owner (speed below 1.3888888) speeds up by half and climbs at
// 0.46296296 (state 21, 13 at 0x1c0); a fast one doubles its speed and climbs at 0.9259259 (state 22, 14).
void Object_000DCBC0::func_000DDB90()
{
    Owner_000DCBC0 *current = owner;
    if (current->speed < 1.3888888f) {
        current->speed = current->speed * 1.5f;
        owner->climb = 0.46296296f;
        state = 21;
        next = 13;
    } else {
        current->speed = current->speed + current->speed;
        owner->climb = 0.9259259f;
        state = 22;
        next = 14;
    }
}
