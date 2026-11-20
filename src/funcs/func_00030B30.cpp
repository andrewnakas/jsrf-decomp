/* sym: ??1Thing_00030B30@@QAE@XZ = 0x00011C90 */
int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_00042CC0 {
    void func_00042E40();
};

extern Object_00042CC0 data_001F90C0;

// Something a scene keeps (its destructor does nothing).
struct Thing_00030B30 {
    ~Thing_00030B30();
};

// A loaded scene of the list at +0x1ac: its key, its place in the list, and two tables of `count` blocks and things.
struct Scene_00030B30 {
    int key;
    Scene_00030B30 **link;
    Scene_00030B30 *next;
    void **blocks;
    Thing_00030B30 **things;
    unsigned int count;
};

struct Object_000265A0 {
    char unknown_0000[0x1ac];
    Scene_00030B30 *scenes;
    Scene_00030B30 **tail;
    Scene_00030B30 *current;
    char unknown_1b8[8];
    void *buffer;

    void func_00030B30(int key);
};

// Handler 29 of the table at 0x1EC288: runs func_00042E40 of 0x1F90C0; deletes the scene at +0x1b4 (its blocks and
// things and both tables) and frees the buffer at +0x1c0; then takes the scene with `key` out of the list at +0x1ac
// (tail link at +0x1b0) and deletes it the same way.
void Object_000265A0::func_00030B30(int key)
{
    data_001F90C0.func_00042E40();
    if (current) {
        unsigned int i;
        if (current->blocks) {
            for (i = 0; i < current->count; i++) {
                if (current->blocks[i])
                    delete current->blocks[i];
            }
            delete current->blocks;
        }
        if (current->things) {
            for (i = 0; i < current->count; i++) {
                if (current->things[i])
                    delete current->things[i];
            }
            delete current->things;
        }
        if (buffer) {
            func_00145A5D(buffer, 0, 0x8000);
            buffer = 0;
        }
        delete current;
        current = 0;
    }
    for (Scene_00030B30 *scene = scenes; scene; scene = scene->next) {
        if (scene->key == key) {
            unsigned int j;
            if (scene->blocks) {
                for (j = 0; j < scene->count; j++) {
                    if (scene->blocks[j])
                        delete scene->blocks[j];
                }
                delete scene->blocks;
            }
            if (scene->things) {
                for (j = 0; j < scene->count; j++) {
                    if (scene->things[j])
                        delete scene->things[j];
                }
                delete scene->things;
            }
            *scene->link = scene->next;
            if (scene->next)
                scene->next->link = scene->link;
            else
                tail = scene->link;
            delete scene;
            return;
        }
    }
}
