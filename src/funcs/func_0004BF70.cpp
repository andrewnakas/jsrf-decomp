struct Vector3 {
    float x;
    float y;
    float z;
};

void func_00060C90();
void func_00106F10(unsigned int id, int value);

struct Game {
    void func_000127C0(int index, int value);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A start record (0x34 bytes): its kind, a place and a direction.
struct Record_0004BF70 {
    int kind;
    int unknown_04[2];
    Vector3 position;
    Vector3 direction;
    char unknown_24[0x10];
};

// Object 11: the start record at +0x544.
struct Object_0004BF70 {
    char unknown_000[0x544];
    Record_0004BF70 record;
};

// One start point of the course (0x2c bytes).
struct Start_0004BF70 {
    char unknown_00[8];
    Vector3 position;
    Vector3 direction;
    char unknown_20[0xc];
};

// The course: its start points at +0x3c.
struct Course_0004BF70 {
    char unknown_00[0x3c];
    Start_0004BF70 *starts;
};

// What +0xfb8 points at: the start point to use (+0x14) and a value for func_00106F10 (+0x18).
struct Setup_0004BF70 {
    char unknown_00[0x14];
    int start;
    int value;
};

// Object 12: the ids of the player (+0x8d4) and of another object (+0x8d8).
struct Object_0004C000 {
    char unknown_000[0x8d4];
    int player;
    int other;
};

// The player: a value at +0xfd0.
struct Player_0004BF70 {
    char unknown_000[0xfd0];
    int unknown_fd0;
};

// What the id at +0x8d8 of object 12 names: an id at +0x23c.
struct Other_0004BF70 {
    char unknown_000[0x23c];
    unsigned int id;
};

// Object 9 (the stage).
struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;
    char unknown_0060[0x8d8];
    Record_0004BF70 record;
    char unknown_096c[0x64c];
    Setup_0004BF70 *setup;
    char unknown_0fbc[0x84];
    Course_0004BF70 *course;
    char unknown_1044[4];
    int unknown_1048;

    void func_0004BF70();
};

// State handler 90 (table at 0x1F9888): copies object 11's start record (placed at the chosen start point of the
// course, kind 10, when there is one) and passes it to func_000127C0 (0x6d), clears 0x8d, hands +0x1048 to the
// player and +0x18 of the setup to func_00106F10 with object 12's other object, runs func_00060C90 and goes to state
// 0x5b.
void Object_0004ABA0::func_0004BF70()
{
    int start = setup->start;
    Object_0004BF70 *object = (Object_0004BF70 *)data_0022FCE0->func_000128C0(11);
    Record_0004BF70 *record = &this->record;
    *record = object->record;
    if (start >= 0) {
        Start_0004BF70 *point = &course->starts[start];
        record->kind = 10;
        record->position.x = point->position.x;
        record->position.y = point->position.y;
        record->position.z = point->position.z;
        record->direction.x = point->direction.x;
        record->direction.y = point->direction.y;
        record->direction.z = point->direction.z;
    }
    data_0022FCE0->func_000127C0(0x6d, (int)record);
    data_0022FCE0->func_000127C0(0x8d, 0);
    Object_0004C000 *owner = (Object_0004C000 *)data_0022FCE0->func_000128C0(12);
    if (owner) {
        Player_0004BF70 *player = (Player_0004BF70 *)data_0022FCE0->func_000128C0(owner->player);
        if (player) {
            player->unknown_fd0 = unknown_1048;
        }
        Other_0004BF70 *other = (Other_0004BF70 *)data_0022FCE0->func_000128C0(owner->other);
        if (other) {
            func_00106F10(other->id, setup->value);
        }
    }
    func_00060C90();
    state = 0x5b;
}
