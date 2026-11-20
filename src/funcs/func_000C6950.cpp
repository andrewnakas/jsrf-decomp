/* sym: ??0Object_000C6690@@QAE@PAUNode@@HIPAUVector3@@1H@Z = 0x000C6690 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The two directions the pieces fly off in (turned by the facing).
extern Vector3 data_00216228;
extern Vector3 data_00216234;

int func_0014C7D0(float x, float z);
void func_001BAA00();
// Declared not to throw: retail leaves the second piece's unwind state live across this call (no reset to -1).
void func_001BAA50() throw();
void __fastcall func_001BB330(int angle);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);

// The class whose table is at 0x1CE030 (0xd0 bytes): a piece with a position, a velocity and a collision shape.
struct Object_000C6690 : Node {
    Object_000C6690(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *velocity, int count);

    char unknown_44[0x8c];
};

// Breaks into two pieces under node 9: facing the direction (`scale`, its x and z through func_0014C7D0), each of
// the directions data_00216228 and data_00216234 is turned (func_001BAC00) and a new Object_000C6690 starts 10
// along it from the place, flying that way.
void func_000C6950(void *place, float *scale)
{
    Node *owner = (Node *)data_0022FCE0->func_000128C0(9);
    int angle = func_0014C7D0(scale[0], scale[2]);
    func_001BAA00();
    func_001BB330(angle);
    Vector3 *position = (Vector3 *)place;
    Vector3 point = *position;
    Vector3 direction;
    func_001BAC00(&direction, &data_00216228);
    func_0014C730(&point, &direction, 10.0f);
    new Object_000C6690(owner, -1, 0, &point, &direction, 1);
    point = *position;
    func_001BAC00(&direction, &data_00216234);
    func_0014C730(&point, &direction, 10.0f);
    new Object_000C6690(owner, -1, 0, &point, &direction, 1);
    func_001BAA50();
}
