/* sym: ??0Object_00086060@@QAE@PAUNode@@HI@Z = 0x00085280 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00086060@@UAE@XZ = 0x00085410 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00086060@@UAEXXZ = 0x00085480 */
/* sym: ?func_00011C90_1@Object_00086060@@UAEXXZ = 0x000854B0 */
/* sym: ?func_00011C80@Object_00086060@@UAEXH@Z = 0x000854E0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Sphere_00017EC0 {
    Vector3 center;
    float radius;
};

struct Part_00017F60 {
    Sphere_00017EC0 sphere;
    Vector3 motion;
    int unknown_1c;
    int kind;
};

struct Mesh_00017F60 {
    Part_00017F60 *parts;
    unsigned int count;
    Sphere_00017EC0 bounds;
};

struct Item_000162A0 {
    int unknown_00[2];
    Mesh_00017F60 *mesh;
    char unknown_0c[8];
    int unknown_14;
};

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *source);
};

struct Game {
    int func_000128E0(int first, int last);
};

struct Motion_00085F80 {
    float speed;
    float lift;
    float fall;
    int unknown_0c;
    float unknown_10;
};

// What the trail constructor copies to +0x44: 0x2c bytes (width at +0x50 of the object, ...).
struct Settings_000141E0 {
    int unknown_00[11];
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
    char unknown_34[0x10];
};

void *func_00025700(unsigned int index, int first, int second, int third);
void func_00014680(Node *owner, int id, const Settings_000141E0 *settings);

extern Game *data_0022FCE0;
extern Object_00016200 data_0022FCE8;
extern Motion_00085F80 data_0020D960;
extern Mesh_00017F60 data_0020D948;
extern Settings_000141E0 data_0020D99C;
extern void *data_0020D9B4;

// Object 0x50 (table 0x1CD0C0, 0x170 bytes): a state machine whose handlers are in the table at 0x20D9C8.
struct Object_00086060 : Node {
    Object_00086060(Node *owner, int id, unsigned int flags);
    virtual ~Object_00086060();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

    int state;
    Vector3 first;
    Vector3 second;
    Vector3 third;
    Vector3 fourth;
    Vector3 velocity;
    int unknown_084;
    int unknown_088;
    int unknown_08c;
    unsigned int time;
    unsigned int delay;
    int unknown_098;
    unsigned int options;
    int trail;
    Motion_00085F80 *motion;
    char unknown_0a8[0x50];
    int unknown_0f8;
    int unknown_0fc;
    void *unknown_100;
    void *unknown_104;
    int unknown_108[17];
    Item_000162A0 item;
    char unknown_164[0xc];
};

// Makes the node with flags 0x4100: clears the state, the five vectors and the words up to +0x94, +0x98 and +0xfc
// to -1, options 0x11, the motion at 0x20D960, two values of func_00025700 (11, 0, 1, 15 and 11, 0, 3, 0), the
// block at +0x108 (its first word 0xffff), the item (0x1000, 1, a copy of the mesh at 0x20D948); keeps
// func_00025700 (11, 0, 0, 2) in 0x20D9B4 and makes its trail with an id between 0x51 and 0xd1 and the settings at
// 0x20D99C.
Object_00086060::Object_00086060(Node *owner, int id, unsigned int flags)
    : Node(owner, id, flags)
{
    this->flags = 0x4100;
    state = 0;
    memset(&first, 0, sizeof(first));
    memset(&second, 0, sizeof(second));
    memset(&third, 0, sizeof(third));
    memset(&fourth, 0, sizeof(fourth));
    memset(&velocity, 0, sizeof(velocity));
    unknown_084 = 0;
    unknown_088 = 0;
    unknown_08c = 0;
    time = 0;
    delay = 0;
    unknown_098 = -1;
    options = 0x11;
    motion = &data_0020D960;
    unknown_0f8 = 0;
    unknown_0fc = -1;
    unknown_100 = func_00025700(0xb, 0, 1, 0xf);
    unknown_104 = func_00025700(0xb, 0, 3, 0);
    memset(unknown_108, 0, sizeof(unknown_108));
    unknown_108[0] = 0xffff;
    item.mesh = data_0022FCE8.func_00019680(&data_0020D948);
    item.unknown_00[0] = 0x1000;
    item.unknown_00[1] = 1;
    item.unknown_14 = 0;
    data_0020D9B4 = func_00025700(0xb, 0, 0, 2);
    trail = data_0022FCE0->func_000128E0(0x51, 0xd1);
    func_00014680(this, trail, &data_0020D99C);
}
