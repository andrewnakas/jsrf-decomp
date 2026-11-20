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

struct Interface_00257BD0 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

extern Interface_00257BD0 *data_00257BD0[10];
extern Interface_00257BD0 *data_002577D8;

struct Interface_00251D74 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
    virtual long __stdcall slot9(int first, int second, Interface_00257BD0 **result);
};

extern Interface_00251D74 *data_00251D74;

// The class whose table is at 0x1CCAE0: overrides slots 1 (720B0), 3 (72760).
struct Object_00072710 : Node {
    virtual ~Object_00072710();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int unknown_44;

    void func_00072370();
    void func_000723B0();
};

// Creates the ten interfaces at 0x257BD0 and the one at 0x2577D8 (slot 9 of 0x251D74).
void Object_00072710::func_00072370()
{
    for (unsigned int i = 0; i < 10; i++) {
        data_00251D74->slot9(1, 0, &data_00257BD0[i]);
    }
    data_00251D74->slot9(1, 0, &data_002577D8);
}
