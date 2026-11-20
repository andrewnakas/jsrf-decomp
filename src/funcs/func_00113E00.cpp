struct Vector3 {
    float x;
    float y;
    float z;
};

struct Point_00113E00 {
    char unknown_00[8];
    Vector3 position;
    char unknown_14[0x34];
};

struct List_000149B0 {
    Point_00113E00 *points;
    unsigned int count;
    char unknown_08[0x184];
    List_000149B0 *next;
};

struct Model_00113E00 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

struct Object_000149B0 {
    List_000149B0 *func_000149D0();
};

struct Object_00113C40 {
    char unknown_000[0xa4];
    float scale;
    char unknown_0a8[0x1c];
    Model_00113E00 *model;

    void func_00113E00();
};

extern Object_000149B0 data_0020C750;
void func_001BA9C0();
void __fastcall func_001BAA50();
void func_001BB230(float x, float y, float z);
void __fastcall func_001BADB0(Vector3 *position);

// Member of the class whose table is at 0x1D2B28 (called by 0x114A80): for each point of each list from
// func_000149D0 of data_0020C750, draws the model at +0xc4 (its slot 5) there, scaled by 0.01 and by the float at
// +0xa4.
void Object_00113C40::func_00113E00()
{
    for (List_000149B0 *list = data_0020C750.func_000149D0(); list; list = list->next) {
        for (unsigned int i = 0; i < list->count; i++) {
            func_001BA9C0();
            func_001BB230(0.01f, 0.01f, 0.01f);
            func_001BADB0(&list->points[i].position);
            func_001BB230(scale, scale, scale);
            if (model) {
                model->slot5(0, 0);
            }
            func_001BAA50();
        }
    }
}
