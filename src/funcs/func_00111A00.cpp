struct Vector3 {
    float x;
    float y;
    float z;
};

struct Point_00111A00 {
    char unknown_00[8];
    Vector3 position;
    char unknown_14[0x34];
};

struct List_00111A00 {
    Point_00111A00 *points;
    unsigned int count;
    char unknown_08[0x184];
    List_00111A00 *next;
};

struct Model_00111A00 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

struct Object_000149B0 {
    int func_000149D0();
};

struct Object_001118F0 {
    char unknown_000[0xb8];
    Model_00111A00 *model;
    char unknown_0bc[0x6c];
    float scale;

    void func_00111A00();
};

extern Object_000149B0 data_0020C750;
void func_001BA9C0();
void func_001BAA50();
void func_001BB230(float x, float y, float z);
void __fastcall func_001BADB0(Vector3 *position);

// Member of the class whose table is at 0x1D27C8 (called by 0x112470): for each point of each list from
// func_000149D0 of data_0020C750, draws the model at +0xb8 (its slot 5) there, scaled by 0.01 and by the float at
// +0x128.
void Object_001118F0::func_00111A00()
{
    for (List_00111A00 *list = (List_00111A00 *)data_0020C750.func_000149D0(); list; list = list->next) {
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
