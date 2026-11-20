struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BAA00();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAA50();
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);

// The owner at 0x4 of the Object_000CC600 family: placed at 0x44 and turned by 0x54; kind 0's area is the four
// corners at 0xcc.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[4];
    int angle;
    char unknown_58[0x74];
    Vector3 *corners;

    int func_000C5B90(Vector3 *point);
};

// Kind 0's test: 1 when the point lies over the area, seen from above. The four corners are placed and turned
// with the object; the point is in either triangle (0, 1, 2) or (3, 1, 2) when the flat (y = 0) cross products
// (func_0014C3B0) of the ways from it to each pair of corners all point up or all point down.
int Object_000C5B50::func_000C5B90(Vector3 *point)
{
    Vector3 a;
    Vector3 b;
    Vector3 c;
    Vector3 ab;
    Vector3 ca;
    Vector3 bc;
    Vector3 placed[4];
    Vector3 *area = corners;
    c.y = 0.0f;
    b.y = 0.0f;
    a.y = 0.0f;
    func_001BAA00();
    func_001BAAA0(&position.x);
    func_001BB330(angle);
    func_001BAB20(&placed[0], &area[0]);
    func_001BAB20(&placed[1], &area[1]);
    func_001BAB20(&placed[2], &area[2]);
    func_001BAB20(&placed[3], &area[3]);
    func_001BAA50();
    a.x = placed[0].x - point->x;
    a.z = placed[0].z - point->z;
    b.x = placed[1].x - point->x;
    b.z = placed[1].z - point->z;
    c.x = placed[2].x - point->x;
    c.z = placed[2].z - point->z;
    func_0014C3B0(&ab, &a, &b);
    func_0014C3B0(&bc, &b, &c);
    func_0014C3B0(&ca, &c, &a);
    if ((ab.y >= 0.0f && bc.y >= 0.0f && ca.y >= 0.0f) || (ab.y <= 0.0f && bc.y <= 0.0f && ca.y <= 0.0f)) {
        return 1;
    }
    a.x = placed[3].x - point->x;
    a.z = placed[3].z - point->z;
    func_0014C3B0(&ab, &a, &b);
    func_0014C3B0(&ca, &c, &a);
    if ((ab.y >= 0.0f && bc.y >= 0.0f && ca.y >= 0.0f) || (ab.y <= 0.0f && bc.y <= 0.0f && ca.y <= 0.0f)) {
        return 1;
    }
    return 0;
}
