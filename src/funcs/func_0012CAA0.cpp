struct Object_00070850 {
    void func_00070960(int index);
};

struct Object_00120420 {
    char unknown_0000[0x1138];
    int choice;

    int func_0012CAA0();
};

extern unsigned int data_00251EE8;

// Member of object 0x1de2's class: a yes/no choice at +0x1138 moved by bits 14 (to 0) and 15 (to 1) of the
// buttons in data_00251EE8 and kept within 0 and 1; bits 0 or 2 confirm (1 for choice 0, else -1), bits 1 or 3
// cancel (-1). Each sounds through func_00070960. 0 when nothing is pressed.
int Object_00120420::func_0012CAA0()
{
    int result = 0;
    if (data_00251EE8 & 0x4000) {
        choice = 0;
        ((Object_00070850 *)this)->func_00070960(3);
    }
    if (data_00251EE8 & 0x8000) {
        choice = 1;
        ((Object_00070850 *)this)->func_00070960(3);
    }
    if (choice < 0 || choice > 1) {
        choice = 1;
    }
    if (data_00251EE8 & 5) {
        if (choice == 0) {
            result = 1;
            ((Object_00070850 *)this)->func_00070960(0);
        } else {
            result = -1;
            ((Object_00070850 *)this)->func_00070960(2);
        }
    }
    if (data_00251EE8 & 0xa) {
        result = -1;
        ((Object_00070850 *)this)->func_00070960(2);
    }
    return result;
}
