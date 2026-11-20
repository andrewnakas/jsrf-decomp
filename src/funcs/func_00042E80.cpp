/* sym: ??0Object_00042E80@@QAE@XZ = 0x00042E80 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Object_00042E80 {
    char unknown_00[0xc];
    int first[0x14];
    char unknown_5c[8];
    int second[0x14];

    Object_00042E80();
};

// Zeroes the two 20-word tables.
Object_00042E80::Object_00042E80()
{
    memset(first, 0, sizeof(first));
    memset(second, 0, sizeof(second));
}
