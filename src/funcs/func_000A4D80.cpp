/* sym: ??0Object_000A4D80@@QAE@PAUNode@@HIPAUParams_000A4D80@@@Z = 0x000A4D80 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??0Object_000461B0@@QAE@PAUNode@@HIH@Z = 0x000461B0 */
/* sym: ??1Object_000A4D80@@UAE@XZ = 0x000A2820 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000A4D80@@UAEXXZ = 0x000A5070 */
/* sym: ?func_00011C90_1@Object_000A4D80@@UAEXXZ = 0x000A28B0 */
/* sym: ?func_00011C80@Object_000A4D80@@UAEXH@Z = 0x000A2960 */
/* sym: ?func_00011C80_4@Object_000A4D80@@UAEXH@Z = 0x000B3DE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    Node *func_00011BD0();
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
    int player;
};

// The surface at +0x178: slot 3 opens a handle, slot 5 closes it, slot 16 presents it.
struct Surface_000A2960 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual int __stdcall slot3(int flags, void *settings, int argument);
    virtual void __stdcall slot4();
    virtual void __stdcall slot5(int handle);
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16(int handle);
};

// The quad drawer at +0x180.
struct Drawer_000A2960 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8(float scale, float alpha);
    virtual void __stdcall slot9(void *vertices, int argument);
};

void *__cdecl operator new(unsigned int size);

struct Interface_00251D74 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4(int first, int second, Surface_000A2960 **surface);
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9(int first, int second, Drawer_000A2960 **drawer);
};

extern Interface_00251D74 *data_00251D74;

struct Device_00251D6C {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30();
    virtual void __stdcall slot31(unsigned int value, float first, float second);
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37(void *out, const void *in, float scale);
};

extern Device_00251D6C *data_00251D6C;

// A screen vertex with texture coordinates (0x1c bytes).
struct TexturedVertex_000A2960 {
    float x;
    float y;
    float z;
    float u;
    float v;
    float unknown_14[2];
};

// The camera's screen quad and its indices.
extern TexturedVertex_000A2960 data_00215458[4];
extern unsigned short data_00215528[6];

struct Game {
    char unknown_0000[0x8838];
    int texture_8838;
    int texture_883c;

    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

struct Object_000461B0 : Node {
    Object_000461B0(Node *owner, int id, unsigned int flags, int value);
    virtual ~Object_000461B0();
};

int func_00108760(Node *node);
void func_00106B90(unsigned int handle, int value, int mode);
void *func_00025700(unsigned int kind, int first, int second, int third);
void func_001BAA00();
void __fastcall func_001BAA50();

// What the camera is made with: its screen at 0x10.
struct Params_000A4D80 {
    char unknown_00[0x10];
    int screen;
};

// The player (the camera's parent): its index at 0xc9c.
struct Player_000A4D80 {
    char unknown_000[0xc9c];
    int index;
};

// What the surface draws: the quad's vertices, their count, format and size, the indices and their count.
struct Settings_000A4D80 {
    TexturedVertex_000A2960 *vertices;
    int count;
    int format;
    int stride;
    unsigned short *indices;
    int indexCount;
};

// The class whose table is at 0x1CD518 (constructor 0xA4D80, destructor 0xA2820): overrides slots 1 (A5070),
// 2 (A28B0), 3 (A2960), 15 (B3DE0).
struct Object_000A4D80 : Object_00012170 {
    Object_000A4D80(Node *owner, int id, unsigned int flags, Params_000A4D80 *params);
    virtual ~Object_000A4D80();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_4(int argument);

    int screen;
    char unknown_09c[0x44];
    int unknown_0e0;
    int value_e4;
    float distance;
    int yaw;
    char unknown_0f0[0x78];
    int unknown_168;
    int texture_16c;
    int texture_170;
    void *texture_174;
    Surface_000A2960 *surface;
    Interface_00251D74 *factory;
    Drawer_000A2960 *drawer;
    int handle;
    Settings_000A4D80 settings;
    char unknown_1a0[0xc];
    unsigned int phase;
    char unknown_1b0[8];
    float colour[4];
    float colourTarget[4];
    float colourStep;
    unsigned int colourWord;
    int colourDone;
    Vector3 target;
    Vector3 anchor;
    char unknown_1fc[0xc];
    int mode;
    char unknown_20c[0x2c];
    int unknown_238;
    int sound;

    void func_000A32B0(Vector3 *first, Vector3 *second);
};

// Makes the camera for the screen in params (0x10), starting in mode 0xf with a child node (func_000461B0) and a
// sound handle (func_00108760) set from setting 0x19e, places the eye and the focus (func_000A32B0), scales the
// screen quad data_00215458 by 2.45 under a turned matrix and makes the surface and drawer that show it; the colour
// fade starts done at 0 with a step of 1/60. Keeps the player's index at 0x94.
Object_000A4D80::Object_000A4D80(Node *owner, int id, unsigned int flags, Params_000A4D80 *params)
    : Object_00012170(owner, id, flags)
{
    screen = params->screen;
    mode = 0xf;
    new Object_000461B0(this, -1, 0, 0);
    sound = func_00108760(this);
    func_00106B90(sound, ~data_0022FCE0->func_000127E0(0x19e), 0);
    func_00106B90(sound, data_0022FCE0->func_000127E0(0x19e), 1);
    func_000A32B0(&target, &anchor);
    unknown_0e0 = 0;
    value_e4 = 0;
    distance = 1.0f;
    unknown_168 = 0;
    yaw = 0;
    texture_16c = data_0022FCE0->texture_8838;
    texture_170 = data_0022FCE0->texture_883c;
    texture_174 = func_00025700(0xb, 0, 0, 0);
    func_001BAA00();
    data_00251D6C->slot31(0x2aaa, 1.0f, 20.0f);
    data_00251D6C->slot37(&data_00215458[0], &data_00215458[0], 2.45f);
    data_00251D6C->slot37(&data_00215458[1], &data_00215458[1], 2.45f);
    data_00251D6C->slot37(&data_00215458[2], &data_00215458[2], 2.45f);
    data_00251D6C->slot37(&data_00215458[3], &data_00215458[3], 2.45f);
    settings.vertices = data_00215458;
    settings.count = 4;
    settings.format = 0x202;
    settings.stride = 0x1c;
    settings.indices = data_00215528;
    settings.indexCount = 6;
    factory = data_00251D74;
    factory->slot4(1, 0, &surface);
    factory->slot9(1, 0, &drawer);
    handle = surface->slot3(0x202, &settings, 0);
    func_001BAA50();
    phase = 0;
    for (int i = 0; i < 4; i++) {
        colour[i] = 0.0f;
        colourTarget[i] = 0.0f;
    }
    colourWord = 0;
    colourDone = 1;
    colourStep = 0.016666668f;
    player = ((Player_000A4D80 *)func_00011BD0())->index;
    unknown_238 = 0;
}
