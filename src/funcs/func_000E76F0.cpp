/* sym: ??1Object_000E7770@@UAE@XZ = 0x000E76F0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000E7770@@UAEXXZ = 0x000E7770 */
/* sym: ?func_00011C90_1@Object_000E7770@@UAEXXZ = 0x000E7CA0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

struct Object_0006DB80 {
    void func_0006DF30(int key);
};

extern Object_0006DB80 data_00251F78;

// The owner at 0xb0.
struct Object_000C5B50 {
    char unknown_00[0x9c];
    int value_9c;

    int func_000C5B10(int message, void *data);
};

void func_000FEC30(int value, const Vector3 *position);

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

// The class whose tables are at 0x1CEDF0 (Node) and 0x1CEDE8 (Object_000C60C0 at +0x44).
struct Object_000E7770 : Node, Object_000C60C0 {
    virtual ~Object_000E7770();
    virtual void func_00011C90();
    virtual void func_00011C90_1();

    Vector3 position;
    char unknown_054[0x5c];
    Object_000C5B50 *owner;
    char unknown_0b4[8];
    int state;
    char unknown_0c0[0x20];
    void *mesh;
    int value_e4;
    char unknown_0e8[0x14];
    int key;
};

// Releases the key at 0xfc (data_00251F78) and the mesh at 0xe0 (data_0022FCE8).
Object_000E7770::~Object_000E7770()
{
    if (key != -1) {
        data_00251F78.func_0006DF30(key);
    }
    if (mesh) {
        data_0022FCE8.func_00019760(mesh);
    }
}
