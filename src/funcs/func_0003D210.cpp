/* const: 0x4b0f0 */
/* const: 0x4b0f8 */
/* const: 0x4b100 */
/* const: 0x4b104 */
/* const: 0x4b118 */
/* const: 0x4b114 */
/* const: 0x4b120 */
/* const: 0x4b128 */
/* const: 0x4b130 */
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

struct Point_0003D170 {
    float x;
    float y;
};

// The text drawer (object 0x1166): its state for two levels.
struct Object_0003D680 : Node {
    char unknown_00044[0x4b0ac];
    float scale[2];
    unsigned int color[2];
    Point_0003D170 position[2];
    Point_0003D170 origin[2];
    float unknown_4b120[2];
    unsigned int alpha[2];
    int level;

    void func_0003CF20(int last);
    void func_0003D210(float first, float second, float scale, unsigned int value, float x, float y, int last);
};

// The same as func_0003D170 on level 1, then messages 7 and 8 (slot 3) and back to level 0.
void Object_0003D680::func_0003D210(float first, float second, float scale, unsigned int value, float x, float y,
                                    int last)
{
    level = 1;
    origin[level].x = first;
    unknown_4b120[level] = first;
    origin[level].y = second;
    this->scale[level] = scale;
    color[level] = value;
    alpha[level] = value >> 24;
    position[level].x = x;
    position[level].y = y;
    func_0003CF20(last);
    func_00011C80(7);
    func_00011C80(8);
    level = 0;
}
