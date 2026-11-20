struct Object_00043700 {
    int func_00043700();
};

struct Object_00120420 {
    void func_00133850(int value);
    void func_00133A50(int value);
    void func_00133C80(int value);
    void func_00133EA0(int value);
    void func_00134020(int value);
    void func_001341A0(int value);
    void func_00134320(int value);
};

extern Object_00043700 data_001FC724;

// Member of object 0x1de2's class: passes a value to one of six members by what func_00043700 of data_001FC724
// gives (0 to 5).
void Object_00120420::func_00134320(int value)
{
    switch (data_001FC724.func_00043700()) {
    case 0:
        func_00133850(value);
        break;
    case 1:
        func_00133A50(value);
        break;
    case 2:
        func_00133C80(value);
        break;
    case 3:
        func_00133EA0(value);
        break;
    case 4:
        func_00134020(value);
        break;
    case 5:
        func_001341A0(value);
        break;
    }
}
