struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BADB0(Vector3 *position);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
float func_0014C870(float first, float second);

extern unsigned int data_0020C6C8[];

// Whether bit `index` of the visibility mask at 0x20C6C8 is set.
inline int IsVisible(int index)
{
    return index >= 0 && (data_0020C6C8[index >> 5] & (1 << (index & 0x1f)));
}

// A part of a group (0x50 bytes): where it stands, the model it shows and its kind.
struct Part_0006BA80 {
    Vector3 position;
    char unknown_0c[0x34];
    int model;
    int kind;
    char unknown_48[8];
};

struct Group_0006BA80 {
    Part_0006BA80 *parts;
    unsigned int count;
};

struct Scene_0006BA80 {
    Group_0006BA80 *groups;
    char unknown_04[4];
    unsigned int count;
};

// The shape of a model: its centre and radius.
struct Shape_0006C360 {
    char unknown_00[0x54];
    Vector3 centre;
    float radius;
};

struct Model_0006BA80 {
    virtual void slot0();

    char unknown_04[4];
    Shape_0006C360 *shape;
};

// A record of the model table at +0x14 (0x14 bytes).
struct Record_0006BA80 {
    char unknown_00[0xc];
    Model_0006BA80 *model;
    char unknown_10[4];
};

// An entry of the draw list (0x10 bytes): the part, its depth, the sort key and the next entry.
struct Item_0006A7C0 {
    Part_0006BA80 *part;
    float depth;
    unsigned int key;
    Item_0006A7C0 *next;
};

struct Object_0006A720 {
    char unknown_000[0x10];
    Scene_0006BA80 *scene;
    Record_0006BA80 *records;
    char unknown_018[4];
    Item_0006A7C0 *items;
    unsigned int count;
    Item_0006A7C0 *head;
    Item_0006A7C0 **tail;

    void func_0006A8D0(int shift);
    float func_0006C360();
};

// Lists every kind-1 part with a model of each visible group of the scene at +0x10 in the entries at +0x1c: its
// depth (the z of its model's centre, moved to the part) and a key from its far side whose order follows the
// floats; then sorts the list by the key in four byte passes (func_0006A8D0). Returns the nearest depth (from 10000,
// func_0014C870).
float Object_0006A720::func_0006C360()
{
    count = 0;
    head = 0;
    tail = &head;
    float nearest = 10000.0f;
    for (unsigned int i = 0; i < scene->count; i++) {
        if (IsVisible(i)) {
            for (unsigned int j = 0; j < scene->groups[i].count; j++) {
                Part_0006BA80 *part = &scene->groups[i].parts[j];
                if (part->kind == 1 && records[part->model].model) {
                    func_001BA9C0();
                    func_001BADB0(&part->position);
                    Vector3 centre;
                    func_001BAB20(&centre, &records[part->model].model->shape->centre);
                    items[count].part = part;
                    items[count].depth = centre.z;
                    float back = centre.z + records[part->model].model->shape->radius;
                    if (centre.z >= 0.0f) {
                        items[count].key = *(unsigned int *)&back | 0x80000000;
                    } else {
                        items[count].key = -*(int *)&back;
                    }
                    items[count].next = 0;
                    nearest = func_0014C870(nearest, centre.z);
                    *tail = &items[count];
                    tail = &items[count].next;
                    count++;
                    func_001BAA50();
                }
            }
        }
    }
    func_0006A8D0(0);
    func_0006A8D0(8);
    func_0006A8D0(0x10);
    func_0006A8D0(0x18);
    return nearest;
}
