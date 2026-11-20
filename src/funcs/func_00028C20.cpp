// An entry of the table at +0xc0c.
struct Item_00028C20 {
    char unknown_00[0x60];
    void **unknown_60;
    char unknown_64[0x38];
    int **unknown_9c;
};

struct Object_000265A0 {
    char unknown_000[0xc0c];
    Item_00028C20 *items[1];

    void *func_00028C20(int index, int kind, int sub);
};

// Handler 9 of the table at 0x1EC200: entry `index` of the table at +0xc0c (kind 0), the address of word `sub` of
// its list `index` at +0x9c (kind 1) or its pointer `sub` at +0x60 (kind 2); else 0.
void *Object_000265A0::func_00028C20(int index, int kind, int sub)
{
    Item_00028C20 *item = items[index];
    switch (kind) {
    case 0:
        return item;
    case 1:
        return &item->unknown_9c[index][sub];
    case 2:
        return item->unknown_60[sub];
    }
    return 0;
}
