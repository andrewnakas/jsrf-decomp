struct Object_00043700 {
    int func_00043700();
};

// The class whose table is at 0x1DEA60 (destructor 0x1379E0).
struct Object_001379E0 {
    char unknown_000[0x44];
    unsigned int value_44;
    char unknown_048[4];
    int value_4c;
    int value_50;
    unsigned int value_54;

    void func_00138620(float depth);
};

extern Object_00043700 data_001FC724;
extern int data_0022D7A0[];
extern int data_0022D7B8[][2];
extern int data_0022D7E0[][9];
extern int data_0022D898[][5];
extern int data_0022D8FC[][2];

void func_0003D610(float x, float y, float scale, unsigned int color, float width, float height, int text);

// Draws the screen's texts at `depth`, each picked by the language (func_00043700 of data_001FC724): the title
// by +0x4c; from step 1 (+0x44) the line chosen by +0x50; from step 2 the one chosen by +0x54 (raised by 20 and
// drawn at 0.7 for languages other than 0), then, unless +0x4c is 1, a line once +0x54 reaches 6; and always the
// prompt at (495, 405).
void Object_001379E0::func_00138620(float depth)
{
    func_0003D610(70.0f, 113.0f, depth, 0xffff0000, 0.8f, 0.8f,
                  data_0022D8FC[data_001FC724.func_00043700()][value_4c]);
    if (value_44 >= 1) {
        func_0003D610(70.0f, 215.0f, depth, 0xffff0000, 0.8f, 0.8f,
                      data_0022D898[data_001FC724.func_00043700()][value_50]);
    }
    if (value_44 >= 2) {
        float offset = 0.0f;
        float scale = 0.8f;
        if (data_001FC724.func_00043700()) {
            offset = -20.0f;
            scale = 0.7f;
        }
        func_0003D610(292.0f, offset + 233.0f, depth, 0xff000000, scale, scale,
                      data_0022D7E0[data_001FC724.func_00043700()][value_54]);
        if (value_4c != 1 && value_54 >= 6) {
            func_0003D610(70.0f, 316.0f, depth, 0xffffffff, 0.8f, 0.8f,
                          data_0022D7B8[data_001FC724.func_00043700()][0]);
        }
    }
    func_0003D610(495.0f, 405.0f, depth, 0xffffffff, 1.0f, 1.0f, data_0022D7A0[data_001FC724.func_00043700()]);
}
