/* sym: ??1Object_000265A0@@UAE@XZ = 0x000260D0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Object_000265A0;

extern void (Object_000265A0::*data_001EC288[])(int argument);

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

// Object 7 (table 0x1C4F68).
struct Object_000265A0 : Node {
    virtual ~Object_000265A0();

    int pending;
    unsigned int handler;
    int argument;

    void func_000255C0();
};

// As func_00026080: when a call is pending (+0x44), runs func_000255C0 and the pending handler (+0x48, table 0x1EC288)
// with its argument (+0x4c), then clears the request.
Object_000265A0::~Object_000265A0()
{
    if (pending == 1) {
        func_000255C0();
        if (handler < 0x21) {
            void (Object_000265A0::*run)(int) = data_001EC288[handler];
            int value = argument;
            if (run) {
                (this->*run)(value);
            }
            pending = 0;
        }
    }
}
