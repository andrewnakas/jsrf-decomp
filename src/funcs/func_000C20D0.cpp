/* sym: ?func_000C3140@Object_000C20A0@@UAEXXZ = 0x000C20D0 */
struct Data_000C2700;

struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Motion_0005F060;

// The motions at 0xc8 of data_00257CEC.
struct Motions_000C3350 {
    char unknown_00[0xc];
    Motion_0005F060 *fourth;
};

struct Object_000C3BE0 {
    char unknown_00[0xc8];
    Motions_000C3350 *motions;
};

extern Object_000C3BE0 *data_00257CEC;

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1450.
struct Object_00157F10 : Object_000C1440 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *point);
};

extern Object_00157F10 *data_00257CE8;

struct Object_000607B0 {
    int func_000651E0(int kind, void *position, Vector3 *direction);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A direction with a spare word (what func_0014CD50 fills).
struct Heading_000CFB70 {
    Vector3 vector;
    float w;
};

// One row of data_00215E90 (8 bytes): the sound at 2.
struct Row_000C3140 {
    short unknown_00;
    short sound;
    int unknown_04;
};

extern Row_000C3140 data_00215E90[];

int func_00118750(int id, unsigned int index);
int func_00119540(int group, int index, void *position);
void __fastcall func_0014CD50(Vector3 *out, const Vector3 *in);

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470); slot 9 is the
// destructor.
struct Object_000C2420 {
    Object_000C2420(Data_000C2700 *data);
    virtual void func_000C2630();
    virtual void func_000C2700();
    virtual void func_000C3800();
    virtual void func_000C30C0();
    virtual void func_000C3100();
    virtual void func_000C3140();
    virtual void func_000C31B0();
    virtual void func_000C3350();
    virtual void func_000C33C0();
    virtual ~Object_000C2420();
    virtual void func_000C2480();
    virtual void func_000C36F0();
    virtual void func_000C2FE0();
    virtual void func_000C2500();
    virtual void func_000C2560();
    virtual void func_000C25D0();
    virtual int func_000C2AA0();

    Vector3 position;
    char unknown_10[0xc];
    Angles_000C1300 angles;
    float speed;
    char unknown_2c[8];
    unsigned int state;
    char unknown_38[0x18];
    Vector3 point;
    char unknown_5c[4];
    int index;
    char unknown_64[0x18];
    Motion_0005F060 *motion;
    float time;
    char unknown_84[0x48];
    int handle;
};

// The class whose table is at 0x1CDC60 (constructor func_000C2010, destructor func_000C2030): overrides slots 5,
// 6, 11 and 16 of its base, and slots 14 and 15 with empty functions.
struct Object_000C20A0 : Object_000C2420 {
    Object_000C20A0(Data_000C2700 *data);
    virtual void func_000C3140();
    virtual void func_000C31B0();
    virtual ~Object_000C20A0();
    virtual void func_000C36F0();
    virtual void func_000C2560();
    virtual void func_000C25D0();
    virtual int func_000C2AA0();
};

// Overrides slot 5: time 0, state 6, the fourth motion of data_00257CEC and speed 25/36; turns the angles toward the
// point at 0x50 (func_000C1300). Tells node 0xe8 (func_000651E0, kind 0x5d for row 0x21, else 0x5c) about the
// position and the point's direction (func_0014CD50), keeping the answer at 0xcc (-1 without the node), and plays
// sound 0x34 of the row at 0x60 of data_00215E90 at the position unless func_00118750 says it is playing.
void Object_000C20A0::func_000C3140()
{
    time = 0.0f;
    state = 6;
    motion = data_00257CEC->motions->fourth;
    speed = 0.69444442f;
    data_00257CE8->func_000C1300(&angles, &point);
    Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (node) {
        int kind = (index == 0x21) + 0x5c;
        Heading_000CFB70 direction;
        func_0014CD50(&direction.vector, &point);
        handle = node->func_000651E0(kind, &position, &direction.vector);
        if (!func_00118750(0x34, data_00215E90[index].sound)) {
            func_00119540(0x34, data_00215E90[index].sound, &position);
        }
    } else {
        handle = -1;
    }
}
