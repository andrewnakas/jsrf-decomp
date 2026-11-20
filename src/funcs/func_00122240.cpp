struct Point_001223B0 {
    float x;
    float y;
};

// One of the 15 pieces of a player (0x30 bytes).
struct Piece_001223B0 {
    int id;
    unsigned char flag;
    char unknown_05;
    unsigned short value_06;
    unsigned short value_08;
    char unknown_0a[2];
    float x;
    float y;
    float scale;
    int value_18;
    int value_1c;
    int value_20;
    unsigned int colors[3];
};

struct Object_00120420 {
    char unknown_0000[0x1dc];
    int layout;
    char unknown_01e0[0xbc8];
    Piece_001223B0 pieces[15];

    void func_00122240(int index);
};

extern Point_001223B0 data_00225DE8[][15];
extern unsigned int data_00226040[];

// Resets the piece `index` of the own set at +0xDA8 to its start position in the layout at +0x1DC
// (data_00225DE8), scale 10 and the layout's colour (data_00226040); the single-piece form of func_001223B0.
void Object_00120420::func_00122240(int index)
{
    pieces[index].id = -1;
    pieces[index].x = data_00225DE8[layout][index].x;
    pieces[index].y = data_00225DE8[layout][index].y;
    pieces[index].scale = 10.0f;
    pieces[index].value_18 = 0;
    pieces[index].value_1c = 0;
    pieces[index].value_20 = 0;
    pieces[index].colors[0] = data_00226040[layout];
    pieces[index].colors[1] = data_00226040[layout];
    pieces[index].colors[2] = data_00226040[layout];
    pieces[index].value_06 = 0;
    pieces[index].value_08 = 0;
    pieces[index].flag = 0;
}
