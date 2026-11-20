/* sym: ??1Object_00022990@@UAE@XZ = 0x00022990 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void func_00116870();
void func_00116670(int value);
void func_001166B0(int value);
void func_000FE550(int index);
void func_0005DAA0(void *block);
void func_00025740(unsigned int index, int argument);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern int data_00230D94;

// The object 0x1ddc.
struct Object_000239D0 {
    void func_00023AD0(int value);
    void func_00023B90(int value, float scale);
};

// What +0xc of an entry points at (and +0x74, +0x78): deleted through its virtual destructor.
struct Object_000800D0 {
    virtual ~Object_000800D0();
};

struct Entry_0001FED0 {
    char unknown_00[0xc];
    Object_000800D0 *object;
    char unknown_10[0x60];
    void *block;
    Object_000800D0 *first;
    Object_000800D0 *second;
};

struct State_0001FED0 {
    int unknown_00;
    char unknown_04[0x14];
    unsigned int count;
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
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
    char unknown_34[0x10];
};

// Node child with the table at 0x1C4BA8.
struct Object_00022990 : Node {
    virtual ~Object_00022990();

    char unknown_44[0x98];
    State_0001FED0 *state;
    Entry_0001FED0 **entries;
};

// Resets object 0x1ddc (func_00023AD0 (0), func_00023B90 (0, 1.0)), runs func_00116870, func_00116670 (0),
// func_001166B0 (0) and func_000FE550 for 0 to 5, frees each entry (its block through func_0005DAA0 and its three
// objects) and the table, and with data_00230D94 set runs func_00025740 (9, the state's first word).
Object_00022990::~Object_00022990()
{
    Object_000239D0 *object = (Object_000239D0 *)data_0022FCE0->func_000128C0(0x1ddc);
    if (object) {
        object->func_00023AD0(0);
        object->func_00023B90(0, 1.0f);
    }
    func_00116870();
    func_00116670(0);
    func_001166B0(0);
    func_000FE550(0);
    func_000FE550(1);
    func_000FE550(2);
    func_000FE550(3);
    func_000FE550(4);
    func_000FE550(5);
    if (entries) {
        for (unsigned int i = 0; i < state->count; i++) {
            Entry_0001FED0 *entry = entries[i];
            if (entry) {
                if (entry->block) {
                    func_0005DAA0(entry->block);
                }
                delete entry->object;
                delete entry->first;
                delete entry->second;
                delete entry;
            }
        }
        delete entries;
    }
    if (data_00230D94) {
        func_00025740(9, state->unknown_00);
    }
}
