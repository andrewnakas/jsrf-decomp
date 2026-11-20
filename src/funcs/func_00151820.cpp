void __fastcall func_00186A30(float *rgba, unsigned long color);

// A class whose table is at 0x1E1248 (9 slots; Release 0x151C40, created by 0x151CA0).
struct Object_001E1248 {
    virtual void __stdcall func_00151820(int level, unsigned long color);  // slot 3

    float color[4];
    char unknown_14[8];
    float scale;
};

// Keeps level / 16 at +0x1C and the colour as four floats at +4.
void __stdcall Object_001E1248::func_00151820(int level, unsigned long color)
{
    scale = level * 0.0625f;
    func_00186A30(this->color, color);
}
