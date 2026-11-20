struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;
struct Pose_0005F060;
struct Mesh_00017F60;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void func_001BB670(float angle);

struct Item_00016200 {
    int unknown_00;
    Item_00016200 *next;
};

struct Item_00016260 {
    char unknown_00[8];
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

// A vertex of a deformed mesh (0x18 bytes): position and normal.
struct Vertex_00017DF0 {
    Vector3 position;
    Vector3 normal;
};

// What func_000179B0 finds by key: its vertices, a copy of them, their bounds and count.
struct Entry_000179B0 {
    int unknown_00;
    Vertex_00017DF0 *vertices;
    Vertex_00017DF0 *copies;
    char unknown_0c[4];
    Box_00017CC0 box;
    unsigned int count;
};

struct Model_000178B0 {
    Pose_0005F060 *pose;
};

// A drawn mark (0x24 bytes).
struct Item_000162A0 {
    int mode;
    int flag;
    Mesh_00017F60 *mesh;
    int value;
    char unknown_10[0x14];
};

// The collision world (data_0022FCE8).
struct Object_00016200 {
    void func_00016240(Item_00016200 *item);
    void func_00016260(Item_00016260 *item, int value);
    void func_000162A0(Item_000162A0 *item);
    void func_000178B0(Model_000178B0 *model, Motion_0005F060 *motion, float time);
    Entry_000179B0 *func_000179B0(int key);
    void func_00017D90(Box_00017CC0 *box, const Vector3 *points, unsigned int count, float radius);
    void func_00017DF0(Box_00017CC0 *box, const Vertex_00017DF0 *vertices, unsigned int count);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_0021A81C;

// The four box points and their far ends, the two ends of the edge and the origin of the marks.
extern Vector3 data_0021A834[4];
extern Vector3 data_0021A864[4];
extern Vector3 data_0021A974;
extern Vector3 data_0021A980;
extern float data_0021A968[3];

struct Object_00047470 {
    void func_000480C0(unsigned int index);
};

struct Holder_000EDC30 {
    Object_00047470 *model;
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[8];
    int id;
    char unknown_0c[0x50];
    float speed;
    float climb;
};

// A 0x44-byte block of the four at 0x124: a link, a box and two counts.
struct Block_000EDC30 {
    Item_00016260 link;
    Box_00017CC0 box;
    char unknown_20[4];
    int value_24;
    char unknown_28[0xc];
    int value_34;
    char unknown_38[0xc];
};

// The class whose table is at 0x1CEFAC (constructor func_000EDC30).
struct Object_000EDC30 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    char unknown_008[0xd4];
    int mode;
    char unknown_0e0[0x14];
    Holder_000EDC30 *holder;
    char unknown_0f8[4];
    Motion_0005F060 *motion;
    char unknown_100[0x20];
    Model_000178B0 *model;
    Block_000EDC30 blocks[4];
    Item_000162A0 mark;
    Item_000162A0 marks[4];
    Vector3 points[4];
    Vector3 ends[4];
    Item_00016200 item;
    int key;

    void func_000EEED0();
};

// While the owner stands still, clears the counts of the four blocks at 0x124 and of the mark at 0x234; otherwise puts
// each block's box (radius 8) at its point (data_0021A834 through the current matrix, the far end from data_0021A864)
// and links it with the owner's id. Then poses the model at 0x120 (motion 0xfc, time 0), relinks the item at 0x348, and
// places the edge found by the key at 0x350 at joint 2 of the holder's model (data_0021A974, data_0021A980; copies and
// bounds). In modes 4 and 5 turns the four marks at 0x258 by -6 each from joint 2 at data_0021A968 (mesh
// data_0021A81C), drawing them in mode 5.
void Object_000EDC30::func_000EEED0()
{
    if (owner->speed == 0.0f && owner->climb == 0.0f) {
        for (int i = 0; i < 4; i++) {
            blocks[i].value_34 = 0;
            blocks[i].value_24 = 0;
        }
        mark.value = 0;
    } else {
        for (unsigned int i = 0; i < 4; i++) {
            func_001BAB20(&points[i], &data_0021A834[i]);
            func_001BAB20(&ends[i], &data_0021A864[i]);
            data_0022FCE8.func_00017D90(&blocks[i].box, &points[i], 1, 8.0f);
            data_0022FCE8.func_00016260(&blocks[i].link, owner->id);
        }
    }
    data_0022FCE8.func_000178B0(model, motion, 0.0f);
    data_0022FCE8.func_00016240(&item);
    Entry_000179B0 *entry = data_0022FCE8.func_000179B0(key);
    if (entry) {
        func_001BA9C0();
        holder->model->func_000480C0(2);
        func_001BAB20(&entry->vertices[0].position, &data_0021A974);
        func_001BAB20(&entry->vertices[1].position, &data_0021A980);
        entry->copies[0].position = entry->vertices[0].position;
        entry->copies[1].position = entry->vertices[1].position;
        data_0022FCE8.func_00017DF0(&entry->box, entry->vertices, entry->count);
        func_001BAA50();
    }
    if (mode == 5 || mode == 4) {
        func_001BA9C0();
        holder->model->func_000480C0(2);
        func_001BAAA0(data_0021A968);
        for (int i = 0; i < 4; i++) {
            func_001BB670(-6.0f);
            data_0022FCE8.func_00019570(marks[i].mesh, &data_0021A81C);
            if (mode == 5) {
                data_0022FCE8.func_000162A0(&marks[i]);
            }
        }
        func_001BAA50();
    }
}
