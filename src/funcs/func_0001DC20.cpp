struct Block_0001DC20 {
    int words[0x24];
};

struct Source_0001DC20 {
    Block_0001DC20 block;
    int unknown_90;
    int unknown_94;
    int unknown_98;
    int unknown_9c;
};

struct Item_0001DCA0 {
    Block_0001DC20 block;
    int unknown_90;
    int unknown_94;
    int unknown_98;
    int unknown_9c;
    Item_0001DCA0 **link;
    Item_0001DCA0 *next;
};

struct Object_00039A10 {
    char unknown_00[8];
    Item_0001DCA0 **tail;

    Item_0001DCA0 *func_0001DC20(const Source_0001DC20 *source);
};

// Appends a new item to the list whose tail link is at +0x8: a copy of the source's first 0x90 bytes and its four
// words after them, the last one first. Returns it.
Item_0001DCA0 *Object_00039A10::func_0001DC20(const Source_0001DC20 *source)
{
    Item_0001DCA0 *item = new Item_0001DCA0;
    item->block = source->block;
    item->unknown_90 = source->unknown_9c;
    item->unknown_94 = source->unknown_90;
    item->unknown_98 = source->unknown_94;
    item->unknown_9c = source->unknown_98;
    item->next = 0;
    *tail = item;
    item->link = tail;
    tail = &item->next;
    return item;
}
