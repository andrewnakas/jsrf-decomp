/* sym: ??0Object_001377C0@@QAE@PAUNode@@HI@Z = 0x00137570 */
int func_000256C0(unsigned int index, int argument);

struct Object_000667D0 {
    void func_000667D0();
};

extern Object_000667D0 *data_00251F24;

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

    char unknown_04[0x40];
};

// The class whose table is at 0x1DEA20 (constructor 0x137570, destructor 0x1377C0; 0x54 bytes).
struct Object_001377C0 : Node {
    Object_001377C0(Node *owner, int id, unsigned int flags);
    virtual ~Object_001377C0();

    char unknown_44[0x10];
};

struct Object_0007C250 : Node {
    int unknown_44;
    int state;

    void func_0007D080();
};

// State handler 57 of the table at 0x20D2B8: once func_000256C0 (0x12, 1) says so, state 0x3a, a new
// Object_001377C0 under this object (id 0x1deb, flags 0x200), and the fader's func_000667D0.
void Object_0007C250::func_0007D080()
{
    if (func_000256C0(0x12, 1)) {
        state = 0x3a;
        new Object_001377C0(this, 0x1deb, 0x200);
        data_00251F24->func_000667D0();
    }
}
