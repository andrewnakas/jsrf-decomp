// Stores the value in every pointer from `first` up to `last` (the library's fill for vectors of pointers; the
// six vector insert functions 0x161010, 0x163430, 0x1690C0, 0x16A790, 0x17A000 and 0x17ADB0 all call this one copy).
void func_00179B60(void **first, void **last, void *const &value)
{
    for (; first != last; ++first)
        *first = value;
}
