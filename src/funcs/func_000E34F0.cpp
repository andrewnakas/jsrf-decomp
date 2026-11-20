/* sym: ??0Object_000E34F0@@QAE@PAUNode@@HI@Z = 0x000E34F0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??1Object_000E34F0@@UAE@XZ = 0x000E35A0 */
/* sym: ?func_00011C90@Object_000E34F0@@UAEXXZ = 0x000E3600 */
/* sym: ?func_00011C80@Object_000E34F0@@UAEXH@Z = 0x000E3640 */
/* sym: ?func_00011C80_3@Object_000E34F0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000E34F0@@UAEXH@Z = 0x000B3DE0 */
struct Motion_0005F060;
struct Vector3;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

extern float data_002188D8[3];

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
void func_00060BA0(int key);
void __fastcall func_001BAAA0(float *vector);

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

// What slot 5 of the four models takes.
struct Model_000E34F0 {
    virtual void func_00();
    virtual void func_04();
    virtual void func_08();
    virtual void func_0C();
    virtual void func_10();
    virtual void func_14(Motion_0005F060 *motion, float time);
};

struct Resource_000E34F0 {
    Model_000E34F0 **models;
    char unknown_04[0x14];
    Motion_0005F060 **motions;
};

// The class whose table is at 0x1CECD8: four models, each playing its motion; slots 12, 15 hold folded thunks.
struct Object_000E34F0 : Node {
    Object_000E34F0(Node *owner, int id, unsigned int flags);
    virtual ~Object_000E34F0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    Model_000E34F0 **models;
    Motion_0005F060 **motions;
    float times[4];
    int sound;
};

// Takes the models and motions of resource 5/0x14, clears the four times and starts sound 0x82 on object 0xe8.
Object_000E34F0::Object_000E34F0(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    Resource_000E34F0 *resource = (Resource_000E34F0 *)func_00025700(5, 0x14, 0, 0);
    models = resource->models;
    motions = resource->motions;
    for (unsigned int i = 0; i < 4; i++) {
        times[i] = 0.0f;
    }
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        sound = object->func_000651E0(0x82, data_002188D8, 0);
    }
}
