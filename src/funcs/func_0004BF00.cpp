struct Data_0004BF00 {
    char unknown_00[0x1c];
    int unknown_1c;
};

struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;
    char unknown_0060[0xf58];
    Data_0004BF00 *data;
    char unknown_0fbc[0x78];
    int unknown_1034;

    void func_0004BF00();
};

void func_00117350(int first, int second);

// State handler (table at 0x1F9888): passes the word at +0x1c of the data to func_00117350, notes whether it is 10, and goes to state 0x59.
void Object_0004ABA0::func_0004BF00()
{
    unknown_1034 = data->unknown_1c == 10;
    func_00117350(data->unknown_1c, 0x14);
    state = 0x59;
}
