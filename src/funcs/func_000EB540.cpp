/* sym: ??0Object_000EB440@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x000EB290 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Node;

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);

extern int data_00219308[][3];
extern Vector3 data_00219338;
extern int data_00219344[10];
extern int data_0021936C[][3];

// The child of Node whose table is at 0x1CEED8 (0xe0 bytes; constructor func_000EB290).
struct Object_000EB440 {
    Object_000EB440(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *velocity);

    char unknown_00[0xdc];
    int value_dc;
};

// Fans ten Object_000EB440 out of `position` under object 9 (id -1, flags 4): the n-th moves along data_00219338
// turned by the heading data_0021936C gives for (column, row), by -0x1555 + n * 0x444 and by the n-th pitch of
// data_00219344, and takes the value data_00219308 gives for (column, row). Called by func_000EC3E0.
void func_000EB540(Vector3 *position, int column, int row)
{
    Node *owner = (Node *)data_0022FCE0->func_000128C0(9);
    int angle = -0x1555;
    for (unsigned int i = 0; i < 10; i++, angle += 0x444) {
        func_001BAA00();
        func_001BB330(data_0021936C[row][column]);
        func_001BB330(angle);
        func_001BB2E0(data_00219344[i]);
        Vector3 velocity;
        func_001BAC00(&velocity, &data_00219338);
        func_001BAA50();
        Object_000EB440 *object = new Object_000EB440(owner, -1, 4, position, &velocity);
        object->value_dc = data_00219308[row][column];
    }
}
