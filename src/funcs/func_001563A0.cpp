// The size in bytes of a vertex of the flexible vertex format (D3DFVF bits): the position (3 to 7 floats by the
// bits 1-3), the normal (0x10), the diffuse (0x40) and specular (0x80) colours and up to four texture coordinate
// sets (count in bits 8-11, each set's size in two bits from bit 16). E_INVALIDARG for an unknown position.
unsigned int __stdcall func_001563A0(unsigned long fvf)
{
    unsigned int size;
    switch (fvf & 0xE) {
    case 2:
        size = 3;
        break;
    case 4:
        size = 4;
        break;
    case 6:
        size = 4;
        break;
    case 8:
        size = 5;
        break;
    case 0xA:
        size = 6;
        break;
    case 0xC:
        size = 7;
        break;
    default:
        return 0x80070057;
    }
    if (fvf & 0x10)
        size += 3;
    if (fvf & 0x40)
        size++;
    if (fvf & 0x80)
        size++;
    unsigned int count = 0;
    switch (fvf & 0xF00) {
    case 0x400:
        count++;
    case 0x300:
        count++;
    case 0x200:
        count++;
    case 0x100:
        count++;
    }
    size <<= 2;
    for (unsigned int i = 0; i < count; i++) {
        switch ((fvf >> (i * 2 + 16)) & 3) {
        case 1:
            size += 3 * sizeof(float);
            break;
        case 2:
            size += 4 * sizeof(float);
            break;
        case 3:
            size += sizeof(float);
            break;
        default:
            size += 2 * sizeof(float);
            break;
        }
    }
    return size;
}
