extern void **data_00265120;
extern unsigned int data_00265124;

// Takes the object off the list at 0x265120 (0x265124 entries): 0, or E_NOINTERFACE if it is not there, or 1 if
// the list is empty. The first argument is not used.
long __stdcall func_00159F30(void *unused, void *object)
{
    if (data_00265124 != 0) {
        for (unsigned int i = 0; i < data_00265124; i++) {
            if (data_00265120[i] == object) {
                data_00265120[i] = 0;
                return 0;
            }
        }
        return 0x80004002;
    }
    return 1;
}
