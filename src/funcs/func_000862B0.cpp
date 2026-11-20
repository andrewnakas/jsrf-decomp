/* sym: ??0Object_00086960@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x000862B0 */
/* sym: ??1Object_00086960@@UAE@XZ = 0x00086460 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);
void *func_00025700(unsigned int index, int first, int second, int third);

struct Mesh_00017F60;

// The collision world (data_0022FCE8).
struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_0020DA3C;
extern Mesh_00017F60 data_0020DA78;

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

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

// A collision body (0x24 bytes): its kinds, its mesh and a word at +0x14.
struct Body_000862B0 {
    int kind;
    int mask;
    Mesh_00017F60 *mesh;
    char unknown_0c[8];
    int unknown_14;
    char unknown_18[0xc];
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

struct Item_00016260 {
    int unknown_00;
    int value;
    Box_00017CC0 box;
    int unknown_20[8];
    Item_00016260 *next;
};

// The family of tables at 0x1CD120, 0x1CD170, 0x1CD1C0 and 0x1CD210 (constructor 0x862B0, destructor 0x86460).
struct Object_00086960 : Node {
    Object_00086960(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction);
    virtual ~Object_00086960();

    Vector3 start;
    Vector3 position;
    Vector3 direction;
    char unknown_068[0x20];
    int unknown_88;
    int unknown_8c;
    int unknown_90;
    int unknown_94;
    int unknown_98;
    int unknown_9c;
    int still;
    int unknown_a4;
    int unknown_a8;
    char unknown_ac[4];
    void *unknown_b0;
    void *unknown_b4;
    void *unknown_b8;
    Vector3 point;
    float radius;
    Item_00016260 shape;
    Body_000862B0 body;
    Body_000862B0 otherBody;
};

// Sets flags 0x8100, keeps the position (twice) and the direction flattened to y 0 (+0x5c; a zero-length one clears
// it and sets +0xa0), clears the counters, takes +0xb0 to +0xb8 from func_00025700, sets the radius at +0xc8 to 10,
// clears the shape at +0xcc (kind 0xf3ff) and makes the two collision bodies from the meshes at 0x20DA3C and
// 0x20DA78.
Object_00086960::Object_00086960(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction)
    : Node(owner, id, flags)
{
    this->flags = 0x8100;
    this->position = *position;
    start = *position;
    this->direction = *direction;
    this->direction.y = 0.0f;
    if (func_0014C460(&this->direction, &this->direction) > 0.0f) {
        still = 0;
    } else {
        this->direction.z = 0.0f;
        this->direction.x = 0.0f;
        still = 1;
    }
    unknown_88 = unknown_8c = unknown_90 = 0;
    unknown_94 = unknown_98 = 0;
    unknown_a4 = 0;
    unknown_a8 = 0;
    unknown_b0 = func_00025700(11, 0, 1, 14);
    unknown_b4 = func_00025700(11, 0, 2, 0);
    unknown_b8 = func_00025700(11, 0, 3, 0);
    radius = 10.0f;
    memset(&shape, 0, sizeof(shape));
    shape.unknown_00 = 0xf3ff;
    body.mesh = data_0022FCE8.func_00019680(&data_0020DA3C);
    body.kind = 0x40;
    body.mask = 0x41;
    body.unknown_14 = 0;
    otherBody.mesh = data_0022FCE8.func_00019680(&data_0020DA78);
    otherBody.kind = 0x40;
    otherBody.unknown_14 = 0;
    otherBody.mask = 1;
}
