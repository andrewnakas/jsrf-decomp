struct Game {
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;

struct Object_0006E130 {
    void func_0006E7B0(int id);
};

extern Object_0006E130 data_00252790;

struct Object_000265A0 {
    char unknown_0000[0x18b0];
    int unknown_18b0;

    void func_0002D040(int argument);
};

// Handler 26 of the table at 0x1EC288: clears +0x18b0, runs func_0006E7B0 of 0x252790 for 0x102 and 0x103 and
// func_000127C0 of the game (0x1c5, 0).
void Object_000265A0::func_0002D040(int argument)
{
    unknown_18b0 = 0;
    data_00252790.func_0006E7B0(0x102);
    data_00252790.func_0006E7B0(0x103);
    data_0022FCE0->func_000127C0(0x1c5, 0);
}
