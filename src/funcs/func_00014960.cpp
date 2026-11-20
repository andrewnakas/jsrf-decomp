struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000851A0 {
    void func_000851A0(const Vector3 *position);
};

struct Object_00014A80 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    Vector3 position;
    int unknown_18;
    int unknown_1c;
    int unknown_20;

    void func_00014960();
};

// Resets the object at 0x1EB938 (called from the stage's func_00051780): clears +4, +8 and the position, -1 into
// +0x18 to +0x20, and hands the position to func_000851A0 of object 0x50 when the game has one.
void Object_00014A80::func_00014960()
{
    unknown_04 = 0;
    unknown_08 = 0;
    position.x = 0;
    position.y = 0;
    position.z = 0;
    unknown_18 = -1;
    unknown_1c = -1;
    unknown_20 = -1;
    if (data_0022FCE0) {
        Object_000851A0 *object = (Object_000851A0 *)data_0022FCE0->func_000128C0(0x50);
        if (object)
            object->func_000851A0(&position);
    }
}
