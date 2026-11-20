/* sym: ??0Object_00113700@@QAE@PAUNode@@HI@Z = 0x00113A30 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??1Object_00113700@@UAE@XZ = 0x00113700 */
/* sym: ??1Object_00012170@@UAE@XZ = 0x000121D0 */
/* sym: ?func_00011C90@Object_00113700@@UAEXXZ = 0x00113CD0 */
/* sym: ?func_00011C90_2@Object_00113700@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00113700@@UAEXXZ = 0x00113710 */
/* sym: ?func_00011C80_2@Object_00113700@@UAEXH@Z = 0x001137B0 */
/* sym: ?func_00011C90_6@Object_00113700@@UAEXXZ = 0x000AECC0 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

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
    char unknown_34[0x60];
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A node with no virtual functions of its own (table 0x1C43D8). Its destructor (0x121D0) is what this
// constructor's unwind code calls.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);
    virtual ~Object_00012170();

    int unknown_94;
};

struct Sprite_00113A30 {
    char unknown_00[0x24];
    unsigned int flags;
};

struct Vector3_00113A30 {
    float x;
    float y;
    float z;
};

struct Menu_00113A30 {
    char unknown_000[0x154];
    int enabled[23];
};

extern Vector3_00113A30 data_0021BD8C;
extern Vector3_00113A30 data_0021BEAC;
extern Vector3_00113A30 data_0021BFCC;

void *func_00025700(unsigned int index, int first, int second, int third);

// The class whose table is at 0x1D2AE8, built on Object_00012170.
struct Object_00113700 : Object_00012170 {
    Object_00113700(Node *owner, int id, unsigned int flags);
    virtual ~Object_00113700();
    virtual void func_00011C90();
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();

    Sprite_00113A30 *left[23];
    Sprite_00113A30 *right[23];
    float phase;
    float speed;
    char unknown_158[0x80];
    Vector3_00113A30 position_1d8;
    int angles[3];
    Vector3_00113A30 vector_1f0;
    float offset[3];
    int value_208;
    int value_20c;
};

// Unless menu object 0x1167 is missing (then the node unlinks itself), creates sprites 0xA7 + i and 0xBE + i for
// each of the menu's 23 enabled entries and sets the starting position, angles and offsets.
Object_00113700::Object_00113700(Node *owner, int id, unsigned int flags) : Object_00012170(owner, id, flags)
{
    Menu_00113A30 *menu = (Menu_00113A30 *)data_0022FCE0->func_000128C0(0x1167);
    if (menu == 0) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    for (int i = 0; i < 23; i++) {
        left[i] = 0;
        right[i] = 0;
    }
    position_1d8.x = data_0021BEAC.x;
    position_1d8.y = data_0021BEAC.y;
    position_1d8.z = data_0021BEAC.z;
    vector_1f0.x = data_0021BD8C.x;
    vector_1f0.y = data_0021BD8C.y;
    vector_1f0.z = data_0021BD8C.z;
    angles[0] = (int)(data_0021BFCC.x * 182.04445f);
    angles[1] = (int)(data_0021BFCC.y * 182.04445f);
    angles[2] = (int)(data_0021BFCC.z * 182.04445f);
    value_208 = 0;
    value_20c = 0;
    phase = 0.0f;
    offset[0] = -32.0f;
    offset[1] = 24.0f;
    offset[2] = 42.0f;
    speed = 1.0f;
    for (int j = 0; j < 23; j++) {
        if (menu->enabled[j] == 1) {
            left[j] = (Sprite_00113A30 *)func_00025700(10, 0, 1, 0xa7 + j);
            if (left[j]) {
                left[j]->flags &= ~1;
                left[j]->flags |= 1;
            }
            right[j] = (Sprite_00113A30 *)func_00025700(10, 0, 1, 0xbe + j);
            if (right[j]) {
                right[j]->flags &= ~1;
                right[j]->flags |= 1;
            }
        }
    }
    sortKey = 0x15;
}
