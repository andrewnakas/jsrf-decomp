struct Object_00120420 {
    char unknown_000[0x210];
    unsigned int number;

    void func_00133750(unsigned int value, float x, float y);
    void func_00133C80(int language);
};

extern char data_001C78EF[];
extern char data_001DE3D4[];
extern char data_001DE3F8[];
extern char data_001DE404[];
extern char data_001DE430[];
extern char data_001DE450[];
extern char data_001DE478[];
extern char data_001DE4A0[];
extern char data_001DE4B4[];
extern char data_001DE4DC[];

void func_0003D610(float x, float y, float scale, unsigned int color, float width, float height, int text);

// Draws a graffiti save notice of up to four lines for `language` at x 65 from y 140 in black at 0.8: four strings
// for language 4, two and the number at +0x210 (func_00133750 at (269, 140)) for language 1, three for languages 0
// and 2, and the string at data_001C78EF three times for language 3.
void Object_00120420::func_00133C80(int language)
{
    switch (language) {
    case 4:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE4DC);
        func_0003D610(65.0f, 162.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE4B4);
        func_0003D610(65.0f, 184.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE4A0);
        func_0003D610(65.0f, 206.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE478);
        break;
    case 1:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE450);
        func_0003D610(65.0f, 162.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE430);
        func_00133750(number, 269.0f, 140.0f);
        break;
    case 0:
    case 2:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE404);
        func_0003D610(65.0f, 162.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE3F8);
        func_0003D610(65.0f, 184.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE3D4);
        break;
    case 3:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001C78EF);
        func_0003D610(65.0f, 162.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001C78EF);
        func_0003D610(65.0f, 184.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001C78EF);
        break;
    }
}
