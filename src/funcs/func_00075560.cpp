struct Object_00039BE0 {
    void func_0003A4C0(int *first, int *second);
    int func_0003A4F0();
};

extern Object_00039BE0 data_001EFFB0;

// The settings the menu edits (12 words at the pointer +0xe8).
struct Settings_00075560 {
    int values[12];
};

// The class whose table is at 0x1CCCD8 (constructor 0x75A30, destructor 0x74D60).
struct Object_00074D60 {
    char unknown_00[0xa8];
    int first;
    int second;
    char unknown_b0[0x38];
    Settings_00075560 *settings;

    void func_00075560();
};

// Resets the settings at +0xe8 (0, 0, 1, 0, 1, 0, 1, 0, 2, 0, 1, 0), then takes word 3 from func_0003A4F0 of
// 0x1EFFB0 and words 7 and 11 from its func_0003A4C0, keeping those two also at +0xa8 and +0xac.
void Object_00074D60::func_00075560()
{
    if (settings) {
        settings->values[0] = 0;
        settings->values[1] = 0;
        settings->values[2] = 1;
        settings->values[3] = 0;
        settings->values[4] = 1;
        settings->values[5] = 0;
        settings->values[6] = 1;
        settings->values[7] = 0;
        settings->values[8] = 2;
        settings->values[9] = 0;
        settings->values[10] = 1;
        settings->values[11] = 0;
        settings->values[3] = data_001EFFB0.func_0003A4F0();
        int a;
        int b;
        data_001EFFB0.func_0003A4C0(&a, &b);
        settings->values[7] = a;
        settings->values[11] = b;
        first = a;
        second = b;
    }
}
