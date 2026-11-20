// A flag word and the value it stands for.
struct Flag {
    unsigned long mask;
    unsigned long value;
};

// The values the queries below look up, with the bit of the capability word each one needs.
extern Flag data_0022E7C0[26];
extern Flag data_0022E890[8];
extern Flag data_0022E8D0[3];
extern Flag data_0022E8E8[4];
extern Flag data_0022E908[10];
extern Flag data_0022E958[8];
extern Flag data_0022E998[3];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00155560(unsigned long argument1, unsigned long argument2,
                                         unsigned long argument3);  // slot 5
};

// 1 when the table entry for value has a bit in common with bits, 0 when it has none or value is not listed.
static inline long Supports(const Flag *table, unsigned int count, unsigned long value, unsigned long bits)
{
    for (unsigned int i = 0; i < count; i++) {
        if (value == table[i].value)
            return (table[i].mask & bits) != 0;
    }
    return 0;
}

// Slot 5: answers query argument2 (0 to 46) about the capabilities argument1 points at (the 0xD4 bytes Direct3D
// fills, then a count at +0xD4 and that many formats at +0xD8), with argument3 as the value asked about: single
// bits, whole words, low words, the float at +0xB0 above 1, or whether a listed value has its bit. 0 for no
// capabilities (0 or -1) and unknown queries.
long __stdcall Object_001E0F00::func_00155560(unsigned long argument1, unsigned long argument2,
                                              unsigned long argument3)
{
    const unsigned long *caps = (const unsigned long *)argument1;
    unsigned long value = argument3;
    unsigned long bits;
    if (!caps || caps == (const unsigned long *)0xFFFFFFFF)
        return 0;
    switch (argument2) {
    case 0:
        for (unsigned int i = 0; i < caps[53]; i++) {
            if (caps[54 + i] == value)
                return 1;
        }
        return 0;
    case 1:
        return (caps[3] >> 17) & 1;
    case 2:
        return (caps[7] >> 16) & 1;
    case 3:
        return (caps[7] >> 24) & 1;
    case 11:
        return Supports(data_0022E998, 3, value, caps[8]);
    case 7:
        return (caps[8] >> 1) & 1;
    case 4:
        return caps[9] & 1;
    case 5:
        return (caps[9] >> 8) & 1;
    case 6:
        return (caps[9] >> 18) & 1;
    case 8:
        return Supports(data_0022E958, 8, value, caps[10]);
    case 9:
    case 10:
        if (argument2 == 9)
            bits = caps[11];
        else
            bits = caps[12];
        return Supports(data_0022E908, 10, value, bits);
    case 12:
        return (caps[15] >> 2) & 1;
    case 13:
        return (caps[15] >> 11) & 1;
    case 14:
        return (caps[15] >> 14) & 1;
    case 15:
        return (caps[15] >> 13) & 1;
    case 36:
        return (caps[15] >> 10) & 1;
    case 16:
        return (caps[16] >> 25) & 1;
    case 17:
        return (caps[16] >> 16) & 1;
    case 46:
        return Supports(data_0022E8E8, 4, value, caps[16]);
    case 18:
        return (caps[16] >> 17) & 1;
    case 39:
        return (caps[18] >> 25) & 1;
    case 40:
        return (caps[18] >> 16) & 1;
    case 41:
        return (caps[18] >> 17) & 1;
    case 19:
    case 38:
        if (argument2 == 19) {
            bits = caps[19];
            unsigned long filter = value & 0x300;
            if ((filter == 0x100 || filter == 0x200) && !(bits & 0x10))
                return 0;
        } else {
            bits = caps[20];
        }
        value &= 0xFFFFF8FF;
        return Supports(data_0022E8D0, 3, value, bits);
    case 20:
        return caps[22];
    case 37:
        return caps[24];
    case 21:
        return caps[25];
    case 22:
        return Supports(data_0022E890, 8, value, caps[34]);
    case 23:
        return Supports(data_0022E7C0, 26, value, caps[36]);
    case 24:
        return caps[38];
    case 26:
        return caps[42];
    case 27:
        return caps[43];
    case 25:
        return caps[40];
    case 28:
        return caps[45];
    case 29:
        return caps[46];
    case 30:
        return (caps[39] >> 6) & 1;
    case 31:
        if (*(const float *)&caps[44] > 1.0f)
            return 1;
        return 0;
    case 32:
        return caps[47];
    case 33:
        return caps[48];
    case 34:
        return caps[49] & 0xFFFF;
    case 35:
        return caps[51] & 0xFFFF;
    case 42:
        return caps[39] & 8;
    case 43:
        return caps[39] & 0x10;
    case 44:
        return caps[39] & 2;
    case 45:
        return caps[39] & 1;
    }
    return 0;
}
