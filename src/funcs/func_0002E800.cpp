/* sym: ??0Object_00047470@@QAE@XZ = 0x00048100 */
struct Frame_000479D0;

struct Device_00251D6C;
struct Interface_00251D74;

extern Device_00251D6C *data_00251D6C;
extern Interface_00251D74 *data_00251D74;

struct Header_0006E970;
struct Entry_0006E970;

void __stdcall func_0006E970(Header_0006E970 *header, Entry_0006E970 *entry);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The model base class (table 0x1CAA8C, 0x74 bytes); slot 1 builds it from model data, slot 2 sets flag 0x10 first.
struct Object_00047470 {
    Object_00047470();
    virtual ~Object_00047470();
    virtual void func_00048190(void *first, void *second, Frame_000479D0 *frame);
    virtual void func_00047470(void *first, void *second, Frame_000479D0 *frame);

    char unknown_04[0x20];
    unsigned int flags;
    char unknown_28[0x10];
    float unknown_38;
    float unknown_3c;
    char unknown_40[0x20];
    void *unknown_60;
    char unknown_64[0x10];
};

// One entry of a model pack: where its chunk is, where the next entry is, and the chunk's size.
struct Entry_0002E800 {
    int offset;
    int next;
    unsigned int size;
};

// A model pack as loaded: how many entries, then the first entry at +0x10.
struct Pack_0002E800 {
    int unknown_00;
    unsigned int count;
    char unknown_08[8];
    Entry_0002E800 first;
};

// Object 0x1de2: a value per model at +0x1140, the models at +0x1708 and a second model per entry at +0x1cd0.
struct Scene_00121880 {
    char unknown_0000[0x1140];
    void *items[0x172];
    Object_00047470 *models[0x172];
    Object_00047470 *shadows[0x172];
};

struct Object_000265A0 {
    void func_0002E800(Pack_0002E800 *pack);
};

// Makes two models for every non-empty entry of the pack in object 0x1de2: one built by slot 2 (flag 0x10, +0x38 =
// 0.04, +0x3c = 0.08, its value from +0x1140, flag 1 cleared afterwards) at +0x1708 and one built by slot 1 (flag
// 0x40) at +0x1cd0; empty entries clear the first. Does not use `this`.
void Object_000265A0::func_0002E800(Pack_0002E800 *pack)
{
    Scene_00121880 *scene = (Scene_00121880 *)data_0022FCE0->func_000128C0(0x1de2);
    Entry_0002E800 *entry = &pack->first;
    for (unsigned int i = 0; i < pack->count; i++) {
        Entry_0002E800 *current = entry;
        entry = (Entry_0002E800 *)((char *)pack + current->next);
        if (current->size > 0) {
            char *data = (char *)pack + current->offset + 0x10;
            char *chunk = (char *)pack + current->offset;
            func_0006E970((Header_0006E970 *)chunk, (Entry_0006E970 *)data);
            scene->models[i] = new Object_00047470;
            scene->models[i]->flags &= ~0x10;
            scene->models[i]->flags |= 0x10;
            scene->models[i]->unknown_38 = 0.04f;
            scene->models[i]->unknown_3c = 0.08f;
            scene->models[i]->func_00047470(data_00251D6C, data_00251D74, (Frame_000479D0 *)data);
            scene->shadows[i] = new Object_00047470;
            scene->shadows[i]->flags &= ~0x40;
            scene->shadows[i]->flags |= 0x40;
            scene->shadows[i]->func_00048190(data_00251D6C, data_00251D74, (Frame_000479D0 *)data);
            scene->models[i]->unknown_60 = scene->items[i];
            scene->models[i]->flags &= ~1;
        } else {
            scene->models[i] = 0;
        }
    }
}
