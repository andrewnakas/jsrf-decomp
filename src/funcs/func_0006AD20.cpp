float func_0014C850(float a, float b);
float func_0014C870(float a, float b);
unsigned int func_0014C690(float value);

// Object 0x20C6C0.
struct Object_0006A960 {
    unsigned int func_0006AD20(float *colour);
};

// Packs four colour channels, each held between 0 and 1 (func_0014C870, func_0014C850), into a 32-bit colour with
// the first in the top byte. Does not use this.
unsigned int Object_0006A960::func_0006AD20(float *colour)
{
    float first = colour[0];
    first = func_0014C870(first, 1.0f);
    first = func_0014C850(first, 0.0f);
    float second = colour[1];
    second = func_0014C870(second, 1.0f);
    second = func_0014C850(second, 0.0f);
    float third = colour[2];
    third = func_0014C870(third, 1.0f);
    third = func_0014C850(third, 0.0f);
    float fourth = colour[3];
    fourth = func_0014C870(fourth, 1.0f);
    fourth = func_0014C850(fourth, 0.0f);
    return ((func_0014C690(first * 255.0f) << 8 | func_0014C690(second * 255.0f)) << 8 |
            func_0014C690(third * 255.0f)) << 8 |
           func_0014C690(fourth * 255.0f);
}
