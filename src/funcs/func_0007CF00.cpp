/* sym: ??0Object_00120420@@QAE@PAUNode@@HI@Z = 0x00127590 */
int func_00025680();
int func_000256A0(unsigned int index, int argument);
int func_000256C0(unsigned int index, int argument);
void func_00024620(unsigned int colour, float time);

struct Object_000667D0 {
    void func_000666F0(int first, int second);
};

extern Object_000667D0 *data_00251F24;

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

    char unknown_04[0x40];
};

// Object 0x1de2: the class whose table is at 0x1DA300 (constructor 0x127590, destructor 0x126AC0; 0x4180 bytes).
struct Object_00120420 : Node {
    Object_00120420(Node *owner, int id, unsigned int flags);
    virtual ~Object_00120420();

    char unknown_44[0x413c];
};

struct Object_0007C250 : Node {
    int unknown_44;
    int state;

    void func_0007CF00();
};

// State handler 44 of the table at 0x20D2B8: unless func_000256C0 (0x13, 0) or func_00025680 says to wait, makes
// object 0x1de2 under this object (flags 0x300), runs func_000256A0 (0x13, 0), goes to state 0x2d, fades from black
// (func_00024620) and starts the fader's fade with sound (func_000666F0 (0, 1)).
void Object_0007C250::func_0007CF00()
{
    if (!func_000256C0(0x13, 0) && !func_00025680()) {
        new Object_00120420(this, 0x1de2, 0x300);
        func_000256A0(0x13, 0);
        state = 0x2d;
        func_00024620(0, 1.0f / 60.0f);
        data_00251F24->func_000666F0(0, 1);
    }
}
