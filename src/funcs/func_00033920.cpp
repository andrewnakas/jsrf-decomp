extern "C" void *memcpy(void *destination, const void *source, unsigned int size);
/* sym: ??0Object_00047470@@QAE@XZ = 0x00048100 */
struct Device_00251D6C;
struct Interface_00251D74;

extern Device_00251D6C *data_00251D6C;
extern Interface_00251D74 *data_00251D74;

struct Header_0006E970;
struct Entry_0006E970;

void __stdcall func_0006E970(Header_0006E970 *header, Entry_0006E970 *entry);

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

struct Header_0006EA40;

void __stdcall func_0006EA40(Header_0006EA40 *header);

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x17f4];
    Object_00047470 *models[3];
    char *buffer;

    void func_00033920(void *data);
};

// Sets up a loaded pack: entries 0 to 2 become models (Object_00047470, built by its slot 1 with the device; flag
// 0x40 set, flags 1 and 8 cleared) at +0x17f4, entry 3 is copied into a buffer of its own at +0x1800 and handed to
// func_0006EA40; empty entries clear their slot.
void Object_000265A0::func_00033920(void *data)
{
    Pack_0002E350 *pack = (Pack_0002E350 *)data;
    Entry_0002E350 *entry = &pack->first;
    for (unsigned int i = 0; i < pack->count; i++) {
        Entry_0002E350 *current = entry;
        entry = (Entry_0002E350 *)((char *)pack + current->next);
        switch (i) {
        case 0:
        case 1:
        case 2:
            if (current->size > 0) {
                char *model = (char *)pack + current->offset + 0x10;
                char *chunk = (char *)pack + current->offset;
                func_0006E970((Header_0006E970 *)chunk, (Entry_0006E970 *)model);
                models[i] = new Object_00047470;
                models[i]->flags &= ~0x40;
                models[i]->flags |= 0x40;
                models[i]->func_00048190(data_00251D6C, data_00251D74, model);
                models[i]->flags &= ~1;
                models[i]->flags &= ~8;
            } else {
                models[i] = 0;
            }
            break;
        case 3: {
            unsigned int size = current->size;
            if (size > 0) {
                buffer = (char *)operator new(size);
                memcpy(buffer, (char *)pack + current->offset, size);
                func_0006EA40((Header_0006EA40 *)buffer);
            } else {
                buffer = 0;
            }
            break;
        }
        }
    }
}
