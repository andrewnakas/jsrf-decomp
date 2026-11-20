struct Node {
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

struct Matrix_001BA950 {
    float m[4][4];
};

void __fastcall func_001BA950(Matrix_001BA950 *matrix);

// The game (constructor 0x12210, table 0x1C4458).
struct Game {
    char unknown_0000[0x40];
    int pass_40;
    int pass_44;
    int pass_48;
    int pass_4c;
    char unknown_0050[0x20];
    int restore;
    char unknown_0074[0x8784];
    Matrix_001BA950 matrix;

    void func_00012580(Node *node, int argument);
};

// Called by 0x131F0 for each node: runs the node's slot 9, 6, 12 or 15 when the flag at +0x40, +0x44, +0x48 or +0x4c
// is set (the first that is), else slot 3; then restores the matrix at +0x87f8 (func_001BA950) when +0x70 is set.
void Game::func_00012580(Node *node, int argument)
{
    if (pass_40) {
        node->func_00011C80_2(argument);
    } else if (pass_44) {
        node->func_00011C80_1(argument);
    } else if (pass_48) {
        node->func_00011C80_3(argument);
    } else if (pass_4c) {
        node->func_00011C80_4(argument);
    } else {
        node->func_00011C80(argument);
    }
    if (restore) {
        func_001BA950(&matrix);
    }
}
