/* sym: ?func_00011C90_2@Object_000512E0@@UAEXXZ = 0x000512F0 */
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

    Node *func_00011BD0();
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Model_00050CC0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Link_000512F0 {
    char unknown_00[8];
    int id;
};

struct Parent_000512F0 {
    char unknown_00[0x48];
    Link_000512F0 *link;
};

struct Owner_000512F0 {
    char unknown_000[0x8d4];
    int targetId;
};

struct Target_000512F0 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0x18];
    int angles[3];
};

void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

// The class whose table is at 0x1CAE28 (constructor 0x51210). Overrides slots 4 and 6 of Node.
struct Object_000512E0 : Node {
    virtual ~Object_000512E0();
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);

    Vector3 start;
    Vector3 end;
    float time;
    float duration;
    int spin[3];
    int angles[3];
    Model_00050CC0 *model;
    Vector3 position;
};

// Slot 4: flies from the start to the end point, or to a point in front of the target of the parent's owner when
// there is one, spinning on the way; kills itself and its children once the time runs out.
void Object_000512E0::func_00011C90_2()
{
    Parent_000512F0 *parent = (Parent_000512F0 *)func_00011BD0();
    Vector3 point = end;
    Owner_000512F0 *owner = (Owner_000512F0 *)data_0022FCE0->func_000128C0(parent->link->id);
    if (owner) {
        Target_000512F0 *target = (Target_000512F0 *)data_0022FCE0->func_000128C0(owner->targetId);
        if (target) {
            func_001BAAA0(&target->position.x);
            func_001BB2E0(target->angles[0]);
            func_001BB380(target->angles[2]);
            func_001BB330(target->angles[1] + 0x8000);
            Vector3 offset;
            offset.x = 0.5f;
            offset.y = 17.0f;
            offset.z = 0.0f;
            func_001BAB20(&point, &offset);
        }
    }
    float rate = 1.0f / duration;
    spin[0] += 0xe38;
    position.x = time * (rate * (point.x - start.x)) + start.x;
    position.y = time * (rate * (point.y - start.y)) + start.y;
    position.z = time * (rate * (point.z - start.z)) + start.z;
    time += 1.0f;
    if (time >= duration) {
        func_00011BE0(this);
        func_00011C20(child);
    }
}
