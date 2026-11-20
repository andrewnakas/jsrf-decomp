/* sym: ??0Object_0001DA20@@QAE@PAUNode@@HI@Z = 0x0001DAF0 */
/* sym: ??1Object_0001DA20@@UAE@XZ = 0x0001DA20 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Light_00046920 {
    int unknown_00;
    unsigned int color_04;
    unsigned int color_08;
    int unknown_0c;
    Vector3 direction;
    char unknown_1c[0x24];
    unsigned int color_40;
    int unknown_44;
    unsigned int color_48;
    int unknown_4c;
    int value_50;
    char unknown_54[0x1c];
};

// The light stack (data_001F93C8).
struct Object_00046670 {
    void func_00046700(const Light_00046920 *light);
    void func_00046740(Light_00046920 *light);
    void func_00046940(int enable);
};

extern Object_00046670 data_001F93C8;

extern "C" void *memset(void *destination, int value, unsigned int size);

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

// A camera node (table 0x1C43D8 repeats Node's slots 1 to 15; mask 7): eye, target, field of view and roll.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);

    Vector3 eye;
    char unknown_50[0xc];
    Vector3 target;
    char unknown_68[0xc];
    unsigned int fov;
    int unknown_78;
    int roll;
    int unknown_80;
    int left;
    int top;
    int width;
    int height;
    int unknown_94;
};

// A camera node with the table at 0x1C4580 (destructor 0x1DA20).
struct Object_0001DA20 : Object_00012170 {
    Object_0001DA20(Node *owner, int id, unsigned int flags);
    virtual ~Object_0001DA20();

    int child;
};

// Puts the eye at the origin looking 3000 units down z over a 640x480 viewport (sort key 15, no child node), then
// pushes a white light pointing down z on the light stack, makes it the current one and turns lighting off.
Object_0001DA20::Object_0001DA20(Node *owner, int id, unsigned int flags)
    : Object_00012170(owner, id, flags)
{
    eye.x = 0.0f;
    eye.y = 0.0f;
    eye.z = 0.0f;
    target.x = 0.0f;
    target.y = 0.0f;
    target.z = 3000.0f;
    left = 0;
    top = 0;
    width = 640;
    height = 480;
    sortKey = 15;
    child = 0;
    Light_00046920 light;
    memset(&light, 0, sizeof light);
    light.direction.x = 0.0f;
    light.direction.y = 0.0f;
    light.direction.z = 1.0f;
    light.value_50 = 0;
    light.color_04 = 0xffffff;
    light.color_08 = 0;
    data_001F93C8.func_00046700(&light);
    data_001F93C8.func_00046740(&light);
    data_001F93C8.func_00046940(0);
}
