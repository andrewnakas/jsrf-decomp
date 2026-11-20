/* const: 0xf4240 */

// The timer at 0x20CC48: its counter frequency at +0x8.
struct Object_0006E910 {
    char unknown_00[0x8];
    __int64 frequency;

    void func_0006E910(__int64 *out, __int64 start, __int64 end);
};

// The microseconds between two counter readings.
void Object_0006E910::func_0006E910(__int64 *out, __int64 start, __int64 end)
{
    *out = (end - start) * 1000000 / frequency;
}
