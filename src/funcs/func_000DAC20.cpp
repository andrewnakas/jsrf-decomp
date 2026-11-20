/* sym: ??0Object_000DAB10@@QAE@PAUNode@@HIPAUParams_000DAB10@@@Z = 0x000DAB10 */
struct Node;
struct Params_000DAB10;

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// The Node child func_000DAB10 builds (0x48 bytes).
struct Object_000DAB10 {
    Object_000DAB10(Node *owner, int id, unsigned int flags, Params_000DAB10 *params);
    virtual ~Object_000DAB10();

    char unknown_04[0x44];
};

// One of the factories of the table at 0x215D68: builds an Object_000DAB10 under the object with the first free id
// in [0x12B2, 0x13B2], no flags, and the description.
void func_000DAC20(Node *owner, Params_000DAB10 *params)
{
    new Object_000DAB10(owner, data_0022FCE0->func_000128E0(0x12b2, 0x13b2), 0, params);
}
