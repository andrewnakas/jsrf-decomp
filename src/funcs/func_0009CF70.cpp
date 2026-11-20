void func_0005DAA0(void *pointer);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x9a0];
    void *motions[8];
    char unknown_9c0[0x4bc];
    void *motion_e7c;

    void func_0009CF70();
};

// Frees the motion at 0xe7c and the eight at 0x9a0 (func_0005DAA0).
void Object_000A1C50::func_0009CF70()
{
    func_0005DAA0(motion_e7c);
    func_0005DAA0(motions[0]);
    func_0005DAA0(motions[1]);
    func_0005DAA0(motions[2]);
    func_0005DAA0(motions[3]);
    func_0005DAA0(motions[4]);
    func_0005DAA0(motions[5]);
    func_0005DAA0(motions[6]);
    func_0005DAA0(motions[7]);
}
