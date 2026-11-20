struct Object_00039BE0 {
    int func_00039B50(int value);
    int func_00039D40(int *values, unsigned int count);
};

// Says whether func_00039B50 accepts every value of the array.
int Object_00039BE0::func_00039D40(int *values, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++) {
        if (!func_00039B50(values[i])) {
            return 0;
        }
    }
    return 1;
}
