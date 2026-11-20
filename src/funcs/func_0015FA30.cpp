/* sym: ??8@YA_NABUGuid@@0@Z = 0x0015FA30 */
extern "C" int __cdecl memcmp(const void *a, const void *b, unsigned int size);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

// Two GUIDs are equal when they are the same object or have the same sixteen bytes. Inlined almost everywhere; this
// is the copy the MFile2 factory's CreateInstance (0x176170) calls.
bool operator==(const Guid &a, const Guid &b)
{
    return &a == &b ? true : memcmp(&a, &b, sizeof(Guid)) == 0;
}
