struct Unit_0022C808 {
    unsigned long port;
    unsigned long slot;
};

struct Object_00136270 {
    char unknown_00[0x44];
    unsigned long port;
    unsigned long slot;
    unsigned char drive;

    void func_00135D00(int kind, int value);
    int func_00135DF0(unsigned char drive, int index, int value);
    void func_00136550();
    int func_00136270(int index, int value);
    int func_00136580(unsigned long port, unsigned long slot, unsigned long *result);
};

extern Unit_0022C808 data_0022C808[];

// For indexes 0 to 7 (a port and slot from data_0022C808): mounts that unit (func_00136580), runs func_00135DF0
// on its drive and unmounts it (func_00136550); for other indexes runs func_00135DF0 on drive U. func_00135D00
// is told which (0 or 1) first. Whether func_00135DF0 gave nonzero; 0 when the unit does not mount.
int Object_00136270::func_00136270(int index, int value)
{
    int found;
    if (index < 8) {
        func_00135D00(0, value);
        unsigned long result;
        unsigned long port = data_0022C808[index].port;
        unsigned long slot = data_0022C808[index].slot;
        if (func_00136580(port, slot, &result) != 1) {
            return 0;
        }
        found = func_00135DF0(drive, index, value);
        func_00136550();
    } else {
        func_00135D00(1, value);
        found = func_00135DF0(0x55, index, value);
    }
    return found != 0;
}
