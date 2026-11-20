/* sym: ??0Object_00086900@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x00086900 */
/* sym: ??0Object_00086980@@QAE@PAUNode@@HIPAUVector3@@1H@Z = 0x00086980 */
/* sym: ??0Object_00086D30@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x00086D30 */
void *__cdecl operator new(unsigned int size);
void __cdecl operator delete(void *memory);

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A player (object 4 and on): a word at +0x116c.
struct Object_000A1C50 {
    char unknown_0000[0x116c];
    int unknown_116c;
};

struct Node {
    unsigned int flags;
};

// The kind whose table is at 0x1CD170 (0x158 bytes).
struct Object_00086900 {
    Object_00086900(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction);

    char unknown_000[0x158];
};

// The kind whose table is at 0x1CD1C0 (0x164 bytes): aimed at the object with the given id.
struct Object_00086980 {
    Object_00086980(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction, int target);

    char unknown_000[0x164];
};

// The kind whose table is at 0x1CD210 (0x158 bytes).
struct Object_00086D30 {
    Object_00086D30(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction);

    char unknown_000[0x158];
};

// Makes one of the three kinds of the family at 0x1CD120 under object 9 (when it is there): kind 0 (0x1CD170),
// kind 1 aimed at the object `target` (0x1CD1C0; only while that object is there with its +0x116c clear, else it
// falls back to kind 2) or kind 2 (0x1CD210). Called from the player (0x80BD0).
void func_00086E30(Vector3 *position, Vector3 *direction, int target, int kind)
{
    Node *owner = (Node *)data_0022FCE0->func_000128C0(9);
    if (!owner) {
        return;
    }
    switch (kind) {
    case 0:
        new Object_00086900(owner, -1, 0, position, direction);
        break;
    case 1: {
        Object_000A1C50 *object = (Object_000A1C50 *)data_0022FCE0->func_000128C0(target);
        if (object && !object->unknown_116c) {
            new Object_00086980(owner, -1, 0, position, direction, target);
            break;
        }
    }
    case 2:
        new Object_00086D30(owner, -1, 0, position, direction);
        break;
    }
}
