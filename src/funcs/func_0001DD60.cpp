struct Vector3 {
    float x;
    float y;
    float z;
};

// A convex cell (0x90 bytes): six points on its faces, then the six face normals.
struct Cell_000A6DC0 {
    Vector3 points[6];
    Vector3 normals[6];
};

int func_0004A6F0(Vector3 *point, Cell_000A6DC0 *cell);

// An entry of the cell list (+0x4): the cell, a value and a vector.
struct Item_0001DCA0 {
    Cell_000A6DC0 cell;
    int value;
    Vector3 vector;
    Item_0001DCA0 **link;
    Item_0001DCA0 *next;
};

// An entry of the point list (+0xc): its point, whether a cell holds it, and that cell's value and vector.
struct Item_0001DCF0 {
    Vector3 point;
    int inside;
    int value;
    Vector3 vector;
    Item_0001DCF0 **link;
    Item_0001DCF0 *next;
};

// The object at 0x1EBAA8.
struct Object_00039A10 {
    char unknown_00[4];
    Item_0001DCA0 *cells;
    Item_0001DCA0 **cellTail;
    Item_0001DCF0 *points;

    void func_0001DD60();
};

// For each entry of the point list, finds the first cell of the cell list that holds its point (func_0004A6F0) and
// takes that cell's value and vector; +0xc says whether one was found.
void Object_00039A10::func_0001DD60()
{
    for (Item_0001DCF0 *item = points; item; item = item->next) {
        item->inside = 0;
        for (Item_0001DCA0 *cell = cells; cell; cell = cell->next) {
            if (func_0004A6F0(&item->point, &cell->cell)) {
                item->inside = 1;
                item->value = cell->value;
                item->vector = cell->vector;
            }
            if (item->inside)
                break;
        }
    }
}
