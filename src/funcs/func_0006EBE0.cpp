// Frees a block through the pointer kept in the word before it.
void __stdcall func_0006EBE0(void *block)
{
    operator delete(((void **)block)[-1]);
}
