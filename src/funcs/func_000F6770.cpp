struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *first, const Vector3 *second);

// One link of the list at 0x1d4: taken while 0 at 0x0, the next link at 0x38.
struct Frame_000C1490 {
    int taken;
    char unknown_04[0x34];
    Frame_000C1490 *next;
};

// The object in data_00257CE8.
struct Object_00157F10 {
    void func_000C1490(Vector3 *out, Frame_000C1490 *frame, float first, float second);
};

extern Object_00157F10 *data_00257CE8;

// The object in data_00257CE4: a speed at 0xb4.
struct Object_000C1270 {
    char unknown_00[0xb4];
    float speed;
};

extern Object_000C1270 *data_00257CE4;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *position, Vector3 *direction);
};

// The handler object at 0xb0: a value at 0x5c.
struct Object_000C5B50 {
    char unknown_00[0x5c];
    int value_5c;

    int func_000C5B10(int message, void *data);
    void func_000C5B50(int *handle);
    int func_000C5B70(int handle);
};

struct Object_00047470 {
    void func_00047970(void *motion, int frame);
    void func_000480C0(unsigned int part);
};

struct Node {
    virtual ~Node();

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

// The child of Node whose table is at 0x1CF220 (constructor func_000F5E70, destructor func_000F60C0).
struct Object_000F55E0 : Node {
    virtual void func_000F6770();

    char unknown_040[8];
    Vector3 position;
    char unknown_054[0x3c];
    unsigned int options;
    char unknown_094[0x1c];
    Object_000C5B50 *handler;
    char unknown_0b4[0xc];
    Vector3 facing;
    char unknown_0cc[0x1c];
    Vector3 direction;
    char unknown_0f4[0x3c];
    Object_00047470 *model;
    char unknown_134[0x14];
    void *motion;
    char unknown_14c[0x88];
    Frame_000C1490 *frames;
    char unknown_1d8[0x20];
    int first;
    int second;

    void func_000F5890();
    void func_000F58E0();
};

// Slot 35: takes the first free frame of the list at 0x1d4 and its direction (func_000C1490 into 0xe8). With a
// direction on the ground and data_00257CE4's speed above 1.389, flattens and normalises it, clears the handler's
// 0x5c, turns one way or the other by the side of 0xc0 it lies on (func_000F5890 / func_000F58E0), swaps option bits
// (clears 0x3008000, sets 0xa00000), poses the model (motion at 0x148, part 9) at the position and hands the posed
// origin to object 0xe8 (func_000651E0, kind 0x24) and to the handler (message 0x10); then releases the handler's
// handles at 0x1f8 and 0x1fc when it still knows them. Otherwise clears option bit 23.
void Object_000F55E0::func_000F6770()
{
    for (Frame_000C1490 *frame = frames; frame; frame = frame->next) {
        if (frame->taken) {
            continue;
        }
        data_00257CE8->func_000C1490(&direction, frame, 0.0f, 1.0f);
        if (direction.x == 0.0f && direction.z == 0.0f) {
            break;
        }
        direction.y = 0.0f;
        func_0014C410(&direction, &direction);
        if (!(data_00257CE4->speed > 1.3888888f)) {
            break;
        }
        handler->value_5c = 0;
        Vector3 point;
        func_0014C3B0(&point, &facing, &direction);
        if (point.y >= 0.0f) {
            func_000F5890();
        } else {
            func_000F58E0();
        }
        options = options & 0xfcff7fff | 0xa00000;
        func_001BAA00();
        func_001BAAA0(&position.x);
        model->func_00047970(motion, 0);
        model->func_000480C0(9);
        func_001BAB20(&point, 0);
        Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (object) {
            object->func_000651E0(0x24, &point, 0);
        }
        handler->func_000C5B10(0x10, &point);
        func_001BAA50();
        if (handler->func_000C5B70(first)) {
            handler->func_000C5B50(&first);
        }
        if (handler->func_000C5B70(second)) {
            handler->func_000C5B50(&second);
        }
        return;
    }
    options &= 0xff7fffff;
}
