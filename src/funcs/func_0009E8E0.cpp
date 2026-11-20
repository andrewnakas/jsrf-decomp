struct Object_000A1C50 {
    char unknown_000[0xa10];
    int value_a10;
    int value_a14;
    int value_a18;
    int value_a1c;

    void func_0009E8E0(int first, int second);
};

// Stores the two arguments at 0xa10 and 0xa14 and clears 0xa18 and 0xa1c. func_000936A0 calls it on the
// same `this` as its neighbour func_00093690.
void Object_000A1C50::func_0009E8E0(int first, int second)
{
    value_a10 = first;
    value_a14 = second;
    value_a18 = 0;
    value_a1c = 0;
}
