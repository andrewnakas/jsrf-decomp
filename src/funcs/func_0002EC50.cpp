struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Motion_0006EB20;

void __stdcall func_0006EB20(Motion_0006EB20 *motion);

// One part of a loaded file: where its data is (from the file's start, past an 8-byte header), where the next part
// is, and its size.
struct Part_0002EC50 {
    int offset;
    int next;
    unsigned int size;
};

// A loaded file: its part count at +4 and its first part at +0x10.
struct File_0002EC50 {
    int unknown_00;
    unsigned int count;
    char unknown_08[8];
    Part_0002EC50 first;
};

struct Shape_0002EC50 {
    char unknown_00[8];
    float x;
    char unknown_0c[8];
    float y;
    char unknown_18[8];
    float z;
    float w;
};

// Object 0x1de2.
struct Object_0002EC50 {
    char unknown_0000[0x4148];
    Shape_0002EC50 *shape;
    Motion_0006EB20 *motion;
};

struct Object_000265A0 {
    void func_0002EC50(File_0002EC50 *file);
};

// Hands the parts of `file` to object 0x1de2: part 0 is its shape (+0x4148, four values turned round), part 1 its
// motion (+0x414c, set up by func_0006EB20); an empty part leaves 0.
void Object_000265A0::func_0002EC50(File_0002EC50 *file)
{
    Object_0002EC50 *object = (Object_0002EC50 *)data_0022FCE0->func_000128C0(0x1de2);
    Part_0002EC50 *next = &file->first;
    for (unsigned int i = 0; i < file->count; i++) {
        Part_0002EC50 *part = next;
        next = (Part_0002EC50 *)((char *)file + part->next);
        switch (i) {
        case 0:
            if (part->size > 0) {
                object->shape = (Shape_0002EC50 *)((char *)file + part->offset + 8);
                object->shape->x *= -1.0f;
                object->shape->y *= -1.0f;
                object->shape->z *= -1.0f;
                object->shape->w *= -1.0f;
            } else {
                object->shape = 0;
            }
            break;
        case 1:
            if (part->size > 0) {
                object->motion = (Motion_0006EB20 *)((char *)file + part->offset + 8);
                func_0006EB20(object->motion);
            } else {
                object->motion = 0;
            }
            break;
        }
    }
}
