/* sym: ?func_00011C80@Object_0009C3C0@@UAEXH@Z = 0x0009CBE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Entry_0006DB80;

struct Object_0006DB80 {
    Entry_0006DB80 *func_0006DB80(int key);
};

extern Object_0006DB80 data_00251F78;

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// The child of Node whose table is at 0x1CD4A8: overrides slot 3 (the message handler at 0x9CBE0).
struct Object_0009C3C0 : Node {
    Object_0009C3C0(Node *owner, int id, unsigned int flags, int value);
    virtual ~Object_0009C3C0();
    virtual void func_00011C80(int message);

    char unknown_40[4];
    int value;

    void func_0009C410(int value);
};

// Overrides slot 3, the message handler: on 7, takes the depth at 0x10 from where the entry of data_00251F78 for
// the value at 0x44 puts the origin (func_001BAAA0, func_001BAB20, between func_001BA9C0 and func_001BAA50); on 8,
// func_0009C410 with the value. The point is 16 bytes in retail's frame (0x10), so func_001BAB20 likely writes four
// floats; this unit passes it as a Vector3.
void Object_0009C3C0::func_00011C80(int message)
{
    float point[4];
    switch (message) {
    case 7:
        func_001BA9C0();
        func_001BAAA0((float *)data_00251F78.func_0006DB80(value));
        func_001BAB20((Vector3 *)point, 0);
        depth = point[2];
        func_001BAA50();
        break;
    case 8:
        func_0009C410(value);
        break;
    }
}
