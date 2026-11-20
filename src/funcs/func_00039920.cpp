struct Block_00039920 {
    int words[0x24];
};

struct Words_00039920 {
    int words[8];
};

struct Source_00039920 {
    Block_00039920 block;
    int unknown_90;
    int unknown_94;
    int unknown_98;
    int unknown_9c;
    int unknown_a0;
    int unknown_a4;
    int unknown_a8;
    Words_00039920 words;
};

struct Item_000399C0 {
    Block_00039920 block;
    int unknown_90;
    int unknown_94;
    int unknown_98;
    int unknown_9c;
    Words_00039920 words;
    int unknown_c0;
    Item_000399C0 **link;
    Item_000399C0 *next;
};

struct Object_00039A10 {
    char unknown_00[8];
    Item_000399C0 **tail;

    Item_000399C0 *func_00039920(const Source_00039920 *source);
};

// Appends a new item to the list whose tail link is at +0x8, made from parts of the source, and returns it.
Item_000399C0 *Object_00039A10::func_00039920(const Source_00039920 *source)
{
    Item_000399C0 *item = new Item_000399C0;
    item->block = source->block;
    item->unknown_90 = source->unknown_90;
    item->unknown_94 = source->unknown_a0;
    item->unknown_98 = source->unknown_a4;
    item->unknown_9c = source->unknown_a8;
    item->words = source->words;
    item->unknown_c0 = source->unknown_94;
    item->next = 0;
    *tail = item;
    item->link = tail;
    tail = &item->next;
    return item;
}
