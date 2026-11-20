struct Node {
    unsigned int func_000A4CF0(float *color);
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


float func_0014C870(float a, float b);
float func_0014C850(float a, float b);

// Clamps the four colour components (red, green, blue, alpha order as stored) to 0..1 (func_0014C870, func_0014C850)
// and packs them into one word, the first component in the top byte.
unsigned int Node::func_000A4CF0(float *color)
{
    for (unsigned int i = 0; i < 4; i++) {
        color[i] = func_0014C870(color[i], 1.0f);
        color[i] = func_0014C850(color[i], 0.0f);
    }
    return (int)(color[0] * 255.0f) << 24 | (int)(color[1] * 255.0f) << 16 | (int)(color[2] * 255.0f) << 8 |
           (int)(color[3] * 255.0f);
}
