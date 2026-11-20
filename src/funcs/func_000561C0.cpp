/* sym: ??0Object_000511B0@@QAE@PAUNode@@HIPAX1@Z = 0x000561C0 */
/* sym: ??1Object_000511B0@@UAE@XZ = 0x000511B0 */
/* sym: ?func_00011C90_2@Object_000511B0@@UAEXXZ = 0x00056340 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??0Object_000800D0@@QAE@HPAMPAHH@Z = 0x00084010 */
/* sym: ??0Object_000512E0@@QAE@PAUNode@@HIPBUVector3@@1PBH@Z = 0x00051210 */
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

struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Game {
    int func_000127E0(int id);
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// The class whose table at 0x1CD088 holds only its scalar deleting destructor 0x84160 (constructor 0x84010); its
// methods 0x800D0, 0x80110, 0x80150, 0x801F0 and 0x841C0 work on the game object named by the id at +8.
struct Object_000800D0 {
    Object_000800D0(int value, float *position, int *rotation, int unused);
    virtual ~Object_000800D0();

    void *block;
    int id;
};

// The node 0x561C0 makes beside itself (0x8c bytes, constructor 0x51210).
struct Object_000512E0 : Node {
    Object_000512E0(Node *owner, int id, unsigned int flags, const Vector3 *start, const Vector3 *end,
                    const int *angles);
    virtual ~Object_000512E0();

    char unknown_44[0x48];
};

// The class whose table is at 0x1CADE8 (constructor 0x561C0, destructor 0x511B0; 0x58 bytes): overrides slot 4.
struct Object_000511B0 : Node {
    Object_000511B0(Node *owner, int id, unsigned int flags, void *first, void *second);
    virtual ~Object_000511B0();
    virtual void func_00011C90_2();

    int unknown_44;
    Object_000800D0 *part;
    int handle;
    Vector3 *position;
    int *rotation;
};

// Made by 0x568F0 with a stage record's position and angles: keeps them at +0x50 / +0x54, makes the part at +0x48
// from them (Object_000800D0 with the game's value 0xd), takes a free id in 0xd2-0xe6 (+0x4c) and makes an
// Object_000512E0 under it from the point 52.78 above the position (turned by the angles) to the position.
Object_000511B0::Object_000511B0(Node *owner, int id, unsigned int flags, void *first, void *second)
    : Node(owner, id, flags)
{
    unknown_44 = 0;
    position = (Vector3 *)first;
    rotation = (int *)second;
    handle = -1;
    part = new Object_000800D0(data_0022FCE0->func_000127E0(0xd), (float *)position, rotation, 0);
    handle = data_0022FCE0->func_000128E0(0xd2, 0xe6);
    Vector3 offset = {0.0f, 52.777779f, 0.0f};
    func_001BAA00();
    func_001BAAA0((float *)position);
    func_001BB2E0(((int *)second)[0]);
    func_001BB330(((int *)second)[1]);
    func_001BB380(((int *)second)[2]);
    Vector3 top;
    func_001BAB20(&top, &offset);
    func_001BAA50();
    new Object_000512E0(this, handle, 0, &top, position, (int *)second);
}
