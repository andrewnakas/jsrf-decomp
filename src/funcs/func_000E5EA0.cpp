/* const: 0x10000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// The part of the collision item func_0001B5C0 tests: two counts, at +0x4 and +0x14.
struct Shape_000EC910 {
    int unknown_00;
    unsigned int first;
    char unknown_08[0xc];
    unsigned int second;
    char unknown_18[0xc];
};

struct Sphere_000EC910;

// A surface record of a contact (0x24 bytes): flags, a height at 0xc and a point at 0x18.
struct Record_000E5EA0 {
    unsigned int flags;
    char unknown_04[8];
    float height;
    char unknown_10[8];
    Vector3 point;
};

// A contact func_0001B5C0 finds (0x58 bytes): its record at 0x24.
struct Contact_000C4A90 {
    char unknown_00[0x24];
    Record_000E5EA0 record;
    char unknown_48[0x10];
};

// A contact of the other kind: its record at 0x48.
struct OtherContact_000E5EA0 {
    char unknown_00[0x48];
    Record_000E5EA0 record;
};

struct Hits_000C4C60 {
    Contact_000C4A90 *contacts;
    unsigned int count;
    OtherContact_000E5EA0 *others;
    unsigned int otherCount;
};

struct Object_00016200 {
    int func_0001B5C0(Shape_000EC910 *shape, Sphere_000EC910 *sphere, int radius, int *hit, int mask, int limit);
};

extern Object_00016200 data_0022FCE8;

void __fastcall func_0014C340(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);

// A swept segment (0x44 bytes): from, to and the model to sweep at 0x20.
struct Segment_000E6720 {
    Vector3 from;
    Vector3 to;
    char unknown_18[8];
    Shape_000EC910 model;
};

// Where a segment's sweep landed (12 bytes).
struct Result_000E6720 {
    Vector3 point;
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0xa4];
    unsigned int flags;
};

// The class whose table is at 0x1CED80 (handlers at 0x218DD0, run by the state at 0x30).
struct Object_000E5FF0 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    char unknown_008[0xc];
    Vector3 offset;

    int func_000E5EA0(Segment_000E6720 *segment, Result_000E6720 *result);
};

// Tests the segment's model in a 3.5 sphere around the result point (func_0001B5C0). The contact points (for the
// other kind, the first other contact's each time) are averaged and added to the offset at 0x14; a contact with
// surface flags 0x2413 counts as a hit and, with the owner's flag 0x10000, its height becomes the offset's y.
// Returns whether anything hit.
int Object_000E5FF0::func_000E5EA0(Segment_000E6720 *segment, Result_000E6720 *result)
{
    int hit = 0;
    Hits_000C4C60 hits;
    if (data_0022FCE8.func_0001B5C0(&segment->model, (Sphere_000EC910 *)result, 0x40600000, (int *)&hits, 0xffff,
                                    -1)) {
        Vector3 sum;
        sum.x = 0.0f;
        sum.y = 0.0f;
        sum.z = 0.0f;
        Contact_000C4A90 *contact = hits.contacts;
        for (unsigned int i = 0; i < hits.count; i++, contact++) {
            func_0014C340(&sum, &contact->record.point);
            if (contact->record.flags & 0x2413) {
                hit = 1;
                if (owner->flags & 0x10000) {
                    offset.y = contact->record.height;
                }
            }
        }
        OtherContact_000E5EA0 *other = hits.others;
        for (unsigned int j = 0; j < hits.otherCount; j++) {
            func_0014C340(&sum, &other->record.point);
            if (other->record.flags & 0x2413) {
                hit = 1;
                if (owner->flags & 0x10000) {
                    offset.y = other->record.height;
                }
            }
        }
        func_0014C370(&sum, &sum, 1.0f / (float)(hits.count + hits.otherCount));
        func_0014C340(&offset, &sum);
    }
    return hit;
}
