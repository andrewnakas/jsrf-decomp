/* const: 0x10000 */
// The difference of two 16-bit angles (second less first), wrapped into -0x8000 to 0x7fff.
int func_0004A7F0(int first, int second)
{
    int difference = (second & 0xffff) - (first & 0xffff);
    if (difference > 0x7fff) {
        difference -= 0x10000;
    }
    if (difference < -0x8000) {
        difference += 0x10000;
    }
    return difference;
}
