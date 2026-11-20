struct Object_0006E130 {
    void func_0006E7B0(int id);
};

extern Object_0006E130 data_00252790;

struct Object_000265A0 {
    char unknown_0000[0x17e0];
    int sounds[2];
    unsigned int soundCount;

    void func_00039790(int argument);
};

// Handler 22 of the table at 0x1EC288: hands each of the ids at +0x17e0 (count at +0x17e8) to func_0006E7B0 of 0x252790, then
// clears the count.
void Object_000265A0::func_00039790(int)
{
    for (unsigned int i = 0; i < soundCount; i++)
        data_00252790.func_0006E7B0(sounds[i]);
    soundCount = 0;
}
