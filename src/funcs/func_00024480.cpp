struct Object_00024480 {
    char unknown_00[0x98];
    float alpha;
    float red;
    float green;
    float blue;
    char unknown_a8[0x14];
    unsigned int color;
    int changed;

    void func_00024480(int value);
};

// Takes a colour (0xAARRGGBB): its four channels as fractions of 255 and the colour itself, and marks it changed.
void Object_00024480::func_00024480(int value)
{
    changed = 1;
    alpha = (float)((unsigned int)value >> 24) * (1.0f / 255.0f);
    red = (float)(((unsigned int)value >> 16) & 0xff) * (1.0f / 255.0f);
    green = (float)(((unsigned int)value >> 8) & 0xff) * (1.0f / 255.0f);
    blue = (float)((unsigned int)value & 0xff) * (1.0f / 255.0f);
    color = value;
}
