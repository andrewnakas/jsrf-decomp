/* sym: ?func_00011C80@Object_001379E0@@UAEXH@Z = 0x0013A240 */
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
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24(int value);
    virtual void __stdcall slot25(int value);
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37();
    virtual void __stdcall slot38();
    virtual void __stdcall slot39();
    virtual void __stdcall slot40();
    virtual void __stdcall slot41();
    virtual void __stdcall slot42();
    virtual void __stdcall slot43();
    virtual int __stdcall slot44();
    virtual void __stdcall slot45();
};

struct Game {
    void *func_000128C0(int id);
};

struct Object_00137910 {
    int func_00137920();
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

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

// The class whose table is at 0x1DEA60 (destructor 0x1379E0, slot 1 func_0013A340): overrides slot 3 of Node.
struct Object_001379E0 : Node {
    virtual void func_00011C80(int argument);

    char unknown_44[0x370];
    int shown;

    void func_00138290();
    void func_00138540(float angle);
    void func_00138620(float angle);
    void func_001387A0(float angle);
    void func_001388F0(float angle);
    void func_00138AF0(float angle);
    void func_00138C80(float angle);
    void func_00138DC0(float angle);
    void func_00138F00(float angle);
    void func_00139150(float angle);
    void func_00139260(float angle);
};

extern Device_00251D6C *data_00251D6C;
extern Game *data_0022FCE0;

// Slot 3: when func_00137920 of object 0x1deb gives 1 and the flag at +0x3b4 is set, sets device slots 24 (0) and
// 25 (-1), runs func_00138290, and if device slot 44 succeeds draws the ten parts (func_00138C80 ... func_00138540,
// given 90 down to 5) and ends with device slot 45. The argument is not read.
void Object_001379E0::func_00011C80(int)
{
    if (((Object_00137910 *)data_0022FCE0->func_000128C0(0x1deb))->func_00137920() == 1 && shown) {
        data_00251D6C->slot24(0);
        data_00251D6C->slot25(-1);
        func_00138290();
        if (data_00251D6C->slot44() >= 0) {
            func_00138C80(90.0f);
            func_001387A0(80.0f);
            func_00138AF0(70.0f);
            func_001388F0(60.0f);
            func_00138DC0(50.0f);
            func_00138F00(40.0f);
            func_00138620(30.0f);
            func_00139150(20.0f);
            func_00139260(10.0f);
            func_00138540(5.0f);
            data_00251D6C->slot45();
        }
    }
}
