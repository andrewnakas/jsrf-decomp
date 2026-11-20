/* sym: ??0Object_00107FE0@@QAE@PAUNode@@HIH@Z = 0x001074B0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00107FE0@@UAE@XZ = 0x00107620 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00107FE0@@UAEXXZ = 0x00108840 */
/* sym: ?func_00011C80@Object_00107FE0@@UAEXH@Z = 0x00107680 */
/* sym: ?func_00011C90_2@Object_00107FE0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00107FE0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_00107FE0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_00107FE0@@UAEXXZ = 0x000AECC0 */
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern int data_00251F20;

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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

// What object 9 keeps at 0x1040.
struct Mode_00107FE0 {
    char unknown_00[0x1c];
    int value_1c;
};

// Object 9 (only the field used here).
struct Object9_00107FE0 {
    char unknown_0000[0x1040];
    Mode_00107FE0 *mode;
};

// One of the 32 entries of object 0xb at 0x50 (0x28 bytes each).
struct Entry_00107FE0 {
    int value;
    char unknown_04[8];
    int id;
    char unknown_10[0x18];
};

// Object 0xb (only the entries used here).
struct ObjectB_00107FE0 {
    char unknown_00[0x50];
    Entry_00107FE0 entries[32];
};

// The player under the owner object (only the field used here).
struct Player_00107FE0 {
    char unknown_000[0xc9c];
    int value_c9c;
};

// An entry of the list at 0xa4: the object with that id was made for (kind, value).
struct Entry_00107D10 {
    int kind;
    int id;
    int value;
    int unknown_c;
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020, destructor func_00107620).
struct Object_00107FE0 : Node {
    Object_00107FE0(Node *owner, int id, unsigned int flags, int owner_id);
    virtual ~Object_00107FE0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    char unknown_0040[4];
    int ids[24];
    Entry_00107D10 entries[16];
    char unknown_01a4[0x1500];
    int unknown_16a4;
    int unknown_16a8;
    unsigned int mask;
    int unknown_16b0;
    int unknown_16b4;
    int ownerId;
    int value_16bc;
    int value_16c0;
    char unknown_16c4[0x2c];
    int screen;
    int unknown_16f4;
    int unknown_16f8;
    int unknown_16fc;
    unsigned int state;
    int unknown_1704;
};

// Keeps the owner's id, sort key 0x15, every id at 0x44 and every list entry unset; the value at 0x16bc is
// data_00251F20, or (when object 9's mode is 1) that of object 0xb's entry for the owner; the value at 0x16c0 is
// that of the player under the owner object, or -1.
Object_00107FE0::Object_00107FE0(Node *owner, int id, unsigned int flags, int owner_id) : Node(owner, id, flags)
{
    ownerId = owner_id;
    sortKey = 0x15;
    mask = 0;
    unknown_16b0 = 0;
    unknown_16b4 = 0;
    state = 0;
    unknown_1704 = 0;
    unknown_16f4 = -1;
    screen = -1;
    unknown_16a8 = -1;
    unknown_16a4 = 0;
    unknown_16f8 = 0;
    unknown_16fc = 0;
    for (int k = 0; k < 24; k++) {
        ids[k] = -1;
    }
    for (int i = 0; i < 16; i++) {
        entries[i].id = -1;
        entries[i].value = -1;
    }
    value_16bc = data_00251F20;
    Object9_00107FE0 *object9 = (Object9_00107FE0 *)data_0022FCE0->func_000128C0(9);
    if (object9 && object9->mode->value_1c == 1) {
        ObjectB_00107FE0 *objectB = (ObjectB_00107FE0 *)data_0022FCE0->func_000128C0(0xb);
        if (objectB) {
            for (int j = 0; j < 32; j++) {
                if (objectB->entries[j].id == ownerId) {
                    value_16bc = objectB->entries[j].value;
                    break;
                }
            }
        }
    }
    value_16c0 = -1;
    Node *ownerNode = (Node *)data_0022FCE0->func_000128C0(ownerId);
    if (ownerNode && ownerNode->parent) {
        value_16c0 = ((Player_00107FE0 *)ownerNode->parent)->value_c9c;
    }
}
