struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The stage kinds by course, for the two modes.
extern int data_00227720[];
extern int data_00227740[];

struct Object_00120420 {
    char unknown_0000[0x44];
    int mode;
    char unknown_0048[8];
    int course;
    char unknown_0054[0x174];
    int state;
    int step;
    char unknown_01d0[0x2ccd];
    unsigned char unlocks[0x53];

    void func_001282C0();
};

// Sets the open flags of object 0x1de2 (the bytes from +0x2e9d) by its state: in state 3 opens the set from +0x2ed9
// and moves the one of this course's kind (data_00227740 by +0x50) to its neighbour, then opens the set from +0x2e9d;
// in state 2 opens the set from +0x2e9f and, unless in mode 3 at step 7, moves the one of this course's kind
// (data_00227720) the same way.
void Object_00120420::func_001282C0()
{
    Object_00120420 *scene = (Object_00120420 *)data_0022FCE0->func_000128C0(0x1de2);
    switch (scene->state) {
    case 3: {
        int kind = data_00227740[course];
        scene->unlocks[0x51] = 1;
        scene->unlocks[0x52] = 1;
        scene->unlocks[0x3c] = 1;
        scene->unlocks[0x3f] = 1;
        scene->unlocks[0x41] = 1;
        scene->unlocks[0x43] = 1;
        scene->unlocks[0x45] = 1;
        scene->unlocks[0x49] = 1;
        scene->unlocks[0x4b] = 1;
        scene->unlocks[0x4f] = 1;
        scene->unlocks[0x4d] = 1;
        if (kind == 8) {
            scene->unlocks[0x46] = 1;
            scene->unlocks[0x45] = 0;
        } else if (kind == 9) {
            scene->unlocks[0x40] = 1;
            scene->unlocks[0x3f] = 0;
        } else if (kind == 13) {
            scene->unlocks[0x42] = 1;
            scene->unlocks[0x41] = 0;
        } else if (kind == 14) {
            scene->unlocks[0x44] = 1;
            scene->unlocks[0x43] = 0;
        } else if (kind == 12) {
            scene->unlocks[0x4a] = 1;
            scene->unlocks[0x49] = 0;
        } else if (kind == 11) {
            scene->unlocks[0x4c] = 1;
            scene->unlocks[0x4b] = 0;
        } else if (kind == 10) {
            scene->unlocks[0x50] = 1;
            scene->unlocks[0x4f] = 0;
        } else if (kind == 15) {
            scene->unlocks[0x4e] = 1;
            scene->unlocks[0x4d] = 0;
        }
        scene->unlocks[0x00] = 1;
        scene->unlocks[0x02] = 1;
        scene->unlocks[0x04] = 1;
        scene->unlocks[0x06] = 1;
        scene->unlocks[0x08] = 1;
        scene->unlocks[0x0a] = 1;
        scene->unlocks[0x0c] = 1;
        scene->unlocks[0x0f] = 1;
        break;
    }
    case 2: {
        int kind = data_00227720[course];
        scene->unlocks[0x02] = 1;
        scene->unlocks[0x04] = 1;
        scene->unlocks[0x06] = 1;
        scene->unlocks[0x08] = 1;
        scene->unlocks[0x0a] = 1;
        scene->unlocks[0x0c] = 1;
        scene->unlocks[0x0e] = 1;
        if (mode == 3 && scene->step == 7) {
            break;
        }
        if (kind == 0) {
            scene->unlocks[0x02] = 0;
            scene->unlocks[0x03] = 1;
        } else if (kind == 1) {
            scene->unlocks[0x0c] = 0;
            scene->unlocks[0x0d] = 1;
        } else if (kind == 2) {
            scene->unlocks[0x06] = 0;
            scene->unlocks[0x07] = 1;
        } else if (kind == 3) {
            scene->unlocks[0x08] = 0;
            scene->unlocks[0x09] = 1;
        } else if (kind == 4) {
            scene->unlocks[0x04] = 0;
            scene->unlocks[0x05] = 1;
        } else if (kind == 5) {
            scene->unlocks[0x0e] = 0;
            scene->unlocks[0x0f] = 1;
        } else if (kind == 6) {
            scene->unlocks[0x0b] = 1;
            scene->unlocks[0x0a] = 0;
        }
        break;
    }
    }
}
