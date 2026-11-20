long __stdcall func_00145A99(void *first, unsigned long second, unsigned long third, unsigned long *result);

// Calls func_00145A99 and returns the word it stores (0 if it stores none).
unsigned long __cdecl func_00159140(void *first, unsigned long second, unsigned long third)
{
    unsigned long result = 0;
    func_00145A99(first, second, third, &result);
    return result;
}
