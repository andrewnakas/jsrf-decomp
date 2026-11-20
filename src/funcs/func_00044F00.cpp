// The class whose table is at 0x1CA788 (Node child, destructor 0x44AE0).
struct Object_00044AE0 {
    char unknown_000[0x48];
    int mode;
    char unknown_04c[0x24];
    unsigned int colour;
    char unknown_074[0x50];
    float distance;
    float farEnd;
    float nearEnd;
    char unknown_0d0[0x10];
    int timer;

    void func_00044F00(unsigned int *first, unsigned int *second);
};

// Two colours (the one at +0x70 with an alpha): the fade t is how farEnd the distance at +0xc4 is from +0xc8 towards
// +0xcc (0 when it is not below +0xc8); modes 3 and 4 blend it with the timer at +0xe0 (over 6 and 30 frames) in
// opposite ways for the two colours. Alpha is 255 at fade 0 and 0 at fade 1.
void Object_00044AE0::func_00044F00(unsigned int *first, unsigned int *second)
{
    float t;
    float k;
    float u;
    float a;
    float b;
    if (distance < farEnd)
        t = (farEnd - distance) / (farEnd - nearEnd);
    else
        t = 0.0f;
    switch (mode) {
    case 3:
        k = timer * 0.16666667f;
        u = 1.0f - t;
        a = t + u * k;
        b = (1.0f - k) * u + t;
        break;
    case 4:
        k = timer * 0.033333335f;
        u = 1.0f - t;
        a = t + (1.0f - k) * u;
        b = u * k + t;
        break;
    default:
        b = t;
        a = t;
        break;
    }
    int alpha = (int)((1.0f - a) * 255.0f + a * 0.0f);
    if (alpha < 0)
        alpha = 0;
    *first = (colour & 0xffffff) + (alpha << 24);
    alpha = (int)((1.0f - b) * 255.0f + b * 0.0f);
    if (alpha < 0)
        alpha = 0;
    *second = (colour & 0xffffff) + (alpha << 24);
}
