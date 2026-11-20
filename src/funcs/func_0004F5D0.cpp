struct Game {
    void func_000127C0(int index, int value);
    int func_000127E0(int index);
    void *func_000128C0(int index);
};

extern Game *data_0022FCE0;

// A record of object 0xb's table at +0x544 (0x34 bytes).
struct Record_000556D0 {
    int kind;
    char unknown_04[0x24];
    int size;
    int offset;
    int unknown_30;
};

struct Object_000556D0 {
    char unknown_000[0x544];
    Record_000556D0 records[4];
};

struct Node {
    void func_00011C20(Node *node);

    char unknown_00[0x28];
    Node *child;
};

struct Object_0004EF90 : Node {
    char unknown_2c[0x18];
    int next;
    char unknown_48[0x0c];
    int unknown_54;
    int unknown_58;
    int unknown_5c;
    unsigned int counts[4];
    void *made[4];
    int marked[4];
    Record_000556D0 *blocks[4];
    int sizes[4];

    void func_0004F5D0();
};

// A state handler (table 0x1FA008, slot 16): marks the players with a count and no block made yet; for each marked one
// notes the size of object 0xb's record (plus 0x10) and resets its block's record (kind 1, offset 0x34); then runs
// func_00011C20 on the child, clears three words and goes to state 17.
void Object_0004EF90::func_0004F5D0()
{
    unsigned int i;
    for (i = 0; i < 4; i++) {
        if (counts[i] > 0 && made[i] == 0) {
            marked[i] = 1;
        } else {
            marked[i] = 0;
        }
    }
    Object_000556D0 *source = (Object_000556D0 *)data_0022FCE0->func_000128C0(0xb);
    for (i = 0; i < 4; i++) {
        if (marked[i]) {
            sizes[i] = source->records[i].size + 0x10;
            Record_000556D0 *record = blocks[i];
            record->kind = 1;
            record->size = 0;
            record->offset = 0x34;
        } else {
            sizes[i] = 0;
        }
    }
    child->func_00011C20(child);
    unknown_54 = 0;
    unknown_58 = 0;
    unknown_5c = 0;
    next = 17;
}
