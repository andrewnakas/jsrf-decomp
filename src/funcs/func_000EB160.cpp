/* sym: ??0Object_000EAD20@@QAE@PAUNode@@HIPAUVector3@@@Z = 0x000EAD20 */
struct Node;
struct Vector3;

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// The owner type of the Object_000CC600 family.
struct Object_000C5B50;

// The Node child func_000EAD20 builds (0x84 bytes).
struct Object_000EAD20 {
    Object_000EAD20(Node *owner, int id, unsigned int flags, Vector3 *position);
    virtual ~Object_000EAD20();

    char unknown_04[0x80];
};

// Builds an Object_000EAD20 under the owner at the position, with the first free id in [0x13B3, 0x15B3] and the flags
// 0x800, when there is a free id.
void func_000EB160(Object_000C5B50 *owner, Vector3 *position)
{
    int id = data_0022FCE0->func_000128E0(0x13b3, 0x15b3);
    if (id >= 0) {
        new Object_000EAD20((Node *)owner, id, 0x800, position);
    }
}
