struct Object_00116A10 {
    char unknown_000[0x9c];
    int track;
    char unknown_0a0[0x68];
    int alternate;

    void func_00116170(int track);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Before a new track starts on object 5: flips the alternate flag at +0x108 when a track from 30 to 59 follows
// one outside that range (other than -1, 0, 20 and 21), and for track 26; sets it after track 67 for a track from
// 30 to 59; clears it for tracks 20, 21 and 0. Reads object 5 itself, never this (0x1173b0 loads ecx).
void Object_00116A10::func_00116170(int next)
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (object) {
        int current = object->track;
        if (current != -1 && current != 0 && current != 20 && current != 21 && (current < 30 || current >= 60)) {
            if (next >= 30 && next < 60) {
                object->alternate ^= 1;
            }
        }
        if (next == 26) {
            object->alternate ^= 1;
        }
        if (current == 67 && next >= 30 && next < 60) {
            object->alternate = 1;
        }
        if (next >= 20 && next <= 21) {
            object->alternate = 0;
        }
        if (next == 0) {
            object->alternate = next;
        }
    }
}
