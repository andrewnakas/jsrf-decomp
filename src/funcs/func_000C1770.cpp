struct Vector3 {
    float x;
    float y;
    float z;
};

struct Matrix_001BA950 {
    float m[4][4];
};

void func_001BA8A0();
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BA950(Matrix_001BA950 *matrix);

// The thing an entry of data_002314B0 points to first: a point at 0x90.
struct Body_000C1EA0 {
    char unknown_00[0x90];
    Vector3 point;
};

struct Entry_0003E720 {
    Body_000C1EA0 *body;
    char unknown_04[0xc4];
    float value_c8;
};

struct Object_0003E750 {
    Entry_0003E720 *func_0003E720(int key);
};

extern Object_0003E750 data_002314B0;

// What the object in data_00257CE4 keeps at 0xcc: slot 5 draws. Its table is not identified yet, so the slots are
// named by position.
struct Drawer_000C1770 {
    virtual void func_slot0();
    virtual void func_slot1();
    virtual void func_slot2();
    virtual void func_slot3();
    virtual void func_slot4();
    virtual void func_slot5(int first, int second);
};

struct Object_000C1270 {
    char unknown_00[0xcc];
    Drawer_000C1770 *drawer;
    int value_d0;
    int value_d4;
};

extern Object_000C1270 *data_00257CE4;

// The object in data_00257CE8 (its callers load `ecx` from there; this function does not read it).
struct Object_00157F10 {
    void func_000C1770(int key);
};

// With data_00257CE4 set and an entry of data_002314B0 for the key whose 0xc8 is above 0: finds where the entry's
// body point (0x90) lands (func_001BAAA0, func_001BAB20), and with the matrix of func_001BA950 there has the drawer
// at 0xcc of data_00257CE4 draw its 0xd0 and 0xd4 (slot 5), between func_001BA9C0 and func_001BAA50.
void Object_00157F10::func_000C1770(int key)
{
    Vector3 point;
    Matrix_001BA950 matrix;
    if (data_00257CE4 && key != -1) {
        Entry_0003E720 *entry = data_002314B0.func_0003E720(key);
        if (entry && entry->value_c8 > 0.0f) {
            func_001BA9C0();
            func_001BAAA0(&entry->body->point.x);
            func_001BAB20(&point, 0);
            func_001BA8A0();
            func_001BA950(&matrix);
            func_001BAAA0(&point.x);
            data_00257CE4->drawer->func_slot5(data_00257CE4->value_d0, data_00257CE4->value_d4);
            func_001BAA50();
        }
    }
}
