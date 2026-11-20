struct Object_000A6340 {
    char unknown_000[0x8b4];
    int first;
    int second;

    void func_000A6340(int newFirst, int newSecond);
};

void Object_000A6340::func_000A6340(int newFirst, int newSecond)
{
    first = newFirst;
    second = newSecond;
}
