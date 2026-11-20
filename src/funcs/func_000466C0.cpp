struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_0006A960 {
    float func_0006AC40(Vector3 *position, int hint);
};

extern Object_0006A960 data_0020C6C0;

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int index);
};

// Asks the global at 0x20C6C0 for its value at the position (this object adds nothing of its own).
float Object_00046670::func_000466C0(Vector3 *position, int index)
{
    return data_0020C6C0.func_0006AC40(position, index);
}
