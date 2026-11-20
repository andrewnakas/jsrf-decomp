void func_0003D610(float x, float y, float scale, unsigned int color, float width, float height, int text);

// The sprites of the ten digits.
extern int data_0022C644[10];

struct Object_00120420 {
    void func_00133750(unsigned int value, float x, float y);
};

// Draws a number (at most 999) as three digits from data_0022C644, 10 apart from x on, in black at 0.6 by 0.8.
void Object_00120420::func_00133750(unsigned int value, float x, float y)
{
    unsigned int hundreds;
    unsigned int tens;
    if (value > 999) {
        value = 999;
    }
    if (value >= 100) {
        hundreds = value / 100;
    } else {
        hundreds = 0;
    }
    unsigned int rest = value - hundreds * 100;
    if (rest >= 10) {
        tens = rest / 10;
    } else {
        tens = 0;
    }
    func_0003D610(x, y, 1.0f, 0xff000000, 0.6f, 0.8f, data_0022C644[hundreds]);
    func_0003D610(x + 10.0f, y, 1.0f, 0xff000000, 0.6f, 0.8f, data_0022C644[tens]);
    func_0003D610(x + 20.0f, y, 1.0f, 0xff000000, 0.6f, 0.8f, data_0022C644[value - hundreds * 100 - tens * 10]);
}
