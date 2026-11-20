/* sym: ??0Object_000B3200@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000B2F40 */
/* sym: ??0Object_000B9960@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000B8230 */
/* sym: ??0Object_000BDAE0@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000BD8D0 */
/* sym: ??0Object_000BF340@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000BF0C0 */
/* sym: ??0Object_000B0190@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000AFEE0 */
/* sym: ??0Object_000B7440@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000B7170 */
/* sym: ??0Object_000BB710@@QAE@PAUNode@@HIPAUParams_000BAC60@@HHH@Z = 0x000BB4C0 */
/* sym: ??0Object_000AE970@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000AE6C0 */
/* sym: ??0Object_000AF790@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000AF090 */
/* sym: ??0Object_000AE220@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000ADE90 */
/* sym: ??0Object_000BE1B0@@QAE@PAUNode@@HIPAUParams_000BAC60@@@Z = 0x000BEA80 */
/* const: 0x200010 */
/* const: 0x200100 */
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

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// The child of Node whose table is at 0x1CDA20 (0xa4 bytes): the ids of what it made of each of the 24 kinds.
struct Object_000BAE00 : Node {
    void func_000BAE10(int kind, Params_000BAC60 *records, unsigned int count);
};

// What func_000BAE10 makes of each kind (operator new's size is the class's size).
struct Object_000B3200 : Node {
    Object_000B3200(Node *owner, int id, unsigned int flags, Params_000BAC60 *record);
    char unknown_40[0x21c - 0x40];
};

struct Object_000B9960 : Node {
    Object_000B9960(Node *owner, int id, unsigned int flags, Params_000BAC60 *record);
    char unknown_40[0x374 - 0x40];
};

struct Object_000BDAE0 : Node {
    Object_000BDAE0(Node *owner, int id, unsigned int flags, Params_000BAC60 *record);
    char unknown_40[0x1a0 - 0x40];
};

struct Object_000BF340 : Node {
    Object_000BF340(Node *owner, int id, unsigned int flags, Params_000BAC60 *record);
    char unknown_40[0x208 - 0x40];
};

struct Object_000B0190 : Node {
    Object_000B0190(Node *owner, int id, unsigned int flags, Params_000BAC60 *record);
    char unknown_40[0x290 - 0x40];
};

struct Object_000B7440 : Node {
    Object_000B7440(Node *owner, int id, unsigned int flags, Params_000BAC60 *record);
    char unknown_40[0x204 - 0x40];
};

// Its constructor keeps the fifth argument at 0x16c.
struct Object_000BB710 : Node {
    Object_000BB710(Node *owner, int id, unsigned int flags, Params_000BAC60 *record, int value, int first,
                    int second);
    char unknown_40[0x1bc - 0x40];
};

struct Object_000AE970 : Node {
    Object_000AE970(Node *owner, int id, unsigned int flags, Params_000BAC60 *record);
    char unknown_40[0x1b0 - 0x40];
};

struct Object_000AF790 : Node {
    Object_000AF790(Node *owner, int id, unsigned int flags, Params_000BAC60 *record);
    char unknown_40[0x20c - 0x40];
};

struct Object_000AE220 : Node {
    Object_000AE220(Node *owner, int id, unsigned int flags, Params_000BAC60 *record);
    char unknown_40[0x1d4 - 0x40];
};

struct Object_000BE1B0 : Node {
    Object_000BE1B0(Node *owner, int id, unsigned int flags, Params_000BAC60 *record);
    char unknown_40[0x320 - 0x40];
};

int func_00065640(int first, int second, int third);
void func_00011C90_13(int model, Params_000BAC60 *record);
void func_00117770(int kind, Vector3 *position, float x, float y);
void func_00117B20(int id, Vector3 *position);

// Makes one object of the given kind for each record, each under a new id from func_000128E0 (0xec to 0x10ec):
// kinds 6, 8 to 14, 17, 18 and 23 are Node children built here; 15, 16, 19 and 20 pass the record to functions
// elsewhere.
void Object_000BAE00::func_000BAE10(int kind, Params_000BAC60 *records, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++) {
        int id = data_0022FCE0->func_000128E0(0xec, 0x10ec);
        switch (kind) {
        case 13:
            new Object_000B3200(this, id, 0x200010, &records[i]);
            break;
        case 6:
            new Object_000B9960(this, id, 0x200010, &records[i]);
            break;
        case 8:
            new Object_000BDAE0(this, id, 0x200100, &records[i]);
            break;
        case 14:
            new Object_000BF340(this, id, 0x200100, &records[i]);
            break;
        case 9:
            new Object_000B0190(this, id, 0x200100, &records[i]);
            break;
        case 23:
            new Object_000B7440(this, id, 0x200010, &records[i]);
            break;
        case 10:
            new Object_000BB710(this, id, 0x200010, &records[i], 0, -1, -1);
            break;
        case 11:
            new Object_000AE970(this, id, 0x200010, &records[i]);
            break;
        case 12:
            new Object_000AF790(this, id, 0x200100, &records[i]);
            break;
        case 17:
            new Object_000AE220(this, id, 0x200010, &records[i]);
            break;
        case 15:
            func_00065640(records[i].model, (int)&records[i], (int)&records[i].angles);
            break;
        case 16:
            func_00011C90_13(records[i].model, &records[i]);
            break;
        case 18:
            new Object_000BE1B0(this, id, 0x200100, &records[i]);
            break;
        case 19:
            func_00117770(records[i].model, &records[i].position, records[i].scale.x, records[i].scale.y);
            break;
        case 20:
            func_00117B20(records[i].model, &records[i].position);
            break;
        }
    }
}
