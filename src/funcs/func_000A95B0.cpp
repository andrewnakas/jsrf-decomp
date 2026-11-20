struct Vector3 {
    float x;
    float y;
    float z;
};

// A line: a point and a direction (each padded to 16 bytes).
struct Line_0014C250 {
    Vector3 point;
    float unused_0c;
    Vector3 direction;
    float unused_1c;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAC50(int *angles, int zero);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
int __fastcall func_0014C250(const Line_0014C250 *first, const Line_0014C250 *second);

// One of the node's entries (0x1cc bytes).
struct Entry_000A95B0 {
    unsigned int flags;
    char unknown_004[0x90];
    Vector3 position;
    int angles[3];
    char unknown_0ac[0x120];
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD608).
struct Object_000A8B50 {
    char unknown_000[0x44];
    Entry_000A95B0 *entries;
    unsigned int count;

    int func_000A95B0(int index);
};

// Whether entry `index`, turned by its angles (0xa0), has its x, z or y axis parallel to the vertical through its
// position (func_0014C250); if so sets the top flag bit.
int Object_000A8B50::func_000A95B0(int index)
{
    Line_0014C250 vertical;
    vertical.point.x = entries[index].position.x;
    vertical.point.y = entries[index].position.y;
    vertical.point.z = entries[index].position.z;
    vertical.direction.x = 0.0f;
    vertical.direction.y = 1.0f;
    vertical.direction.z = 0.0f;
    Line_0014C250 axis;
    axis.point.x = entries[index].position.x;
    axis.point.y = entries[index].position.y;
    axis.point.z = entries[index].position.z;
    axis.direction.x = 0.0f;
    axis.direction.y = 0.0f;
    axis.direction.z = 0.0f;
    func_001BA9C0();
    func_001BAC50(entries[index].angles, 0);
    axis.direction.x = 1.0f;
    axis.direction.y = 0.0f;
    axis.direction.z = 0.0f;
    func_001BAB20(&axis.direction, &axis.direction);
    if (func_0014C250(&axis, &vertical) == 1) {
        entries[index].flags |= 0x80000000;
        func_001BAA50();
        return 1;
    }
    axis.direction.x = 0.0f;
    axis.direction.y = 0.0f;
    axis.direction.z = 1.0f;
    func_001BAB20(&axis.direction, &axis.direction);
    if (func_0014C250(&axis, &vertical) == 1) {
        entries[index].flags |= 0x80000000;
        func_001BAA50();
        return 1;
    }
    axis.direction.x = 0.0f;
    axis.direction.y = 1.0f;
    axis.direction.z = 0.0f;
    func_001BAB20(&axis.direction, &axis.direction);
    if (func_0014C250(&axis, &vertical) == 1) {
        entries[index].flags |= 0x80000000;
        func_001BAA50();
        return 1;
    }
    func_001BAA50();
    return 0;
}
