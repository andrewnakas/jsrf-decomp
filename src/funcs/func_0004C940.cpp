struct Command_000585E0 {
    char unknown_00[0x14];
    int arguments[1];
};

struct Object_000585E0 {
    void func_0004C940(Command_000585E0 *command);
};

void func_00107340(void *arguments, int on);

// Called by func_000585E0 on its own object (0x5afc5 and after): passes the command's arguments and 0 to func_00107340.
void Object_000585E0::func_0004C940(Command_000585E0 *command)
{
    func_00107340(command->arguments, 0);
}
