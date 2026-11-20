/* sym: ?func_00011C90_1@Object_000BDAE0@@UAEXXZ = 0x000BDE30 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();

    char unknown_04[0x3c];
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_000606C0(int key, Vector3 *point);
    void func_00060930(int key, int on);
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

// An entry of the list at 0x160: its kind, a vector at 0x8 and the next entry at 0x38.
struct Entry_000BDE30 {
    int kind;
    int unknown_04;
    Vector3 vector;
    char unknown_14[0x24];
    Entry_000BDE30 *next;
};

float __fastcall func_0014C6B0(const Vector3 *vector);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CDAE0).
struct Object_000BDAE0 : Node {
    virtual void func_00011C90_1();

    char unknown_040[0x30];
    unsigned int flags;
    char unknown_074[4];
    int kind;
    char unknown_07c[8];
    float height;
    char unknown_088[0x10];
    int value_98;
    int value_9c;
    char unknown_0a0[0xc];
    int first;
    char unknown_0b0[4];
    Vector3 position;
    char unknown_0c0[0x8c];
    int state;
    char unknown_150[0x10];
    Entry_000BDE30 *entries;
};

// State 1: when 0x98 and 0x9c are both set and the first entry of kind 0 or 1 has a vector longer than 0.01, tells
// object 0xe8 about the position raised by 0x84 (kind 0x78; with the key at 0xac moves it there and switches it off,
// else takes a new key from func_000651E0, which is dropped when flags bit 31 is set) and goes to state 3. State 3:
// once the first entry of kind 0 or 1 is short enough (or there is none, and flag 0x40000000 is clear) switches the
// key back on and goes to state 1. 0x98 and 0x9c are cleared each time.
void Object_000BDAE0::func_00011C90_1()
{
    Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    switch (state) {
    case 3: {
        Entry_000BDE30 *entry = entries;
        while (entry) {
            if (entry->kind == 0 || entry->kind == 1)
                break;
        }
        if (entry) {
            if (flags & 0x40000000)
                break;
            if (func_0014C6B0(&entry->vector) > 0.01f)
                break;
        }
        if (!(flags & 0x80000000) && target && first != -1)
            target->func_00060930(first, 1);
        state = 1;
        break;
    }
    case 1:
        if (value_98 && value_9c) {
            Entry_000BDE30 *entry;
            for (entry = entries; entry; entry = entry->next) {
                if (entry->kind == 0 || entry->kind == 1)
                    break;
            }
            if (entry && func_0014C6B0(&entry->vector) > 0.01f) {
                Vector3 point;
                point.x = position.x;
                point.y = position.y + height;
                point.z = position.z;
                if (target && kind != -1) {
                    if (!(flags & 0x80000000)) {
                        if (first != -1) {
                            target->func_000606C0(first, &point);
                            target->func_00060930(first, 0);
                        } else {
                            first = target->func_000651E0(kind, &point, 0);
                        }
                    } else {
                        target->func_000651E0(kind, &point, 0);
                    }
                }
                state = 3;
            }
        }
        break;
    }
    value_98 = 0;
    value_9c = 0;
}
