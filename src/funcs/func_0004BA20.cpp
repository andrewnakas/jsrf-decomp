struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;
    char unknown_0060[0xfd4];
    int unknown_1034;

    void func_0004BA20();
};

int func_001167F0();
int func_001168B0();

// State handler (table at 0x1F9888): goes to state 0x46 when the poll returns 2.
void Object_0004ABA0::func_0004BA20()
{
    int result;
    if (unknown_1034) {
        result = func_001168B0();
    } else {
        result = func_001167F0();
    }
    if (result == 2) {
        state = 0x46;
    }
}
