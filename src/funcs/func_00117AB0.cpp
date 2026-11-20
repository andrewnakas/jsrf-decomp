/* sym: ?func_00011C90@Object_00117A30@@UAEXXZ = 0x00117AB0 */
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
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Marker_00117B20 {
    int id;
    Vector3 position;
};

struct Sound_00117AB0 {
    int group;
    int index;
};

struct Object_00117A30 : Node {
    virtual ~Object_00117A30();
    virtual void func_00011C90();

    char unknown_034[0x14];
    int played;
    unsigned int count;
    Marker_00117B20 markers[32];
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern Sound_00117AB0 data_002227A8[];
int func_00119540(int group, int index, void *position);

// Slot 1 of the table at 0x1D77B8: once object 0x4c exists, plays the sound of each marker at its position
// (func_00119540 with the group and entry data_002227A8 gives for the marker's id), once.
void Object_00117A30::func_00011C90()
{
    if (data_0022FCE0->func_000128C0(0x4c) && !played) {
        for (unsigned int i = 0; i < count; i++) {
            Sound_00117AB0 *sound = &data_002227A8[markers[i].id];
            func_00119540(sound->group, sound->index, &markers[i].position);
        }
        played = 1;
    }
}
