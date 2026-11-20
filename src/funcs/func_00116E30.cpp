/* sym: ?func_00011C90@Object_00116A10@@UAEXXZ = 0x00116E30 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    char unknown_34[0x10];
};

// Object 5's class, whose table is at 0x1D76C8: overrides slot 1 of Node.
struct Object_00116A10 : Node {
    virtual ~Object_00116A10();
    virtual void func_00011C90();

    void func_001162E0();
    void func_00116440();
    void func_00116C30();

    char unknown_44[0x1c];
    int status;
    char unknown_64[4];
    void *handles[4];
    char unknown_78[0x54];
    int value_cc;
    float steps[4];
    float targets[4];
    int active[4];
    int value_100;
    char unknown_104[0xc];
    int pending;
};

int func_0013AA50(void *handle);
void func_0006F730();

// Slot 1: runs func_00116C30, func_00116440 and func_001162E0; starts the pending fade of channel 0 (to 1 over
// 30 steps) unless +0xcc is set; then notes the status func_0013AA50 reports for each of the four ADX handles and
// calls func_0006F730 for each nonzero one.
void Object_00116A10::func_00011C90()
{
    func_00116C30();
    func_00116440();
    func_001162E0();
    if (pending && !value_cc) {
        value_100 = 0;
        targets[0] = 1.0f;
        steps[0] = 1.0f / 30.0f;
        active[0] = 1;
        pending = 0;
    }
    for (int i = 0; i < 4; i++) {
        int result = func_0013AA50(handles[i]);
        if (result) {
            status = result;
            func_0006F730();
        }
    }
}
