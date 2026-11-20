// A vertex of the quads at +0x74 (0x14 bytes): position and texture coordinates.
struct Vertex_0005FAF0 {
    float x;
    float y;
    float z;
    float u;
    float v;
};

// A point of the list at +0x14d4: its frame at +0x30 and how many ticks a frame lasts at +0x80.
struct Point_0005FAF0 {
    char unknown_00[0x30];
    int frame;
    char unknown_34[0x4c];
    unsigned short ticks;
};

// The quad the vertices are copied from (corners at -0.5 and 0.5, texture corners 0 and 1).
extern const Vertex_0005FAF0 data_001CAFA8[4];

struct Object_00062390 {
    char unknown_0000[0x74];
    Vertex_0005FAF0 *vertices;
    char unknown_0078[0x14];
    unsigned char *frames;
    char unknown_0090[0x328];
    int columns;
    int rows;
    char unknown_03c0[0x39c];
    int wrap;
    char unknown_0760[0xd74];
    Point_0005FAF0 **points;

    void func_0005FAF0(int quad, int index);
};

// Fills quad `quad` with the template quad and the texture cell of the point's frame: the start frame at +0x8c plus,
// when the point has a frame length, its frame over that length, wrapped round the row count (+0x75c set) or held at
// the last one; the cell is one of `columns` (+0x3b8) to a row, each 1/columns wide and high.
void Object_00062390::func_0005FAF0(int quad, int index)
{
    Point_0005FAF0 *point = points[index];
    int ticks = point->ticks;
    if (!ticks) {
        ticks = 1;
    }
    int columns = this->columns;
    if (!columns) {
        columns = 1;
    }
    int rows = this->rows;
    if (!rows) {
        rows = 1;
    }
    float step = 1.0f / columns;
    unsigned char frame;
    if (!point->ticks) {
        frame = frames[index];
    } else {
        frame = point->frame / ticks + frames[index];
        if (wrap) {
            frame = frame % rows;
        } else if (frame >= rows) {
            frame = rows - 1;
        }
    }
    int column = frame % columns;
    int row = frame / columns;
    float u = column * step;
    float v = row * step;
    Vertex_0005FAF0 *vertex = &vertices[quad * 4];
    *vertex = data_001CAFA8[0];
    vertex->u = u;
    vertex->v = v;
    vertex++;
    *vertex = data_001CAFA8[1];
    vertex->u = u + step;
    vertex->v = v;
    vertex++;
    *vertex = data_001CAFA8[2];
    vertex->u = u;
    vertex->v = v + step;
    vertex++;
    *vertex = data_001CAFA8[3];
    vertex->u = u + step;
    vertex->v = v + step;
}
