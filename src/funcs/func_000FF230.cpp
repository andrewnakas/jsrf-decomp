/* sym: ??0Object_000FEDB0@@QAE@PAUNode@@HI@Z = 0x000FF230 */
/* sym: ??1Object_000FEDB0@@UAE@XZ = 0x000FEC60 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??1Object_00012170@@UAE@XZ = 0x000121D0 */
/* sym: ?func_00011C90@Object_000FEDB0@@UAEXXZ = 0x000FECC0 */
/* sym: ?func_00011C90_1@Object_000FEDB0@@UAEXXZ = 0x000FEDB0 */
/* sym: ?func_00011C80@Object_000FEDB0@@UAEXH@Z = 0x000FEDC0 */
/* sym: ?func_00011C80_1@Object_000FEDB0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_2@Object_000FEDB0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_3@Object_000FEDB0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000FEDB0@@UAEXH@Z = 0x000B3DE0 */
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

// An entry of the list at 0xa4.
struct Entry_000FEDB0 {
    int first;
    int second;
    int value;
    int unknown_c;
};

// The child of the camera node whose table is at 0x1D1C30 (destructor func_000FEC60; object 0x1163).
struct Object_000FEDB0 : Object_00012170 {
    Object_000FEDB0(Node *owner, int id, unsigned int flags);
    virtual ~Object_000FEDB0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    int unknown_098[3];
    Entry_000FEDB0 entries[8];
    int unknown_124[5];
    int unknown_138[3];
    unsigned int flags_144;
    int value_148;
    char unknown_14c[0xc00];
    int value_d4c;
};

extern Object_00046670 data_001F93C8;

// Clears its fields and the entries at 0xa4, then sets the light as func_000FE740 does.
Object_000FEDB0::Object_000FEDB0(Node *owner, int id, unsigned int flags) : Object_00012170(owner, id, flags)
{
    unknown_138[0] = 0;
    unknown_138[1] = 0;
    unknown_138[2] = 0;
    flags_144 = 0;
    value_148 = 0;
    sortKey = 0x19;
    for (int k = 0; k < 5; k++) {
        unknown_124[k] = 0;
    }
    for (int i = 0; i < 8; i++) {
        entries[i].first = -1;
        entries[i].second = -1;
        entries[i].value = 0;
    }
    unknown_098[2] = 0;
    unknown_098[1] = 0;
    unknown_098[0] = 0;
    value_d4c = 0;
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
