struct Object_00136270 {
    char unknown_00[0x44];
    unsigned long port;
    unsigned long slot;
    char drive;

    int func_00136580(unsigned long port, unsigned long slot, unsigned long *result);
};

unsigned long __stdcall func_001BE8ED(unsigned long first, unsigned long second);
unsigned long __stdcall func_001BE7DE(unsigned long first, unsigned long second, char *drive);

// Releases the drive it holds (func_001BE8ED) and takes the one func_001BE7DE gives for a port and slot. Stores
// the library's result; 1 when it got a drive, else 0.
int Object_00136270::func_00136580(unsigned long newPort, unsigned long newSlot, unsigned long *result)
{
    char newDrive;
    if (drive) {
        func_001BE8ED(port, slot);
        port = 0;
        slot = 0;
        drive = 0;
    }
    *result = func_001BE7DE(newPort, newSlot, &newDrive);
    if (*result) {
        return 0;
    }
    slot = newSlot;
    port = newPort;
    drive = newDrive;
    return 1;
}
