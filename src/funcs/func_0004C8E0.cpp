struct Command_000585E0 {
    char unknown_00[0x14];
    int arguments[1];
};

struct Object_000585E0 {
    void func_0004C8E0(Command_000585E0 *command);
};

void func_001072B0(void *arguments, int on);

// Called by func_000585E0 on its own object (0x5afc5 and after): passes the command's arguments and 1 to func_001072B0.
void Object_000585E0::func_0004C8E0(Command_000585E0 *command)
{
    func_001072B0(command->arguments, 1);
}
