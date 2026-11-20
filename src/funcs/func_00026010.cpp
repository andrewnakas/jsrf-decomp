/* sym: ??0Object_000265A0@@QAE@PAUNode@@HI@Z = 0x000257D0 */
struct Node;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 7 (0x1920 bytes).
struct Object_000265A0 {
    Object_000265A0(Node *owner, int id, unsigned int flags);

    char unknown_0000[0x1920];
};

// Called by func_00012AE0: creates object 7 under `owner` (id 7, flags 0) unless it exists.
void func_00026010(Node *owner)
{
    if (!data_0022FCE0->func_000128C0(7))
        new Object_000265A0(owner, 7, 0);
}
