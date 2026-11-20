struct Game {
    void func_000127C0(int id, int value);
};

extern Game *data_0022FCE0;

// An entry of the stage's list at +0x194 (0x44 bytes).
struct Entry_00053FB0 {
    int kind;
    int unknown_04;
    int unknown_08;
    char unknown_0c[0x38];
};

struct Stage_0005BAD0 {
    char unknown_000[0x194];
    Entry_00053FB0 *entries;
};

// Object 9.
struct Object_0004ABA0 {
    char unknown_0000[0x54];
    int unknown_54;
    char unknown_0058[4];
    unsigned int state;
    char unknown_0060[0xfe0];
    Stage_0005BAD0 *stage;

    void func_0004D880();
    void func_00053FB0(int index);
};

// By the kind of the stage's entry `index`: 251 and 253 run func_0004D880 and take the entry's +4 (into +0x54) and
// +8 (game id 0x4d), 252 takes them alone; 254 and 255 run func_0004D880; then the state 0x5d / 0x5f / 0x61 / 0x63 /
// 0x65, or 0x67 for kind 257.
void Object_0004ABA0::func_00053FB0(int index)
{
    Entry_00053FB0 *entry = &stage->entries[index];
    switch (entry->kind) {
    case 251:
        func_0004D880();
        unknown_54 = entry->unknown_04;
        data_0022FCE0->func_000127C0(0x4d, entry->unknown_08);
        state = 0x5d;
        break;
    case 252:
        unknown_54 = entry->unknown_04;
        data_0022FCE0->func_000127C0(0x4d, entry->unknown_08);
        state = 0x5f;
        break;
    case 253:
        func_0004D880();
        unknown_54 = entry->unknown_04;
        data_0022FCE0->func_000127C0(0x4d, entry->unknown_08);
        state = 0x61;
        break;
    case 254:
        func_0004D880();
        state = 0x63;
        break;
    case 255:
        func_0004D880();
        state = 0x65;
        break;
    case 257:
        state = 0x67;
        break;
    }
}
