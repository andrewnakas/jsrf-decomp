/* sym: ??0Object_000A87E0@@QAE@PAUNode@@HIPAUParams_000BAC60@@I@Z = 0x000A87E0 */
/* sym: ??0Object_000AA180@@QAE@PAUNode@@HIPAUParams_000BAC60@@I@Z = 0x000AA180 */
/* sym: ??0Object_000AB2A0@@QAE@PAUNode@@HIPAUParams_000BAC60@@I@Z = 0x000AB2A0 */
/* sym: ??0Object_000B1130@@QAE@PAUNode@@HIPAUParams_000BAC60@@I@Z = 0x000B0A20 */
/* sym: ??0Object_000B4FD0@@QAE@PAUNode@@HIPAUParams_000BAC60@@I@Z = 0x000B4FD0 */
/* sym: ??0Object_000BBD10@@QAE@PAUNode@@HIPAUParams_000BAC60@@I@Z = 0x000BBD10 */
/* const: 0x200008 */
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

struct Vector3 {
    float x;
    float y;
    float z;
};

// Where func_000BAC60 places the object: position, angles, scale and a model code (bank << 10 | index).
struct Params_000BAC60 {
    Vector3 position;
    int angles[3];
    Vector3 scale;
    unsigned int model;
};

// The six kinds of objects func_000BA290 makes (0x4c bytes each), all built from a list of placements.
struct Object_000A87E0 : Node {
    Object_000A87E0(Node *owner, int id, unsigned int flags, Params_000BAC60 *placements, unsigned int count);

    char unknown_40[0xc];
};

struct Object_000AA180 : Node {
    Object_000AA180(Node *owner, int id, unsigned int flags, Params_000BAC60 *placements, unsigned int count);

    char unknown_40[0xc];
};

struct Object_000AB2A0 : Node {
    Object_000AB2A0(Node *owner, int id, unsigned int flags, Params_000BAC60 *placements, unsigned int count);

    char unknown_40[0xc];
};

struct Object_000B1130 : Node {
    Object_000B1130(Node *owner, int id, unsigned int flags, Params_000BAC60 *placements, unsigned int count);

    char unknown_40[0xc];
};

struct Object_000B4FD0 : Node {
    Object_000B4FD0(Node *owner, int id, unsigned int flags, Params_000BAC60 *placements, unsigned int count);

    char unknown_40[0xc];
};

struct Object_000BBD10 : Node {
    Object_000BBD10(Node *owner, int id, unsigned int flags, Params_000BAC60 *placements, unsigned int count);

    char unknown_40[0xc];
};

// Makes the object of a kind (0, 1, 2, 4, 5 and 7; the others make nothing) under the owner with a free id from
// 0xec to 0x10ec, flags 0x200008 and the placements; returns the id.
int func_000BA290(Node *owner, unsigned int kind, Params_000BAC60 *placements, unsigned int count)
{
    int id = data_0022FCE0->func_000128E0(0xec, 0x10ec);
    switch (kind) {
    case 0:
        new Object_000A87E0(owner, id, 0x200008, placements, count);
        break;
    case 1:
        new Object_000AA180(owner, id, 0x200008, placements, count);
        break;
    case 2:
        new Object_000AB2A0(owner, id, 0x200008, placements, count);
        break;
    case 4:
        new Object_000B1130(owner, id, 0x200008, placements, count);
        break;
    case 5:
        new Object_000B4FD0(owner, id, 0x200008, placements, count);
        break;
    case 7:
        new Object_000BBD10(owner, id, 0x200008, placements, count);
        break;
    }
    return id;
}
