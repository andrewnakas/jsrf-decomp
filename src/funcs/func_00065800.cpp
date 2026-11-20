struct Vector3 {
    float x;
    float y;
    float z;
};

// A segment from `start` to `end` along `direction`.
struct Segment_0006F8C0 {
    Vector3 start;
    float unknown_0c;
    Vector3 direction;
    float unknown_1c;
    Vector3 end;
};

// A triangle (0x30 bytes): a point on its plane, the plane's distance and its normal, then its corners' data.
struct Triangle_0006F8C0 {
    Vector3 point;
    float distance;
    Vector3 normal;
    char unknown_1c[0x14];
};

float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
int __fastcall func_0014C100(Vector3 *out, const Segment_0006F8C0 *segment, const Triangle_0006F8C0 *triangle);
int __fastcall func_0014B800(const Segment_0006F8C0 *segment, const Vector3 *point);
int __fastcall func_0014BCB0(const Triangle_0006F8C0 *triangle, const Vector3 *point);

// Three values a face collects from a probe.
struct Hit_00065800 {
    int values[3];
};

// A two-sided face of the list at +4 (next at +0x64): its front and back triangles and its share of the hit table.
struct Face_00065800 {
    Triangle_0006F8C0 front;
    Triangle_0006F8C0 back;
    char unknown_60[4];
    Face_00065800 *next;
    Hit_00065800 *hits;
    unsigned int hitCount;
};

// A probe of the list at +0xc (next at +0x40): its segment and three values.
struct Probe_00065800 {
    Segment_0006F8C0 segment;
    char unknown_2c[4];
    int values[3];
    char unknown_3c[4];
    Probe_00065800 *next;
};

// Object 0x1FB804.
struct Object_00065730 {
    char unknown_00[4];
    Face_00065800 *faces;
    char unknown_08[4];
    Probe_00065800 *probes;
    char unknown_10[4];
    Hit_00065800 *hits;
    unsigned int count;

    void func_00065800();
};

// For each face, lists the values of every probe whose segment passes into its front or back from the open side
// (the dot product with the front's normal below 0, func_0014C100 / func_0014B800 / func_0014BCB0). Every face's list
// starts at the entry of the table at +0x14 that the count at +0x18 names; the count is cleared first and never
// advanced.
void Object_00065730::func_00065800()
{
    count = 0;
    for (Face_00065800 *face = faces; face; face = face->next) {
        face->hits = &hits[count];
        Probe_00065800 *probe = probes;
        face->hitCount = 0;
        for (; probe; probe = probe->next) {
            Vector3 point;
            if (func_0014C800(&probe->segment.direction, &face->front.normal) < 0.0f &&
                ((func_0014C100(&point, &probe->segment, &face->front) && func_0014B800(&probe->segment, &point) &&
                  func_0014BCB0(&face->front, &point)) ||
                 (func_0014C100(&point, &probe->segment, &face->back) && func_0014B800(&probe->segment, &point) &&
                  func_0014BCB0(&face->back, &point)))) {
                face->hits[face->hitCount].values[0] = probe->values[0];
                face->hits[face->hitCount].values[1] = probe->values[1];
                face->hits[face->hitCount].values[2] = probe->values[2];
                face->hitCount++;
            }
        }
    }
}
