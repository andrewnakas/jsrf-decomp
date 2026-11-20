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

struct Block_00039A80 {
    int words[8];
};

// An entry of the cell list (+0x4): the cell, a value, a vector, a block and a word.
struct Item_000399C0 {
    Cell_000A6DC0 cell;
    int value;
    Vector3 vector;
    Block_00039A80 block;
    int word;
    Item_000399C0 **link;
    Item_000399C0 *next;
};

// An entry of the point list (+0xc): its point, whether a cell holds it, and that cell's value, vector, block and
// word.
struct Item_00039A10 {
    Vector3 point;
    int inside;
    int value;
    Vector3 vector;
    Block_00039A80 block;
    int word;
    Item_00039A10 **link;
    Item_00039A10 *next;
};

// The object at 0x1EFC74.
struct Object_00039A10 {
    char unknown_00[4];
    Item_000399C0 *cells;
    Item_000399C0 **cellTail;
    Item_00039A10 *points;

    void func_00039A80();
};

// As func_0001DD60 for the lists of 0x1EFC74: for each entry of the point list, finds the first cell that holds its
// point (func_0004A6F0) and takes that cell's value, vector, block and word; +0xc says whether one was found.
void Object_00039A10::func_00039A80()
{
    for (Item_00039A10 *item = points; item; item = item->next) {
        item->inside = 0;
        for (Item_000399C0 *cell = cells; cell; cell = cell->next) {
            if (func_0004A6F0(&item->point, &cell->cell)) {
                item->inside = 1;
                item->value = cell->value;
                item->vector = cell->vector;
                item->block = cell->block;
                item->word = cell->word;
            }
            if (item->inside)
                break;
        }
    }
}
