/* sym: ??0Object_000E34F0@@QAE@PAUNode@@HI@Z = 0x000E34F0 */
struct Node;
struct Params_000E34F0;

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// The Node child func_000E34F0 builds (0x60 bytes).
struct Object_000E34F0 {
    Object_000E34F0(Node *owner, int id, unsigned int flags);
    virtual ~Object_000E34F0();

    char unknown_04[0x5c];
};

// One of the factories of the table at 0x215D68: builds an Object_000E34F0 under the object with the first free id
// in [0x12B2, 0x13B2] and the flags 8; the description is not used.
void func_000E3690(Node *owner, Params_000E34F0 *params)
{
    new Object_000E34F0(owner, data_0022FCE0->func_000128E0(0x12b2, 0x13b2), 8);
}
