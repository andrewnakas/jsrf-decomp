struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_00106BD0(unsigned int id, unsigned int flags, int value);
void func_001070A0(unsigned int id, int value, int second, int third);

struct Owner_0007FD20 {
    char unknown_000[0x23c];
    unsigned int sound;
};

struct Object_000A1C50 {
    char unknown_000[0x454];
    int stopSound;
    int unknown_458;
    int playSound;
    int soundValue;
    char unknown_464[0x834];
    int owner;

    void func_0007FD20();
};

// Handles the two sound requests of the player against its owner's sound (func_00106BD0 to stop it,
// func_001070A0 to start one).
void Object_000A1C50::func_0007FD20()
{
    Owner_0007FD20 *owner = (Owner_0007FD20 *)data_0022FCE0->func_000128C0(this->owner);
    if (stopSound) {
        if (owner) {
            func_00106BD0(owner->sound, 0x1000000, 0);
        }
        stopSound = 0;
    }
    if (playSound) {
        playSound = 0;
        if (owner) {
            func_001070A0(owner->sound, soundValue, 0, 3);
        }
    }
}
