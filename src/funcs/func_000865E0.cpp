/* sym: ?func_00011C80@Object_00086960@@UAEXH@Z = 0x000865E0 */
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *matrix);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void func_00047470();
    virtual void slot3();
    virtual void func_00047540();
    virtual void func_00047690(int first, int second);
    void func_00047970(void *data, int argument);
};

struct Holder_000854E0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(Object_00047470 *object);
};

// The family of tables at 0x1CD120, 0x1CD170, 0x1CD1C0 and 0x1CD210 (constructor 0x862B0, destructor 0x86460).
struct Object_00086960 : Node {
    virtual void func_00011C80(int argument);
    virtual void func_00086940();
    virtual void func_00086960();
    virtual void func_000866F0(int argument);

    Vector3 start;
    char unknown_050[0x38];
    int angleX;
    int angleY;
    int angleZ;
    char unknown_094[4];
    unsigned int state;
    char unknown_09c[0x14];
    Object_00047470 *model;
    char unknown_b4[4];
    Holder_000854E0 *holder;
};

// Slot 3 of the tables at 0x1CD120, 0x1CD170, 0x1CD1C0 and 0x1CD210: in states 0 and 1, under the start position
// (func_001BAAA0): pass 7 stores the depth of the moved origin, pass 8 draws the model at +0xb0 (slot 5) turned by the
// angles at +0x88 and runs slot 18 with the pass, passes 17 and 18 set the model up (func_00047970) and hand it to
// slot 6 of +0xb8.
void Object_00086960::func_00011C80(int argument)
{
    if (state <= 1) {
        func_001BAAA0(&start.x);
        switch (argument) {
        case 7: {
            Vector3 origin;
            func_001BAB20(&origin, 0);
            depth = origin.z;
            break;
        }
        case 8:
            func_001BA9C0();
            func_001BB330(angleY);
            func_001BB2E0(angleX);
            func_001BB380(angleZ);
            model->func_00047690(0, 0);
            func_001BAA50();
            func_000866F0(argument);
            break;
        case 17:
        case 18:
            func_001BB330(angleY);
            func_001BB2E0(angleX);
            func_001BB380(angleZ);
            model->func_00047970(0, 0);
            holder->slot6(model);
            break;
        }
    }
}
