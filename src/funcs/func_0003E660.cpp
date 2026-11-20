/* sym: ?func_00011C80@Object_0003E420@@UAEXH@Z = 0x0003E660 */
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

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Device_00251D6C {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20(const Vector3 *direction);
};

extern Device_00251D6C *data_00251D6C;

void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);

// The class whose table is at 0x1CA4C8: a light with a colour (0xFFFFFF) and a direction (constructor 0x3E5F0).
struct Object_0003E420 : Node {
    virtual ~Object_0003E420();
    virtual void func_00011C80(int argument);

    void func_0003E450();

    int colour;
    char unknown_48[4];
    Vector3 direction;
    Vector3 viewDirection;
};

// Slot 3: turns the direction into view space, hands it to the device, then func_0003E450.
void Object_0003E420::func_00011C80(int)
{
    func_001BAC00(&viewDirection, &direction);
    data_00251D6C->slot20(&viewDirection);
    func_0003E450();
}
