struct Matrix_001BA950 {
    float m[4][4];
};

// Four values copied with a bone (16 bytes).
struct Quad_00047D40 {
    float x;
    float y;
    float z;
    float w;
};

// One frame of a model (0x6c bytes): its index, matrix, four values and links to its first child and next sibling.
struct Frame_000479D0 {
    int unknown_00;
    int unknown_04;
    int index;
    char unknown_0c[8];
    Matrix_001BA950 matrix;
    Quad_00047D40 quad;
    Frame_000479D0 *child;
    Frame_000479D0 *next;
};

// One bone of a model file: four values, its matrix and links to its first child and next sibling.
struct Bone_00047D40 {
    char unknown_00[0x10];
    Quad_00047D40 quad;
    Matrix_001BA950 matrix;
    Bone_00047D40 *child;
    Bone_00047D40 *next;
};

// The model base class (table 0x1CAA8C).
struct Object_00047470 {
    virtual ~Object_00047470();

    void func_00047D40(Bone_00047D40 *bone, Frame_000479D0 **cursor, int *index);
};

// Fills the frame at `*cursor` from `bone` (matrix, four values, the next index) and the frames after it from the
// bone's children and siblings, depth first, linking them; leaves `*cursor` at the last frame filled.
void Object_00047470::func_00047D40(Bone_00047D40 *bone, Frame_000479D0 **cursor, int *index)
{
    Frame_000479D0 *frame = *cursor;
    (*cursor)->matrix = bone->matrix;
    (*cursor)->quad = bone->quad;
    (*cursor)->index = *index;
    (*index)++;
    if (bone->child) {
        frame++;
        (*cursor)->child = frame;
        func_00047D40(bone->child, &frame, index);
    } else {
        (*cursor)->child = 0;
    }
    if (bone->next) {
        frame++;
        (*cursor)->next = frame;
        func_00047D40(bone->next, &frame, index);
    } else {
        (*cursor)->next = 0;
    }
    *cursor = frame;
}
