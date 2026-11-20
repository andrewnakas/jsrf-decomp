struct Object_00120420 {
    char unknown_000[0x210];
    unsigned int number;

    void func_00133750(unsigned int value, float x, float y);
    void func_00133A50(int language);
};

extern char data_001DE2B4[];
extern char data_001DE2D4[];
extern char data_001DE2F8[];
extern char data_001DE310[];
extern char data_001DE330[];
extern char data_001DE35C[];
extern char data_001DE374[];
extern char data_001DE394[];
extern char data_001DE3A8[];

void func_0003D610(float x, float y, float scale, unsigned int color, float width, float height, int text);

// Draws a graffiti save/load notice of two or three lines for `language` at x 65 from y 140 in black at 0.8 (not
// enough free blocks, saving, unable to load, saving, loading); language 1 adds the number at +0x210 (func_00133750
// at (275, 140)).
void Object_00120420::func_00133A50(int language)
{
    switch (language) {
    case 4:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE3A8);
        func_0003D610(65.0f, 162.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE394);
        func_0003D610(65.0f, 184.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE374);
        break;
    case 0:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE35C);
        func_0003D610(65.0f, 162.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE330);
        break;
    case 1:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE310);
        func_0003D610(65.0f, 184.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE374);
        func_00133750(number, 275.0f, 140.0f);
        break;
    case 2:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE35C);
        func_0003D610(65.0f, 184.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE330);
        break;
    case 3:
        func_0003D610(65.0f, 140.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE2F8);
        func_0003D610(65.0f, 162.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE2D4);
        func_0003D610(65.0f, 184.0f, 1.0f, 0xff000000, 0.8f, 0.8f, (int)data_001DE2B4);
        break;
    }
}
