// Whether 0x15D9E0 supports the format word: kind 2 or 6 (or 8 with bit 0x1000), bit 0x10 set and 0 to 4 in bits
// 8-11. E_NOTIMPL otherwise.
long __fastcall func_0015D3F0(unsigned long format)
{
    switch (format & 0xe) {
    case 2:
    case 6:
        break;
    case 8:
        if (!(format & 0x1000))
            return 0x80004001;
        break;
    default:
        return 0x80004001;
    }
    if (!(format & 0x10))
        return 0x80004001;
    switch (format & 0xf00) {
    case 0:
    case 0x100:
    case 0x200:
    case 0x300:
    case 0x400:
        return 0;
    }
    return 0x80004001;
}
