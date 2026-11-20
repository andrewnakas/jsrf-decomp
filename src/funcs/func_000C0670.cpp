struct Object_000C0670 {
    char unknown_00[0x44];
    int first;
    int second;

    void func_000C0670(int *firstOut, int *secondOut);
};

void Object_000C0670::func_000C0670(int *firstOut, int *secondOut)
{
    *firstOut = first;
    *secondOut = second;
}
