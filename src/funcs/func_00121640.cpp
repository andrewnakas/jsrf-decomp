struct Object_00120420 {
    char unknown_0000[0x4158];
    float fade;

    void func_00120A80(int index, unsigned int color);
    void func_00121640(int index);
};

// Calls func_00120A80 with white at the alpha of the fade at +0x4158 (opaque white from 1 up).
void Object_00120420::func_00121640(int index)
{
    unsigned int color;
    if (fade >= 1.0f) {
        color = 0xffffffff;
    } else {
        color = ((int)(fade * 255.0f) << 24) | 0xffffff;
    }
    func_00120A80(index, color);
}
