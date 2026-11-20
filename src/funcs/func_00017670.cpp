extern "C" void *memcpy(void *destination, const void *source, unsigned int size);

// One item of a mesh (12 bytes).
struct Item_00017670 {
    int x;
    int y;
    int z;
};

struct Mesh_00017860 {
    Item_00017670 *items;
    int count;
    Item_00017670 *extras;
    int extra;
};

struct Frame_00017860 {
    int values[9];
    Mesh_00017860 *mesh;
    Frame_00017860 *child;
    Frame_00017860 *next;
};

// A copied mesh (0x34 bytes, its items follow it): three copies of the items, then the extra items.
struct Copy_00017670 {
    char unknown_00[0x18];
    int unknown_18;
    Item_00017670 *first;
    Item_00017670 *second;
    Item_00017670 *third;
    int count;
    Item_00017670 *extras;
    int extra;
};

// A copied frame (0x30 bytes).
struct Frame_00017670 {
    int values[9];
    Copy_00017670 *mesh;
    Frame_00017670 *child;
    Frame_00017670 *next;
};

struct Object_00016200 {
    void func_00017670(char **cursor, Frame_00017860 *frame);
};

// Copies a frame tree into the block at `*cursor` (sized by func_00017860), moving the cursor past each piece: the
// frame, then its mesh with three copies of its items and its extra items, then its children; the frames after it
// follow. The copies' child and next links point into the block.
void Object_00016200::func_00017670(char **cursor, Frame_00017860 *frame)
{
    Frame_00017670 **frames = (Frame_00017670 **)cursor;
    while (frame) {
        Frame_00017670 *out = *frames;
        (*frames)->values[0] = frame->values[0];
        (*frames)->values[1] = frame->values[1];
        (*frames)->values[2] = frame->values[2];
        (*frames)->values[3] = frame->values[3];
        (*frames)->values[4] = frame->values[4];
        (*frames)->values[5] = frame->values[5];
        (*frames)->values[6] = frame->values[6];
        (*frames)->values[7] = frame->values[7];
        (*frames)->values[8] = frame->values[8];
        if (frame->mesh) {
            (*frames)->mesh = (Copy_00017670 *)(*cursor + 0x30);
            (*frames)->mesh->unknown_18 = 0;
            (*frames)->mesh->first = (Item_00017670 *)((char *)(*frames)->mesh + 0x34);
            (*frames)->mesh->second = (*frames)->mesh->first + frame->mesh->count;
            (*frames)->mesh->third = (*frames)->mesh->second + frame->mesh->count;
            (*frames)->mesh->count = frame->mesh->count;
            memcpy((*frames)->mesh->first, frame->mesh->items, frame->mesh->count * sizeof(Item_00017670));
            memcpy((*frames)->mesh->second, frame->mesh->items, frame->mesh->count * sizeof(Item_00017670));
            memcpy((*frames)->mesh->third, frame->mesh->items, frame->mesh->count * sizeof(Item_00017670));
            (*frames)->mesh->extras = (*frames)->mesh->third + frame->mesh->count;
            (*frames)->mesh->extra = frame->mesh->extra;
            memcpy((*frames)->mesh->extras, frame->mesh->extras, frame->mesh->extra * sizeof(Item_00017670));
            *cursor = (char *)((*frames)->mesh->extras + frame->mesh->extra);
        } else {
            (*frames)->mesh = 0;
            *cursor += 0x30;
        }
        if (frame->child) {
            out->child = *frames;
            func_00017670(cursor, frame->child);
        } else {
            out->child = 0;
        }
        frame = frame->next;
        if (frame)
            out->next = *frames;
        else
            out->next = 0;
    }
}
