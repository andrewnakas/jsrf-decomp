// The object at 0x2a0 of the player.
struct Object_00094780 {
    int value_00;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x2a0];
    Object_00094780 *object_2a0;
    char unknown_2a4[0xa30];
    float value_cd4;
    char unknown_cd8[0x148];
    int value_e20;

    void func_00092A80(int index, float value);
};

extern void (Object_000A1C50::*data_0020DC3C[])();
extern void (Object_000A1C50::*data_0020DC6C[])();
extern void (Object_000A1C50::*data_0020DC9C[])();
extern void (Object_000A1C50::*data_0020DCCC[])();
extern void (Object_000A1C50::*data_0020DCFC[])();
extern void (Object_000A1C50::*data_0020DD2C[])();
extern void (Object_000A1C50::*data_0020DD5C[])();
extern void (Object_000A1C50::*data_0020DD8C[])();
extern void (Object_000A1C50::*data_0020DDBC[])();

// Calls entry `index` of one of nine tables of handlers (0x20DC3C on, twelve each), picked by whether the speed at
// 0xcd4 and the value are over 25/18, over 25/36 or neither; then copies the word at 0 of the object at 0x2a0 to 0xe20.
void Object_000A1C50::func_00092A80(int index, float value)
{
    if (value_cd4 > 1.3888888f) {
        if (value > 1.3888888f) {
            (this->*data_0020DC3C[index])();
        } else if (value > 0.69444442f) {
            (this->*data_0020DC6C[index])();
        } else {
            (this->*data_0020DC9C[index])();
        }
    } else if (value_cd4 > 0.69444442f) {
        if (value > 1.3888888f) {
            (this->*data_0020DCCC[index])();
        } else if (value > 0.69444442f) {
            (this->*data_0020DCFC[index])();
        } else {
            (this->*data_0020DD2C[index])();
        }
    } else {
        if (value > 1.3888888f) {
            (this->*data_0020DD5C[index])();
        } else if (value > 0.69444442f) {
            (this->*data_0020DD8C[index])();
        } else {
            (this->*data_0020DDBC[index])();
        }
    }
    value_e20 = object_2a0->value_00;
}
