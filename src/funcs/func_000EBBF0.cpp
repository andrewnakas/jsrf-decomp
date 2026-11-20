/* const: 0x10000 */
// The object at data_00257CE8.
struct Object_00157F10 {
    int func_000C1D40(int *effect, int *second, int *third);
};

extern Object_00157F10 *data_00257CE8;

extern float data_0021A0D4[];

// The 0x6c-byte part at 0x30 of Object_000EA3B0 and at 0xbc of Object_000ECB50.
struct Part_000EB830 {
    int kind;
    char unknown_04[0x38];
    int effects[4];
    float sizes[4];
    int values[4];

    int func_000EBBF0(unsigned int *flags);
};

// Runs func_000C1D40 on each of the four (effect, value, size) triples and counts the ones that answer non-zero;
// sets 0x10000 in `flags` when the four sizes add up to at least the limit data_0021A0D4 gives for the kind at 0.
// Called by func_000E96E0 and func_000ECE70.
int Part_000EB830::func_000EBBF0(unsigned int *flags)
{
    int count = 0;
    float total = 0.0f;
    for (int i = 0; i < 4; i++) {
        if (data_00257CE8->func_000C1D40(&effects[i], &values[i], (int *)&sizes[i])) {
            count++;
        }
        total += sizes[i];
    }
    if (total >= data_0021A0D4[kind]) {
        *flags |= 0x10000;
    }
    return count;
}
