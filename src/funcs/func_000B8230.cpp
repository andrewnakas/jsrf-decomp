/* sym: ??0Object_000B9960@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000B8230 */
/* sym: ??1Object_000B9960@@UAE@XZ = 0x000B8610 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000B9960@@UAEXXZ = 0x000B9960 */
/* sym: ?func_00011C90_1@Object_000B9960@@UAEXXZ = 0x000B9980 */
/* sym: ?func_00011C80@Object_000B9960@@UAEXH@Z = 0x000B86E0 */
/* sym: ?func_00011C90_2@Object_000B9960@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000B9960@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000B9960@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000B9960@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000B9960@@UAEXH@Z = 0x000B3DE0 */
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

// What func_000B9E70 reads the kind of the child to create from (at 0x28).
struct Info_000B9E70 {
    Params_000BAC60 record;
    int kind;
    int unknown_2c;
};

// An entry of table 5 (0xf0 bytes, copied to 0x228): ids in tables 2, 3 and 7 (-1 = none) and the 16 children.
struct Entry_000B8230 {
    unsigned int flags;
    int model;
    int shadow;
    int first;
    int second;
    int extra;
    char unknown_18[0x88];
    int children[16];
    Vector3 position;
    char unknown_ec[4];
};

// func_001BB410's output: a vector and a spare word.
struct Out_000B8230 {
    Vector3 vector;
    float unknown_0c;
};

struct Model_000B8230 {
    char unknown_00[8];
    struct {
        char unknown_00[0x60];
        int value;
    } *info;
    char unknown_0c[0x10];
    int flags;
};

struct Buffer_000B8230 {
    char unknown_00[0xc];
    int value;
    char unknown_10[0xc];
    int kind;
    int count;
};

struct Buffer2_000B8230 {
    char unknown_00[0x6c];
    int kind;
    int count;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0xeb (constructor func_000BB1A0, destructor func_000BAC20).
struct Object_000BAC20 {
    int func_000BAC30(Info_000B9E70 *info, int value, int unused1, int unused2);
};

struct Object_000B7840 {
    void func_000B7840(int newValue);
};

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *matrix);
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_001BB410(Vector3 *out);
void func_001BB9C0(int *angles, int unused);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD998).
struct Object_000B9960 : Node {
    Object_000B9960(Node *owner, int id, unsigned int flags, Params_000BAC60 *record);
    virtual ~Object_000B9960();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[4];
    int value_44;
    int state;
    int value_4c;
    int value_50;
    int value_54;
    int value_58;
    int value_5c;
    int set;
    int value_64;
    Model_000B8230 *model;
    void *shadow;
    Model_000B8230 *current;
    int value_74;
    int value_78;
    void *active;
    void *first;
    void *second;
    void *block;
    int value_8c;
    char unknown_090[8];
    int ids[16];
    int count;
    int value_dc;
    int alpha;
    char unknown_0e4[0xc4];
    Buffer_000B8230 *buffer;
    int bufferCount;
    char unknown_1b0[0x10];
    void *extra;
    char unknown_1c4[0x24];
    Buffer2_000B8230 *buffer2;
    int buffer2Count;
    char unknown_1f0[0x10];
    Params_000BAC60 record;
    Entry_000B8230 entry;
    unsigned int flags_318;
    Vector3 direction;
    int value_328;
    Vector3 velocity;
    int angles[3];
    Vector3 scale;
    char unknown_350[0x18];
    Vector3 value_368;
};

// Builds the object from the record: with none it unlinks itself at once. Otherwise it copies the record, looks up
// its entry in table 5 of the set (func_00025700), the entry's models in tables 2, 3 and 7 (-1 = none; no shadow
// sets bit 30 of 0x318, no model state 7), two small buffers, and has object 0xeb create the entry's 16 children
// (kind 0x17, model = the child's id) and give them this object's id (func_000B7840).
Object_000B9960::Object_000B9960(Node *owner, int id, unsigned int flags, Params_000BAC60 *record)
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
    Entry_000B8230 *entries = (Entry_000B8230 *)func_00025700(6, set, 5, 6);
    entry = entries[index];
    value_50 = 1;
    value_4c = 0;
    value_54 = 1;
    model = 0;
    shadow = 0;
    current = 0;
    value_74 = 0;
    buffer = 0;
    buffer2 = 0;
    value_78 = -1;
    first = 0;
    second = 0;
    block = 0;
    value_58 = -1;
    value_5c = 0;
    func_001BAA00();
    func_001BAAA0(&this->record.position.x);
    func_001BAC50(this->record.angles, 0);
    func_001BAAA0(&entry.position.x);
    Out_000B8230 out;
    func_001BB410(&out.vector);
    func_001BB9C0(angles, 0);
    func_001BAA50();
    direction.x = out.vector.x;
    direction.y = out.vector.y;
    direction.z = out.vector.z;
    velocity.x = 0;
    velocity.y = 0;
    velocity.z = 0;
    scale.x = this->record.scale.x;
    scale.y = this->record.scale.y;
    scale.z = this->record.scale.z;
    value_368.x = 0;
    value_368.y = 0;
    value_368.z = 0;
    value_328 = 0;
    state = 0;
    value_44 = 0;
    flags_318 = 0;
    alpha = 0xff;
    value_dc = 0;
    count = 0;
    value_64 = -1;
    model = (Model_000B8230 *)func_00025700(6, set, 2, entry.model);
    if (entry.shadow != -1) {
        shadow = func_00025700(6, set, 2, entry.shadow);
    } else {
        flags_318 |= 0x40000000;
    }
    current = model;
    if (current) {
        value_dc = current->info->value;
    } else {
        state = 7;
    }
    value_8c = 0;
    if (entry.first != -1) {
        first = func_00025700(6, set, 3, entry.first);
    }
    active = first;
    if (entry.second != -1) {
        second = func_00025700(6, set, 3, entry.second);
    }
    if (entry.first != -1 && entry.second != -1) {
        block = (void *)func_0005E790(first, current->flags);
    }
    buffer = (Buffer_000B8230 *)operator new(sizeof(Buffer_000B8230));
    buffer->kind = 3;
    buffer->count = 0;
    buffer->value = value_dc;
    bufferCount = 1;
    if (entry.extra != -1) {
        extra = func_00025700(6, set, 7, entry.extra);
        buffer2 = (Buffer2_000B8230 *)operator new(sizeof(Buffer2_000B8230));
        buffer2->kind = 3;
        buffer2->count = 0;
        buffer2Count = 1;
    }
    for (int i = 0; i < 16; i++) {
        ids[i] = 0;
    }
    Object_000BAC20 *manager = (Object_000BAC20 *)data_0022FCE0->func_000128C0(0xeb);
    if (manager) {
        Info_000B9E70 info;
        info.record = *record;
        info.kind = 0x17;
        for (int i = 0; i < 16; i++) {
            if (entry.children[i] != -1) {
                info.record.model = entry.children[i];
                ids[i] = manager->func_000BAC30(&info, 0, -1, -1);
                Object_000B7840 *node = (Object_000B7840 *)data_0022FCE0->func_000128C0(ids[i]);
                node->func_000B7840(this->id);
                count++;
            }
        }
    }
}
