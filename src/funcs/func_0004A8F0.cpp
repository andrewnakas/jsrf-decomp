/* sym: ??2@YAPAXI@Z = 0x0004A8F0 */
void *__cdecl func_0017C953(unsigned int size);

// The game's operator new: hands the request to the C runtime's allocator.
void *__cdecl operator new(unsigned int size)
{
    return func_0017C953(size);
}
