struct Rect6 {
    int left;
    int top;
    int right;
    int bottom;
    int unknown_10;
    int unknown_14;
};

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual int __stdcall func_00154CF0(Rect6 *out);  // slot 11

    int left;
    int top;
    int right;
    int bottom;
};

// Copies the four words at +4 to the destination and clears its last two; E_INVALIDARG without one.
int __stdcall Object_001E0F00::func_00154CF0(Rect6 *out)
{
    if (out) {
        out->left = left;
        out->top = top;
        out->right = right;
        out->bottom = bottom;
        out->unknown_10 = 0;
        out->unknown_14 = 0;
        return 1;
    }
    return 0x80070057;
}
