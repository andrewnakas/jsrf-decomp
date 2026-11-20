// One of the four controller slots at data_00251E1C (0x40 bytes each).
struct Slot_001116E0 {
    int busy;
    char unknown_04[0x3c];
};

extern Slot_001116E0 data_00251E1C[4];
extern int data_00251F20;

void func_0006F5B0(int slot);
void func_0006F6A0();

// The class whose table is at 0x1CB0F8 (constructor 0x67B60, destructor 0x67980).
struct Object_00067980 {
    char unknown_000[0x98];
    int state;
    char unknown_09c[8];
    int unknown_0a4;

    void func_000689A0();
    void func_00069040();
    void func_00069430();
};

// With +0xa4 clear: carries on with func_00069040 while the current controller slot (0x251F20) is busy, else hands
// it to func_0006F5B0 and goes to state 3. With +0xa4 set: carries on with func_000689A0 while any slot is busy, else
// func_0006F6A0 and state 3.
void Object_00067980::func_00069430()
{
    if (!unknown_0a4) {
        if (!data_00251E1C[data_00251F20].busy) {
            func_0006F5B0(data_00251F20);
            state = 3;
            return;
        }
        func_00069040();
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (data_00251E1C[i].busy) {
            func_000689A0();
            return;
        }
    }
    func_0006F6A0();
    state = 3;
}
