/* const: 0x10000 */
struct Object_00039BE0 {
    int func_00039B50(int value);
    int func_00039DB0(int type, int index);
};

int Object_00039BE0::func_00039DB0(int type, int index)
{
    return func_00039B50((((index & 0xffff) | 0x10000) << 3) | (type & 7));
}
