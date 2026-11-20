/* sym: ?func_00011C90_1@Object_000B0190@@UAEXXZ = 0x000B0600 */
struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C6B0(const Vector3 *vector);
int func_000BA800(int bank, int kind, int sound, void *position, int handle);

// The motion the node follows (0x250): its state at 0 and a vector at 8.
struct Motion_000B0600 {
    int state;
    int unknown_04;
    Vector3 vector;
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
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD7F8).
struct Object_000B0190 : Node {
    virtual void func_00011C90_1();

    char unknown_040[0x30];
    unsigned int entryFlags;
    int unknown_074;
    int count;
    char unknown_07c[8];
    int sound;
    char unknown_088[0xa8];
    int touched;
    int value_134;
    char unknown_138[0x58];
    int value_190;
    int index;
    int unknown_198;
    int bank;
    int handle;
    char position[0xc];
    char unknown_1b0[0x8c];
    int mode;
    char unknown_240[0x10];
    Motion_000B0600 *motion;
};

// Slot 2: unless the entry has flag 0x20000000, a touched node in mode 1 whose motion has settled (state 0 or 1)
// and moves faster than 0.01 steps to the next index (mode 3, or 8 at the last) and plays the entry's sound
// (func_000BA800) at 0x1a4; the touch words at 0x130 and 0x134 are cleared.
void Object_000B0190::func_00011C90_1()
{
    if (entryFlags & 0x20000000) {
        return;
    }
    switch (mode) {
    case 1:
        if (touched && motion) {
            while (motion->state != 0 && motion->state != 1) {
            }
            if (func_0014C6B0(&motion->vector) > 0.01f) {
                mode = 3;
                if (++index >= count - 1) {
                    mode = 8;
                }
                value_190 = 0;
                if (sound != -1) {
                    handle = func_000BA800(bank, 0, sound, position, handle);
                }
            }
        }
        break;
    }
    touched = 0;
    value_134 = 0;
}
