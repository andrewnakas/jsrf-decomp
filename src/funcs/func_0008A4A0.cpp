/* const: 0x40000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// The item the player keeps in the list at 0x20C750 (0x38 bytes, linked at +0x34).
struct Item_0006C640 {
    Vector3 position;
    char unknown_0c[0x28];
    Item_0006C640 *next;
};

struct Object_000149B0 {
    void func_0006C640(Item_0006C640 *item, int first, int second, int third, int fourth);
};

extern Object_000149B0 data_0020C750;

extern "C" void *memset(void *destination, int value, unsigned int size);

struct Object_000A1C50 {
    char unknown_000[0x2dc];
    int value_2dc;
    int value_2e0;
    int unknown_2e4;
    Item_0006C640 item;
    char unknown_320[0x984];
    Vector3 position;

    int func_0007F500();
    int func_0007F880();
    void func_0008A4A0(int argument);
};

// While func_0007F500 allows it, puts the player's item at its position (+0xca4) into the list at 0x20C750, flagged
// by bit 0x40000 of func_0007F880; otherwise clears the item.
void Object_000A1C50::func_0008A4A0(int argument)
{
    if (func_0007F500()) {
        item.position.x = position.x;
        item.position.y = position.y;
        item.position.z = position.z;
        if (func_0007F880() & 0x40000) {
            data_0020C750.func_0006C640(&item, 1, value_2dc, argument, value_2e0);
        } else {
            data_0020C750.func_0006C640(&item, 0, value_2dc, argument, value_2e0);
        }
    } else {
        memset(&item, 0, sizeof(item));
    }
}
