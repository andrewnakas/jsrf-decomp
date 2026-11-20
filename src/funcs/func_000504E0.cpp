/* sym: ?func_00011C90_1@Object_00050320@@UAEXXZ = 0x000504E0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Plane_0007F030 {
    Vector3 point;
    float distance;
    Vector3 normal;
};

void __fastcall func_0014C340(Vector3 *vector, const Vector3 *offset);
float __fastcall func_0014BD00(Vector3 *out, const Vector3 *point, const Plane_0007F030 *plane);

struct Game {
    void *func_000128C0(int id);
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();

    char unknown_04[0x40];
};

struct Object_00012170 : Node {
    Vector3 eye;
    char unknown_50[0xc];
    Vector3 target;
    char unknown_68[0xc];
    unsigned int fov;
    int unknown_78;
    int roll;
};

// Object 0x12ac: the ids at +0x88c (with their count) and the slots they stand for at +0x894.
struct Object_0004FC40 {
    char unknown_000[0x88c];
    int *ids;
    unsigned int count;
    int *slots;
};

// Objects 0xc and on: the object they hold at +0x8d4.
struct Member_000504E0 {
    char unknown_000[0x8d4];
    int holder;
};

// What a member holds: where it is (+0xca4) and how the camera looks at it (+0xec8 on, +0xecc mode: 0 from the
// point at +0xed0, 1 from the plane at +0xedc, 2 from where it is moved by +0xed0).
struct Holder_000504E0 {
    char unknown_000[0xca4];
    Vector3 position;
    char unknown_cb0[0x218];
    int watched;
    int mode;
    Vector3 point;
    Plane_0007F030 plane;
};

// The camera node class whose table is at 0x1CAC18.
struct Object_00050320 : Object_00012170 {
    virtual void func_00011C90_1();
};

// Slot 2: for every slot of object 0x12ac whose id is the game's value 0x1ac, aims the camera at what its member
// (object slot + 0xc) holds when that is watched: the target 14 above its position, the eye by the holder's mode;
// field of view 0x3555, no roll.
void Object_00050320::func_00011C90_1()
{
    Object_0004FC40 *list = (Object_0004FC40 *)data_0022FCE0->func_000128C0(0x12ac);
    int current = data_0022FCE0->func_000127E0(0x1ac);
    if (!list) {
        return;
    }
    for (unsigned int i = 0; i < list->count; i++) {
        if (list->ids[i] != current) {
            continue;
        }
        Member_000504E0 *member = (Member_000504E0 *)data_0022FCE0->func_000128C0(list->slots[i] + 0xc);
        if (!member) {
            continue;
        }
        int held = member->holder;
        Holder_000504E0 *holder = (Holder_000504E0 *)data_0022FCE0->func_000128C0(held);
        if (!holder || !holder->watched) {
            continue;
        }
        {
            Vector3 look = holder->position;
            {
                Vector3 from;
                switch (holder->mode) {
                case 0:
                    from = holder->point;
                    look.y += 14.0f;
                    break;
                case 1:
                    look.y += 14.0f;
                    func_0014BD00(&from, &look, &holder->plane);
                    break;
                case 2:
                    from = holder->position;
                    look.y += 14.0f;
                    func_0014C340(&from, &holder->point);
                    break;
                }
                eye.x = from.x;
                eye.y = from.y;
                eye.z = from.z;
            }
            target.x = look.x;
            target.y = look.y;
            target.z = look.z;
        }
        fov = 0x3555;
        roll = 0;
    }
}
