// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE364 (constructor func_000CD7D0); slots 8 and 9 are pure.
struct Object_000CD1E0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0() = 0;
    virtual void func_000D7880() = 0;

    int unknown_04;
    int state;
    char unknown_0c[0x68];
    void (Object_000CD1E0::**handlers)();
};

// Slot 0 of the table at 0x1CE364: runs the handler for the current state from the table at 0x74, then slot 8.
void Object_000CD1E0::func_000CD1E0()
{
    (this->*handlers[state])();
    func_000D77D0();
}
