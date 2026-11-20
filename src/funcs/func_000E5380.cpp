/* sym: ??0Object_000E5380@@QAE@XZ = 0x000E5380 */
/* sym: ??1Object_000E5380@@UAE@XZ = 0x000E53D0 */
/* sym: ?func_000CD1E0@Object_000E5380@@UAEXXZ = 0x00011C90 */
/* sym: ?func_00011C80@Object_000E5380@@UAEXH@Z = 0x000E5030 */
/* sym: ?func_00011C80_1@Object_000E5380@@UAEXH@Z = 0x000AEE80 */
// The resource slot 9 of data_00251D74 makes; slot 2 releases it.
struct Interface_000E5380 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
};

struct Interface_00251D74 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
    virtual long __stdcall slot9(int first, int second, Interface_000E5380 **result);
};

extern Interface_00251D74 *data_00251D74;

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CED6C: holds a resource of data_00251D74 at 0x30; slot 0 is empty and slot 3
// is a folded thunk.
struct Object_000E5380 : Object_000CC600 {
    Object_000E5380();
    virtual void func_000CD1E0();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000E5380();

    char unknown_04[0x2c];
    Interface_000E5380 *resource;
};

// Has slot 9 of data_00251D74 make the resource.
Object_000E5380::Object_000E5380()
{
    data_00251D74->slot9(1, 0, &resource);
}
