/* sym: ?func_00011C90_2@Object_000239D0@@UAEXXZ = 0x00023C50 */
struct Vector3 {
    float x;
    float y;
    float z;
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

    unsigned int func_000A4CF0(float *colour);

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

// A camera node (as in 0x1DAA0): eye at +0x44, target at +0x5c, field of view at +0x74, roll at +0x7c.
struct Object_00012170 : Node {
    Vector3 eye;
    char unknown_50[0xc];
    Vector3 target;
    char unknown_68[0xc];
    unsigned int fov;
    int unknown_78;
    int roll;
    int unknown_80;
    char unknown_84[0x14];
};

struct Object_00011CA0 {
    void func_00011CA0();
};

// The object 0x1ddc (table 0x1C4C88, constructor 0x24150).
struct Object_000239D0 : Object_00012170 {
    virtual ~Object_000239D0();
    virtual void func_00011C90_2();

    char unknown_098[0x14];
    float colour[4];
    float goal[4];
    float step;
    unsigned int packed;
    int done;
    Vector3 eye_d8;
    Vector3 target_e4;
    int roll_f0;
    int fov_f4;
};

// Slot 4: keeps the last view (func_00011CA0) and takes the view at +0xd8; until done (+0xd4) moves each of the four
// colour channels (+0xac) by the step (+0xcc) towards its goal (+0xbc), done when all four are there, and packs the
// colour into +0xd0 (func_000A4CF0).
void Object_000239D0::func_00011C90_2()
{
    ((Object_00011CA0 *)this)->func_00011CA0();
    eye.x = eye_d8.x;
    eye.y = eye_d8.y;
    eye.z = eye_d8.z;
    target.x = target_e4.x;
    target.y = target_e4.y;
    target.z = target_e4.z;
    fov = fov_f4;
    roll = roll_f0;
    if (!done) {
        int count = 0;
        for (int i = 0; i < 4; i++) {
            if (colour[i] == goal[i])
                count++;
            if (colour[i] < goal[i]) {
                colour[i] += step;
                if (colour[i] >= goal[i]) {
                    colour[i] = goal[i];
                    count++;
                }
            }
            if (colour[i] > goal[i]) {
                colour[i] -= step;
                if (colour[i] <= goal[i]) {
                    colour[i] = goal[i];
                    count++;
                }
            }
        }
        if (count == 4)
            done = 1;
        packed = func_000A4CF0(colour);
    }
}
