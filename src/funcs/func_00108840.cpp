/* sym: ?func_00011C90@Object_00107FE0@@UAEXXZ = 0x00108840 */
struct Game {
    void *func_000128C0(int id);
};

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

struct Object_000FC4D0 {
    void func_000FC4D0(unsigned int mask, int set);
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020; func_00108760 creates one with func_001074B0): func_00106F70
// looks one up by id and calls func_00107B20 on it, as func_00107190 and func_00106F10 call func_00109850 and
// func_00109300.
struct Object_00107FE0 : Node {
    virtual ~Object_00107FE0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    char unknown_0040[0x24];
    int partner_id;
    char unknown_0068[0x1698];
    unsigned int flags;
};

extern Game *data_0022FCE0;

// Slot 1: with flag 0x20000000 at 0x1700 set, sets the same flag (func_000FC4D0) in the object whose id is at 0x64,
// when it exists.
void Object_00107FE0::func_00011C90()
{
    if (flags & 0x20000000) {
        Object_000FC4D0 *partner = (Object_000FC4D0 *)data_0022FCE0->func_000128C0(partner_id);
        if (partner) {
            partner->func_000FC4D0(0x20000000, 1);
        }
    }
}
