/* const: 0x80881 */
// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    char unknown_0000[0x16ac];
    unsigned int mask;

    void func_00108870(unsigned int mask, int set);
    void func_001098A0(int bits, int set);
};

// Sets or clears the bits at 0x16ac, then passes the bits within 0xcee10a00 (setting) or 0x80881 (clearing) on to
// func_00108870.
void Object_00107FE0::func_001098A0(int bits, int set)
{
    if (set) {
        mask |= bits;
        func_00108870(bits & 0xcee10a00, 1);
    } else {
        mask &= ~bits;
        func_00108870(bits & 0x80881, 0);
    }
}
