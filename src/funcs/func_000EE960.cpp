struct Motion_0005F060;

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

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
float __fastcall func_0014C460(Vector3 *a, const Vector3 *b);
void __fastcall func_0014C500(Vector3 *vector, const Vector3 *other);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
void func_000C5670(void *parent, Vector3 *position, Vector3 *direction, int kind);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 unknown_7c;
};

extern Object_000C1270 *data_00257CE4;

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 : Object_000C1440 {
    void func_000C1300(Angles_000C1300 *angles, Vector3 *direction);
};

extern Object_00157F10 *data_00257CE8;

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);

    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    float value_5c;
    char unknown_60[0x44];
    unsigned int flags;
};

// The model (the holder's first word).
struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

struct Holder_000EDC30 {
    Object_00047470 *model;
};

// The motions at 0xf8.
struct Source_000EDC30 {
    char unknown_00[8];
    Motion_0005F060 *motion_08;
    char unknown_0c[0xc];
    Motion_0005F060 *motion_18;
    Motion_0005F060 *motion_1c;
    Motion_0005F060 *motion_20;
};

// The ranges at 0xd4: the count to start with, a reach at 0x8 and the count between shots at 0x10.
struct Ranges_000EDC30 {
    int count;
    char unknown_04[4];
    float reach;
    char unknown_0c[4];
    int interval;
};

// The two ends of the shot (from joint 2 of the holder's model).
extern Vector3 data_0021A894;
extern Vector3 data_0021A8A0;

// The class of func_000EDC30; these are handlers of its table at 0x21A900.
struct Object_000EDC30 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    char unknown_008[0xc];
    Vector3 position;
    char unknown_020[0xb4];
    Ranges_000EDC30 *ranges;
    int shots;
    int value_0dc;
    int value_0e0;
    char unknown_0e4[0xc];
    int count;
    Holder_000EDC30 *holder;
    Source_000EDC30 *source;
    void *handle;
    char unknown_100[0xc];
    float time_10c;
    float time_110;

    void func_000EE960();
};

// A handler of the table at 0x21A900: plays the set's motions 0x18 and 0x8 (times 0x10c, 0x110) to their end. With the
// owner's flag 0x2000000: state 3 at 0xdc and no count. Otherwise, within 60 of the object at data_00257CE4: state 4;
// within the reach of the ranges at 0xd4 and ahead of the owner turned by 0xe0 (cosine above 0.7), counts down 0xf0 and
// then shoots (func_000C5670 kind 2 and message 0x25 between data_0021A894 and data_0021A8A0 from joint 2 of the
// holder's model posed at 0x14), restarting both motions and the count; after the last shot (0xd8), or out of reach:
// state 3 with the ranges' count.
void Object_000EDC30::func_000EE960()
{
    if (time_10c >= 0.0f) {
        if (func_0005E030(source->motion_18, &time_10c, 0.5f, 1)) {
            time_10c = -1.0f;
        }
    }
    if (time_110 >= 0.0f) {
        if (func_0005E030(source->motion_08, &time_110, 0.5f, 1)) {
            time_110 = -1.0f;
        }
    }
    if (!(owner->flags & 0x2000000)) {
        Vector3 offset;
        func_0014C4C0(&offset, &data_00257CE4->unknown_7c, &owner->position);
        float distance = func_0014C460(&offset, &offset);
        if (60.0f > distance) {
            value_0dc = 4;
            return;
        }
        if (distance < ranges->reach) {
            Angles_000C1300 turn = {0, owner->angles.y + value_0e0, 0};
            Vector3 facing;
            data_00257CE8->func_000C1300(&turn, &facing);
            if (func_0014C800(&offset, &facing) > 0.7f && --count <= 0) {
                count = ranges->interval;
                time_10c = 0.0f;
                time_110 = 0.0f;
                func_001BA9C0();
                func_001BAAA0(&position.x);
                func_001BB330(owner->angles.y + 0x8000);
                func_001BB2E0(owner->angles.x);
                func_001BB380(owner->angles.z);
                holder->model->func_00047970(handle, 0);
                holder->model->func_000480C0(2);
                Vector3 start;
                Vector3 end;
                func_001BAB20(&start, &data_0021A894);
                func_001BAB20(&end, &data_0021A8A0);
                func_0014C500(&end, &start);
                func_000C5670(0, &start, &end, 2);
                owner->func_000C5B10(0x25, &start);
                func_001BAA50();
                if (--shots == 0) {
                    value_0dc = 3;
                    count = ranges->count;
                }
            }
            return;
        }
        value_0dc = 3;
        count = ranges->count;
    } else {
        value_0dc = 3;
        count = 0x7fffffff;
    }
}
