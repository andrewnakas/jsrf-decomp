struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_001BA9C0();
void func_001BA8A0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int zero);
void __fastcall func_001BB270(float *scale);
void __fastcall func_001BB410(Vector3 *out);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C6B0(const Vector3 *vector);
void func_001BB650(float distance);
void func_001BB9C0(int *angles, int unused);

// The object the id at 0x200 names (only the fields used here).
struct Target_000B76A0 {
    char unknown_000[0x250];
    Vector3 turn;
    char unknown_25c[0xc0];
    Vector3 position;
    float distance;
    int pitch[3];
    int angles[3];
    Vector3 scale;
    char unknown_350[0x18];
    Vector3 velocity;
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD950).
struct Object_000B7440 {
    char unknown_000[0x98];
    Vector3 position;
    char unknown_0a4[0x48];
    Vector3 offset;
    int angles_f8;
    int words[12];
    Vector3 velocity;
    char unknown_138[4];
    int angles[3];
    char unknown_148[0xb8];
    int targetId;

    void func_000B76A0();
};

// Takes its velocity at 0x12c from the object the id at 0x200 names: in that object's frame (position, distance back
// along z, two turns and scale), the direction (0, 0, -1) turned by its degrees at 0x250 is transformed and normalised
// (func_0014C410), added to the object's velocity (0x368) and scaled by its length and 0.6. Then builds its own
// matrix from 0x98, the angles at 0x13c and 0xec into the words at 0xfc (func_001BB9C0).
void Object_000B7440::func_000B76A0()
{
    Vector3 direction;
    direction.x = 0.0f;
    direction.y = 0.0f;
    direction.z = -1.0f;
    Target_000B76A0 *target = (Target_000B76A0 *)data_0022FCE0->func_000128C0(targetId);
    func_001BA9C0();
    func_001BA8A0();
    func_001BAAA0(&target->position.x);
    func_001BB650(target->distance * -1.0f);
    func_001BAC50(target->angles, 0);
    func_001BAC50(target->pitch, 0);
    func_001BB270(&target->scale.x);
    func_001BA9C0();
    int turnAngles[3];
    turnAngles[0] = (int)(target->turn.x * 182.04445f);
    turnAngles[1] = (int)(target->turn.y * 182.04445f);
    turnAngles[2] = (int)(target->turn.z * 182.04445f);
    func_001BAC50(turnAngles, 0);
    func_001BAB20(&direction, &direction);
    func_0014C410(&direction, &direction);
    Vector3 unit;
    func_0014C410(&unit, &target->velocity);
    float speed = func_0014C6B0(&target->velocity);
    velocity.x = (direction.x + target->velocity.x) * speed * 0.6f;
    velocity.y = (direction.y + target->velocity.y) * speed * 0.6f;
    velocity.z = (direction.z + target->velocity.z) * speed * 0.6f;
    func_001BAA50();
    func_001BAAA0(&position.x);
    func_001BAC50(angles, 0);
    func_001BB410(&offset);
    func_001BB9C0(words, 0);
    func_001BAA50();
}
