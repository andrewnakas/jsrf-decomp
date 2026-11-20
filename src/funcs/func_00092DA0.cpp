// The object at 0x2a0 of the player: its first word.
struct Object_00094780 {
    int value_00;
};

struct Object_000A1C50 {
    char unknown_000[0x2a0];
    Object_00094780 *object_2a0;
    char unknown_2a4[0xa30];
    float speed;
    char unknown_cd8[0x148];
    int value_e20;

    int func_00092DA0(int index, float value);
};

extern int (Object_000A1C50::*data_0020DF9C[])();
extern int (Object_000A1C50::*data_0020DFCC[])();
extern int (Object_000A1C50::*data_0020DFFC[])();
extern int (Object_000A1C50::*data_0020E02C[])();

// A two-argument handler: the handler for the index from one of four tables by whether the speed at 0xcd4 and the
// value are above 1.3889 (0x20df9c both, 0x20dfcc speed only, 0x20dffc value only, 0x20e02c neither); the first word
// of the object at 0x2a0 goes to 0xe20.
int Object_000A1C50::func_00092DA0(int index, float value)
{
    int result;
    if (speed > 1.3888888f) {
        if (value > 1.3888888f) {
            result = (this->*data_0020DF9C[index])();
        } else {
            result = (this->*data_0020DFCC[index])();
        }
    } else {
        if (value > 1.3888888f) {
            result = (this->*data_0020DFFC[index])();
        } else {
            result = (this->*data_0020E02C[index])();
        }
    }
    value_e20 = object_2a0->value_00;
    return result;
}
