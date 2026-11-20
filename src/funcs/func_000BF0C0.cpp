/* sym: ??0Object_000BF340@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000BF0C0 */
/* sym: ??1Object_000BF340@@UAE@XZ = 0x000BF340 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000BF340@@UAEXXZ = 0x000BF3B0 */
/* sym: ?func_00011C90_1@Object_000BF340@@UAEXXZ = 0x000BFA20 */
/* sym: ?func_00011C80@Object_000BF340@@UAEXH@Z = 0x000BFD70 */
/* sym: ?func_00011C90_2@Object_000BF340@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000BF340@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000BF340@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000BF340@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000BF340@@UAEXH@Z = 0x000B3DE0 */
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

struct Vector3 {
    float x;
    float y;
    float z;
};

// Where func_000BAC60 places the object: position, angles, scale and a model code (bank << 10 | index).
struct Params_000BAC60 {
    Vector3 position;
    int angles[3];
    Vector3 scale;
    unsigned int model;
};

// An entry of table 14 (0x30 bytes, copied to 0x84): ids in tables 2 and 3 (-1 = none).
struct Entry_000BF0C0 {
    int model;
    int first;
    char unknown_08[0x10];
    unsigned int flags;
    char unknown_1c[0xc];
    int value;
    char unknown_2c[4];
};

struct Model_000BF0C0 {
    char unknown_00[8];
    struct {
        char unknown_00[0x60];
        int value;
    } *info;
};

struct Motion_000BF0C0 {
    short unknown_00;
    short length;
};

struct Buffer_000BF0C0 {
    char unknown_00[0xc];
    int value;
    char unknown_10[0xc];
    int kind;
    int count;
};

// The 15-bit pseudo-random generator.
struct Object_00066980 {
    float func_00066950();
};

extern Object_00066980 data_00257C80;

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CDBA0).
struct Object_000BF340 : Node {
    Object_000BF340(Node *owner, int id, unsigned int flags, Params_000BAC60 *record);
    virtual ~Object_000BF340();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[4];
    unsigned int flags_44;
    int value_48;
    int value_4c;
    int value_50;
    int value_54;
    int set;
    Params_000BAC60 record;
    Entry_000BF0C0 entry;
    int value_b4;
    int value_b8;
    Model_000BF0C0 *model;
    Motion_000BF0C0 *active;
    Motion_000BF0C0 *first;
    void *block;
    float time;
    int value_d0;
    int value_d4;
    char unknown_0d8[8];
    Vector3 position;
    int angles[3];
    Vector3 scale;
    char unknown_104[0x18];
    Vector3 value_11c;
    int value_128;
    int alpha;
    char unknown_130[0xc0];
    Buffer_000BF0C0 *buffer;
    int bufferCount;
    char unknown_1f8[0x10];
};

// Builds the object from the record: with none, or no model for its entry, it unlinks itself. Otherwise it copies
// the record, looks up its entry in table 14 of the set (func_00025700), the entry's model in table 2 (its info's
// value at 0x128) and motion in table 3 (no motion sets bit 30 of 0x44; the top bit of the entry's flags at 0x18
// starts the motion at a random time), and makes a small buffer for the entry's value.
Object_000BF340::Object_000BF340(Node *owner, int id, unsigned int flags, Params_000BAC60 *record)
    : Node(owner, id, flags)
{
    if (record == 0) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    this->record = *record;
    unsigned int group = record->model >> 10;
    if (group < 5) {
        set = group + 1;
    } else {
        set = 0;
    }
    unsigned int index = record->model - (group << 10);
    Entry_000BF0C0 *entries = (Entry_000BF0C0 *)func_00025700(6, set, 5, 0xe);
    entry = entries[index];
    value_50 = 0;
    value_54 = 1;
    model = 0;
    active = 0;
    first = 0;
    block = 0;
    buffer = 0;
    value_b4 = -1;
    value_b8 = 0;
    time = 0;
    value_d0 = 0;
    value_d4 = 0;
    for (int i = 0; i < 3; i++) {
        angles[i] = 0;
        ((float *)&scale)[i] = 1.0f;
    }
    position.x = 0;
    position.y = 0;
    position.z = 0;
    value_11c.x = 0;
    value_11c.y = 0;
    value_11c.z = 0;
    value_4c = 0;
    value_48 = 0;
    flags_44 = 0;
    alpha = 0xff;
    value_128 = 0;
    model = (Model_000BF0C0 *)func_00025700(6, set, 2, entry.model);
    if (model) {
        value_128 = model->info->value;
        if (entry.first != -1) {
            first = (Motion_000BF0C0 *)func_00025700(6, set, 3, entry.first);
            if (entry.flags & 0x80000000) {
                float random = data_00257C80.func_00066950();
                time = first->length * random;
            }
            block = (void *)func_0005E790(first, 1);
            active = first;
        } else {
            flags_44 |= 0x40000000;
        }
        buffer = (Buffer_000BF0C0 *)operator new(sizeof(Buffer_000BF0C0));
        buffer->kind = 3;
        buffer->count = 0;
        buffer->value = entry.value;
        bufferCount = 1;
        flags_44 |= 0x10000000;
    } else {
        func_00011BE0(this);
        func_00011C20(child);
    }
}
