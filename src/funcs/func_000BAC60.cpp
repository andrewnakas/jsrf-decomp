/* sym: ??0Object_000B40F0@@QAE@PAUNode@@HIPAUParams_000BAC60@@H@Z = 0x000B4330 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

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

// What func_000B4330 is built from: a place, a turn, a scale and a value.
struct Params_000BAC60 {
    Vector3 position;
    Angles_000C1300 angles;
    Vector3 scale;
    int value;
};

// The class whose table is at 0x1CD8C8 (0x144 bytes; constructor func_000B4330).
struct Object_000B40F0 {
    Object_000B40F0(Node *owner, int id, unsigned int flags, Params_000BAC60 *params, int extra);

    char unknown_000[0x144];
};

// The child of Node whose table is at 0x1CD9E0: it overrides none of Node's slots.
struct Object_000BAC20 : Node {
    virtual ~Object_000BAC20();

    char unknown_40[4];
    int values[20];

    int func_000BAC60(int value, int extra);
};

// Takes a free one of the 20 slots at 0x44 for a new id (func_000128E0, 0x10ee to 0x10f8) and makes an
// Object_000B40F0 there under this object (flags 4) at the origin, unturned, at scale 1 with the value. Returns the
// id, or 0 when every slot is taken.
int Object_000BAC20::func_000BAC60(int value, int extra)
{
    int id = 0;
    for (int i = 0; i < 20; i++) {
        if (!values[i]) {
            id = data_0022FCE0->func_000128E0(0x10ee, 0x10f8);
            values[i] = id;
            Params_000BAC60 params;
            params.position.x = 0.0f;
            params.position.y = 0.0f;
            params.position.z = 0.0f;
            params.angles.x = 0;
            params.angles.y = 0;
            params.angles.z = 0;
            params.scale.x = 1.0f;
            params.scale.y = 1.0f;
            params.scale.z = 1.0f;
            params.value = value;
            new Object_000B40F0(this, id, 4, &params, extra);
            break;
        }
    }
    return id;
}
