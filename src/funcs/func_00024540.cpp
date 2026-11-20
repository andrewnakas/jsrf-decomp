struct Object_00024480 {
    char unknown_00[0xa8];
    float targetAlpha;
    float targetRed;
    float targetGreen;
    float targetBlue;
    float step;
    unsigned int color;
    int changed;

    void func_00024540(unsigned int color, float step);
};

// Starts a fade towards a colour (0xAARRGGBB): its four channels as fractions of 255 and the step per frame.
void Object_00024480::func_00024540(unsigned int color, float step)
{
    changed = 0;
    targetAlpha = (float)(color >> 24) * (1.0f / 255.0f);
    targetRed = (float)((color >> 16) & 0xff) * (1.0f / 255.0f);
    targetGreen = (float)((color >> 8) & 0xff) * (1.0f / 255.0f);
    targetBlue = (float)(color & 0xff) * (1.0f / 255.0f);
    this->step = step;
}
