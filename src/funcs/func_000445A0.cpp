/* sym: ?func_00011C80@Object_00043860@@UAEXH@Z = 0x000445A0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

void func_001BA9C0();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAA50();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Object_0006A960 {
    int func_0006AC10(int index);
};

extern Object_0006A960 data_0020C6C0;

// The model at +0x54: slot 5 draws it in a pose of a motion; a value at +0x5c.
struct Model_000445A0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(Motion_0005F060 *motion, float time);

    char unknown_04[0x58];
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

// The node class whose table is at 0x1CA6C8 (constructor 0x43710, destructor 0x43860): overrides slot 3.
struct Object_00043860 : Node {
    virtual void func_00011C80(int argument);
    int func_000435B0(float *alpha);

    Vector3 position;
    int value;
    Model_000445A0 *model;
    Motion_0005F060 *motion;
    float time;
    int enabled;
    int shown;
    int area;
    float unknown_6c;
    float alpha;
};

// Slot 3: when enabled, message 0 places it (func_001BAAA0) when its area is drawn (func_0006AC10 of 0x20C6C0) and,
// until it is shown, asks func_000435B0 whether it is and for its alpha. Once shown, message 12 takes the depth of
// its position in view and message 13 draws the model at +0x54 at its place in the pose of the motion at +0x58.
void Object_00043860::func_00011C80(int argument)
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
                model->unknown_5c = unknown_6c;
                model->slot5(motion, time);
                func_001BAA50();
                break;
            }
        }
    }
}
