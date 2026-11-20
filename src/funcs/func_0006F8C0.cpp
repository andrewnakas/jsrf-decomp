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

// A two-sided face of the list at +4 (next at +0x70): its front and back triangles and three values.
struct Face_0006F8C0 {
    Triangle_0006F8C0 front;
    Triangle_0006F8C0 back;
    int values[3];
    char unknown_6c[4];
    Face_0006F8C0 *next;
};

// A probe of the list at +0xc (next at +0x34): its segment and what it hit.
struct Probe_0006F8C0 {
    Segment_0006F8C0 segment;
    char unknown_2c[8];
    Probe_0006F8C0 *next;
    int hit;
    int values[3];
};

// Object 0x20CC58.
struct Object_0001DEF0 {
    char unknown_00[4];
    Face_0006F8C0 *faces;
    char unknown_08[4];
    Probe_0006F8C0 *probes;

    void func_0006F8C0();
};

// For each probe, finds the first face whose front or back its segment enters from the open side (the dot product
// of the directions below 0, func_0014C100 / func_0014B800 / func_0014BCB0): marks the probe hit and copies the
// face's three values.
void Object_0001DEF0::func_0006F8C0()
{
    for (Probe_0006F8C0 *probe = probes; probe; probe = probe->next) {
        for (Face_0006F8C0 *face = faces; face; face = face->next) {
            Vector3 point;
            if ((func_0014C800(&probe->segment.direction, &face->front.normal) < 0.0f &&
                 func_0014C100(&point, &probe->segment, &face->front) && func_0014B800(&probe->segment, &point) &&
                 func_0014BCB0(&face->front, &point)) ||
                (func_0014C800(&probe->segment.direction, &face->back.normal) < 0.0f &&
                 func_0014C100(&point, &probe->segment, &face->back) && func_0014B800(&probe->segment, &point) &&
                 func_0014BCB0(&face->back, &point))) {
                probe->hit = 1;
                probe->values[0] = face->values[0];
                probe->values[1] = face->values[1];
                probe->values[2] = face->values[2];
                break;
            }
        }
    }
}
