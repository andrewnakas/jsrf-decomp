/* sym: ??0Object_000BB710@@QAE@PAUNode@@HIPAUParams_000BAC60@@HHH@Z = 0x000BB4C0 */
/* sym: ??1Object_000BB710@@UAE@XZ = 0x000BB710 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000BB710@@UAEXXZ = 0x000BB7B0 */
/* sym: ?func_00011C80@Object_000BB710@@UAEXH@Z = 0x000BBA40 */
/* sym: ?func_00011C90_2@Object_000BB710@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_3@Object_000BB710@@UAEXXZ = 0x000AEE80 */
/* sym: ?func_00011C80_1@Object_000BB710@@UAEXH@Z = 0x000AE660 */
/* sym: ?func_00011C80_3@Object_000BB710@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000BB710@@UAEXH@Z = 0x000B3DE0 */
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

// An entry of table 7 of bank 7 (0x20 bytes, copied to 0x70): the model's id in tables 2 and 5, its scale and size.
struct Entry_000BB4C0 {
    int unknown_00;
    int model;
    char unknown_08[0xc];
    float scale;
    float size;
    int unknown_1c;
};

struct Model_000BB4C0 {
    char unknown_00[8];
    struct {
        char unknown_00[0x60];
        float scale;
    } *info;
    char unknown_0c[4];
    int kind;
};

struct Buffer_000BB4C0 {
    char unknown_00[0xc];
    float size;
    char unknown_10[0xc];
    int kind;
    int count;
};

struct Object_00016200 {
    int func_0001D950(void *data, int id);
};

extern Object_00016200 data_0022FCE8;

void *func_00025700(unsigned int index, int first, int second, int third);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CDA60).
struct Object_000BB710 : Node {
    Object_000BB710(Node *owner, int id, unsigned int flags, Params_000BAC60 *record, int value, int first,
                    int second);
    virtual ~Object_000BB710();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_040[4];
    unsigned int flags_44;
    Params_000BAC60 record;
    Entry_000BB4C0 entry;
    int value_90;
    char unknown_094[4];
    int value_98;
    Model_000BB4C0 *model;
    int value_a0;
    int value_a4;
    int value_a8;
    char unknown_0ac[0x20];
    Vector3 position;
    int angles[3];
    Vector3 scale;
    char unknown_0f0[0x18];
    Vector3 value_108;
    int alpha;
    char unknown_118[0x48];
    int value_160;
    int value_164;
    float scale_168;
    int value_16c;
    char unknown_170[0x24];
    Buffer_000BB4C0 *buffer;
    int bufferCount;
    char unknown_19c[0x10];
    void *mesh;
    int handle;
    int handle_1b4;
    char unknown_1b8[4];
};

// Builds the object from the record (the last two arguments are not used): keeps the value at 0x16c; with no
// record, or no model for its entry (table 7 of bank 7), it unlinks itself. Otherwise the model is marked kind 5, the
// scale is the entry's or else the model info's, the entry's mesh in table 5 (if any) is registered with
// data_0022FCE8 (func_0001D950, handles at 0x1b0 and 0x1b4) and a small buffer holds the entry's size scaled.
Object_000BB710::Object_000BB710(Node *owner, int id, unsigned int flags, Params_000BAC60 *record, int value,
                                 int first, int second)
    : Node(owner, id, flags)
{
    value_16c = value;
    model = 0;
    value_a0 = 0;
    mesh = 0;
    buffer = 0;
    value_a8 = 0;
    value_90 = -1;
    value_a4 = 0;
    if (record == 0) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    this->record = *record;
    unsigned int group = record->model >> 10;
    int set;
    if (group < 5) {
        set = group + 1;
    } else {
        set = 0;
    }
    unsigned int index = record->model - (group << 10);
    Entry_000BB4C0 *entries = (Entry_000BB4C0 *)func_00025700(7, set, 7, 2);
    entry = entries[index];
    for (int i = 0; i < 3; i++) {
        angles[i] = 0;
        ((float *)&scale)[i] = 1.0f;
    }
    position.x = 0;
    position.y = 0;
    position.z = 0;
    value_108.x = 0;
    value_108.y = 0;
    value_108.z = 0;
    value_164 = 0;
    value_160 = 0;
    flags_44 = 0;
    alpha = 0xff;
    value_98 = -1;
    model = (Model_000BB4C0 *)func_00025700(7, set, 2, entry.model);
    if (model) {
        model->kind = 5;
        if (entry.scale == 0.0f) {
            scale_168 = model->info->scale;
        } else {
            scale_168 = entry.scale;
        }
        mesh = func_00025700(7, set, 5, entry.model);
        if (mesh) {
            handle_1b4 = handle = data_0022FCE8.func_0001D950(mesh, -1);
        }
        buffer = (Buffer_000BB4C0 *)operator new(sizeof(Buffer_000BB4C0));
        buffer->kind = 3;
        buffer->count = 0;
        buffer->size = entry.size * scale_168;
        bufferCount = 1;
    } else {
        func_00011BE0(this);
        func_00011C20(child);
    }
}
