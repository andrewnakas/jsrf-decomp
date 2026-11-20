/* sym: ?func_00011C90_1@Object_000432E0@@UAEXXZ = 0x000433C0 */
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
    char unknown_34[0x10];
};

struct Game {
    int func_000127E0(int value);
};

extern Game *data_0022FCE0;

struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int flags);

extern void *data_00231D18[9];

// One entry (0x54 bytes, as in 0x43C00).
struct Entry_00043370 {
    float position[3];
    unsigned int kind;
    int unknown_10;
    unsigned int timer;
    int active;
    int hit;
    float time;
    float time_24;
    float alpha;
    char unknown_2c[0x10];
    int unknown_3c;
    char unknown_40[0x14];
};

// The node class whose table is at 0x1CA678 (constructor 0x43C00, destructor 0x432E0).
struct Object_000432E0 : Node {
    virtual ~Object_000432E0();
    virtual void func_00011C90_1();

    Entry_00043370 *entries;
    unsigned int count;
};

// Slot 2: for each entry: while active runs its motion by kind (lookups 0 and 1, 2 and 3, 1, or 5 with 6 on the
// second time) at half speed; when hit (+0x1c) with +0x3c set it goes inactive for a while (kinds 0 and 1: 60 times
// func_000127E0 (0x19f) of the game, 0x1c20 if that is 0; kind 5: 0x78; others 0x1c20), and fades in by 1/30 up to 1.
// An inactive entry counts its timer down and comes back at alpha 0.05. The hit flag is cleared every time.
void Object_000432E0::func_00011C90_1()
{
    for (unsigned int i = 0; i < count; i++) {
        if (entries[i].active) {
            switch (entries[i].kind) {
            case 0:
                func_0005E030((Motion_0005F060 *)data_00231D18[0], &entries[i].time, 0.5f, 0);
                break;
            case 1:
                func_0005E030((Motion_0005F060 *)data_00231D18[0], &entries[i].time, 0.5f, 0);
                break;
            case 2:
                func_0005E030((Motion_0005F060 *)data_00231D18[2], &entries[i].time, 0.5f, 0);
                break;
            case 3:
                func_0005E030((Motion_0005F060 *)data_00231D18[2], &entries[i].time, 0.5f, 0);
                break;
            case 4:
                func_0005E030((Motion_0005F060 *)data_00231D18[1], &entries[i].time, 0.5f, 0);
                break;
            case 5:
                func_0005E030((Motion_0005F060 *)data_00231D18[5], &entries[i].time, 0.5f, 0);
                func_0005E030((Motion_0005F060 *)data_00231D18[6], &entries[i].time_24, 0.5f, 0);
                break;
            }
            if (entries[i].hit && entries[i].unknown_3c) {
                switch (entries[i].kind) {
                case 0:
                case 1:
                    entries[i].timer = data_0022FCE0->func_000127E0(0x19f) * 60;
                    if (entries[i].timer == 0)
                        entries[i].timer = 0x1c20;
                    entries[i].active = 0;
                    break;
                case 5:
                    entries[i].timer = 0x78;
                    entries[i].active = 0;
                    break;
                default:
                    entries[i].timer = 0x1c20;
                    entries[i].active = 0;
                    break;
                }
            }
            entries[i].alpha += 1.0f / 30.0f;
            if (entries[i].alpha > 1.0f)
                entries[i].alpha = 1.0f;
        } else if (entries[i].timer > 0) {
            entries[i].timer--;
        } else {
            entries[i].active = 1;
            entries[i].alpha = 0.05f;
        }
        entries[i].hit = 0;
    }
}
