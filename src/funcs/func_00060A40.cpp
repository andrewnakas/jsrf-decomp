// What func_00062230 builds an entry from (it passes the same pointer here and to the entry's constructor 0x60CB0).
struct Desc_00060A40 {
    char unknown_000[0x210];
    int unknown_210;
    char unknown_214[0x8];
    int unknown_21c;
    char unknown_220[0x2c];
    int unknown_24c;
    char unknown_250[0xc];
    int unknown_25c;
    char unknown_260[0x4];
    int unknown_264;
};

struct Object_000607B0 {
    int func_00060A40(Desc_00060A40 *desc);
};

// The size an entry built from a description needs: 0x1558, 12 bytes per +0x25c and, per frame (+0x25c + 1 times +0x21c times +0x210 sixtieths
// plus one, at most +0x24c), 0xb5 bytes plus 16, 24 or 0x70 by the kind at +0x264.
int Object_000607B0::func_00060A40(Desc_00060A40 *desc)
{
    int count = (desc->unknown_25c + 1) * desc->unknown_21c * desc->unknown_210 / 60 + 1;
    if (desc->unknown_24c < count) {
        count = desc->unknown_24c;
    }
    int size = count * 0xb5 + desc->unknown_25c * 12 + 0x1558;
    switch (desc->unknown_264) {
    case 0:
        size += count * 16;
        break;
    case 1:
        size += count * 24;
        break;
    case 2:
        size += count * 0x70;
        break;
    }
    return size;
}
