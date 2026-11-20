/* sym: ??0Object_0001E140@@QAE@PAUNode@@HIPAX@Z = 0x0001E280 */
struct Node;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The class whose table is at 0x1C45C8 (destructor 0x1E140; 0xd8 bytes).
struct Object_0001E140 {
    Object_0001E140(Node *owner, int id, unsigned int flags, void *data);

    char unknown_000[0xd8];
};

// Creates object 0x1DDF (the class at 0x1C45C8) under an owner with its data and returns its id.
int func_0001E460(void *owner, void *data)
{
    data_0022FCE0->func_000128C0(0x1ddf);
    new Object_0001E140((Node *)owner, 0x1ddf, 1, data);
    return 0x1ddf;
}
