/* sym: ??1Object_00014280@@UAE@XZ = 0x00014280 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// A ring of points from `start` to `end`.
struct Trail_00014370 {
    int unknown_00;
    int start;
    int end;
    int last;
    Vector3 *points;
};

// The vertex buffer the trails are drawn from: slot 2 releases it.
struct Buffer_00014280 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall Release();
};

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

// The node class whose table is at 0x1C4500 (trails; constructor 0x141E0, 0xc0 bytes).
struct Object_00014280 : Node {
    virtual ~Object_00014280();

    char unknown_44[0x2c];
    Trail_00014370 *trails[8];
    Trail_00014370 *fading[8];
    unsigned int count;
    unsigned int fadingCount;
    Buffer_00014280 *buffer;
    int enabled;
};

// Frees every live and fading trail with its points, then releases the vertex buffer at +0xb8.
Object_00014280::~Object_00014280()
{
    for (unsigned int i = 0; i < count; i++) {
        delete trails[i]->points;
        delete trails[i];
    }
    count = 0;
    for (unsigned int j = 0; j < fadingCount; j++) {
        delete fading[j]->points;
        delete fading[j];
    }
    fadingCount = 0;
    if (buffer) {
        buffer->Release();
        buffer = 0;
    }
}
