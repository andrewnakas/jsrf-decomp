/* sym: ??1Object_0006CEE0@@UAE@XZ = 0x0006CEE0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void __cdecl operator delete(void *memory);
void func_000F78C0(int value);
void func_000FE550(int index);

// The six sounds the class may hold (0x1CC300).
extern const int data_001CC300[6];

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

// The class whose table is at 0x1CC5D0 (constructor 0x6D9A0, destructor 0x6CEE0; 0x188 bytes).
struct Object_0006CEE0 : Node {
    virtual ~Object_0006CEE0();

    char unknown_044[0x20];
    void *buffer;
    char unknown_068[0x108];
    int playing[6];
};

// Runs func_000F78C0(0), stops each of the six sounds of 0x1CC300 whose flag at +0x170 is set (func_000FE550) and
// frees the buffer at +0x64.
Object_0006CEE0::~Object_0006CEE0()
{
    func_000F78C0(0);
    for (int i = 0; i < 6; i++) {
        if (playing[i]) {
            func_000FE550(data_001CC300[i]);
        }
    }
    if (buffer) {
        operator delete(buffer);
    }
}
