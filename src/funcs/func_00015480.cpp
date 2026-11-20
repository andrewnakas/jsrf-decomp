struct Vector3 {
    float x;
    float y;
    float z;
};

extern "C" void *memset(void *destination, int value, unsigned int size);
void func_001BAA00();
void func_001BA9C0();
void __fastcall func_001BAAA0(float *matrix);
void __fastcall func_001BAB20(Vector3 *to, const Vector3 *from);
void __fastcall func_001BAA50();

// A frame of the model (0x6c bytes): the index of its part at +0x8, its matrix at +0x14.
struct Frame_00015480 {
    char unknown_00[8];
    int part;
    char unknown_0c[8];
    float matrix[16];
    char unknown_54[0x18];
};

// The model +0x38 points at: its frames (+0x8) and their count (+0x1c).
struct Model_00015480 {
    char unknown_00[8];
    Frame_00015480 *frames;
    char unknown_0c[0x10];
    unsigned int count;
};

// A part (0x5c bytes) of the table at +0x84: its position, two copies of it and a cleared vector.
struct Part_00015480 {
    Vector3 position;
    Vector3 previous;
    float velocity[3];
    Vector3 start;
    char unknown_30[0x2c];
};

// The class whose table at 0x1C454C holds only its scalar deleting destructor 0x15D50 (constructor 0x15420).
struct Object_00015D50 {
    virtual ~Object_00015D50();

    char unknown_04[0x34];
    Model_00015480 *owner;
    int unknown_3c;
    char unknown_40[0x44];
    Part_00015480 *parts;
    unsigned int count;
    char unknown_8c[0x88];
    unsigned int flags;

    void func_00015480();
};

// Called by func_00015D90 and others: moves each frame's part to the frame's origin (func_001BAB20 under the frame's
// matrix), with both copies of the position (copied as raw words) and the vector cleared; then clears +0x3c and the
// record count and sets flag 1 at +0x114.
void Object_00015D50::func_00015480()
{
    Frame_00015480 *frame = owner->frames;
    func_001BAA00();
    for (unsigned int i = 0; i < owner->count; frame++, i++) {
        func_001BA9C0();
        func_001BAAA0(frame->matrix);
        Part_00015480 *part = &parts[frame->part];
        func_001BAB20(&part->position, 0);
        *(int *)&part->previous.x = *(int *)&part->position.x;
        *(int *)&part->previous.y = *(int *)&part->position.y;
        *(int *)&part->previous.z = *(int *)&part->position.z;
        *(int *)&part->start.x = *(int *)&part->position.x;
        *(int *)&part->start.y = *(int *)&part->position.y;
        *(int *)&part->start.z = *(int *)&part->position.z;
        memset(part->velocity, 0, sizeof part->velocity);
        func_001BAA50();
    }
    func_001BAA50();
    unknown_3c = 0;
    count = 0;
    flags |= 1;
}
