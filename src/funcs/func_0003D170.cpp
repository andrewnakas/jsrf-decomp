/* const: 0x4b0f0 */
/* const: 0x4b0f8 */
/* const: 0x4b100 */
/* const: 0x4b104 */
/* const: 0x4b110 */
/* const: 0x4b114 */
/* const: 0x4b120 */
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

    void func_0003CF20(int last);
    void func_0003D170(float first, float second, float scale, unsigned int value, float x, float y, int last);
};

// Sets the current level's origin, scale, colour (with its alpha byte) and position, then runs func_0003CF20.
void Object_0003D680::func_0003D170(float first, float second, float scale, unsigned int value, float x, float y,
                                    int last)
{
    origin[level].x = first;
    unknown_4b120[level] = first;
    origin[level].y = second;
    this->scale[level] = scale;
    color[level] = value;
    alpha[level] = value >> 24;
    position[level].x = x;
    position[level].y = y;
    func_0003CF20(last);
}
