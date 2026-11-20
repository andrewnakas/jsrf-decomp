struct Object_00120420 {
    char unknown_000[0x210];
    unsigned int number;

    void func_00133750(unsigned int value, float x, float y);
    void func_00133850(int language);
};

extern char data_001DE16C[];
extern char data_001DE194[];
extern char data_001DE1B4[];
extern char data_001DE1D4[];
extern char data_001DE1F8[];
extern char data_001DE21C[];
extern char data_001DE240[];
extern char data_001DE264[];
extern char data_001DE288[];

void func_0003D610(float x, float y, float scale, unsigned int color, float width, float height, int text);

// Draws a notice of two or three lines for `language` at x 65 from y 140 in black at 0.8: three strings for language
// 4; two (the second at 162 or 184) for languages 2, 0 and 3, and for language 1 also the number at +0x210
// (func_00133750 at (139, 140)).
void Object_00120420::func_00133850(int language)
{
    switch (language) {
    case 4:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE288);
        func_0003D610(65.0f, 162.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE264);
        func_0003D610(65.0f, 206.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE240);
        break;
    case 2:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE21C);
        func_0003D610(65.0f, 162.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE1F8);
        break;
    case 0:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE1D4);
        func_0003D610(65.0f, 184.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE240);
        break;
    case 1:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE1B4);
        func_0003D610(65.0f, 184.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE240);
        func_00133750(number, 139.0f, 140.0f);
        break;
    case 3:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE194);
        func_0003D610(65.0f, 162.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE16C);
        break;
    }
}
