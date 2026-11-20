/* sym: ??3@YAXPAX@Z = 0x0004A900 */
void __cdecl func_0017C965(void *memory);

// The game's operator delete: hands the block back to the C runtime.
void __cdecl operator delete(void *memory)
{
    func_0017C965(memory);
}
