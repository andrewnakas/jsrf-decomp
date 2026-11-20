// A vertex of the triangle pairs at +0x78 (0x18 bytes): texture coordinates at +0x10.
struct Vertex_0005FC40 {
    char unknown_00[0x10];
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

struct Object_00062390 {
    char unknown_0000[0x78];
    Vertex_0005FC40 *vertices;
    char unknown_007c[0x10];
    unsigned char *frames;
    char unknown_0090[0x328];
    int columns;
    int rows;
    char unknown_03c0[0x39c];
    int wrap;
    char unknown_0760[0xd74];
    Point_0005FAF0 **points;

    void func_0005FC40(int quad, int index);
};

// Like func_0005FAF0 for the two triangles of quad `quad` in the list at +0x78: sets only their texture coordinates
// to the cell of the point's frame.
void Object_00062390::func_0005FC40(int quad, int index)
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
    Vertex_0005FC40 *vertex = &vertices[quad * 6];
    vertex->u = u;
    vertex->v = v + step;
    vertex++;
    vertex->u = u;
    vertex->v = v;
    vertex++;
    vertex->u = u + step;
    vertex->v = v;
    vertex++;
    vertex->u = u;
    vertex->v = v + step;
    vertex++;
    vertex->u = u + step;
    vertex->v = v;
    vertex++;
    vertex->u = u + step;
    vertex->v = v + step;
}
