struct Vector3 {
    float x;
    float y;
    float z;
};

// The object in data_00257CE4.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

float __fastcall func_0014C580(const Vector3 *a, const Vector3 *b);

// A mesh copy: the point its part is drawn at (first word) and its own position at 0x8.
struct Mesh_000DAF90 {
    Vector3 *origin;
    int unknown_04;
    Vector3 position;
};

// An item that draws a mesh (0x24 bytes; its mesh at 0x8).
struct Item_000162A0 {
    char unknown_00[8];
    Mesh_000DAF90 *mesh;
    char unknown_0c[0x18];
};

struct Item_00016260 {
    char unknown_00[8];
};

struct Box_00017CC0 {
    char unknown_00[0x18];
};

// The collision block at 0x6f8: its item, its box at 0x8.
struct Block_000DAF90 {
    Item_00016260 item;
    Box_00017CC0 box;
    char unknown_20[4];
    int value_24;
    char unknown_28[0xc];
    int value_34;
    char unknown_38[0xc];
};

struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int value);
    void func_000162A0(Item_000162A0 *item);
    void func_00017CC0(Box_00017CC0 *box, const Vector3 *points, unsigned int count);
};

extern Object_00016200 data_0022FCE8;

// A point of the trail (0x1c bytes).
struct Point_000DAF90 {
    Vector3 position;
    char unknown_0c[0x10];
};

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
    char unknown_34[0x10];
};


struct Object_000DB0F0 : Node {
    virtual void func_00011C90();

    void func_000DAF90();

    int state;
    unsigned int flags;
    int timer;
    Point_000DAF90 points[60];
    unsigned int head;
    unsigned int tail;
    char unknown_6e8[0x10];
    Block_000DAF90 block;
    Item_000162A0 items[16];
};

// Draws up to sixteen points of the trail from the tail at 0x6e4 to the head at 0x6e0 (wrapping at 60) that lie
// within 225 of the point at 0x7c of data_00257CE4, each with the next item from 0x73c; when the head and the tail
// are apart, the block at 0x6f8 spans them, else its 0x24 and 0x34 are cleared.
void Object_000DB0F0::func_000DAF90()
{
    unsigned int drawn = 0;
    unsigned int i = tail;
    while (i != head) {
        if (func_0014C580(&data_00257CE4->position, &points[i].position) < 225.0f) {
            items[drawn].mesh->position = points[i].position;
            *items[drawn].mesh->origin = points[i].position;
            data_0022FCE8.func_000162A0(&items[drawn]);
            if (++drawn >= 16) {
                break;
            }
        }
        if (++i >= 60) {
            i = 0;
        }
    }
    Vector3 ends[2];
    ends[0] = points[head].position;
    ends[1] = points[tail].position;
    if (func_0014C580(&ends[0], &ends[1]) > 0.0f) {
        data_0022FCE8.func_00017CC0(&block.box, ends, 2);
        data_0022FCE8.func_00016260(&block.item, -1);
    } else {
        block.value_24 = 0;
        block.value_34 = 0;
    }
}
