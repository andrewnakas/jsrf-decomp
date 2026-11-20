/* sym: ??0Object_00074260@@QAE@PAUNode@@HIHI@Z = 0x000740A0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00074260@@UAE@XZ = 0x000743D0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
extern "C" void *memset(void *to, int value, unsigned int size);

void func_00118870(int value);

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    Node *func_00011BD0();

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

struct Object_00107FE0 : Node {
    char unknown_0044[0x1678];
    int value_16bc;
    int value_16c0;

    void func_00108000(int index, unsigned int mode);
    int func_001084E0(int index);
};

// An entry of the screen's list at +0x44 (8 bytes).
struct Entry_000740A0 {
    int value;
    int mask;
};

// The screens made by func_00109690 (table 0x1CCC58, 0xe4 bytes).
struct Object_00074260 : Node {
    Object_00074260(Node *owner, int id, unsigned int flags, int ownerId, unsigned int mode);
    virtual ~Object_00074260();

    Entry_000740A0 entries[10];
    int unknown_94;
    char unknown_98[0x4];
    unsigned int mode;
    char unknown_a0[0x4];
    int unknown_a4;
    int unknown_a8;
    int unknown_ac;
    int ownerId;
    unsigned int state;
    int settings[10];
    int unknown_e0;
};

// Makes the node with the owner's id and mode; takes the owner's values 7 and 8 into mode 7 (func_00108000) and
// keeps its words at +0x16bc and +0x16c0 and its value 8 (func_001084E0), or 0, -1 and 1 without an owner; clears
// the list (entries 4 and 5 to -1), the state and the settings (the first two to 1); +0xe0 says whether the mode has
// bit 0 or 2. Passes 1 to func_00118870.
Object_00074260::Object_00074260(Node *owner, int id, unsigned int flags, int ownerId, unsigned int mode)
    : Node(owner, id, flags)
{
    this->ownerId = ownerId;
    this->mode = mode;
    Object_00107FE0 *object = (Object_00107FE0 *)func_00011BD0();
    if (object) {
        object->func_00108000(7, 7);
        object->func_00108000(8, 7);
        unknown_a4 = object->value_16bc;
        unknown_a8 = object->value_16c0;
        unknown_ac = object->func_001084E0(8);
    } else {
        unknown_a4 = 0;
        unknown_a8 = -1;
        unknown_ac = 1;
    }
    state = 0;
    unknown_94 = 0;
    unknown_e0 = 0;
    for (int i = 0; i < 10; i++) {
        entries[i].value = 0;
        entries[i].mask = 0xf;
    }
    entries[4].value = -1;
    entries[5].value = -1;
    int *values = settings;
    memset(values, 0, sizeof(settings));
    for (int j = 0; j < 2; j++) {
        values[j] = 1;
    }
    if (this->mode & 1 || this->mode & 4) {
        unknown_e0 = 1;
    } else {
        unknown_e0 = 0;
    }
    func_00118870(1);
}
