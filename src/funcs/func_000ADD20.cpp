/* sym: ?func_00011C90_1@Object_000ACFB0@@UAEXXZ = 0x000ADD20 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();

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

    Node *func_00011BD0();
};

struct Object_000ACFB0;

// The path the object follows (its parent).
struct Object_000B45A0 {
    int func_000B3F40(Object_000ACFB0 *object);
};

// The block at 0x120 that func_000ADBE0 is given.
struct Block_000ADBE0 {
    int unknown_00;
};

// One of the direct children of Node with the table at 0x1CD6E8 (constructor func_000AD4B0).
struct Object_000ACFB0 : Node {
    virtual void func_00011C90_1();

    char unknown_040[0x40];
    float fade;
    char unknown_084[0x18];
    Vector3 offset;
    char unknown_0a8[0x4c];
    int mode;
    char unknown_0f8[4];
    int bank;
    int handle;
    char unknown_104[0x1c];
    Block_000ADBE0 block;
    char unknown_124[0x74];
    int sound;
    char unknown_19c[8];
    int delay;
    char unknown_1a8[8];
    unsigned int flags_1b0;
    char unknown_1b4[0x14];
    int wait;
    char unknown_1cc[0x14];
    Vector3 position;

    unsigned int func_000ADBE0(Block_000ADBE0 *block);
};

int func_000BA800(int bank, int kind, int sound, void *position, int handle);
float __fastcall func_0014C6B0(const Vector3 *vector);

// Slot 2: in mode 5, once func_000ADBE0 of the block at 0x120 gives a value or the parent path's func_000B3F40 gives 1,
// sets flag bit 30 (clearing bit 27), the fade at 0x80 to 0.02 of the length of 0x9c and mode 3. In mode 4, while
// neither holds, swaps flag bit 28 for bit 27, clears 0x1c8 and moves to mode 5. In mode 1, when either holds, plays
// the sound at 0x198 (func_000BA800, kind 1) if the path gave 0, then sets bit 30, copies 0x1a4 to 0x1c8 and goes to
// mode 3 as in mode 5.
void Object_000ACFB0::func_00011C90_1()
{
    Object_000B45A0 *path = (Object_000B45A0 *)func_00011BD0();
    switch (mode) {
    case 5:
        if (func_000ADBE0(&block) > 0 || path->func_000B3F40(this) == 1) {
            flags_1b0 = flags_1b0 & 0xf7ffffff | 0x40000000;
            fade = func_0014C6B0(&offset) * 0.02f;
            mode = 3;
        }
        break;
    case 4:
        if (func_000ADBE0(&block) == 0 && path->func_000B3F40(this) != 1) {
            flags_1b0 = flags_1b0 & 0xefffffff | 0x8000000;
            wait = 0;
            mode = 5;
        }
        break;
    case 1: {
        unsigned int close = func_000ADBE0(&block);
        int found = path->func_000B3F40(this);
        if (found == 1 || close > 0) {
            if (found == 0 && sound != -1) {
                handle = func_000BA800(bank, 1, sound, &position, handle);
            }
            flags_1b0 |= 0x40000000;
            wait = delay;
            fade = func_0014C6B0(&offset) * 0.02f;
            mode = 3;
        }
        break;
    }
    }
}
