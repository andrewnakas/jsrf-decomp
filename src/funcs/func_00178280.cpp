// The class whose table is at 0x1E4020.
struct Object_001E4020;

// Finishes the pending transfer (0x178180).
long __stdcall func_00178180(Object_001E4020 *self);

// The callback that slot 4 (0x1782A0) and 0x178830 pass on with the object as the third argument: finishes the
// object's transfer (0x178180) and returns 1.
int __stdcall func_00178280(unsigned long argument1, unsigned long argument2, Object_001E4020 *self)
{
    func_00178180(self);
    return 1;
}
