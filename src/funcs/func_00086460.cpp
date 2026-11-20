/* sym: ??1Object_00086960@@UAE@XZ = 0x00086460 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Mesh_00017F60;

// The collision world (data_0022FCE8).
struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

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

// The family of tables at 0x1CD120, 0x1CD170, 0x1CD1C0 and 0x1CD210 (constructor 0x862B0, destructor 0x86460): two
// collision meshes at +0x118 and +0x13c.
struct Object_00086960 : Node {
    virtual ~Object_00086960();

    char unknown_044[0xd4];
    Mesh_00017F60 *mesh;
    char unknown_11c[0x20];
    Mesh_00017F60 *otherMesh;
};

// Hands both collision meshes back to the world (func_00019760) when they are there.
Object_00086960::~Object_00086960()
{
    if (mesh) {
        data_0022FCE8.func_00019760(mesh);
    }
    if (otherMesh) {
        data_0022FCE8.func_00019760(otherMesh);
    }
}
