struct Data_0004B010 {
    char unknown_00[0x24];
    int unknown_24;
};

struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;
    char unknown_0060[0xf58];
    Data_0004B010 *data;
    char unknown_0fbc[0x78];
    int unknown_1034;

    void func_0004B010();
};

void func_00117350(int first, int second);

// State handler (table at 0x1F9888): passes the word at +0x24 of the data to func_00117350, notes whether it is 10, and goes to state 0x1b.
void Object_0004ABA0::func_0004B010()
{
    unknown_1034 = data->unknown_24 == 10;
    func_00117350(data->unknown_24, 0);
    state = 0x1b;
}
