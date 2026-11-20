struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_00060810(int key);
};

// The owner type of the Object_000CC600 family.
struct Object_000C5B50 {
    void func_000C5B50(int *handle);
};

struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

// The chain link (table 0x1CE1B8).
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

struct Source_000ECB50 {
    char unknown_00[0x18];
    int value_18;
};

// The object func_000ECB50 builds; this is a handler of the table at 0x258520 its slot 1 (func_000ECDB0) runs,
// filled in by the dynamic initializer func_0018C0C0.
struct Object_000ECB50 : Node, Object_000C60C0 {
    char unknown_048[0x48];
    unsigned int flags;
    char unknown_094[0x1c];
    Object_000C5B50 *owner;
    char unknown_0b4[0x20];
    int handles_d4[4];
    int handles_e4[4];
    char unknown_0f4[0x34];
    int next;
    int phase;
    char unknown_130[0xc];
    Source_000ECB50 *source;
    int value_140;
    char unknown_144[0x20];
    int effects[4];
    char unknown_174[0x50];
    int effect_1c4;

    void func_000EC650();
};

// Entry 5 of the handlers at 0x258520: counts up at 0x12c; past 60, state 6 with the flag 0x2000, the link's slot 1,
// 0x140 takes the source's 0x18, object 0xE8 (if any) releases the five effects, and the eight handles at 0xd4 go
// back to the owner at 0xb0.
void Object_000ECB50::func_000EC650()
{
    if (++phase > 60) {
        next = 6;
        flags |= 0x2000;
        func_000C60C0();
        value_140 = source->value_18;
        Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (node) {
            for (int i = 0; i < 4; i++) {
                node->func_00060810(effects[i]);
            }
            node->func_00060810(effect_1c4);
        }
        for (int j = 0; j < 4; j++) {
            owner->func_000C5B50(&handles_d4[j]);
            owner->func_000C5B50(&handles_e4[j]);
        }
    }
}
