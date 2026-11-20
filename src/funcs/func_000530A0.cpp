void func_00106F10(unsigned int id, int value);

struct Game {
    void func_000127C0(int index, int value);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// A 0x34-byte slot record: its kind (+0) and, while it is held, the place it was taken at (+0x30).
struct Slot_000530A0 {
    int kind;
    int unknown_04[10];
    int unknown_2c;
    void *place;
};

// Objects 0xc - 0x2b: their slot (+0x8a4), whether they are out (+0x8b4) and the objects they hold (+0x8d4, +0x8d8).
struct Member_000530A0 {
    char unknown_000[0x8a4];
    int slot;
    char unknown_8a8[0xc];
    int out;
    char unknown_8b8[0x1c];
    int holder;
    int partner;
};

struct Holder_000530A0 {
    char unknown_000[0xca0];
    int kind;
};

struct Partner_000530A0 {
    char unknown_000[0x23c];
    unsigned int id;
};

// Object 0xb: the slot records at +0x544.
struct Table_000530A0 {
    char unknown_000[0x544];
    Slot_000530A0 slots[1];
};

struct Entry_0005BA00 {
    char unknown_00[0x1c];
    int place;
};

struct Block_0005BA00 {
    char unknown_000[0xdc];
    char (*places)[0x10];
};

struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;
    char unknown_0060[0x258];
    Slot_000530A0 slots[1];
    char unknown_02ec[0xccc];
    Entry_0005BA00 *current;
    int unknown_fbc;
    char unknown_0fc0[0xc];
    int kinds[4];
    unsigned int kindCount;
    char unknown_0fe0[0x60];
    Block_0005BA00 *block;

    void func_000530A0();
};

// Counts the objects 0xc - 0x2b that hold a live object (+0x8d4); then, for each of those not out, takes its slot
// record from object 0xb as kind 4 at the current entry's place, copies it back and publishes it (game values
// slot + 0x6d and slot + 0xcd); when its partner (+0x8d8) is live and the holder's kind is one of this object's kinds
// (+0xfcc), runs func_00106F10 for the partner's id with 0x15. Ends with +0xfbc = 0xb4 and state 0x49.
void Object_0004ABA0::func_000530A0()
{
    unsigned int held = 0;
    int id;
    for (id = 0xc; id <= 0x2b; id++) {
        {
            Member_000530A0 *member = (Member_000530A0 *)data_0022FCE0->func_000128C0(id);
            if (member && data_0022FCE0->func_000128C0(member->holder)) {
                held++;
            }
        }
    }
    for (id = 0xc; id <= 0x2b; id++) {
        Member_000530A0 *member = (Member_000530A0 *)data_0022FCE0->func_000128C0(id);
        if (!member || member->out) {
            continue;
        }
        Holder_000530A0 *holder = (Holder_000530A0 *)data_0022FCE0->func_000128C0(member->holder);
        if (!holder) {
            continue;
        }
        int slot = member->slot;
        Table_000530A0 *table = (Table_000530A0 *)data_0022FCE0->func_000128C0(0xb);
        Slot_000530A0 *record = &slots[slot];
        *record = table->slots[slot];
        void *place = block->places[current->place];
        record->kind = 4;
        record->unknown_2c = 0;
        record->place = place;
        table->slots[slot] = *record;
        data_0022FCE0->func_000127C0(slot + 0x6d, (int)record);
        data_0022FCE0->func_000127C0(slot + 0xcd, 1);
        Partner_000530A0 *partner = (Partner_000530A0 *)data_0022FCE0->func_000128C0(member->partner);
        if (!partner) {
            continue;
        }
        unsigned int total = kindCount;
        unsigned int i = 0;
        while (i < kindCount && kinds[i] != holder->kind) {
            i++;
        }
        if (i < total) {
            if (held > 2) {
                func_00106F10(partner->id, 0x15);
            } else {
                func_00106F10(partner->id, 0x15);
            }
        }
    }
    unknown_fbc = 0xb4;
    state = 0x49;
}
