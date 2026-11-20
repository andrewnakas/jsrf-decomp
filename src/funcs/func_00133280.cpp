struct Object_00070850 {
    void func_00070960(int index);
};

struct Object_00120420 {
    char unknown_0000[0x1e0];
    int busy;
    char unknown_01e4[0xf50];
    int choice;
    char unknown_1138[0x1d7b];
    unsigned char flag_2eb3;
    unsigned char flag_2eb4;
    unsigned char flag_2eb5;
    char unknown_2eb6;
    unsigned char flag_2eb7;
    unsigned char flag_2eb8;
    unsigned char flag_2eb9;

    int func_00133280();
};

extern unsigned int data_00251EE8;

// The yes / no prompt of func_0012C9D0 with its choice at +0x1134 and its flags at +0x2EB3: 0x4000 picks 0, 0x8000
// picks 1 (each with sound 3); 1 or 4 confirms (1 for choice 0, else -1), 2 or 8 cancels (-1). Then sets the
// highlight flags for the choice and returns the result (0 while undecided or busy).
int Object_00120420::func_00133280()
{
    int result = 0;
    if (busy == 0) {
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
    }
    flag_2eb5 = 1;
    flag_2eb9 = 1;
    if (choice == 0) {
        flag_2eb8 = 1;
        flag_2eb3 = 1;
    } else {
        flag_2eb7 = 1;
        flag_2eb4 = 1;
    }
    return result;
}
