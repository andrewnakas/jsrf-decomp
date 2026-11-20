/* sym: ??0Object_000FDF30@@QAE@PAUNode@@HI@Z = 0x000FE740 */
/* sym: ??1Object_000FDF30@@UAE@XZ = 0x000FDF30 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??1Object_00012170@@UAE@XZ = 0x000121D0 */
/* sym: ?func_00011C80@Object_000FDF30@@UAEXH@Z = 0x000FEDC0 */
/* sym: ?func_00011C90_2@Object_000FDF30@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_000FDF30@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_2@Object_000FDF30@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_6@Object_000FDF30@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_3@Object_000FDF30@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_8@Object_000FDF30@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_4@Object_000FDF30@@UAEXH@Z = 0x000B3DE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

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

// The camera node (constructor func_00012170): its table repeats Node's slots; its destructor is at 0x121D0.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);
    virtual ~Object_00012170();

    char unknown_040[0x58];
};

struct Light_00046920 {
    int unknown_00;
    unsigned int color_04;
    unsigned int color_08;
    int unknown_0c;
    Vector3 direction;
    char unknown_1c[0x24];
    unsigned int color_40;
    int unknown_44;
    unsigned int color_48;
    int unknown_4c;
    int value_50;
    char unknown_54[0x1c];
};

struct Object_00046670 {
    void func_00046700(const Light_00046920 *light);
    void func_00046740(Light_00046920 *light);
    void func_00046920(Light_00046920 *light);
    void func_00046940(int enable);
};

// An entry of the list at 0xdc; the constructor clears only the buffer.
struct Entry_000FDF30 {
    int unknown_0[2];
    void *buffer;
    char unknown_c[0xc];
};

// The child of the camera node whose table is at 0x1D1BF0 (destructor func_000FDF30; object 0x1165).
struct Object_000FDF30 : Object_00012170 {
    Object_000FDF30(Node *owner, int id, unsigned int flags);
    virtual ~Object_000FDF30();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C80_4(int argument);

    int unknown_098[3];
    int ids[7];
    int unknown_0c0[7];
    Entry_000FDF30 entries[7];
    int table[5][16];
    char unknown_2c4[0x80];
};

extern Object_00046670 data_001F93C8;

// Clears the lists and the table, then sets the light: the default from func_00046920 with its direction and
// colours set, through func_00046700, func_00046740 and func_00046940.
Object_000FDF30::Object_000FDF30(Node *owner, int id, unsigned int flags) : Object_00012170(owner, id, flags)
{
    unknown_098[0] = 0;
    unknown_098[1] = 0;
    unknown_098[2] = 0;
    sortKey = 0x14;
    for (int i = 0; i < 7; i++) {
        ids[i] = -1;
        unknown_0c0[i] = -1;
        entries[i].buffer = 0;
    }
    for (int j = 0; j < 16; j++) {
        table[0][j] = 0;
        table[1][j] = 0;
        table[2][j] = 0;
        table[3][j] = 0;
        table[4][j] = 0;
    }
    Light_00046920 light;
    data_001F93C8.func_00046920(&light);
    light.direction.x = 0.0f;
    light.direction.y = 0.0f;
    light.direction.z = 1.0f;
    light.value_50 = 0;
    light.color_04 = 0xffffff;
    light.color_08 = 0;
    data_001F93C8.func_00046700(&light);
    data_001F93C8.func_00046740(&light);
    data_001F93C8.func_00046940(0);
}
