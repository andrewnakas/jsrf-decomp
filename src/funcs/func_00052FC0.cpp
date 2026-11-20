int func_00106F70(unsigned int value);
int func_00106FB0(unsigned int value);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    void func_00039D80(int *first, unsigned int second);
};

extern Object_00039BE0 data_001EFFB0;

// A racer (objects 0xc to 0x2b): its owner (+0x8d4) and target (+0x8d8) object ids.
struct Racer_00052FC0 {
    char unknown_000[0x8d4];
    int owner;
    int target;
};

struct Owner_00052FC0 {
    char unknown_000[0xca0];
    int id;
};

struct Target_00052FC0 {
    char unknown_000[0x23c];
    unsigned int value;
};

struct Info_00052FC0 {
    char unknown_00[0x8];
    int *first;
    unsigned int second;
};

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    unsigned int state;
    char unknown_060[0xf58];
    Info_00052FC0 *info;
    char unknown_fbc[0x10];
    int ids[4];
    unsigned int count;

    void func_00052FC0();
};

// State handler 55 (also 71, 77, 81 and 87) of the table at 0x1F9888: finds the first racer whose owner and target
// exist and whose target passes the check: func_00106F70 when the owner's id is one of the ids at +0xfcc, else
// func_00106FB0 not negative. Then hands the info's two values to func_00039D80 and goes to state 0x69.
void Object_0004ABA0::func_00052FC0()
{
    for (int id = 0xc; id <= 0x2b; id++) {
        Racer_00052FC0 *racer = (Racer_00052FC0 *)data_0022FCE0->func_000128C0(id);
        if (!racer)
            continue;
        Owner_00052FC0 *owner = (Owner_00052FC0 *)data_0022FCE0->func_000128C0(racer->owner);
        if (!owner)
            continue;
        Target_00052FC0 *target = (Target_00052FC0 *)data_0022FCE0->func_000128C0(racer->target);
        if (!target)
            continue;
        unsigned int i;
        for (i = 0; i < count; i++) {
            if (ids[i] == owner->id)
                break;
        }
        if (i < count) {
            if (func_00106F70(target->value)) {
                data_001EFFB0.func_00039D80(info->first, info->second);
                state = 0x69;
                return;
            }
        } else if (func_00106FB0(target->value) >= 0) {
            data_001EFFB0.func_00039D80(info->first, info->second);
            state = 0x69;
            return;
        }
    }
}
