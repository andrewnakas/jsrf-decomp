void func_000FE6C0(int *first, int *second);

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0x23c];
    int unknown_29c;
    int unknown_2a0;

    void func_0004B1B0();
};

// State handler: resets the pair at +0x29c (0, -1), has func_000FE6C0 fill it in, then state 0x25.
void Object_0004ABA0::func_0004B1B0()
{
    unknown_29c = 0;
    unknown_2a0 = -1;
    func_000FE6C0(&unknown_29c, &unknown_2a0);
    state = 0x25;
}
