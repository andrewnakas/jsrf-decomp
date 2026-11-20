struct Vector3 {
    float x;
    float y;
    float z;
};

int func_0004EAA0(int index);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0006A960 {
    int func_0006AAA0(Vector3 *position, int index);
    float func_0006AC40(Vector3 *position, int index);
};

extern Object_0006A960 data_0020C6C0;

// The object 0x1ddc: a camera (its eye at +0x44).
struct Object_000239D0 {
    char unknown_00[0x44];
    Vector3 eye;
};

// One part of the model: a kind value at +0x44 and a light level at +0x5c.
struct Part_00022770 {
    char unknown_00[0x44];
    int kind;
    char unknown_48[0x14];
    float light;
};

// The model at +0xdc: +0x64 groups, each with a kind (+0x74) and a list of parts (+0x98 counts, +0x9c lists).
struct Model_00022770 {
    char unknown_00[0x64];
    unsigned int groupCount;
    char unknown_68[0xc];
    int *kinds;
    char unknown_78[0x20];
    unsigned int *partCounts;
    Part_00022770 ***parts;
};

struct Object_00022990 {
    char unknown_00[0xc8];
    int area;
    char unknown_cc[0x10];
    Model_00022770 *model;

    void func_00022770();
};

// Looks up the area (func_0006AAA0, kept at +0xc8) and light level (func_0006AC40) at the eye of object 0x1ddc and
// gives every part of the model at +0xdc that light, and by its group's kind 0x100 (kind 0), 0x101 (kind 1) or
// 0x299d7657 (kind 2).
void Object_00022990::func_00022770()
{
    Model_00022770 *model = this->model;
    Object_000239D0 *camera = (Object_000239D0 *)data_0022FCE0->func_000128C0(0x1ddc);
    if (model) {
        Vector3 *eye = &camera->eye;
        area = data_0020C6C0.func_0006AAA0(eye, area);
        float light = data_0020C6C0.func_0006AC40(eye, area);
        for (unsigned int i = 0; i < model->groupCount; i++) {
            for (unsigned int j = 0; j < model->partCounts[i]; j++) {
                Part_00022770 *part = model->parts[i][j];
                if (part) {
                    switch (model->kinds[i]) {
                    case 0:
                        part->kind = func_0004EAA0(0);
                        break;
                    case 1:
                        part->kind = func_0004EAA0(1);
                        break;
                    case 2:
                        part->kind = 0x299d7657;
                        break;
                    }
                    part->light = light;
                }
            }
        }
    }
}
