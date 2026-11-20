struct Frame_000479D0;
struct Matrix_001BA950 {
    float m[4][4];
};

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};


// The model base class (table 0x1CAA8C): slot 5 starts a motion.
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void func_00048190(void *first, void *second, void *frame);
    virtual void func_00047470(void *first, void *second, Frame_000479D0 *frame);
    virtual void func_00048390(void *first, void *second, void *frame);
    virtual void func_00047540();
    virtual void func_00047690(int value, int argument);

    char unknown_04[0x1c];
    Matrix_001BA950 *matrices;
    char unknown_24[0x50];
    float weights[4];
};

struct Items_00020A10 {
    Object_00047470 *model;
};

struct Info_0001FED0 {
    int unknown_00;
    int slot;
};

struct Entry_0001FED0 {
    char unknown_00[8];
    Info_0001FED0 *info;
    char unknown_0c[0x74];
    int key;
};

struct State_0001FED0 {
    char unknown_00[0x78];
    int *lit;
    char unknown_7c[0x20];
    Items_00020A10 **items;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990); 0x21320 runs the member-pointer table at 0x1EBD60
// by each entry's kind.
struct Object_00022990 {
    char unknown_00[0xdc];
    State_0001FED0 *state;
    Entry_0001FED0 **entries;

    void func_00020A10(int index, int key, int first, int second);
};

// Kind 19 of the table at 0x1EBD60: when `key` is the entry's (+0x80), sets the four weights of the slot's model to
// 2 (whether or not the slot is lit) and starts its motion (first, second; or 0, 0).
void Object_00022990::func_00020A10(int index, int key, int first, int second)
{
    State_0001FED0 *state = this->state;
    Entry_0001FED0 *entry = entries[index];
    if (entry->key == key) {
        int slot = entry->info->slot;
        Object_00047470 *model = state->items[slot]->model;
        for (int i = 0; i < 4; i++) {
            if (state->lit[slot])
                model->weights[i] = 2.0f;
            else
                model->weights[i] = 2.0f;
        }
        if (first)
            model->func_00047690(first, second);
        else
            model->func_00047690(0, 0);
    }
}
