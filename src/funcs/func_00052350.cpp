int func_00025680();
int func_000256A0(unsigned int index, int argument);
int func_000256C0(unsigned int index, int argument);

// A registration: a handler index and its argument, released through func_00025740.
struct Item_0004D8C0 {
    int first;
    int second;
    Item_0004D8C0 *next;
    Item_0004D8C0 **link;
};

struct Object_0004D8C0 {
    int unknown_00;
    Item_0004D8C0 *items;
    Item_0004D8C0 **tail;

    // Appends a registration.
    void Add(int first, int second)
    {
        Item_0004D8C0 *item = new Item_0004D8C0;
        item->first = first;
        item->second = second;
        *tail = item;
        item->link = tail;
        tail = &item->next;
        *tail = 0;
    }

    // Whether the registration is there.
    int Has(int first, int second)
    {
        for (Item_0004D8C0 *item = items; item; item = item->next) {
            if (item->first == first && item->second == second) {
                return 1;
            }
        }
        return 0;
    }
};

extern Object_0004D8C0 data_001FA05C;

// One of the things a stage needs (0x20 bytes): a handler index and its argument.
struct Need_00052350 {
    int first;
    int second;
    char unknown_08[0x18];
};

struct Object_0004ABA0 {
    char unknown_00[0x5c];
    int state;
    char unknown_60[4];
    Need_00052350 *needs;
    unsigned int count;
    unsigned int next;
    int waiting;

    void func_00052350();
};

// State handler 8 of the tables at 0x1F9888 and 0x1F9C48: once the need it waits for is ready (func_000256C0),
// registers it on 0x1FA05C and goes on to the next. Then skips the needs already registered; past the last one goes
// to state 9, otherwise, unless func_00025680 says to wait, starts the next one (func_000256A0) and waits for it.
void Object_0004ABA0::func_00052350()
{
    if (waiting) {
        if (func_000256C0(needs[next].first, needs[next].second)) {
            data_001FA05C.Add(needs[next].first, needs[next].second);
            next++;
            waiting = 0;
        }
        if (waiting) {
            return;
        }
    }
    unsigned int total = count;
    while (next < count && data_001FA05C.Has(needs[next].first, needs[next].second)) {
        next++;
    }
    if (next < total) {
        if (!func_00025680() && func_000256A0(needs[next].first, needs[next].second)) {
            waiting = 1;
        }
        return;
    }
    state = 9;
}
