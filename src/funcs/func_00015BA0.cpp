struct Vector3 {
    float x;
    float y;
    float z;
};

struct Matrix_001BA950 {
    float m[4][4];
};

// An axis and an angle (func_001BAC70 reads the angle at 0xc).
struct Rotation_000D2B90 {
    Vector3 axis;
    int angle;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAAE0(float *matrix);
void __fastcall func_001BADB0(Vector3 *position);
void __fastcall func_001BAC70(Rotation_000D2B90 *rotation);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
float func_0014C7F0(float value);
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);
int func_0014C7A0(float cosine);

// A frame of the owner's model (0x6c bytes): the matrix it uses at +8.
struct Frame_00015BA0 {
    char unknown_00[8];
    int matrix;
    char unknown_0c[0x60];
};

// The owner's model: its frames at +8 and matrices at +0x20.
struct Model_00015BA0 {
    char unknown_00[8];
    Frame_00015BA0 *frames;
    char unknown_0c[0x14];
    Matrix_001BA950 *matrices;
};

// A point of the effect (0x5c bytes): its position, a matrix at +0x24 and its up vector at +0x30.
struct Point_00015BA0 {
    Vector3 position;
    char unknown_0c[0x18];
    float matrix[3];
    Vector3 up;
    char unknown_3c[0x20];
};

// An effect (constructor 0x15420, size 0x118).
struct Object_00015D50 {
    virtual ~Object_00015D50();

    char unknown_04[0x34];
    Model_00015BA0 *owner;
    char unknown_3c[8];
    Vector3 offset;
    char unknown_50[0x34];
    Point_00015BA0 *points;
    char unknown_88[0x84];
    unsigned int columns;
    unsigned int rows;

    void func_00015BA0();
};

// Places the owner's frames along the points (each with func_001BADB0 of +0x44 and the frame's matrix): the first
// frame as it is, then for each row and column the next frame at the next point, turned so the point's up vector
// (+0x30) follows the way to the following point (unless they already agree to within 0.999), with the point's
// matrix at +0x24. The way and up vectors are kept in 16-byte slots.
void Object_00015D50::func_00015BA0()
{
    Frame_00015BA0 *frame = owner->frames;
    Point_00015BA0 *point = points;
    func_001BA9C0();
    func_001BADB0(&offset);
    func_001BA950(&owner->matrices[frame->matrix]);
    func_001BAA50();
    frame++;
    point++;
    for (unsigned int j = 0; j < rows; j++) {
        for (unsigned int i = 0; i < columns; i++) {
            func_001BA9C0();
            func_001BAAA0(&point->position.x);
            if (i != columns - 1) {
                Rotation_000D2B90 way;
                Rotation_000D2B90 up;
                Rotation_000D2B90 rotation;
                func_0014C4C0(&way.axis, &point[1].position, &point->position);
                func_0014C410(&way.axis, &way.axis);
                up.axis.x = point->up.x;
                up.axis.y = point->up.y;
                up.axis.z = point->up.z;
                float cosine = func_0014C800(&up.axis, &way.axis);
                if (func_0014C7F0(cosine) < 0.999f) {
                    func_0014C3B0(&rotation.axis, &up.axis, &way.axis);
                    func_0014C410(&rotation.axis, &rotation.axis);
                    rotation.angle = func_0014C7A0(cosine);
                    func_001BAC70(&rotation);
                }
            }
            func_001BAAE0(point->matrix);
            func_001BADB0(&offset);
            func_001BA950(&owner->matrices[frame->matrix]);
            func_001BAA50();
            point++;
            frame++;
        }
    }
}
