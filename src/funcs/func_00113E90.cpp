struct Model_00113E90 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

struct Entry_00113E90 {
    float x;
    float y;
    float z;
    unsigned int id;
    char unknown_10[0x28];
    Entry_00113E90 *next;
};

struct Object_00043700 {
    int func_00043700();
};

struct Object_00039BE0 {
    int func_00039EF0(unsigned int id);
};

struct Object_00113C40 {
    char unknown_000[0xa4];
    float scale;
    char unknown_0a8[0x14];
    Model_00113E90 *model;

    void func_00113E90();
};

extern Object_00043700 data_001F9138;
extern Object_00039BE0 data_001EFFB0;

void func_001BA9C0();
void func_001BAA50();
void func_001BAA60(float x, float y, float z);
void func_001BB230(float x, float y, float z);

// Member of the class whose table is at 0x1D2B28 (called by 0x114A80): for each entry of the list that
// data_001F9138 holds whose id data_001EFFB0's func_00039EF0 accepts, draws the model at +0xbc (its slot 5) at the
// entry's position scaled by 0.01, scaled by the float at +0xa4.
void Object_00113C40::func_00113E90()
{
    for (Entry_00113E90 *entry = (Entry_00113E90 *)data_001F9138.func_00043700(); entry; entry = entry->next) {
        if (data_001EFFB0.func_00039EF0(entry->id)) {
            func_001BA9C0();
            func_001BAA60(entry->x * 0.01f, entry->y * 0.01f, entry->z * 0.01f);
            func_001BB230(scale, scale, scale);
            if (model) {
                model->slot5(0, 0);
            }
            func_001BAA50();
        }
    }
}
