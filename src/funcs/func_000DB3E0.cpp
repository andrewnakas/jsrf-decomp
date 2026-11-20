/* sym: ??0Object_000DB3E0@@QAE@PAUNode@@HIPAUEntry_000DB3E0@@@Z = 0x000DB3E0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_000DB3E0@@UAE@XZ = 0x000DB520 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000DB3E0@@UAEXXZ = 0x000DB580 */
/* sym: ?func_00011C80@Object_000DB3E0@@UAEXH@Z = 0x000DB5B0 */
/* sym: ?func_00011C80_3@Object_000DB3E0@@UAEXH@Z = 0x000DB690 */
/* sym: ?func_00011C80_4@Object_000DB3E0@@UAEXH@Z = 0x000B3DE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles {
    int x;
    int y;
    int z;
};

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

struct Item_00017940;

struct Object_00016200 {
    int func_0001D950(void *source, int id);
    void func_000178D0(Item_00017940 *item);
};

extern Object_00016200 data_0022FCE8;

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int index);
};

extern Object_00046670 data_001F93C8;

struct Object_00066980 {
    float func_00066950();
};

// The object at data_00257CE4: a random source at 0x78.
struct Object_000C1270 {
    char unknown_00[0x78];
    Object_00066980 *random;
};

extern Object_000C1270 *data_00257CE4;

void *func_00025700(unsigned int index, int first, int second, int third);
double func_0017C61D(double value);
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int order);

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

// What func_000DB3E0 takes: a position and angles.
struct Entry_000DB3E0 {
    Vector3 position;
    Angles angles;
};

struct Model_000DB3E0 {
    char unknown_00[0x44];
    int key;
};

struct Resource_000DB3E0 {
    Model_000DB3E0 **models;
    char unknown_04[0x14];
    Motion_0005F060 **motions;
    char unknown_1c[4];
    void **sources;
};

// The class whose table is at 0x1CE740: overrides slots 1, 3, 12 of Node; slots 15 hold folded thunks.
struct Object_000DB3E0 : Node {
    Object_000DB3E0(Node *owner, int id, unsigned int flags, Entry_000DB3E0 *entry);
    virtual ~Object_000DB3E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_40[4];
    Vector3 position;
    Angles angles;
    char unknown_5c[4];
    Model_000DB3E0 *model_60;
    Model_000DB3E0 *model_64;
    Model_000DB3E0 *model_68;
    float height;
    Motion_0005F060 *motion;
    float time;
    Item_00017940 *item;
};

// Takes the position and angles, models 1-3 and motion 1 of resource 5/0x11 (model 1 gets the key 0x299D7657 at
// 0x44), a random whole frame of the motion to start at, a handle for source 1 and the height data_001F93C8 gives
// at the position.
Object_000DB3E0::Object_000DB3E0(Node *owner, int id, unsigned int flags, Entry_000DB3E0 *entry)
    : Node(owner, id, flags)
{
    position = entry->position;
    angles = entry->angles;
    Resource_000DB3E0 *resource = (Resource_000DB3E0 *)func_00025700(5, 0x11, 0, 0);
    model_60 = resource->models[1];
    model_64 = resource->models[2];
    model_68 = resource->models[3];
    model_60->key = 0x299d7657;
    motion = resource->motions[1];
    time = (float)func_0017C61D(data_00257CE4->random->func_00066950() * motion->frames);
    func_001BA9C0();
    func_001BAAA0(&position.x);
    func_001BAC50(&angles.x, 0);
    item = (Item_00017940 *)data_0022FCE8.func_0001D950(resource->sources[1], -1);
    func_001BAA50();
    height = data_001F93C8.func_000466C0(&position, -1);
}
