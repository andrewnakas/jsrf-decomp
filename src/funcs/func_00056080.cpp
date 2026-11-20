/* sym: ??0Object_00050EC0@@QAE@PAUNode@@HIPAX1@Z = 0x00056080 */
/* sym: ??1Object_00050EC0@@UAE@XZ = 0x00050EC0 */
/* sym: ?func_00011C90_2@Object_00050EC0@@UAEXXZ = 0x00050ED0 */
/* sym: ?func_00011C80_1@Object_00050EC0@@UAEXH@Z = 0x00050F00 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??0Object_00050FE0@@QAE@PAUNode@@HI@Z = 0x00050F60 */
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
void func_001BB650(float scale);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void *func_00025700(unsigned int kind, int first, int second, int third);

// The node 0x56080 makes beside itself (0xa0 bytes).
struct Object_00050FE0 : Node {
    Object_00050FE0(Node *owner, int id, unsigned int flags);

    char unknown_44[0x5c];
};

// The class whose table is at 0x1CAD60 (constructor 0x56080, destructor 0x50EC0; 0x74 bytes): overrides slots 4
// and 6 of Node.
struct Object_00050EC0 : Node {
    Object_00050EC0(Node *owner, int id, unsigned int flags, void *first, void *second);
    virtual ~Object_00050EC0();
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);

    float unknown_44;
    void *unknown_48;
    Vector3 origin;
    int angles[3];
    int unknown_64;
    int unknown_68;
    int unknown_6c;
    int unknown_70;
};

// Made by 0x56830 with a stage record's position and angles: flag 4, the origin transformed by them at scale 50,
// the angles kept at +0x58, func_00025700(0xb, 0, 1, 0) at +0x48, and an Object_00050FE0 child (id -1, flags 1).
Object_00050EC0::Object_00050EC0(Node *owner, int id, unsigned int flags, void *first, void *second)
    : Node(owner, id, flags)
{
    int *rotation = (int *)second;
    this->flags |= 4;
    func_001BAA00();
    func_001BAAA0((float *)first);
    func_001BB2E0(rotation[0]);
    func_001BB330(rotation[1]);
    func_001BB380(rotation[2]);
    func_001BB650(50.0f);
    func_001BAB20(&origin, 0);
    func_001BAA50();
    unknown_70 = 0;
    unknown_44 = 0.23148148f;
    angles[0] = rotation[0];
    angles[1] = rotation[1];
    angles[2] = rotation[2];
    unknown_64 = 0;
    unknown_68 = 0;
    unknown_6c = 0;
    unknown_48 = func_00025700(0xb, 0, 1, 0);
    new Object_00050FE0(this, -1, 1);
}
