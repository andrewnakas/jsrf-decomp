/* sym: ??0Object_00066980@@QAE@XZ = 0x00066920 */
// The 15-bit pseudo-random generator (data_00251F28, data_00257C80; also +0x40 of Object_00015D50).
struct Object_00066980 {
    Object_00066980();

    unsigned int value;
};

// Called by 0x18AFA0 for data_00257C80, and by the constructors 0x15420, 0xC0E00 and 0xC3B60: starts at 0.
Object_00066980::Object_00066980()
{
    value = 0;
}
