// Counts one call in *count and succeeds (nothing refers to it).
long __stdcall func_001554F0(void *first, void *second, unsigned long *count)
{
    ++*count;
    return 0;
}
