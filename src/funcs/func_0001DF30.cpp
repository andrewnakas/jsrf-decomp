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

// A two-sided face of the list at +4 (next at +0x88): its front and back triangles and three vectors.
struct Face_0001DF30 {
    Triangle_0006F8C0 front;
    Triangle_0006F8C0 back;
    Vector3 first;
    Vector3 second;
    Vector3 third;
    char unknown_84[4];
    Face_0001DF30 *next;
};

// A probe of the list at +0xc (next at +0x34): its segment, whether it hit, and the hit face's three vectors.
struct Probe_0001DF30 {
    Segment_0006F8C0 segment;
    char unknown_2c[8];
    Probe_0001DF30 *next;
    int hit;
    Vector3 first;
    Vector3 second;
    Vector3 third;
};

struct Object_0001DEF0 {
    char unknown_00[4];
    Face_0001DF30 *faces;
    char unknown_08[4];
    Probe_0001DF30 *probes;

    void func_0001DF30();
};

// For each probe, finds the first face whose front or back its segment passes into from the open side (the dot
// product with that side's normal below 0, func_0014C100 / func_0014B800 / func_0014BCB0), marks the probe hit and
// copies the face's three vectors to it.
void Object_0001DEF0::func_0001DF30()
{
    for (Probe_0001DF30 *probe = probes; probe; probe = probe->next) {
        for (Face_0001DF30 *face = faces; face; face = face->next) {
            Vector3 point;
            if (func_0014C800(&probe->segment.direction, &face->front.normal) < 0.0f &&
                func_0014C100(&point, &probe->segment, &face->front) && func_0014B800(&probe->segment, &point) &&
                func_0014BCB0(&face->front, &point)) {
                probe->hit = 1;
                probe->first = face->first;
                probe->second = face->second;
                probe->third = face->third;
                break;
            }
            if (func_0014C800(&probe->segment.direction, &face->back.normal) < 0.0f &&
                func_0014C100(&point, &probe->segment, &face->back) && func_0014B800(&probe->segment, &point) &&
                func_0014BCB0(&face->back, &point)) {
                probe->hit = 1;
                probe->first = face->first;
                probe->second = face->second;
                probe->third = face->third;
                break;
            }
        }
    }
}
