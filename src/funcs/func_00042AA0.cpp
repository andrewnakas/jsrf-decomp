/* sym: ??0Object_00042A30@@QAE@PAUNode@@HII@Z = 0x00042970 */
struct Node;

// The node class whose table is at 0x1CA630 (destructor 0x42A30; 0xa8 bytes).
struct Object_00042A30 {
    Object_00042A30(Node *owner, int id, unsigned int flags, unsigned int index);

    char unknown_00[0xa8];
};

// Called by the player (0x8E5A0): creates an Object_00042A30 under `owner` with no id, flags 1 and the index.
void func_00042AA0(Node *owner, unsigned int index)
{
    new Object_00042A30(owner, -1, 1, index);
}
