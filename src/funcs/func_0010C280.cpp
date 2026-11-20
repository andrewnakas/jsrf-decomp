struct Object_0010C280 {
    int func_0010C280(int value);
};

// The last decimal digit of the value (a remainder, so negative for a negative value). Does not read
// `this`; its caller func_0010CA60 loads `ecx` before the call (`ret 4`).
int Object_0010C280::func_0010C280(int value)
{
    return value - value / 10 * 10;
}
