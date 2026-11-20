/* sym: ??0Object_000461B0@@QAE@PAUNode@@HIH@Z = 0x000461B0 */
/* sym: ??1Object_000461B0@@UAE@XZ = 0x00046310 */
/* sym: ??0Object_00044AE0@@QAE@PAUNode@@HIHHPAUVector3@@HH@Z = 0x00044940 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

int func_0004EA70();

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

extern Vector3 data_001F92C8;

// Object 9: the stage, with its kind at +0x104e and its part at +0x104c.
struct Object_0004ABA0 {
    char unknown_0000[0x104c];
    union {
        int place;
        struct {
            unsigned short part;
            unsigned short kind;
        };
    };
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    Node *func_00011BD0();
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

// The node class whose table is at 0x1CA788 (destructor 0x44AE0; 0x948 bytes).
struct Object_00044AE0 : Node {
    Object_00044AE0(Node *owner, int id, unsigned int flags, int kind, int record, Vector3 *position, int value,
                    int mode);
    virtual ~Object_00044AE0();

    char unknown_044[0x904];
};

// The node class whose table is at 0x1CA7D8 (destructor 0x46310).
struct Object_000461B0 : Node {
    Object_000461B0(Node *owner, int id, unsigned int flags, int value);
    virtual ~Object_000461B0();
};

// When func_0004EA70 has bit 0x400, makes an Object_00044AE0 under the parent node for the stage's kind: kinds 0
// and 1 always, kind 2 unless the part is 1 or 3, kind 4 (placed at 0x1F92C8) only for part 2.
Object_000461B0::Object_000461B0(Node *owner, int id, unsigned int flags, int value)
    : Node(owner, id, flags)
{
    int part = 0;
    int kind = 0;
    Object_0004ABA0 *stage = (Object_0004ABA0 *)data_0022FCE0->func_000128C0(9);
    if (func_0004EA70() & 0x400) {
        if (stage) {
            kind = stage->kind;
            part = stage->place & 0xffff;
        }
        switch (kind) {
        case 0:
        case 1:
            new Object_00044AE0(func_00011BD0(), -1, 0x110, kind, 0, 0, 3, 0);
            break;
        case 2:
            if (part != 1 && part != 3) {
                new Object_00044AE0(func_00011BD0(), -1, 0x110, 2, 0, 0, 3, 0);
            }
            break;
        case 4:
            if (part == 2) {
                new Object_00044AE0(func_00011BD0(), -1, 0x110, 4, 1, &data_001F92C8, 3, 1);
            }
            break;
        }
    }
}
