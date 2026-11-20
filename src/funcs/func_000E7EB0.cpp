/* sym: ??1Object_000CC600@@UAE@XZ = 0x000E7EB0 */
// A base with a pure slot 0 (table 0x1CE304): slot 1 does nothing, slots 2 and 3 take an argument and do
// nothing, slot 4 is the destructor. The class of func_000CD1E0 (table 0x1CE364) derives from it.
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

Object_000CC600::~Object_000CC600()
{
}
