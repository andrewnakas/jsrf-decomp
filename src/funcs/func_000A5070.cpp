/* sym: ?func_00011C90@Object_000A4D80@@UAEXXZ = 0x000A5070 */
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

    Node *func_00011BD0();
    unsigned int func_000A4CF0(float *color);
};

// A viewport: left, top, width, height.
struct Settings_002155E8 {
    int values[4];
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
    Settings_002155E8 viewport;
    int unknown_94;
};

struct Object_00011CA0 {
    void func_00011CA0();
};

struct Game {
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

// The camera's parent (the player): the camera mode it asks for at 0xe58 and the states that override it.
struct Player_000A5070 {
    char unknown_000[0xe38];
    int grinding;
    int grindingSide;
    char unknown_e40[0x18];
    int mode;
    char unknown_e5c[0x6c];
    int special;
    char unknown_ecc[0x4c];
    int falling;
};

// The class whose table is at 0x1CD518 (constructor 0xA4D80, destructor 0xA2820): overrides slots 1 (A5070),
// 2 (A28B0), 3 (A2960), 15 (B3DE0).
struct Object_000A4D80 : Object_00012170 {
    virtual ~Object_000A4D80();
    virtual void func_00011C90();

    int screen;
    char unknown_09c[0x11c];
    float colour[4];
    float colourTarget[4];
    float colourStep;
    unsigned int colourWord;
    int colourDone;
    char unknown_1e4[0x24];
    int mode;
};

// The viewports by screen layout (setting 0xc of data_0022FCE0, four screens each).
extern Settings_002155E8 data_002155E8[];
// The handlers run when a mode starts (data_00215534) and every frame in it (data_00215570); 0 where a mode has none.
extern void (Object_000A4D80::*data_00215534[])();
extern void (Object_000A4D80::*data_00215570[])();

// Slot 1: runs func_00011CA0, takes the viewport for the screen layout and the screen at 0x98, picks the mode the
// player asks for (0xe58; 0xe while 0xf18, 0xa while 0xec8, 0xd while both 0xe38 and 0xe3c are set), runs the start
// handler on a change and the frame handler of the mode. Until all four colour components at 0x1b8 reach those at
// 0x1c8 (by the step at 0x1d8) marks 0x1e0 and packs the colour into 0x1dc (func_000A4CF0).
void Object_000A4D80::func_00011C90()
{
    ((Object_00011CA0 *)this)->func_00011CA0();
    viewport = data_002155E8[screen + data_0022FCE0->func_000127E0(0xc) * 4];
    Player_000A5070 *player = (Player_000A5070 *)func_00011BD0();
    int next = player->mode;
    if (player->falling) {
        next = 0xe;
    }
    if (player->special) {
        next = 0xa;
    }
    if (player->grinding && player->grindingSide) {
        next = 0xd;
    }
    if (next != mode) {
        void (Object_000A4D80::*start)() = data_00215534[next];
        if (start) {
            (this->*start)();
        }
        mode = next;
    }
    void (Object_000A4D80::*handler)() = data_00215570[mode];
    if (handler) {
        (this->*handler)();
    }
    if (!colourDone) {
        int count = 0;
        for (int i = 0; i < 4; i++) {
            if (colour[i] == colourTarget[i]) {
                count++;
            }
            if (colour[i] < colourTarget[i]) {
                colour[i] += colourStep;
                if (colour[i] >= colourTarget[i]) {
                    colour[i] = colourTarget[i];
                    count++;
                }
            }
            if (colour[i] > colourTarget[i]) {
                colour[i] -= colourStep;
                if (colour[i] <= colourTarget[i]) {
                    colour[i] = colourTarget[i];
                    count++;
                }
            }
        }
        if (count == 4) {
            colourDone = 1;
        }
        colourWord = func_000A4CF0(colour);
    }
}
