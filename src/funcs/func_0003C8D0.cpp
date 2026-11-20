/* const: 0x4b0f8 */
/* const: 0x4b128 */
/* const: 0x4b130 */
struct Point_0003D170 {
    float x;
    float y;
};

// The text drawer (object 0x1166): its state for two levels.
struct Object_0003D680 {
    char unknown_00000[0x4b0f0];
    float scale[2];
    unsigned int color[2];
    Point_0003D170 position[2];
    Point_0003D170 origin[2];
    float unknown_4b120[2];
    unsigned int alpha[2];
    int level;

    void func_0003C8D0(int code);
};

// Sets the current level's colour from a colour code (0 black, 2 red, 3 green, 4 blue, 5 yellow, 6 magenta, 7 cyan,
// anything else white) under its alpha byte.
void Object_0003D680::func_0003C8D0(int code)
{
    switch (code) {
    case 0:
        color[level] = alpha[level] << 24;
        break;
    case 2:
        color[level] = (alpha[level] << 24) | 0xff0000;
        break;
    case 3:
        color[level] = (alpha[level] << 24) | 0xff00;
        break;
    case 4:
        color[level] = (alpha[level] << 24) | 0xff;
        break;
    case 5:
        color[level] = (alpha[level] << 24) | 0xffff00;
        break;
    case 6:
        color[level] = (alpha[level] << 24) | 0xff00ff;
        break;
    case 7:
        color[level] = (alpha[level] << 24) | 0xffff;
        break;
    default:
        color[level] = (alpha[level] << 24) | 0xffffff;
        break;
    }
}
