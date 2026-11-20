/* sym: ??1Object_00126AC0@@UAE@XZ = 0x00126AC0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00126AC0@@UAEXXZ = 0x00127810 */
/* sym: ?func_00011C80@Object_00126AC0@@UAEXH@Z = 0x00127080 */
struct Object_0006E130 {
    void func_0006E7B0(int id);
};

extern Object_0006E130 data_00252790;

void func_00025740(unsigned int index, int argument);

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

// The class whose table is at 0x1DA300 (constructor 0x127590): holds sound ids and owns the nodes it creates.
struct Object_00126AC0 : Node {
    Object_00126AC0(Node *owner, int id, unsigned int flags);
    virtual ~Object_00126AC0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    void func_0012CC70();

    char unknown_44[0x458];
    int sounds_49C[80];
    int sounds_5DC[80];
    int sounds_71C[14];
    int sound_754;
    int sound_758;
    int sound_75C;
    int sound_760;
    int sounds_764[80];
    char unknown_8A4[0xe64];
    Node *nodes_1708[370];
    Node *nodes_1CD0[370];
    char unknown_2298[0x200];
    Node *nodes_2498[128];
    char unknown_2698[0x244];
    Node *nodes_28DC[70];
    char unknown_29F4[0x30];
    Node *nodes_2A24[12];
    char unknown_2A54[0x224];
    Node *nodes_2C78[137];
};

// Frees the shared buffers, releases every sound id it holds, deletes the nodes it owns and releases registration
// 0x13.
Object_00126AC0::~Object_00126AC0()
{
    func_0012CC70();
    if (sound_754 != -1) {
        data_00252790.func_0006E7B0(sound_754);
    }
    if (sound_758 != -1) {
        data_00252790.func_0006E7B0(sound_758);
    }
    if (sound_75C != -1) {
        data_00252790.func_0006E7B0(sound_75C);
    }
    if (sound_760 != -1) {
        data_00252790.func_0006E7B0(sound_760);
    }
    int i;
    for (i = 0; i < 80; i++) {
        if (sounds_5DC[i] != -1) {
            data_00252790.func_0006E7B0(sounds_5DC[i]);
        }
        if (sounds_49C[i] != -1) {
            data_00252790.func_0006E7B0(sounds_49C[i]);
        }
    }
    for (i = 0; i < 14; i++) {
        if (sounds_71C[i] != -1) {
            data_00252790.func_0006E7B0(sounds_71C[i]);
        }
    }
    for (i = 0; i < 80; i++) {
        if (sounds_764[i] != -1) {
            data_00252790.func_0006E7B0(sounds_764[i]);
        }
    }
    for (i = 0; i < 70; i++) {
        if (nodes_28DC[i]) {
            delete nodes_28DC[i];
        }
    }
    for (i = 0; i < 128; i++) {
        if (nodes_2498[i]) {
            delete nodes_2498[i];
        }
    }
    for (i = 0; i < 370; i++) {
        if (nodes_1CD0[i]) {
            delete nodes_1CD0[i];
        }
        if (nodes_1708[i]) {
            delete nodes_1708[i];
        }
    }
    for (i = 0; i < 12; i++) {
        if (nodes_2A24[i]) {
            delete nodes_2A24[i];
        }
    }
    for (i = 0; i < 137; i++) {
        if (nodes_2C78[i]) {
            delete nodes_2C78[i];
        }
    }
    func_00025740(0x13, 0);
}
