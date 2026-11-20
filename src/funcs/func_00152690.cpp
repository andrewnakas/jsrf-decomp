/* sym: ??1Object_001E1290@@QAE@XZ = 0x00152690 */
// The base of the classes whose tables are at 0x1E1290 (destructor 0x152690), 0x1E1298, 0x1E12B8 and 0x1E12D8
// (created by 0x152BC0); all four share this QueryInterface.
struct Object_001E1290 {
    virtual long __stdcall func_00152360(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014E1F0_1();  // slot 1: AddRef, folded

    ~Object_001E1290();
};

// The destructor: only the table pointer is reset.
Object_001E1290::~Object_001E1290()
{
}
