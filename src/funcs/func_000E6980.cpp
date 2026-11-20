struct Owner_000E6980 {
    char unknown_00[0x60];
    float step;
};

struct Object_000E6590 {
    int unknown_00;
    Owner_000E6980 *owner;
    char unknown_08[0x10];
    float time;

    void func_000E6590();
    void func_000E6980();
};

void Object_000E6590::func_000E6980()
{
    time = owner->step + time;
    func_000E6590();
}
