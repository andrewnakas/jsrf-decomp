/* const: 0x200000 */
// The part a mesh copy points to first.
struct Part_000DDE20 {
    char unknown_00[0x1c];
    int count;
    char unknown_20[0x20];
    int count_40;
};

struct Mesh_00017F60 {
    Part_000DDE20 *part;
};

// The item at 0x2a0 (kind, count, mesh, flag).
struct Item_000162A0 {
    int kind;
    int count;
    Mesh_00017F60 *mesh;
    int shown;
};

struct Object_00016200 {
    void func_000162A0(Item_000162A0 *item);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_002179F8;

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x5c];
    float speed;
    char unknown_60[0x44];
    unsigned int flags;
};

// The class whose tables are at 0x217A20 and 0x217AB8 (constructor func_000DCBC0).
struct Object_000DCBC0 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    char unknown_008[0x298];
    Item_000162A0 item;

    void func_000DDE20();
};

// Hides the item at 0x2a0 while the owner has the flag 0x100, or when it stands still with 0x200000 but not
// 0x8000000; else places its mesh from data_002179F8 and draws it, as kind 4 with two of each part count while the
// owner moves with 0x200000, else as kind 2 with one. Called by func_000DE8A0.
void Object_000DCBC0::func_000DDE20()
{
    if (owner->flags & 0x100) {
        item.shown = 0;
    } else {
        data_0022FCE8.func_00019570(item.mesh, &data_002179F8);
        if (!(owner->flags & 0x8000000) && (owner->flags & 0x200000) && owner->speed == 0.0f) {
            item.shown = 0;
        } else {
            if ((owner->flags & 0x200000) && owner->speed != 0.0f) {
                item.kind = 4;
                item.mesh->part->count = 2;
                item.mesh->part->count_40 = 2;
            } else {
                item.kind = 2;
                item.mesh->part->count = 1;
                item.mesh->part->count_40 = 1;
            }
            data_0022FCE8.func_000162A0(&item);
        }
    }
}
