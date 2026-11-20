struct Vector3 {
    float x;
    float y;
    float z;
};

struct Matrix_001BA950 {
    float m[4][4];
};

void func_0004A750(Vector3 *to, const Vector3 *from);
void func_001BA9C0();
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void __fastcall func_001BAA50();
void __fastcall func_001BAB20(Vector3 *to, const Vector3 *from);
void __fastcall func_001BAC00(Vector3 *to, const Vector3 *from);
void __fastcall func_001BADB0(Vector3 *position);

// One part of the source shape (0xa8 bytes): a box of six points and six normals and two more points.
struct SourcePart_0003EA80 {
    Vector3 box[12];
    Vector3 first;
    Vector3 second;
};

// The shape an entry is made from: its parts, five points and a normal, another box and a position.
struct Source_0003EA80 {
    char unknown_00[0x9c];
    SourcePart_0003EA80 *parts;
    char unknown_a0[0xc];
    Vector3 *points;
    Vector3 *box;
    Vector3 *position;
};

// One part of an entry (0xb8 bytes): the moved copies of a source part.
struct Part_0003EA80 {
    Vector3 box[12];
    char unknown_90[4];
    Vector3 first;
    Vector3 second;
    char unknown_ac[0xc];
};

struct Entry_0003E720 {
    Source_0003EA80 *source;
    Vector3 box[12];
    Part_0003EA80 *parts;
    unsigned int count;
    char unknown_9c[0x58];
    Vector3 *points;
    Vector3 *other;
    Matrix_001BA950 *matrix;
};

struct Object_0003E750 {
    void func_0003EA80(Entry_0003E720 *entry);
};

// Moves the entry's copy of its source shape by the current matrix: its box, every part's box and two points, the
// five points and the normal (when it has them), the other box, and takes the matrix at the source's position. Does
// not use `this`.
void Object_0003E750::func_0003EA80(Entry_0003E720 *entry)
{
    Source_0003EA80 *source = entry->source;
    func_0004A750(entry->box, (Vector3 *)source);
    for (unsigned int i = 0; i < entry->count; i++) {
        func_0004A750(entry->parts[i].box, source->parts[i].box);
        func_001BAB20(&entry->parts[i].first, &source->parts[i].first);
        func_001BAB20(&entry->parts[i].second, &source->parts[i].second);
    }
    if (entry->points) {
        for (unsigned int j = 0; j < 5; j++) {
            func_001BAB20(&entry->points[j], &source->points[j]);
        }
        func_001BAC00(&entry->points[5], &source->points[5]);
    }
    if (entry->other) {
        func_0004A750(entry->other, source->box);
    }
    if (entry->matrix) {
        func_001BA9C0();
        func_001BADB0(source->position);
        func_001BA950(entry->matrix);
        func_001BAA50();
    }
}
