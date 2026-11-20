unsigned int __cdecl func_0014C690(float value);

// The device's non-polymorphic base at +4 (its statistics); the device calls its colour packers through it.
struct Stats {
    unsigned long func_00156050(const float *color);
};

// Packs a colour of four floats in [0, 1] (red, green, blue, alpha) into 0xAARRGGBB (each channel times 255,
// converted by func_0014C690).
unsigned long Stats::func_00156050(const float *color)
{
    unsigned int red = func_0014C690(color[0] * 255.0f);
    unsigned int green = func_0014C690(color[1] * 255.0f);
    unsigned int blue = func_0014C690(color[2] * 255.0f);
    unsigned int alpha = func_0014C690(color[3] * 255.0f);
    return ((alpha << 8 | red) << 8 | green) << 8 | blue;
}
