struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Game {
    char unknown_0000[0x87f0];
    int frame;
};

extern Game *data_0022FCE0;

// One trail: the frame it was made in and its points.
struct Trail_00014370 {
    int frame;
    int start;
    int end;
    int last;
    Vector3 *points;
};

// The trail drawer (table 0x1C4500, constructor 0x141E0, destructor 0x14280): its place and size, then up to eight
// live trails at +0x70 (count at +0xb0) and eight fading ones at +0x90.
struct Object_00014280 {
    char unknown_00[0x44];
    Vector3 position;
    float radius;
    unsigned int length;
    char unknown_58[0x18];
    Trail_00014370 *trails[8];
    Trail_00014370 *others[8];
    unsigned int trailCount;
    unsigned int otherCount;
    void *buffer;
    int enabled;

    void func_00013FF0();
};

// When enabled, adds its place (moved by the current matrix) as the latest point of the trail made in the current
// frame, or starts a new trail (up to eight) with room for +0x54 points.
void Object_00014280::func_00013FF0()
{
    if (enabled) {
        for (unsigned int i = 0; i < trailCount; i++) {
            if (trails[i]->frame == data_0022FCE0->frame) {
                Trail_00014370 *trail = trails[i];
                func_001BAB20(&trail->points[trail->end], &position);
                trail->last = trail->end;
                return;
            }
        }
        if (trailCount < 8) {
            Trail_00014370 *trail = new Trail_00014370;
            trails[trailCount] = trail;
            trail->frame = data_0022FCE0->frame;
            trail->start = 0;
            trail->end = 0;
            trail->points = new Vector3[length];
            trail->last = 0;
            func_001BAB20(&trail->points[trail->end], &position);
            trailCount++;
        }
    }
}
