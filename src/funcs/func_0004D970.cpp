struct Game {
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

// A registration: a handler index and its argument, released through func_00025740.
struct Item_0004D8C0 {
    int first;
    int second;
    Item_0004D8C0 *next;
    Item_0004D8C0 **link;
};

// A wanted registration (0x20 bytes).
struct Want_0004D970 {
    int first;
    int second;
    char unknown_08[0x18];
};

struct Object_0004D8C0 {
    int unknown_00;
    Item_0004D8C0 *items;
    Item_0004D8C0 **tail;

    void func_0004D900(int first, int second);
    void func_0004D970(Want_0004D970 *wants, unsigned int count);
};

// Releases (func_0004D900) every registration that is not among the `count` wanted ones. Kinds 0, 3, 4 and 29 are
// always kept; kind 2 is kept when wanted, or, when some kind 1 is wanted, when its argument is one of the four players
// (objects 0xd to 0x10).
void Object_0004D8C0::func_0004D970(Want_0004D970 *wants, unsigned int count)
{
    Item_0004D8C0 *next;
    for (Item_0004D8C0 *item = items; item; item = next) {
        next = item->next;
        unsigned int i;
        switch (item->first) {
        case 0:
        case 3:
        case 4:
        case 29:
            break;
        case 2:
            for (i = 0; i < count; i++) {
                if (wants[i].first == 2 && wants[i].second == item->second)
                    break;
            }
            if (i < count)
                break;
            for (i = 0; i < count; i++) {
                if (wants[i].first == 1)
                    break;
            }
            if (i < count) {
                for (i = 0; i < 4; i++) {
                    if (item->second == data_0022FCE0->func_000127E0(i + 0xd))
                        break;
                }
                if (i < 4)
                    break;
                func_0004D900(item->first, item->second);
            } else {
                func_0004D900(2, item->second);
            }
            break;
        default:
            for (i = 0; i < count; i++) {
                if (item->first == wants[i].first && item->second == wants[i].second)
                    break;
            }
            if (i < count)
                break;
            func_0004D900(item->first, item->second);
            break;
        }
    }
}
