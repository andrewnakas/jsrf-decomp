struct Object_000C1270 {
    void func_000C1270(int id, void *position);
};

// The owner at 0x4 of the Object_000CC600 family.
struct Object_000C5B50 {
    void func_000C5B40(int id, void *position);
};

extern Object_000C1270 *data_00257CE4;

// Forwards to the object in data_00257CE4; the callers (func_000C87D0, func_000D7950) pass an id and the
// address of a position.
void Object_000C5B50::func_000C5B40(int id, void *position)
{
    data_00257CE4->func_000C1270(id, position);
}
