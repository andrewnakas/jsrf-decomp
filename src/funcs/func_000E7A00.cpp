/* sym: ?func_00011C80@Object_000E7D70@@UAEXH@Z = 0x000E7A00 */
void func_001BA9C0();
void __fastcall func_001BAA50();

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

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The class whose tables are at 0x1CEDF0 (Node) and 0x1CEDE8 (Object_000C60C0 at +0x44); the objects are chained
// through the second base at 0xb8.
struct Object_000E7770 : Node, Object_000C60C0 {
    virtual void func_00011C90();
    void func_000E7790();

    char unknown_048[0x70];
    Object_000C60C0 *next;
    int state;
};

// The object a behaviour serves: a speed at 0x10 and the first of a chain of Object_000E7770 at 0xd0.
struct Desc_000E7D70 {
    char unknown_00[0x10];
    float speed;
    char unknown_14[0xbc];
    Object_000C60C0 *objects;
};

// A base with a pure slot 0 (table 0x1CE304), destructor func_000E7EB0.
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The behaviour func_000E7D70 builds (0x30 bytes, table 0x1CEE30): slot 0 does nothing, slot 3 runs slot 2.
struct Object_000E7D70 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);

    Desc_000E7D70 *desc;
};

// Slot 2: on event 7 sets the served object's speed to 20; on event 8 runs func_000E7790 on every object of its
// chain, each between func_001BA9C0 and func_001BAA50.
void Object_000E7D70::func_00011C80(int event)
{
    switch (event) {
    case 7:
        desc->speed = 20.0f;
        break;
    case 8:
        for (Object_000E7770 *object = static_cast<Object_000E7770 *>(desc->objects); object;
             object = static_cast<Object_000E7770 *>(object->next)) {
            func_001BA9C0();
            object->func_000E7790();
            func_001BAA50();
        }
        break;
    }
}
