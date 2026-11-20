/* sym: ??0Object_00101BE0@@QAE@PAUNode@@HIHH@Z = 0x00101BE0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??1Object_00101BE0@@UAE@XZ = 0x00101D60 */
/* sym: ?func_00011C90@Object_00101BE0@@UAEXXZ = 0x00101DC0 */
/* sym: ?func_00011C80@Object_00101BE0@@UAEXH@Z = 0x00101F20 */
/* sym: ?func_00011C90_2@Object_00101BE0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00101BE0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_00101BE0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_00101BE0@@UAEXXZ = 0x000AECC0 */
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

    Node(Node *parent, int id, unsigned int mask);
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

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

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    int func_001084E0(int index);
};

void func_001087D0(int handle, unsigned int count, int *values, int value);
void *func_00025700(unsigned int index, int first, int second, int third);

struct Object_0006E130 {
    int func_0006E130(int texture);
};

extern Object_0006E130 data_00252790;

// The resource the interface at data_00251D74 creates for this node (its slot 9); slot 2 releases it.
struct Interface_00101BE0 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

struct Interface_00251D74 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
    virtual long __stdcall slot9(int first, int second, Interface_00101BE0 **result);
};

extern Interface_00251D74 *data_00251D74;

// The corners of the screen rectangle.
extern float data_002207F8;
extern float data_002207FC;
extern float data_00220800;
extern float data_00220804;

// One of the eight corner entries at 0x68 (0x18 bytes each).
struct Corner_00101BE0 {
    int index;
    unsigned int color;
    float x;
    float y;
    int texture;
    int unknown_14;
};

// A direct child of Node (table 0x1D1D90, destructor func_00101D60): a four-digit number at 0x58 (its digits at 0x48)
// following entry 10 of its 0x115e-range owner (id at 0x138), drawn with a resource at 0x44.
struct Object_00101BE0 : Node {
    Object_00101BE0(Node *parent, int id, unsigned int mask, int value, int ownerId);
    virtual ~Object_00101BE0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    int unknown_040;
    Interface_00101BE0 *resource;
    int digits[4];
    int shown;
    int value;
    char unknown_060[8];
    Corner_00101BE0 first[4];
    Corner_00101BE0 second[4];
    int value_128;
    unsigned int state;
    unsigned int frame;
    float alpha;
    int ownerId;
    float scale;
};

// Takes the value and the owner's id, the owner's entry 10 (func_001084E0) and its digits, state 0 at alpha 1 and
// scale 0, and a resource from data_00251D74 (slot 9); without one the node unlinks itself, otherwise it takes the
// texture of sprite (0xa, 0, 0, 0) (at 0x120, in the last corner entry) and the eight corner entries (index -1, white) at the corners of data_002207F8 to
// data_00220804.
Object_00101BE0::Object_00101BE0(Node *parent, int id, unsigned int mask, int value, int ownerId)
    : Node(parent, id, mask)
{
    this->ownerId = ownerId;
    value_128 = value;
    resource = 0;
    shown = 0;
    this->value = 0;
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(ownerId);
    shown = this->value = owner->func_001084E0(10);
    func_001087D0(shown, 4, digits, 0);
    state = 0;
    alpha = 1.0f;
    scale = 0.0f;
    if (data_00251D74->slot9(5, 0, &resource) < 0) {
        func_00011BE0(this);
        func_00011C20(child);
        resource = 0;
    } else {
        second[3].texture = data_00252790.func_0006E130((int)func_00025700(0xa, 0, 0, 0));
        for (int i = 0; i < 4; i++) {
            second[i].index = -1;
            second[i].color = 0xffffff;
            first[i].index = -1;
            first[i].color = 0xffffff;
        }
        first[0].x = data_002207F8;
        first[0].y = data_002207FC;
        first[1].x = data_00220800;
        first[1].y = data_002207FC;
        first[2].x = data_002207F8;
        first[2].y = data_00220804;
        first[3].x = data_00220800;
        first[3].y = data_00220804;
    }
}
