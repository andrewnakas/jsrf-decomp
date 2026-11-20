struct Contact_00089B90 {
    int unknown_00;
    char unknown_04[0x14];
    unsigned char side;
    char unknown_19[0x1f];
    Contact_00089B90 *next;
};

struct Object_000A1C50 {
    char unknown_000[0x258];
    Contact_00089B90 *contacts;

    int func_00089B90();
};

// The kind of the player's last free contact (+0x258, linked at +0x38), from the bit of its side: 4 for bit 3, 5 for
// bit 4, then the pairs 0xa, 0x12, 0xc and 0x14 give 2, 3, 6 and 7; any other bit 1, no contact 0.
int Object_000A1C50::func_00089B90()
{
    int bits = 0;
    for (Contact_00089B90 *contact = contacts; contact; contact = contact->next) {
        if (!contact->unknown_00) {
            bits = 1 << contact->side;
        }
    }
    if (bits) {
        if (bits == 8) {
            return 4;
        }
        if (bits == 0x10) {
            return 5;
        }
        if (bits == 0xa) {
            return 2;
        }
        if (bits == 0x12) {
            return 3;
        }
        if (bits == 0xc) {
            return 6;
        }
        return bits == 0x14 ? 7 : 1;
    }
    return 0;
}
