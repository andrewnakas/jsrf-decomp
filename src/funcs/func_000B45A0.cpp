struct Vector3 {
    float x;
    float y;
    float z;
};

struct __declspec(align(16)) Point_000B45A0 {
    float x;
    float y;
    float z;
    float w;
};

// A 16-byte key of a path: its time (in ticks) first.
struct Key_000B45A0 {
    unsigned int time;
    int unknown_04[3];
};

// The count of keys of a path.
struct Track_000B45A0 {
    unsigned int count;
    unsigned int length;
};

// A path's curve: slot 5 picks the segment, slot 7 gives its point at a time between 0 and 1.
struct Curve_000B45A0 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5(int segment);
    virtual void __stdcall slot6();
    virtual void __stdcall slot7(Point_000B45A0 *point, float time);
};

// The path the object follows.
struct Object_000B45A0 {
    char unknown_00[0xb4];
    Key_000B45A0 *keys[3];
    Curve_000B45A0 *curves[3];
    char unknown_cc[0x70];
    Track_000B45A0 *tracks[3];

    int func_000B3E10(Key_000B45A0 *keys, float time, unsigned int first, unsigned int last);
    void func_000B45A0(int index, float time, Vector3 *out);
};

// Samples path `index` at the time (held at the track's length less one): finds the key (func_000B3E10), the share
// of its span the time has reached (kept between 0 and 1), and the curve's point there.
void Object_000B45A0::func_000B45A0(int index, float time, Vector3 *out)
{
    Track_000B45A0 *track = tracks[index];
    Key_000B45A0 *list = keys[index];
    float end = (float)track->length - 1.0f;
    if (time > end) {
        time = end;
    }
    int key = func_000B3E10(list, time, 0, track->count - 1);
    float share = (time - list[key].time) / (float)(list[key + 1].time - list[key].time);
    if (share > 1.0f) {
        share = 1.0f;
    } else if (share < 0.0f) {
        share = 0.0f;
    }
    curves[index]->slot5(key);
    Point_000B45A0 point;
    curves[index]->slot7(&point, share);
    out->x = point.x;
    out->y = point.y;
    out->z = point.z;
}
