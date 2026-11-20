/* sym: ??0Object_000C4510@@QAE@PAUNode@@HIH@Z = 0x000C4510 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??1Object_000C4510@@UAE@XZ = 0x000121D0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ?func_00011C90@Object_000C4510@@UAEXXZ = 0x000C4670 */
/* sym: ?func_00011C80@Object_000C4510@@UAEXH@Z = 0x000C47F0 */
/* sym: ?func_00011C80_3@Object_000C4510@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000C4510@@UAEXH@Z = 0x000B3DE0 */
struct Frame_000479D0;
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Point_000C4510 {
    Vector3 position;
    float w;
};

struct Matrix_001BA950 {
    float m[4][4];
};

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

extern "C" void *memset(void *destination, int value, unsigned int size);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

// What func_00025700 (5, ...) returns: its models (+0x0) and motions (+0x18).
struct Sprite_000C4510;

void *func_00025700(unsigned int index, int first, int second, int third);
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

// Per kind: the sprite (func_00025700 index), its model and motion, and the kind sent to node 0xe8.
extern int data_002161B4[];
extern int data_0021619C[];
extern int data_00216184[];
extern int data_0021616C[];

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

// The models' base (tables 0x1CA490, 0x1CAA8C, 0x1CC12C): slot 5 poses the model.
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void func_00047470(void *first, void *second, Frame_000479D0 *frame);
    virtual void slot3();
    virtual void func_00047540();
    virtual void func_00047690(int first, int second);

    char unknown_04[0x1c];
    Matrix_001BA950 *matrices;
    char unknown_24[0x34];
    float frame;

    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

// The child of Node with the table at 0x1CDDE0 (constructor func_000C4510, 0xa8 bytes; its implicit destructor and
// deleting destructor are folded into the camera node's, 0x121D0 and 0x121B0): a model (0x44) posed from a motion
// (0x48) at a frame (0x50) under its own matrix (0x54), of a kind (0x94).
struct Object_000C4510 : Node {
    Object_000C4510(Node *owner, int id, unsigned int flags, int kind);
    virtual ~Object_000C4510();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_40[4];
    Object_00047470 *model;
    Motion_0005F060 *motion;
    float time;
    float frame;
    Matrix_001BA950 matrix;
    int kind;
    int parts[4];
};

struct Sprite_000C4510 {
    Object_00047470 **models;
    char unknown_04[0x14];
    Motion_0005F060 **motions;
};

// Builds the Node part, takes the model and motion of its kind from sprite set 5 (func_00025700), starts at frame 1
// under an identity matrix (func_001BA950), and tells node 0xe8 (func_000651E0) about its kind at the origin (10 up
// for kind 4); kinds 2 and 3 also start four or two parts there (kind 0x7d), kept at 0x98.
Object_000C4510::Object_000C4510(Node *owner, int id, unsigned int flags, int kind) : Node(owner, id, flags)
{
    Sprite_000C4510 *sprite = (Sprite_000C4510 *)func_00025700(5, data_002161B4[kind], 0, 0);
    model = sprite->models[data_0021619C[kind]];
    motion = sprite->motions[data_00216184[kind]];
    time = 0.0f;
    frame = 1.0f;
    this->kind = kind;
    func_001BA950(&matrix);
    memset(parts, 0, sizeof parts);
    Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (target) {
        Point_000C4510 point;
        func_001BAB20(&point.position, 0);
        if (kind == 4) {
            point.position.y += 10.0f;
        }
        target->func_000651E0(data_0021616C[kind], &point, 0);
        switch (kind) {
        case 2:
            for (int i = 0; i < 4; i++) {
                parts[i] = target->func_000651E0(0x7d, &point, 0);
            }
            break;
        case 3:
            for (int j = 0; j < 2; j++) {
                parts[j] = target->func_000651E0(0x7d, &point, 0);
            }
            break;
        }
    }
}
