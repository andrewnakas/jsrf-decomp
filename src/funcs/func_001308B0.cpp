struct Object_001308B0 {
    char unknown_000[0xbc0];
    int counter;

    void func_001308B0();
};

extern unsigned int data_00251EE8;

// While bit 8 of data_00251EE8 is set, counts the word at +0xbc0 down from 4 to 0 and around again.
void Object_001308B0::func_001308B0()
{
    if (data_00251EE8 & 0x100) {
        if (--counter < 0) {
            counter = 4;
        }
    }
}
