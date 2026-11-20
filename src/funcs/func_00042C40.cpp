/* sym: ??0Object_00042820@@QAE@PAUNode@@HIPAX@Z = 0x00042B00 */
struct Node;

// The node class whose table is at 0x1CA5F0 (destructor 0x42820; 0xd8 bytes).
struct Object_00042820 {
    Object_00042820(Node *owner, int id, unsigned int flags, void *data);

    char unknown_00[0xd8];
};

// Called by 0x585E0: creates an Object_00042820 under `owner` with no id, flags 1 and the data.
void func_00042C40(Node *owner, void *data)
{
    new Object_00042820(owner, -1, 1, data);
}
