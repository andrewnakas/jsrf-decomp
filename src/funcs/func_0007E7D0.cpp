/* sym: ??0Object_0007E2F0@@QAE@PAUNode@@HI@Z = 0x0007E6A0 */

struct Node;

// The class whose table is at 0x1CCFB8 (constructor 0x7E6A0, destructor 0x7E2F0; 0xbc bytes).
struct Object_0007E2F0 {
    Object_0007E2F0(Node *owner, int id, unsigned int flags);

    char unknown_000[0xbc];
};

// Creates object 0x1dda (flags 9) of the class at 0x1CCFB8 under an owner.
void func_0007E7D0(Node *owner)
{
    new Object_0007E2F0(owner, 0x1dda, 9);
}
