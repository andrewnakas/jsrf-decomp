struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

// The thing an entry of data_002314B0 points to first: a point at 0x90.
struct Body_000C1EA0 {
    char unknown_00[0x90];
    Vector3 point;
};

struct Entry_0003E720 {
    Body_000C1EA0 *body;
};

struct Object_0003E750 {
    Entry_0003E720 *func_0003E720(int key);
    void func_0003F3D0(int key);
    void func_0003F490(int key, const Vector3 *position);
};

extern Object_0003E750 data_002314B0;

// The object in data_00257CE8 (its callers load `ecx` from there; this function does not read it).
struct Object_00157F10 {
    void func_000C1EA0(int key);
};

// When data_002314B0 has an entry for the key: func_0003F3D0 on it, then moves it to where func_001BAB20 puts its
// body's point at 0x90, 5 lower (func_0003F490).
void Object_00157F10::func_000C1EA0(int key)
{
    Vector3 position;
    Entry_0003E720 *entry = data_002314B0.func_0003E720(key);
    if (entry) {
        data_002314B0.func_0003F3D0(key);
        func_001BAB20(&position, &entry->body->point);
        position.y -= 5.0f;
        data_002314B0.func_0003F490(key, &position);
    }
}
