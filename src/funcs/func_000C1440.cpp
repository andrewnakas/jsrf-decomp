struct Object_000C1440 {
    int func_000C1440(int from, int to);
};

// The difference of two 16-bit angles, wrapped into a signed 16-bit value.
int Object_000C1440::func_000C1440(int from, int to)
{
    return (short)(to - from);
}
