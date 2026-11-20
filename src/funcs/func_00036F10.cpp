void __cdecl operator delete(void *memory) throw();

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0006E130 {
    void func_0006E7B0(int id);
};

extern Object_0006E130 data_00252790;

// One of the 25 entries at 0x230DD0: two textures, the loaded file at +8, set up at +0xc.
struct Entry_00230DD0 {
    int textures[2];
    char *file;
    int busy;
};

struct Owner_00036B50;

struct Entry_00230F60 {
    Owner_00036B50 *pointer;
    unsigned int count;
};

extern int *data_001EEAF0[];
extern Entry_00230F60 data_00230F60[];
extern Entry_00230DD0 data_00230DD0[];

struct Object_00047470 {
    virtual ~Object_00047470();
};

// A block of 0x66c bytes, chained through its last word: its texture at +0x658, its model at +0x65c.
struct Owner_00036B50 {
    char unknown_000[0x658];
    int texture;
    Object_00047470 *model;
    char unknown_660[8];
    Owner_00036B50 *next;
};

// One of the 133 records at 0x1FA1E8 (0x28 bytes): two ids and the owners found for each.
struct Record_001FA1E8 {
    int first;
    int second;
    Owner_00036B50 *firstOwners;
    Owner_00036B50 *secondOwners;
    char unknown_10[0x18];
};

extern Record_001FA1E8 data_001FA1E8[133];

// Object 0xe8.
struct Object_000607B0 {
    char unknown_00[0x4c];
    int unknown_4c;
};

int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);
void func_00060C60(int key);

// Undoes func_00036C20 for loaded file `index`, if it is set up: each id of the index's list at 0x1EEAF0 loses one
// count at 0x230F60, and the last one deletes its owners (model, texture, the block itself) and clears the records
// at 0x1FA1E8 that name the id (func_00060C60 for the first). Then the file is freed, both textures released, the
// entry marked not set up and object 0xe8 told (+0x4c = 1).
void func_00036F10(int index)
{
    if (data_00230DD0[index].busy) {
        int id;
        for (int n = 0; (id = data_001EEAF0[index][n]) >= 0; n++) {
            if (data_00230F60[id].count > 0) {
                if (--data_00230F60[id].count <= 0) {
                    Owner_00036B50 *owner = data_00230F60[id].pointer;
                    if (owner) {
                        do {
                            delete owner->model;
                            data_00252790.func_0006E7B0(owner->texture);
                            Owner_00036B50 *next = owner->next;
                            operator delete(owner);
                            owner = next;
                        } while (owner);
                        data_00230F60[data_001EEAF0[index][n]].pointer = 0;
                    }
                    for (unsigned int r = 0; r < 133; r++) {
                        if (data_001FA1E8[r].first == id) {
                            func_00060C60(r);
                            data_001FA1E8[r].firstOwners = 0;
                        }
                        if (data_001FA1E8[r].second == id)
                            data_001FA1E8[r].secondOwners = 0;
                    }
                }
            }
        }
        if (data_00230DD0[index].file) {
            func_00145A5D(data_00230DD0[index].file, 0, 0x8000);
            data_00230DD0[index].file = 0;
        }
        for (int k = 0; k < 2; k++) {
            if (data_00230DD0[index].textures[k]) {
                data_00252790.func_0006E7B0(data_00230DD0[index].textures[k]);
                data_00230DD0[index].textures[k] = 0;
            }
        }
        data_00230DD0[index].busy = 0;
        Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (object)
            object->unknown_4c = 1;
    }
}
