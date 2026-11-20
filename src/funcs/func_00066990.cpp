extern "C" void *memcpy(void *, const void *, unsigned int);

struct Element_00066990 {
    int words[0x24];
};

struct Source_00066990 {
    Element_00066990 *elements;
    int count;
};

struct Item_00066A00 {
    Element_00066990 *elements;
    int count;
    Item_00066A00 **link;
    Item_00066A00 *next;
    int unknown_10[2];
};

struct Object_00066A70 {
    char unknown_00[8];
    Item_00066A00 **tail;

    Item_00066A00 *func_00066990(const Source_00066990 *source);
};

// Appends a new item to the list whose tail link is at +0x8, with a copy of the source's 0x90-byte elements, and
// returns it.
Item_00066A00 *Object_00066A70::func_00066990(const Source_00066990 *source)
{
    Item_00066A00 *item = new Item_00066A00;
    item->elements = (Element_00066990 *)operator new(source->count * sizeof(Element_00066990));
    memcpy(item->elements, source->elements, source->count * sizeof(Element_00066990));
    item->count = source->count;
    item->next = 0;
    *tail = item;
    item->link = tail;
    tail = &item->next;
    return item;
}
