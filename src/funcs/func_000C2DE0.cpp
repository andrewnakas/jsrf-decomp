struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Direction_000C3BE0 {
    Vector3 vector;
    float unknown_0c;
};

struct Object_00157F10 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

// The object at data_00257CEC: four points at 0x8.
struct Object_000C3BE0 {
    char unknown_00[8];
    Vector3 points[4];
};

extern Object_000C3BE0 *data_00257CEC;

// The reach within which a path point counts as reached (10).
extern float data_00215E7C;

struct Data_000C2700 {
    unsigned char type;
    unsigned char mode;
    char unknown_02;
    unsigned char count;
    Vector3 *points;
};

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470).
struct Object_000C2420 {
    virtual void func_000C2630();

    Vector3 position;
    char unknown_10[0xc];
    Angles_000C1300 angles;
    char unknown_28[0x10];
    unsigned int index;
    char unknown_3c[8];
    float distance;
    char unknown_48[0x20];
    int point;
    char unknown_6c[0xc];
    Data_000C2700 *data;

    int func_000C2DE0();
};

// Turns the angles at 0x1c toward the current path point (the index at 0x38 into the data's points, func_000C1F20,
// step 0x38e). Within 12 of the point at 0x68 of data_00257CEC and heading its way (dot above 0), they also turn
// 0x500 toward its side (the cross product's y, func_0014C3B0). Returns 1 when the path point lies within the
// reach data_00215E7C on the flat.
int Object_000C2420::func_000C2DE0()
{
    float reach = data_00215E7C;
    Direction_000C3BE0 way;
    func_0014C4C0(&way.vector, &data->points[index], &position);
    data_00257CE8->func_000C1F20(&angles, &way.vector, 0x38e);
    way.vector.y = 0.0f;
    if (distance < 12.0f) {
        Vector3 toward;
        toward.x = data_00257CEC->points[point].x - position.x;
        toward.y = 0.0f;
        toward.z = data_00257CEC->points[point].z - position.z;
        if (func_0014C800(&toward, &way.vector) > 0.0f) {
            Vector3 cross;
            func_0014C3B0(&cross, &way.vector, &toward);
            if (cross.y < 0.0f) {
                angles.y += 0x500;
            } else {
                angles.y -= 0x500;
            }
        }
    }
    if (way.vector.x * way.vector.x + way.vector.z * way.vector.z > reach * reach) {
        return 0;
    }
    return 1;
}
