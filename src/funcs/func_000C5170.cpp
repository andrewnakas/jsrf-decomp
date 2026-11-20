/* sym: ?func_00011C80@Object_000C4CF0@@UAEXH@Z = 0x000C5170 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);

struct Node {
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

void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB380(int angle);

// The child of Node whose table is at 0x1CDE60 (constructor func_000C4CF0, destructor func_000C4E50): it
// overrides slots 1, 2, 3, 12 and 15 and adds three empty slots, 16 to 18.
struct Object_000C4CF0 : Node {
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);
    virtual void func_00011C90_10();
    virtual void func_00011C90_11();
    virtual void func_00011C90_12();

    char unknown_040[4];
    Vector3 position;
    char unknown_050[0x24];
    int pitch;
    int angle;
    char unknown_07c[4];
    int roll;
};

// Slot 3, the message handler: loads the matrix at the position at 0x44 (func_001BAAA0); on 0xc takes the depth from
// the z of its origin (func_001BAB20); otherwise turns it by the angle at 0x78 + 0x8000, the pitch at 0x74 and the
// roll at 0x80 and runs slot 18.
void Object_000C4CF0::func_00011C80(int argument)
{
    func_001BAAA0(&position.x);
    if (argument == 0xc) {
        Vector3 point;
        func_001BAB20(&point, 0);
        depth = point.z;
        return;
    }
    func_001BB330(angle + 0x8000);
    func_001BB2E0(pitch);
    func_001BB380(roll);
    func_00011C90_12();
}
