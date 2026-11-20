// The object func_00108870 creates for an Object_00107FE0 and whose id it keeps at that object's 0x50 (constructor
// func_00109900, table 0x1D2060; the constructor sets 0x74-0x7c and -1 at 0x80).
struct Object_00109B60 {
    char unknown_00[0x80];
    int value;

    int func_0010A040();
};

int Object_00109B60::func_0010A040()
{
    return value == -1;
}
