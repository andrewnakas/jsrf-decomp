/* sym: ?func_000CD390@Object_000E0440@@UAEHPAUVector3@@M0@Z = 0x000E1000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Object_000C1440 {
    int func_000C1440(int from, int to);
    int func_000C1450(int current, int target, int step);
};

// The object in data_00257CE8; it also answers func_000C1440 and func_000C1450.
struct Object_00157F10 : Object_000C1440 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

int __fastcall func_0014C840(int first, int second);

// The limits at 0x30: the range at 0x18, the largest turn at 0x1c and the turn step at 0x24.
struct Limits_000E1000 {
    char unknown_00[0x18];
    float range;
    int largest;
    char unknown_20[4];
    int step;
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

struct Object_000CD1E0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CD1E0();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0() = 0;
    virtual void func_000D7880() = 0;
    virtual float func_000CD440();
    virtual float func_000CD4F0();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    void *owner;
    int state;
    char unknown_0c[0x24];
    Limits_000E1000 *limits;
    char unknown_34[0x30];
    int turn;
    int unknown_68;
};

// The class whose table is at 0x1CE804; slot 6 is empty (folded with Node's).
struct Object_000E0440 : Object_000CD1E0 {
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000E0440();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);
};

// Slot 12: below the range of the limits at 0x30 returns 1; otherwise turns the angles at `position` (x and y, z
// cleared) toward the direction's angles (func_000C1F20) by the turn at 0x64: that grows toward the distance left
// (func_0014C840 of both func_000C1440 differences), at most the limits' largest, by their step (func_000C1450), or
// shrinks by the step down to it. Returns 0.
int Object_000E0440::func_000CD390(Vector3 *position, float value, Vector3 *direction)
{
    if (value < limits->range) {
        return 1;
    }
    Angles_000C1300 target;
    data_00257CE8->func_000C1F20(&target, direction, 0x8000);
    Angles_000C1300 *angles = (Angles_000C1300 *)position;
    int x = data_00257CE8->func_000C1440(angles->x, target.x);
    int y = data_00257CE8->func_000C1440(angles->y, target.y);
    int first = func_0014C840(x, -x);
    int second = func_0014C840(y, -y);
    int distance = func_0014C840(first, second);
    if (turn >= distance) {
        turn -= limits->step;
        if (turn < distance) {
            turn = distance;
        }
    } else {
        if (distance > limits->largest) {
            distance = limits->largest;
        }
        turn = data_00257CE8->func_000C1450(turn, distance, limits->step);
    }
    angles->x = data_00257CE8->func_000C1450(angles->x, target.x, turn);
    angles->y = data_00257CE8->func_000C1450(angles->y, target.y, turn);
    angles->z = 0;
    return 0;
}
