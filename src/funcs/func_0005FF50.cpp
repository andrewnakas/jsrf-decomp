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
void __fastcall func_001BB410(Vector3 *out);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);
int func_0004EAA0(int kind);

// A table of 0x28-byte records: a byte at +0x8.
struct Record_001FA200 {
    char unknown_00[8];
    unsigned char unknown_08;
    char unknown_09[0x1f];
};

extern Record_001FA200 data_001FA200[];

// The ground: the place under a position and its height.
struct Object_0006A960 {
    int func_0006AAA0(Vector3 *position, int hint);
    float func_0006AC40(Vector3 *position, int hint);
};

extern Object_0006A960 data_0020C6C0;

// The shadow of an object: a kind at +0x44 and a height at +0x5c.
struct Shadow_0005FF50 {
    char unknown_00[0x44];
    int kind;
    char unknown_48[0x14];
    float height;
};

// The class whose table is at 0x1CB040.
struct Object_00062390 {
    char unknown_0000[0x94];
    Matrix_001BA950 first;
    Matrix_001BA950 second;
    char unknown_0114[0x54];
    int hint;
    char unknown_016c[0x13b8];
    int kind;
    char unknown_1528[0x24];
    Shadow_0005FF50 *shadow;

    void func_0005FF50();
};

// With a shadow at +0x154c: takes the translation after the matrix at +0x94 (func_001BB410), runs it through the
// matrix at +0xd4 (func_001BAC00) and func_0014C370 with -1, gives the shadow the kind func_0004EAA0 picks for the
// byte of the object's record (0x1FA200) and the ground height at that point (keeping the ground's hint at +0x168).
void Object_00062390::func_0005FF50()
{
    if (shadow) {
        Vector3 point;
        func_001BA9C0();
        func_001BA8F0(&first);
        func_001BB410(&point);
        func_001BA8F0(&second);
        func_001BAC00(&point, &point);
        func_0014C370(&point, &point, -1.0f);
        func_001BAA50();
        shadow->kind = func_0004EAA0(data_001FA200[kind].unknown_08);
        hint = data_0020C6C0.func_0006AAA0(&point, hint);
        shadow->height = data_0020C6C0.func_0006AC40(&point, hint);
    }
}
