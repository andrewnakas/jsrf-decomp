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

int __fastcall func_0014C100(Vector3 *out, const Segment_0006F8C0 *segment, const Triangle_0006F8C0 *triangle);
int __fastcall func_0014B800(const Segment_0006F8C0 *segment, const Vector3 *point);
int __fastcall func_0014BCB0(const Triangle_0006F8C0 *triangle, const Vector3 *point);

// A two-sided face (0x60 bytes): its front and back triangles.
struct Face_00024AE0 {
    Triangle_0006F8C0 front;
    Triangle_0006F8C0 back;
};

// A mesh of the list at +4 (next at +0x2c): `count` faces, a value, a vector and four more values.
struct Mesh_00024AE0 {
    Face_00024AE0 *faces;
    unsigned int count;
    int value;
    Vector3 normal;
    int values[4];
    char unknown_28[4];
    Mesh_00024AE0 *next;
};

// A probe of the list at +0xc (next at +0x34): its segment, whether it hit, and what it hit.
struct Probe_00024AE0 {
    Segment_0006F8C0 segment;
    char unknown_2c[8];
    Probe_00024AE0 *next;
    int hit;
    int value;
    Vector3 point;
    Vector3 normal;
    int values[4];
};

struct Object_0001DEF0 {
    char unknown_00[4];
    Mesh_00024AE0 *meshes;
    char unknown_08[4];
    Probe_00024AE0 *probes;

    void func_00024AE0();
};

// For each probe and each mesh, finds the first face whose front or back its segment passes through
// (func_0014C100 / func_0014B800 / func_0014BCB0), marks the probe hit and copies the point and the mesh's value,
// vector and four values to it.
void Object_0001DEF0::func_00024AE0()
{
    for (Probe_00024AE0 *probe = probes; probe; probe = probe->next) {
        for (Mesh_00024AE0 *mesh = meshes; mesh; mesh = mesh->next) {
            for (unsigned int i = 0; i < mesh->count; i++) {
                Vector3 point;
                if (func_0014C100(&point, &probe->segment, &mesh->faces[i].front) &&
                    func_0014B800(&probe->segment, &point) && func_0014BCB0(&mesh->faces[i].front, &point)) {
                    probe->hit = 1;
                    probe->value = mesh->value;
                    probe->point = point;
                    probe->normal = mesh->normal;
                    probe->values[0] = mesh->values[0];
                    probe->values[1] = mesh->values[1];
                    probe->values[2] = mesh->values[2];
                    probe->values[3] = mesh->values[3];
                    break;
                }
                if (func_0014C100(&point, &probe->segment, &mesh->faces[i].back) &&
                    func_0014B800(&probe->segment, &point) && func_0014BCB0(&mesh->faces[i].back, &point)) {
                    probe->hit = 1;
                    probe->value = mesh->value;
                    probe->point = point;
                    probe->normal = mesh->normal;
                    probe->values[0] = mesh->values[0];
                    probe->values[1] = mesh->values[1];
                    probe->values[2] = mesh->values[2];
                    probe->values[3] = mesh->values[3];
                    break;
                }
            }
        }
    }
}
