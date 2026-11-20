// The sum of two 16-bit angles, wrapped to 16 bits.
int func_000B99D0(int angle, int delta)
{
    return (angle + delta) & 0xffff;
}
