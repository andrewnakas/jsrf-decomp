void *__cdecl operator new(unsigned int size);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0xeb (table 0x1CD9E0): sets effects up in its 20 slots (func_000BAC60) and plays them (func_000BADB0, under
// another name).
struct Object_000BAC20 {
    int func_000BAC60(int value, int extra);
};

struct Object_000BADB0 {
    int func_000BADB0(int handle, int first, int second, int third, int fourth);
};

// An effect set up on object 0xeb (0x10 bytes): its handle, its id and the links of the list at +0x240.
struct Effect_000540B0 {
    int handle;
    int id;
    Effect_000540B0 *next;
    Effect_000540B0 **link;
};

struct Object_0004ABA0 {
    char unknown_000[0x240];
    Effect_000540B0 *effects;
    Effect_000540B0 **tail;

    void func_000540B0(int id, int first, int second, int third, int fourth);
};

// With object 0xeb there: finds the effect with the id in the list at +0x240, setting it up first (func_000BAC60,
// appended to the list) when there is none, and plays it with the four values (func_000BADB0).
void Object_0004ABA0::func_000540B0(int id, int first, int second, int third, int fourth)
{
    Object_000BADB0 *player = (Object_000BADB0 *)data_0022FCE0->func_000128C0(0xeb);
    if (player) {
        Effect_000540B0 *effect;
        for (effect = effects; effect; effect = effect->next) {
            if (effect->id == id) {
                break;
            }
        }
        if (!effect) {
            effect = new Effect_000540B0;
            effect->handle = ((Object_000BAC20 *)player)->func_000BAC60(id, 0);
            effect->id = id;
            effect->next = 0;
            *tail = effect;
            effect->link = tail;
            tail = &effect->next;
        }
        player->func_000BADB0(effect->handle, first, second, third, fourth);
    }
}
