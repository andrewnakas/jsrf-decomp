/* sym: ??0Object_00047470@@QAE@XZ = 0x00048100 */
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

// The model base class (table 0x1CAA8C, 0x74 bytes); slot 1 builds it from model data.
struct Object_00047470 {
    Object_00047470();
    virtual ~Object_00047470();
    virtual void func_00048190(Device_00251D6C *device, Interface_00251D74 *direct3d, void *data);

    char unknown_04[0x20];
    unsigned int flags;
    char unknown_28[0x30];
    float unknown_58;
    char unknown_5c[4];
    int unknown_60;
    char unknown_64[0x10];
};

// A chunk of a model pack: a header and the model data.
struct Chunk_0002E350 {
    char header[0x10];
    char data[4];
};

// One entry of a model pack: where its chunk is, where the next entry is, and the chunk's size.
struct Entry_0002E350 {
    int offset;
    int next;
    unsigned int size;
};

// A model pack as loaded: how many entries, then the first entry at +0x10.
struct Pack_0002E350 {
    int unknown_00;
    unsigned int count;
    char unknown_08[8];
    Entry_0002E350 first;
};

// Object 0x1de2: a value per model at +0x2a54 and the models at +0x2c78.
struct Object_00126AC0 {
    char unknown_0000[0x2a54];
    int values[0x89];
    Object_00047470 *models[0x80];
};

struct Object_000265A0 {
    void func_0002E1C0(Pack_0002E350 *pack);
};

// Makes a model (Object_00047470, built by its slot 1 with the device) for every non-empty entry of the pack, in the
// second set of model slots of object 0x1de2 (+0x2c78; empty entries clear theirs); every model but 0, 2 to 6 and
// 0x19 to 0x34 gets flag 0x40 and +0x58 = 1.0. Each model takes its value from +0x2a54. Does not use `this`.
void Object_000265A0::func_0002E1C0(Pack_0002E350 *pack)
{
    Object_00126AC0 *stage = (Object_00126AC0 *)data_0022FCE0->func_000128C0(0x1de2);
    Entry_0002E350 *entry = &pack->first;
    for (unsigned int i = 0; i < pack->count; i++) {
        Entry_0002E350 *current = entry;
        entry = (Entry_0002E350 *)((char *)pack + current->next);
        if (current->size > 0) {
            char *data = (char *)pack + current->offset + 0x10;
            char *chunk = (char *)pack + current->offset;
            func_0006E970((Header_0006E970 *)chunk, (Entry_0006E970 *)data);
            stage->models[i] = new Object_00047470;
            if (i != 0 && i != 2 && i != 3 && i != 4 && i != 5 && i != 6 && (i < 0x19 || i > 0x34)) {
                stage->models[i]->flags &= ~0x40;
                stage->models[i]->flags |= 0x40;
                stage->models[i]->unknown_58 = 1.0f;
            }
            stage->models[i]->func_00048190(data_00251D6C, data_00251D74, data);
            stage->models[i]->unknown_60 = stage->values[i];
        } else {
            stage->models[i] = 0;
        }
    }
}
