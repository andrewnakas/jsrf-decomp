/* sym: ?func_00011C90@Object_000243F0@@UAEXXZ = 0x00024700 */
struct Node {
    unsigned int func_000A4CF0(float *color);
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

// A node with no virtual functions of its own (table 0x1C43D8 repeats Node's slots 1 to 15) and mask 7.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);

    char unknown_44[0x50];
    int unknown_94;
};

// The class whose table is at 0x1C4D10: overrides slots 1 (24700), 3 (24400), 4 (AECC0), 6 (B3DE0), 7 (AECC0), 9 (B3DE0), 10 (AECC0), 13 (AECC0).
struct Object_000243F0 : Object_00012170 {
    virtual ~Object_000243F0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    float current[4];
    float target[4];
    float step;
    unsigned int color;
    int finished;
};

// Slot 1: moves each of the four colour components a step towards its target; once all four are there the fade
// is finished. Packs the colour.
void Object_000243F0::func_00011C90()
{
    if (!finished) {
        int done = 0;
        for (int i = 0; i < 4; i++) {
            if (current[i] == target[i]) {
                done++;
            }
            if (current[i] < target[i]) {
                current[i] += step;
                if (current[i] >= target[i]) {
                    current[i] = target[i];
                    done++;
                }
            }
            if (current[i] > target[i]) {
                current[i] -= step;
                if (current[i] <= target[i]) {
                    current[i] = target[i];
                    done++;
                }
            }
        }
        if (done == 4) {
            finished = 1;
        }
        color = func_000A4CF0(current);
    }
}
