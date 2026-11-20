// The object func_00108870 creates for an Object_00107FE0 and whose id it keeps at that object's 0x50 (constructor
// func_00109900, table 0x1D2060; the constructor sets 0x74-0x7c and -1 at 0x80).
struct Object_00109B60 {
    char unknown_00[0x74];
    int value;
    int unknown_78;
    int target;
    int current;
    char unknown_84[8];
    int state;
    int unknown_90;
    int unknown_94;
    float level;
    int unknown_9c;
    int unknown_a0;

    void func_00109FA0(int mode);
};

// Mode 0: state 8 showing the value at 0x74 (or 0 with 0x94/0x98 cleared when it is -1); mode 1: unless nothing is
// shown, state 3 towards the value at level 255 and nothing shown.
void Object_00109B60::func_00109FA0(int mode)
{
    switch (mode) {
    case 0:
        if (value != -1) {
            current = value;
        } else {
            current = 0;
            unknown_94 = 0;
            level = 0;
        }
        unknown_90 = 0;
        state = 8;
        break;
    case 1:
        if (current != -1) {
            unknown_94 = 0;
            unknown_a0 = 0;
            level = 255.0f;
            state = 3;
            target = value;
            current = -1;
        }
        break;
    }
}
