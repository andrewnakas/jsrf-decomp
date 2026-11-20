struct Line_001357A0 {
    int text;
    char unknown_04[0x34];
};

struct Object_00134880 {
    char unknown_000[0x560];
    Line_001357A0 lines[8];

    void func_00135310(int index);
    void func_001357A0(int index);
};

extern int data_0022C768[];
void func_0003D610(float x, float y, float scale, unsigned int color, float width, float height, int text);

// Draws the text of a line at x 230 and y 100 + 102 * index, then calls func_00135310 for the line.
void Object_00134880::func_001357A0(int index)
{
    float y = index * 102.0f;
    y += 100.0f;
    func_0003D610(230.0f, y, 5.0f, 0xffb40000, 0.8f, 0.8f, data_0022C768[lines[index].text]);
    func_00135310(index);
}
