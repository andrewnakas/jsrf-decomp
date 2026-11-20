struct Vector3 {
    float x;
    float y;
    float z;
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
    char unknown_34[0xc];
};

void func_001BA9C0();
void func_001BA8A0();
void __fastcall func_001BB330(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAA50();

// An item of the block's list (kinds 0 and 1 count): its point on the ground plane at 0x2c/0x34 and the next at 0x38.
struct Item_000ADBE0 {
    int kind;
    char unknown_04[0x28];
    float x;
    float y;
    float z;
    Item_000ADBE0 *next;
};

// The block at 0x120 that func_000ADBE0 is given.
struct Block_000ADBE0 {
    Item_000ADBE0 *first;
};

// One of the direct children of Node with the table at 0x1CD6E8 (constructor func_000AD4B0).
struct Object_000ACFB0 : Node {
    char unknown_040[0x5c];
    Vector3 offset;
    char unknown_0a8[0xe8];
    int track;
    char unknown_194[0x5c];
    int heading;

    int func_000AD3A0();
    unsigned int func_000ADBE0(Block_000ADBE0 *block);
};

// Whether an item of the list lies ahead within the view cone (heading at 0x1f0 turned by -0xe38 and 0x1c71 from
// straight ahead): 1 when one does on the side the path turns to (func_000AD3A0, when 0x190 is not negative), 2 when
// one lies on the other side or 0x190 is negative, else 0. `side` stays unset when 0x190 is negative, as in retail,
// which then holds the argument.
unsigned int Object_000ACFB0::func_000ADBE0(Block_000ADBE0 *block)
{
    unsigned int result = 0;
    Vector3 forward;
    forward.x = 0.0f;
    forward.y = 0.0f;
    forward.z = -1.0f;
    int side;
    if (!(track & 0x80000000)) {
        side = func_000AD3A0();
    }
    func_001BA9C0();
    func_001BA8A0();
    func_001BB330(heading - 0xe38);
    Vector3 left;
    func_001BAB20(&left, &forward);
    func_001BB330(0x1c71);
    Vector3 right;
    func_001BAB20(&right, &forward);
    func_001BAA50();
    for (Item_000ADBE0 *item = block->first; item; item = item->next) {
        if (item->kind == 0 || item->kind == 1) {
            float cross[2];
            cross[0] = left.z * item->x - left.x * item->z;
            cross[1] = right.x * item->z - right.z * item->x;
            if (cross[0] > 0.0f && cross[1] > 0.0f) {
                if (track & 0x80000000) {
                    return 2;
                }
                if (offset.z * item->x - offset.x * item->z < 0.0f) {
                    if (side != 1) {
                        return 2;
                    }
                } else if (side == 1) {
                    return 2;
                }
                result = 1;
            }
        }
    }
    return result;
}
