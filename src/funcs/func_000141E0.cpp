/* sym: ??0Object_00014280@@QAE@PAUNode@@HIPBUSettings_000141E0@@@Z = 0x000141E0 */
/* sym: ??1Object_00014280@@UAE@XZ = 0x00014280 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
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
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
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
    virtual void __stdcall slot44();
    virtual void __stdcall slot45();
    virtual void __stdcall slot46();
    virtual void __stdcall slot47();
    virtual void __stdcall slot48();
    virtual void __stdcall slot49();
    virtual void __stdcall slot50();
    virtual void __stdcall slot51();
    virtual void __stdcall slot52();
    virtual void __stdcall slot53();
    virtual int __stdcall slot54(int kind, unsigned int length, int usage, int format, void **buffer);
};

extern Device_00251D6C *data_00251D6C;

struct Settings_000141E0 {
    int unknown_00[4];
    unsigned int count;
    int unknown_14[6];
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

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

// Node child with the table at 0x1C4500 (trails; destructor 0x14280, 0xc0 bytes).
struct Object_00014280 : Node {
    Object_00014280(Node *owner, int id, unsigned int flags, const Settings_000141E0 *settings);
    virtual ~Object_00014280();

    Settings_000141E0 settings;
    char unknown_70[0x40];
    unsigned int trailCount;
    unsigned int otherCount;
    void *buffer;
    int unknown_bc;
};

// Keeps a copy of the settings, clears both counts, sets +0xbc and has slot 54 of the device make the buffer at +0xb8
// (0x142, twice the settings' count at +0x10).
Object_00014280::Object_00014280(Node *owner, int id, unsigned int flags, const Settings_000141E0 *settings)
    : Node(owner, id, flags)
{
    this->settings = *settings;
    trailCount = 0;
    otherCount = 0;
    unknown_bc = 1;
    data_00251D6C->slot54(0x142, this->settings.count * 2, 0, 0, &buffer);
}
