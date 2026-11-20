unsigned int __cdecl func_0014C690(float value);

// The device's non-polymorphic base at +4 (its statistics); the device calls its colour packers through it.
struct Stats {
    unsigned long func_001560C0(const float *color);
};

// Packs a colour of three floats in [0, 1] into 0xRRGGBB (each channel times 255, converted by func_0014C690).
unsigned long Stats::func_001560C0(const float *color)
{
    unsigned int red = func_0014C690(color[0] * 255.0f);
    unsigned int green = func_0014C690(color[1] * 255.0f);
    unsigned int blue = func_0014C690(color[2] * 255.0f);
    return (red << 8 | green) << 8 | blue;
}
