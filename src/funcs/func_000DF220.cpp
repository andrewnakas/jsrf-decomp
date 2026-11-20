struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 unknown_7c;
};

extern Object_000C1270 *data_00257CE4;

struct Object_000DCBC0 {
    char unknown_000[0x44];
    int value_44;
    char unknown_048[0x8];
    Vector3 point;

    void func_000DF220();
};

// Moves the point at 0x50 toward 13 above the point at 0x7c of data_00257CE4 by 1.3888888 (along the direction
// func_0014C4C0 and func_0014C460 give); once it is no farther than that, puts it there and gives 2 at 0x44.
void Object_000DCBC0::func_000DF220()
{
    Vector3 goal = data_00257CE4->unknown_7c;
    goal.y += 13.0f;
    Vector3 direction;
    func_0014C4C0(&direction, &goal, &point);
    if (func_0014C460(&direction, &direction) > 1.3888888f) {
        func_0014C730(&point, &direction, 1.3888888f);
        return;
    }
    point = goal;
    value_44 = 2;
}
