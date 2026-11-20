/* const: 0xd81e4 */
/* const: 0x459e4 */
/* sym: ??0Object_00116A10@@QAE@PAUNode@@HI@Z = 0x00115FC0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
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

extern "C" void *memset(void *destination, int value, unsigned int size);
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

// Clears the fields past the Node and creates the four ADX channels: channel 0 with a 0xD81E4-byte work buffer,
// channels 1 to 3 with 0x459E4 bytes each.
Object_00116A10::Object_00116A10(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    memset(&value_44, 0, sizeof(*this) - 0x44);
    buffers[0] = operator new(0xd81e4);
    handles[0] = func_0013AC80(2, buffers[0], 0xd81e4);
    for (int i = 1; i < 4; i++) {
        buffers[i] = operator new(0x459e4);
        handles[i] = func_0013AC80(2, buffers[i], 0x459e4);
    }
    func_0013A9D0(handles[0], 2);
    func_0013A9D0(handles[1], 1);
    func_0013A9D0(handles[2], 1);
    func_0013A9D0(handles[3], 2);
    value_9c = -1;
    value_a0 = -1;
    value_104 = 1;
    value_60 = 0;
}
