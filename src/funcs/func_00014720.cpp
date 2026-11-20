/* sym: ?func_00011C80@Object_00014280@@UAEXH@Z = 0x00014720 */
struct Node {
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
    char unknown_0000[0x87f0];
    int frame;
};

extern Game *data_0022FCE0;

struct Trail_00014370 {
    int frame;
};

// The trail drawer (table 0x1C4500, constructor 0x141E0, destructor 0x14280): two lists of eight trails.
struct Object_00014280 : Node {
    virtual void func_00011C80(int argument);

    char unknown_44[0x2c];
    Trail_00014370 *trails[8];
    Trail_00014370 *others[8];
    unsigned int trailCount;
    unsigned int otherCount;

    void func_00014370(Trail_00014370 *trail);
};

// Slot 3 of the table at 0x1C4500: draws (func_00014370) the first trail of the first list and every trail of the
// second list that belong to the game's current frame (+0x87f0).
void Object_00014280::func_00011C80(int argument)
{
    int frame = data_0022FCE0->frame;
    for (unsigned int i = 0; i < trailCount; i++) {
        if (trails[i]->frame == frame) {
            func_00014370(trails[i]);
            break;
        }
    }
    for (unsigned int j = 0; j < otherCount; j++) {
        if (others[j]->frame == frame)
            func_00014370(others[j]);
    }
}
