/* sym: ??0Object_00047470@@QAE@XZ = 0x00048100 */
struct Device_00251D6C;
struct Interface_00251D74;

extern Device_00251D6C *data_00251D6C;
extern Interface_00251D74 *data_00251D74;

struct Frame_000479D0;
struct Header_0006E970;
struct Entry_0006E970;

void __stdcall func_0006E970(Header_0006E970 *header, Entry_0006E970 *entry);

struct Object_0006E130 {
    int func_0006E1C0(void *data);
};

extern Object_0006E130 data_00252790;

// The model base class (table 0x1CAA8C, 0x74 bytes); slot 1 builds it from model data.
struct Object_00047470 {
    Object_00047470();
    virtual ~Object_00047470();
    virtual void func_00048190(void *first, void *second, Frame_000479D0 *frame);

    char unknown_04[0x20];
    unsigned int flags;
    char unknown_28[0x4c];
};

// One entry of a pack: where its data is, where the next entry is, and the data's size.
struct Entry_00039070 {
    unsigned int data;
    unsigned int next;
    unsigned int size;
};

// A pack as loaded: how many entries, then the first entry at +0x10.
struct Pack_00039070 {
    int unknown_00;
    unsigned int count;
    char unknown_08[8];
    Entry_00039070 first;
};

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x174c];
    Object_00047470 **models;
    unsigned int modelCount;
    char unknown_1754[8];
    int *textures;
    unsigned int textureCount;

    void func_00039070(void *data);
};

// Called by func_00039410: loads the two packs of the loaded data: every texture of the first (data_00252790's
// func_0006E1C0, -1 for an empty entry) into the list at +0x175c, and a model (Object_00047470, built by its slot 1
// with the device, flag 0x40 set and flags 1 and 8 cleared) for every entry of the second into the list at +0x174c.
void Object_000265A0::func_00039070(void *data)
{
    Pack_00039070 *pack = (Pack_00039070 *)data;
    Entry_00039070 *item = (Entry_00039070 *)((char *)pack + pack->first.data);
    Pack_00039070 *textureData = (Pack_00039070 *)item;
    item = (Entry_00039070 *)((char *)item + 0x10);
    Entry_00039070 *second = (Entry_00039070 *)((char *)pack + pack->first.next);
    unsigned int i;
    textureCount = textureData->count;
    if (textureCount > 0) {
        textures = (int *)operator new(textureCount * 4);
        for (i = 0; i < textureCount; i++) {
            if (item->size > 0)
                textures[i] = data_00252790.func_0006E1C0((char *)textureData + item->data);
            else
                textures[i] = -1;
            item = (Entry_00039070 *)((char *)textureData + item->next);
        }
    } else {
        textures = 0;
    }
    item = (Entry_00039070 *)((char *)pack + second->data);
    Pack_00039070 *modelData = (Pack_00039070 *)item;
    item = (Entry_00039070 *)((char *)item + 0x10);
    modelCount = modelData->count;
    if (modelCount > 0) {
        models = (Object_00047470 **)operator new(modelCount * 4);
        for (i = 0; i < modelCount; i++) {
            if (item->size > 0) {
                char *model = (char *)modelData + item->data + 0x10;
                char *chunk = (char *)modelData + item->data;
                func_0006E970((Header_0006E970 *)chunk, (Entry_0006E970 *)model);
                models[i] = new Object_00047470;
                models[i]->flags &= ~0x40;
                models[i]->flags |= 0x40;
                models[i]->func_00048190(data_00251D6C, data_00251D74, (Frame_000479D0 *)model);
                models[i]->flags &= ~1;
                models[i]->flags &= ~8;
            } else {
                models[i] = 0;
            }
            item = (Entry_00039070 *)((char *)modelData + item->next);
        }
    } else {
        models = 0;
    }
}
