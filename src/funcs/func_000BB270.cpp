/* sym: ??0Object_000BAE00@@QAE@PAUNode@@HIPAUInfo_000B9E70@@I@Z = 0x000BB270 */
/* sym: ??1Object_000BAE00@@UAE@XZ = 0x000BAE00 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
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

// What func_000B9E70 reads the kind of the child to create from (at 0x28); 0x30 bytes.
struct Info_000B9E70 {
    Params_000BAC60 record;
    int kind;
    int unknown_2c;
};

// The child of Node whose table is at 0x1CDA20 (0xa4 bytes): the ids of what it made of each of the 24 kinds.
struct Object_000BAE00 : Node {
    Object_000BAE00(Node *owner, int id, unsigned int flags, Info_000B9E70 *infos, unsigned int count);
    virtual ~Object_000BAE00();

    void func_000BAE10(int kind, Params_000BAC60 *records, unsigned int count);

    char unknown_40[4];
    int ids[24];
};

extern "C" void *memset(void *destination, int value, unsigned int size);

int func_000BA290(Node *owner, unsigned int kind, Params_000BAC60 *placements, unsigned int count);

// Sorts the records by kind (0x28 of each 0x30-byte info) into one array per kind, then makes each kind's objects
// from its array: kinds 3, 6 and 8 to 20 with func_000BAE10, the rest with func_000BA290 (what it returns is kept at
// 0x44 + 4 * kind); then frees the arrays.
Object_000BAE00::Object_000BAE00(Node *owner, int id, unsigned int flags, Info_000B9E70 *infos, unsigned int count)
    : Node(owner, id, flags)
{
    unsigned int counts[24];
    Params_000BAC60 *lists[24];
    unsigned int i;
    unsigned int kind;
    memset(counts, 0, sizeof(counts));
    for (i = 0; i < count; i++) {
        counts[infos[i].kind]++;
    }
    for (kind = 0; kind < 24; kind++) {
        if (counts[kind] > 0) {
            lists[kind] = (Params_000BAC60 *)operator new(counts[kind] * sizeof(Params_000BAC60));
        } else {
            lists[kind] = 0;
        }
    }
    memset(counts, 0, sizeof(counts));
    for (i = 0; i < count; i++) {
        lists[infos[i].kind][counts[infos[i].kind]] = infos[i].record;
        counts[infos[i].kind]++;
    }
    for (kind = 0; kind < 24; kind++) {
        Params_000BAC60 *list = lists[kind];
        if (list) {
            switch (kind) {
            case 3:
            case 6:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
                func_000BAE10(kind, list, counts[kind]);
                break;
            default:
                ids[kind] = func_000BA290(this, kind, list, counts[kind]);
                break;
            }
            operator delete(list);
            lists[kind] = 0;
        }
    }
}
