struct Vector3 {
    float x;
    float y;
    float z;
};

struct Matrix_001BA950 {
    float m[4][4];
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

// A box (0x2c bytes): its corners at 0x0 and 0xc, its centre at 0x18.
struct Box_000CBE60 {
    Vector3 low;
    Vector3 high;
    Vector3 center;
    char unknown_24[8];
};

// The boxes: their count, the boxes and the matrix they are placed by (or none).
struct Boxes_000CBE60 {
    unsigned int count;
    Box_000CBE60 *boxes;
    Matrix_001BA950 *matrix;
};

// The table of boxes at data_00257CE0.
struct Object_000BFF60 {
    Boxes_000CBE60 *data;
    unsigned char *tables[3];
    char unknown_10[0xc];

    int func_000BFF80(Vector3 *position);
};

// The index of the first box holding the position (low <= p < high on each axis), after bringing the position
// into the boxes' space when they have a matrix (func_001BA8F0, func_001BAB20); -1 for none.
int Object_000BFF60::func_000BFF80(Vector3 *position)
{
    if (!data) {
        return -1;
    }
    unsigned int count = data->count;
    if (count > 0) {
        Box_000CBE60 *box = data->boxes;
        Vector3 local;
        Vector3 *point;
        if (data->matrix) {
            func_001BA9C0();
            func_001BA8F0(data->matrix);
            func_001BAB20(&local, position);
            point = &local;
            func_001BAA50();
        } else {
            point = position;
        }
        for (unsigned int i = 0; i < count; i++, box++) {
            if (box->low.x <= point->x && point->x < box->high.x && box->low.y <= point->y &&
                point->y < box->high.y && box->low.z <= point->z && point->z < box->high.z) {
                return i;
            }
        }
    }
    return -1;
}
