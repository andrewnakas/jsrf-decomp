/* sym: ??0Object_000667D0@@QAE@PAUNode@@HI@Z = 0x00066870 */
/* sym: ??1Object_000667D0@@UAE@XZ = 0x000663E0 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void *func_00025700(unsigned int index, int first, int second, int third);

struct Motion_0005F060;

// What func_00025700 gives for 0x17: three models and a motion.
struct Set_00066870 {
    void *models[3];
    Motion_0005F060 *motion;
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

// A node with no virtual functions of its own (table 0x1C43D8 repeats Node's slots 1 to 15) and mask 7.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);

    char unknown_44[0x50];
    int unknown_94;
};

// The node class whose table is at 0x1CB0A8 (data_00251F24 points at the one there is).
struct Object_000667D0 : Object_00012170 {
    Object_000667D0(Node *owner, int id, unsigned int flags);
    virtual ~Object_000667D0();

    int pending;
    char unknown_09c[8];
    unsigned int state;
    char unknown_0a8[8];
    int unknown_b0;
    Set_00066870 *set;
    Motion_0005F060 *motion;
    float time;
};

// Clears the request and the state, sets +0xb0 to -1, takes the set 0x17 from func_00025700 with its motion and
// starts the time at 0.
Object_000667D0::Object_000667D0(Node *owner, int id, unsigned int flags) : Object_00012170(owner, id, flags)
{
    pending = 0;
    state = 0;
    unknown_b0 = -1;
    set = (Set_00066870 *)func_00025700(0x17, 0, 0, 0);
    motion = set->motion;
    time = 0.0f;
}
