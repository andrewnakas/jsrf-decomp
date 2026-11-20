struct State_0003B680 {
    int words[0xd42];
};

struct Object_00039BE0 {
    int unknown_0000;
    State_0003B680 current;
    State_0003B680 saved;

    void func_0003B680();
};

// Saves a copy of the state at +0x4 (0x3508 bytes) at +0x350c.
void Object_00039BE0::func_0003B680()
{
    saved = current;
}
