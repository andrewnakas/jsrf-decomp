struct Vector3 {
    float x;
    float y;
    float z;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

// A hit recorded for an item: the value and id of the entry it touches.
struct Pair_0001D570 {
    int value;
    int id;
};

// A collision item: flags, an id, its box, its hits (+0x38, count +0x3c) and the next item.
struct Item_00016260 {
    unsigned int flags;
    int id;
    Box_00017CC0 box;
    int unknown_20[6];
    Pair_0001D570 *pairs;
    int pairCount;
    Item_00016260 *next;
};

// A model registered for collisions: its mesh, a value and an id; +0x5c cleared every frame.
struct Model_00019970 {
    void *mesh;
    int value;
    int id;
    char unknown_0c[0x50];
    int unknown_5c;
};

struct Link_0001D570 {
    Model_00019970 *model;
    Link_0001D570 *next;
};

// A box entry (+0x1090 list): its box, id, whether it is on, a value, +0x8c cleared every frame, the next entry.
struct Entry_0001D570 {
    char unknown_00[0x10];
    Box_00017CC0 box;
    char unknown_28[8];
    int id;
    int enabled;
    int value;
    char unknown_3c[0x50];
    int unknown_8c;
    char unknown_90[0xc];
    Entry_0001D570 *next;
};

// The collision world (data_0022FCE8).
struct Object_00016200 {
    char unknown_0000[0x18];
    Link_0001D570 *links;
    Item_00016260 *items;
    char unknown_0020[0x20];
    int unknown_40;
    int pairCount;
    char unknown_0048[0xc];
    Pair_0001D570 *pairs;
    char unknown_0058[0x1038];
    Entry_0001D570 *entries;

    void func_00019970(Item_00016260 *item, void *mesh, int value, int id);
    void func_0001D570();
};

// Clears the models' and entries' marks and the hit list, then tests every item against every model
// (func_00019970) and against every enabled entry with flag 0x4000, recording a hit for each entry whose box
// overlaps the item's. Items never meet a model or entry with their own id.
void Object_00016200::func_0001D570()
{
    for (Link_0001D570 *link = links; link; link = link->next) {
        if (link->model) {
            link->model->unknown_5c = 0;
        }
    }
    for (Entry_0001D570 *entry = entries; entry; entry = entry->next) {
        if (entry->enabled) {
            entry->unknown_8c = 0;
        }
    }
    unknown_40 = 0;
    pairCount = 0;
    for (Item_00016260 *item = items; item; item = item->next) {
        for (Link_0001D570 *other = links; other; other = other->next) {
            Model_00019970 *model = other->model;
            if (model) {
                if (!(item->id >= 0 && model->id >= 0 && item->id == model->id)) {
                    func_00019970(item, model->mesh, model->value, model->id);
                }
            }
        }
        for (Entry_0001D570 *box = entries; box; box = box->next) {
            if (box->enabled && (item->flags & 0x4000)) {
                if (!(item->id >= 0 && box->id >= 0 && item->id == box->id)) {
                    if (!(box->box.min.x > item->box.max.x) && !(box->box.max.x < item->box.min.x) &&
                        !(box->box.min.z > item->box.max.z) && !(box->box.max.z < item->box.min.z) &&
                        !(box->box.min.y > item->box.max.y) && !(box->box.max.y < item->box.min.y)) {
                        Pair_0001D570 *pair = &pairs[pairCount];
                        if (!item->pairs) {
                            item->pairs = pair;
                        }
                        pair->value = box->value;
                        pair->id = box->id;
                        item->pairCount++;
                        pairCount++;
                    }
                }
            }
        }
    }
}
