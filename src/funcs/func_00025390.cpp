int __stdcall func_00145560(void *object);

struct Object_000265A0 {
    char unknown_000[0x44];
    int busy;
    unsigned int action;
    int argument;
    char unknown_050[0x130];
    int unknown_180;
    char unknown_184[0xc];
    int unknown_190;

    int func_00025390(unsigned int index, int value);
};

extern int (Object_000265A0::*data_001EC068[0x21])(int argument);

// Starts an action through the first handler table unless one is running; 0 only when one is running.
int Object_000265A0::func_00025390(unsigned int index, int value)
{
    if (!busy) {
        if (index < 0x21) {
            if (data_001EC068[index]) {
                if ((this->*data_001EC068[index])(value)) {
                    action = index;
                    argument = value;
                    unknown_180 = 0;
                    busy = 1;
                }
                func_00145560(&unknown_190);
            } else {
                busy = 0;
            }
        }
        return 1;
    }
    return 0;
}
