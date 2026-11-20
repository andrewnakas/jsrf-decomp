// Four 0x40-byte records at 0x251DF0; the first word of each is cleared.
struct Record_00065C80 {
    int unknown_00;
    char unknown_04[0x3c];
};

extern Record_00065C80 data_00251DF0[];

// Clears the first word of the four records at 0x251DF0.
void func_00065C80()
{
    for (unsigned int i = 0; i < 4; i++) {
        data_00251DF0[i].unknown_00 = 0;
    }
}
