// The class whose table is at 0x1DA350 (destructor 0x127E60).
struct Object_00127E60 {
    void func_0012F4D0(int value, float x, float y);
};

extern int data_0022866C[];

void func_0003D610(float x, float y, float scale, unsigned int color, float width, float height, int text);

// Draws `value` (nothing when negative, at most 999) at (x, y) as up to three digits from data_0022866C, 12
// apart, in black at 0.6 by 0.8, leaving out leading zeros (the last digit always shows). Called by func_0012F600;
// never reads this.
void Object_00127E60::func_0012F4D0(int value, float x, float y)
{
    if (value < 0) {
        return;
    }
    int shown = 0;
    int hundreds;
    int tens;
    if (value > 999) {
        value = 999;
    }
    if (value >= 100) {
        hundreds = value / 100;
    } else {
        hundreds = 0;
    }
    int rest = value - hundreds * 100;
    if (rest >= 10) {
        tens = rest / 10;
    } else {
        tens = 0;
    }
    int ones = value - (tens + hundreds * 10) * 10 < 0 ? 0 : value - (tens + hundreds * 10) * 10;
    if (hundreds > 0) {
        func_0003D610(x, y, 1.0f, 0xff000000, 0.6f, 0.8f, data_0022866C[hundreds]);
        shown = 1;
    }
    if (tens > 0 || shown) {
        func_0003D610(x + 12.0f, y, 1.0f, 0xff000000, 0.6f, 0.8f, data_0022866C[tens]);
    }
    func_0003D610(x + 24.0f, y, 1.0f, 0xff000000, 0.6f, 0.8f, data_0022866C[ones]);
}
