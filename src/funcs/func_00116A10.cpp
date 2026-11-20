/* sym: ??1Object_00116A10@@UAE@XZ = 0x00116A10 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00116A10@@UAEXXZ = 0x00116E30 */
/* sym: ?func_00011C90_2@Object_00116A10@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00116A10@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_00116A10@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_00116A10@@UAEXXZ = 0x000AECC0 */
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

void func_0013A6B0(void *handle);
void func_0013A9D0(void *handle, int mode);
void func_0013AB80(void *handle);
void *func_0013AC80(int kind, void *work, unsigned int size);

// The class whose table is at 0x1D76C8: overrides slot 1 of Node; slots 4, 7, 10, 13 hold folded thunks.
struct Object_00116A10 : Node {
    Object_00116A10(Node *owner, int id, unsigned int flags);
    virtual ~Object_00116A10();
    virtual void func_00011C90();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    int value_44;
    void *buffers[4];
    char unknown_58[8];
    int value_60;
    char unknown_64[4];
    void *handles[4];
    char unknown_78[0x24];
    int value_9c;
    int value_a0;
    char unknown_a4[0x60];
    int value_104;
    char unknown_108[0xc];
};

// Stops the four channels (func_00116200, inlined) and releases their ADX handles and work buffers.
Object_00116A10::~Object_00116A10()
{
    for (int channel = 0; channel < 4; channel++) {
        switch (channel) {
        case 4:
            func_0013A6B0(handles[1]);
            break;
        case 5:
            func_0013A6B0(handles[2]);
            break;
        default:
            func_0013A6B0(handles[channel]);
            break;
        }
    }
    for (int i = 0; i < 4; i++) {
        void *handle = handles[i];
        func_0013AB80(handle);
        void *buffer = buffers[i];
        operator delete(buffer);
    }
}
