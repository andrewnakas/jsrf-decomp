// The class whose table is at 0x1CE6E0 (built inline by func_000DAB10; deleting destructor func_000DAC00).
struct Object_000DAAB0 {
    virtual void func_000DAA70();
    virtual void func_000DAAB0();
    virtual void func_000DAAE0();
    virtual void func_000DAB00();
    virtual ~Object_000DAAB0();
    virtual void func_000DAA40();

    int unknown_04;
    int state;
    float time;
    int value;
};

// Slot 3: clears the value at 0x10.
void Object_000DAAB0::func_000DAB00()
{
    value = 0;
}
