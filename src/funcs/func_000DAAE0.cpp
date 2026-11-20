struct Node;

Node *func_000C70A0(Node *owner, int value, int kind);

// The class whose table is at 0x1CE6E0 (built inline by func_000DAB10; deleting destructor func_000DAC00).
struct Object_000DAAB0 {
    virtual void func_000DAA70();
    virtual void func_000DAAB0();
    virtual void func_000DAAE0();
    virtual void func_000DAB00();
    virtual ~Object_000DAAB0();
    virtual void func_000DAA40();

    int value;
    int state;
};

// Slot 2: creates an object of kind 1 for the value at 4 through func_000C70A0 (no owner), then state 3.
void Object_000DAAB0::func_000DAAE0()
{
    func_000C70A0(0, value, 1);
    state = 3;
}
