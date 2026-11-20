struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C6B0(const Vector3 *vector);

// An entry of the player's list at +0x258: its kind, position (+0x8), value (+0x28) and the next entry (+0x38).
struct Target_0008E380 {
    int kind;
    int unknown_04;
    Vector3 position;
    char unknown_14[0x14];
    float value;
    char unknown_2c[0xc];
    Target_0008E380 *next;
};

// The player.
struct Object_000A1C50 {
    char unknown_000[0x258];
    Target_0008E380 *targets;

    int func_0008ABE0(Target_0008E380 *target);
    int func_0008E2C0(int *result, float *length);
};

// Finds the entry of kind 5 with the largest value above 0 (also measuring every such entry's length into a
// maximum it never reads) and gives func_0008ABE0's answer for it and the length of its position, or 0 and 0.
// Returns 11.
int Object_000A1C50::func_0008E2C0(int *result, float *length)
{
    float best = 0.0f;
    float farthest = 0.0f;
    Target_0008E380 *found = 0;
    for (Target_0008E380 *target = targets; target; target = target->next) {
        if (target->kind == 5) {
            if (target->value > best) {
                best = target->value;
                found = target;
            }
            float distance = func_0014C6B0(&target->position);
            if (distance > farthest)
                farthest = distance;
        }
    }
    if (found) {
        *result = func_0008ABE0(found);
        *length = func_0014C6B0(&found->position);
        return 11;
    }
    *result = 0;
    *length = 0.0f;
    return 11;
}
