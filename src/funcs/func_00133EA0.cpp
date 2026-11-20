struct Object_00120420 {
    char unknown_000[0x210];
    unsigned int number;

    void func_00133750(unsigned int value, float x, float y);
    void func_00133EA0(int language);
};

extern char data_001C78EF[];
extern char data_001DE504[];
extern char data_001DE518[];
extern char data_001DE544[];
extern char data_001DE56C[];
extern char data_001DE598[];

void func_0003D610(float x, float y, float scale, unsigned int color, float width, float height, int text);

// Draws the three lines of a notice for `language` at x 65 from y 140, 22 apart, in black at 0.8: three strings
// for language 4; two for language 1, followed by the number at +0x210 (func_00133750 at (143, 140)); the string
// at data_001C78EF three times for languages 0, 2 and 3.
void Object_00120420::func_00133EA0(int language)
{
    switch (language) {
    case 4:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE598);
        func_0003D610(65.0f, 162.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE56C);
        func_0003D610(65.0f, 184.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE544);
        break;
    case 1:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE518);
        func_0003D610(65.0f, 162.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE504);
        func_00133750(number, 143.0f, 140.0f);
        break;
    case 0:
    case 2:
    case 3:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001C78EF);
        func_0003D610(65.0f, 162.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001C78EF);
        func_0003D610(65.0f, 184.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001C78EF);
        break;
    }
}
