/* sym: ??0Object_00014280@@QAE@PAUNode@@HIPBUSettings_000141E0@@@Z = 0x000141E0 */
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

// What the trail constructor copies to +0x44: 0x2c bytes (width at +0x50 of the object, ...).
struct Settings_000141E0 {
    int unknown_00[11];
};

// Node child with the table at 0x1C4500 (trails; constructor 0x141E0, 0xc0 bytes).
struct Object_00014280 : Node {
    Object_00014280(Node *owner, int id, unsigned int flags, const Settings_000141E0 *settings);

    Settings_000141E0 settings;
    char unknown_70[0x50];
};

// Called by 0x84200 and Object_00086060's 0x85280: creates a trail object under `owner` with flags 0x2000.
void func_00014680(Node *owner, int id, const Settings_000141E0 *settings)
{
    new Object_00014280(owner, id, 0x2000, settings);
}
