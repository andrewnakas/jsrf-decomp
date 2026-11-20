/* cflags: /Oy- */
extern "C" void *memcpy(void *, const void *, unsigned int);

// What a group draws from: the primitive type at +0x18 and the counts the primitive count comes from.
struct Buffer_00047230 {
    int unknown_00;
    unsigned int size;
    char unknown_08[0x0c];
    unsigned int vertexCount;
    int type;
};

struct Item_00047230 {
    char unknown_00[0x14];
};

struct Box_00047230 {
    int a;
    int b;
    int c;
    int d;
};

// A part of a group: 0x20 bytes. In a group's table `handle` holds the index of the part's item; in a copy it holds
// the handle func_00047160 made for that item.
struct Part_00047230 {
    unsigned int primitiveCount;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
    int handle;
    char unknown_14[0x08];
    Box_00047230 *box;
};

struct Group_00047230 {
    Buffer_00047230 *buffer;
    Item_00047230 *items;
    int unknown_08;
    int unknown_0c;
    char unknown_10[0x60];
    Part_00047230 *parts;
    unsigned int partCount;
};

struct Out_00047230 {
    char unknown_00[0x0c];
    Part_00047230 *parts;
    unsigned int partCount;
};

struct Pair_00047230 {
    Item_00047230 *item;
    int handle;
};

extern unsigned char data_00231D40[];

struct Object_00047470 {
    char unknown_00[0x6c];
    int *handles;
    unsigned int handleCount;

    void func_00047230(Group_00047230 *group, Out_00047230 *out);
};

// Copies a group's parts into `out` (one part made up from the group's buffer when the group has no table), giving
// each part the handle func_00047160 left in the scratch pairs at 0x231D40 for its item.
void Object_00047470::func_00047230(Group_00047230 *group, Out_00047230 *out)
{
    Pair_00047230 *pairs = (Pair_00047230 *)data_00231D40;
    if (group->partCount == 0) {
        out->partCount = 1;
        out->parts = (Part_00047230 *)operator new(sizeof(Part_00047230));
        out->parts->handle = -1;
        if (group->items != 0) {
            for (unsigned int k = 0; k < handleCount; k++) {
                if (group->items == pairs[k].item) {
                    out->parts->handle = pairs[k].handle;
                }
            }
        }
        out->parts->unknown_0c = group->unknown_0c;
        Buffer_00047230 *buffer = group->buffer;
        switch (buffer->type) {
        case 0:
            out->parts->primitiveCount = buffer->vertexCount / 3;
            break;
        case 1:
            out->parts->primitiveCount = buffer->vertexCount - 2;
            break;
        case 2:
            out->parts->primitiveCount = buffer->size / 4;
            break;
        }
        out->parts->unknown_04 = 0;
        out->parts->unknown_08 = 0;
        out->parts->box = 0;
        return;
    }
    out->partCount = group->partCount;
    if (group->parts != 0) {
        out->parts = (Part_00047230 *)operator new(group->partCount * sizeof(Part_00047230));
        memcpy(out->parts, group->parts, group->partCount * sizeof(Part_00047230));
        Part_00047230 *source = group->parts;
        for (unsigned int i = 0; i < group->partCount; i++) {
            out->parts[i].handle = -1;
            if (group->items != 0) {
                Item_00047230 *item = &group->items[source[i].handle];
                for (unsigned int k = 0; k < handleCount; k++) {
                    if (item == pairs[k].item) {
                        out->parts[i].handle = pairs[k].handle;
                    }
                }
            }
            if (source[i].box != 0) {
                Box_00047230 *box = (Box_00047230 *)operator new(sizeof(Box_00047230));
                out->parts[i].box = box;
                *box = *source[i].box;
            }
        }
    } else {
        out->parts = 0;
    }
}
