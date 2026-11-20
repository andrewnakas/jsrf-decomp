struct Vector3 {
    float x;
    float y;
    float z;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

struct Item_00016260 {
    int unknown_00;
    int value;
    Box_00017CC0 box;
    int unknown_20[8];
    Item_00016260 *next;
};

struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int value);
    void func_00017D90(Box_00017CC0 *box, const Vector3 *points, unsigned int count, float radius);
};

extern Object_00016200 data_0022FCE8;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A player (object 4 and on): a word at +0x116c.
struct Object_000A1C50 {
    char unknown_0000[0x116c];
    int unknown_116c;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *matrix);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

// The family of tables at 0x1CD120, 0x1CD170, 0x1CD1C0 and 0x1CD210 (constructor 0x862B0, destructor 0x86460).
struct Object_00086960 {
    virtual ~Object_00086960();

    char unknown_004[0x4c];
    Vector3 position;
    Vector3 direction;
    char unknown_068[0xc];
    float scale;
    float lift;
    char unknown_07c[0xc];
    int angleX;
    int angleY;
    int angleZ;
    char unknown_094[0x28];
    Vector3 point;
    float radius;
    Item_00016260 shape;
    char unknown_110[0x48];
    int target;
    int following;

    void func_00086850();
    void func_000868A0();
    void func_00086AC0(Object_000A1C50 *object);
    virtual void func_00086FA0();
};

// Slot 16 of the table at 0x1CD1C0: turns the three angles at +0x88 by -0x222, 0x111 and -0x111; while it follows
// (+0x15c) the target with the id at +0x158 it steers at it (func_00086AC0) as long as the target is there and its
// +0x116c is clear, else it stops following and takes the lift from the scale and the direction's y; when it does not
// follow it moves on (func_000868A0). Then puts a box of the radius around the point at +0xbc, placed at the
// position, into the shape at +0xcc, queues it on the collision world and runs func_00086850.
void Object_00086960::func_00086FA0()
{
    angleX -= 0x222;
    angleY += 0x111;
    angleZ -= 0x111;
    if (following) {
        Object_000A1C50 *object = (Object_000A1C50 *)data_0022FCE0->func_000128C0(target);
        if (object && !object->unknown_116c) {
            func_00086AC0(object);
        } else {
            following = 0;
            lift = scale * direction.y;
        }
    }
    if (!following) {
        func_000868A0();
    }
    func_001BA9C0();
    func_001BAAA0(&position.x);
    func_001BAB20(&point, 0);
    data_0022FCE8.func_00017D90(&shape.box, &point, 1, radius);
    data_0022FCE8.func_00016260(&shape, -1);
    func_00086850();
    func_001BAA50();
}
