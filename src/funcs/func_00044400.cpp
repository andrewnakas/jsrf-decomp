/* sym: ?func_00011C80@Object_000448B0@@UAEXH@Z = 0x00044400 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

void func_001BA9C0();
void __fastcall func_001BAAA0(float *vector);
void func_001BAA50();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Object_0006A960 {
    int func_0006AC10(int index);
};

extern Object_0006A960 data_0020C6C0;

// A model: slot 5 draws it in a pose of a motion; its alpha at +0x58 and a value at +0x5c.
struct Model_00044400 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(Motion_0005F060 *motion, float time);

    char unknown_04[0x54];
    float alpha;
    float unknown_5c;
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

// The node class whose table is at 0x1CA748 (constructor 0x44250, destructor 0x448B0): overrides slot 3.
struct Object_000448B0 : Node {
    virtual void func_00011C80(int argument);
    int func_000435B0(float *alpha);

    Vector3 position;
    char unknown_50[0x24];
    int area;
    float time;
    int shown;
    float unknown_80;
    int index;
    int value;
    Model_00044400 *first;
    Model_00044400 *second;
    Motion_0005F060 *motion;
    char unknown_98[4];
    int enabled;
    char unknown_a0[0x24];
    float alpha;
};

// Slot 3: when enabled, message 0 places it (func_001BAAA0) when its area is drawn (func_0006AC10 of 0x20C6C0) and,
// until it is shown, asks func_000435B0 whether it is and for its alpha. Once shown, message 12 takes the depth of
// its position in view and message 13 draws both models (+0x8c, +0x90) at its place with its alpha in the pose of
// the motion at +0x94.
void Object_000448B0::func_00011C80(int argument)
{
    if (enabled) {
        if (!argument) {
            if (data_0020C6C0.func_0006AC10(area)) {
                func_001BA9C0();
                func_001BAAA0(&position.x);
                if (!shown) {
                    shown = func_000435B0(&alpha);
                }
                func_001BAA50();
            }
        } else if (shown) {
            switch (argument) {
            case 12: {
                Vector3 view;
                func_001BAB20(&view, &position);
                depth = view.z;
                break;
            }
            case 13:
                func_001BA9C0();
                func_001BAAA0(&position.x);
                first->unknown_5c = unknown_80;
                first->alpha = alpha;
                first->slot5(motion, time);
                second->unknown_5c = unknown_80;
                second->alpha = alpha;
                second->slot5(motion, time);
                func_001BAA50();
                break;
            }
        }
    }
}
