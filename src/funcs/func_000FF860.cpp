/* const: 0x40000 */
struct Object_000FEDB0 {
    char unknown_000[0x138];
    unsigned int mask;

    void func_000FF390(unsigned int mask, int value, int flag);
    void func_000FF860(unsigned int mask, int set);
};

void func_0011B420(int enable);

// Sets or clears the bits of `mask` at 0x138 and passes the high bits (when setting) or the bits outside
// 0x7fffe (when clearing) on to func_000FF390; when setting, also passes bit 18 on to func_0011B420.
void Object_000FEDB0::func_000FF860(unsigned int bits, int set)
{
    if (set) {
        mask |= bits;
        func_000FF390(bits & 0xf8000000, 0, 1);
        if (bits & 0x40000) {
            func_0011B420(1);
        } else {
            func_0011B420(0);
        }
    } else {
        mask &= ~bits;
        func_000FF390(bits & 0xfff80001, 0, 0);
    }
}
