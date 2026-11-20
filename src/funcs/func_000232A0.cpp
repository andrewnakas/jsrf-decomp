/* sym: ?func_00011C80_1@Object_00022990@@UAEXH@Z = 0x000232A0 */
struct Matrix_001BA950 {
    float m[4][4];
};

void __fastcall func_001BA950(Matrix_001BA950 *matrix);

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

// The node class whose table is at 0x1C4BA8 (destructor 0x22990): overrides slot 6.
struct Object_00022990 : Node {
    virtual void func_00011C80_1(int argument);
    void func_00021420(unsigned int index, int pass);
    void func_00022770();
    void func_000231E0();

    char unknown_44[4];
    Matrix_001BA950 matrix;
    int state;
    char unknown_8c[0x30];
    float *depths;
    int *order;
    int sortCount;
};

// Slot 6: loads its matrix (func_001BA950); in state 2, messages 7 and 12 sort (func_000231E0), run func_00022770 and
// set the depth to -10; messages 8 and 13 draw its entries in sorted order (func_00021420) for that pass; messages 15
// and 16 sort and then draw them.
void Object_00022990::func_00011C80_1(int argument)
{
    func_001BA950(&matrix);
    switch (state) {
    case 2:
        switch (argument) {
        case 7:
        case 12:
            func_000231E0();
            func_00022770();
            depth = -10.0f;
            break;
        case 8:
        case 13:
            for (int i = 0; i < sortCount; i++) {
                func_00021420(order[i], argument);
            }
            break;
        case 15:
        case 16:
            func_000231E0();
            for (int j = 0; j < sortCount; j++) {
                func_00021420(order[j], argument);
            }
            break;
        }
        break;
    }
}
