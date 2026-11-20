struct Vector3 {
    float x;
    float y;
    float z;
};

struct Model_00018260 {
    void *unknown_00;
    unsigned int count;
    char unknown_08[0xc];
    unsigned int otherCount;
    char unknown_18[0x14];
};

// What func_00018260 reports (16 bytes).
struct Hit_00018260 {
    float unknown_00[4];
};

struct Hits_000C4C60;

// The contact func_000194B0 picks: a point at 0x2c, or at 0x50 for the other kind.
struct Contact_000C4A90 {
    char unknown_00[0x2c];
    Vector3 point;
    char unknown_38[0x18];
    Vector3 otherPoint;
};

struct Object_00016200 {
    int func_00018260(Model_00018260 *model, Vector3 *from, Vector3 *to, Hit_00018260 *hit, int mask, int flags);
    int func_000194B0(Hits_000C4C60 *hits, Contact_000C4A90 **nearest);
};

extern Object_00016200 data_0022FCE8;

// The child of Node whose table is at 0x1CEDA0; its handlers (table at 0x218E4C) run by the state at 0x9c.
struct Object_000E6E80 {
    char unknown_000[0x44];
    Vector3 origin;
    Vector3 position;
    Vector3 start;
    Vector3 previous;
    char unknown_074[0x28];
    int state;
    unsigned int flags_a0;
    char unknown_0a4[0x4c0];
    Model_00018260 model;
    char unknown_590[4];
    int stopped;

    void func_000E6E80();
};

// Unless 0x594 is set, sweeps the model at 0x564 from 0x5c to 0x68 (func_00018260); on a hit, the position at 0x50
// goes to the contact point func_000194B0 picks. A hit (or 0x594) sets state 3 and flag 1 at 0xa0. Then the origin
// at 0x44 takes the position and the start at 0x5c the point at 0x68. Called by slot 2 (func_000E7540).
void Object_000E6E80::func_000E6E80()
{
    if (!stopped) {
        if (model.count > 0 || model.otherCount > 0) {
            Hit_00018260 hit;
            if (data_0022FCE8.func_00018260(&model, &start, &previous, &hit, 0xffff, -1)) {
                Contact_000C4A90 *contact;
                if (!data_0022FCE8.func_000194B0((Hits_000C4C60 *)&hit, &contact)) {
                    position = contact->point;
                } else {
                    position = contact->otherPoint;
                }
                state = 3;
                flags_a0 |= 1;
            }
        }
    } else {
        state = 3;
        flags_a0 |= 1;
    }
    origin = position;
    start = previous;
}
