struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0x50 (constructor 0x85280, destructor 0x85410).
struct Object_00086060 {
    void func_000851E0(int id, const Vector3 *position);
};

struct Record_00014AA0 {
    char unknown_00[0x44];
    int value_44;
    char unknown_48[4];
    int value_4c;
};

// A player's object (id + 0xc) and its owner: the owner's id at 0x8d4, the owner's team at 0xca0.
struct Player_00014AA0 {
    char unknown_000[8];
    int value_008;
    char unknown_00c[0x8c8];
    int ownerId;
    char unknown_8d8[0x3c4];
    int id;
    int team;
    char unknown_ca4[0x378];
    Record_00014AA0 *record;
};

struct Entry_00014AA0 {
    int found;
    int id;
};

// The object at data_001EB938.
struct Object_00014A80 {
    char unknown_00[8];
    int type;
    Vector3 position;
    char unknown_18[4];
    int first;
    int second;
    Entry_00014AA0 entries[4];
    int count;
    int value_48;
    int value_4c;
    int value_50;
    int current;
    int total;

    int func_00014AA0(int index, int value);
};

// Unless the type is already 2: sets type 2 and `index` at +0x1c. With the same team as before, hands the owner of
// `index` and the position to object 0x50. Otherwise keeps the new team at +0x20 and lists the owners of the four
// players on that team (whether each is `index`, and its id); for `index` it copies the record's values and tells
// object 0x50, for the others it keeps the record's +0x4c at +0x4c. Returns 1, or 0 when the type was 2.
int Object_00014A80::func_00014AA0(int index, int value)
{
    if (type == 2)
        return 0;
    type = 2;
    first = index;
    if (second == value) {
        Player_00014AA0 *player = (Player_00014AA0 *)data_0022FCE0->func_000128C0(index + 0xc);
        if (player) {
            Player_00014AA0 *owner = (Player_00014AA0 *)data_0022FCE0->func_000128C0(player->ownerId);
            if (owner) {
                Object_00086060 *object = (Object_00086060 *)data_0022FCE0->func_000128C0(0x50);
                if (object)
                    object->func_000851E0(owner->value_008, &position);
            }
        }
        return 1;
    }
    second = value;
    count = 0;
    for (unsigned int i = 0; i < 4; i++) {
        Player_00014AA0 *player = (Player_00014AA0 *)data_0022FCE0->func_000128C0(i + 0xc);
        if (!player)
            continue;
        Player_00014AA0 *owner = (Player_00014AA0 *)data_0022FCE0->func_000128C0(player->ownerId);
        if (!owner || owner->team != second)
            continue;
        if (owner->id == first) {
            entries[count].found = 1;
            entries[count].id = owner->id;
            value_48 = owner->record->value_4c;
            value_50 = owner->record->value_44;
            current = owner->record->value_44;
            total = 0;
            Object_00086060 *object = (Object_00086060 *)data_0022FCE0->func_000128C0(0x50);
            if (object)
                object->func_000851E0(owner->value_008, &position);
        } else {
            value_4c = owner->record->value_4c;
            entries[count].found = 0;
            entries[count].id = owner->id;
        }
        count++;
    }
    return 1;
}
