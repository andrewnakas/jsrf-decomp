/* sym: ??1Object_000C1270@@QAE@XZ = 0x000C0EB0 */
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

struct Object_000BFF60 {
    void *data;
    char unknown_04[0x18];
};

// The object in data_00257CE4.
struct Object_000C1270 {
    ~Object_000C1270();
};

// The object in data_00257CE8 (deleted through its slot 0).
struct Object_00157F10 {
    virtual ~Object_00157F10();
};

// The object in data_00257CEC (deleted through its slot 0).
struct Object_000C3BE0 {
    virtual ~Object_000C3BE0();
};

extern Object_000BFF60 *data_00257CE0;
extern Object_000C1270 *data_00257CE4;
extern Object_00157F10 *data_00257CE8;
extern Object_000C3BE0 *data_00257CEC;

// A direct child of Node (table 0x1CDC18; constructor func_000C0A90, destructor func_000C0D90).
struct Object_000C0A90 : Node {
    void func_000C0AC0();
};

// Deletes the objects in data_00257CEC, data_00257CE4, data_00257CE0 and data_00257CE8 that exist and clears
// those pointers. Does not read `this`.
void Object_000C0A90::func_000C0AC0()
{
    if (data_00257CEC) {
        delete data_00257CEC;
        data_00257CEC = 0;
    }
    if (data_00257CE4) {
        delete data_00257CE4;
        data_00257CE4 = 0;
    }
    if (data_00257CE0) {
        delete data_00257CE0;
        data_00257CE0 = 0;
    }
    if (data_00257CE8) {
        delete data_00257CE8;
        data_00257CE8 = 0;
    }
}
