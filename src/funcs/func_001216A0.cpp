struct Object_00120420 {
    void func_00120A80(int index, unsigned int color);
    void func_001216A0(int index, float alpha);
};

// Calls func_00120A80 with white at an alpha from 0 to 1 (opaque white from 1 up).
void Object_00120420::func_001216A0(int index, float alpha)
{
    unsigned int color;
    if (alpha >= 1.0f) {
        color = 0xffffffff;
    } else {
        color = ((int)(alpha * 255.0f) << 24) | 0xffffff;
    }
    func_00120A80(index, color);
}
