/* sym: ??0Object_00062390@@QAE@PAUNode@@HIPAUDesc_00060A40@@1H@Z = 0x00060CB0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);

// A description an entry is built from (0x66c bytes); +0x668 chains the next one.
struct Desc_00060A40 {
    char unknown_000[0x668];
    Desc_00060A40 *next;
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

    char unknown_04[0x40];
};

extern int data_001FB6A0;
extern unsigned char data_001FB6A4;

// An entry (table 0x1CB040, constructor 0x60CB0, destructor 0x62390; 0x1558 bytes).
struct Object_00062390 : Node {
    Object_00062390(Node *owner, int id, unsigned int flags, Desc_00060A40 *desc, Desc_00060A40 *second, int size);

    char unknown_044[0x12c];
    int key;
    int child;
    char unknown_178[0x104];
    Vector3 position;
    Vector3 direction;
    char unknown_294[0x1290];
    int unknown_1524;
    int unknown_1528;
    int unknown_152c;
    int unknown_1530;
    char unknown_1534[0x24];
};

struct Object_000607B0 : Node {
    int func_00060A40(Desc_00060A40 *desc);
    int func_00062230(Desc_00060A40 *desc, Vector3 *position, Vector3 *direction);
};

// Makes an entry under this object from a description (sized by func_00060A40) with flags 0x1000: kind 0x84, the
// position and the normalised direction when given, data_001FB6A0 and the two low bits of data_001FB6A4; a chained
// description makes a child entry the same way (+0x174). Returns the entry's key (+0x170).
int Object_000607B0::func_00062230(Desc_00060A40 *desc, Vector3 *position, Vector3 *direction)
{
    int size = func_00060A40(desc);
    Object_00062390 *entry = new Object_00062390(this, -1, 0x1000, desc, 0, size);
    entry->unknown_1524 = 0x84;
    if (position) {
        entry->position.x = position->x;
        entry->position.y = position->y;
        entry->position.z = position->z;
    }
    if (direction) {
        entry->direction.x = direction->x;
        entry->direction.y = direction->y;
        entry->direction.z = direction->z;
        func_0014C410(&entry->direction, &entry->direction);
    }
    entry->unknown_1528 = data_001FB6A0;
    if (data_001FB6A4 & 1) {
        entry->unknown_152c = 1;
    }
    if (data_001FB6A4 & 2) {
        entry->unknown_1530 = 1;
    }
    if (desc->next) {
        entry->child = func_00062230(desc->next, position, direction);
    }
    return entry->key;
}
