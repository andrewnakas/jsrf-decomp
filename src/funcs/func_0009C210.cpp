struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_00106E50(unsigned int id, unsigned int kind, int first, int second, int third);

// The object whose id the player keeps at 0xc98.
struct Partner_0009C210 {
    char unknown_000[0x23c];
    unsigned int id;
};

struct Object_000A1C50 {
    char unknown_000[0xc98];
    int partnerId;

    void func_0009C210();
};

// Passes the id at 0x23c of the object at 0xc98, when it exists, to func_00106E50 with kind 0 and 2, 3, 0.
void Object_000A1C50::func_0009C210()
{
    Partner_0009C210 *partner = (Partner_0009C210 *)data_0022FCE0->func_000128C0(partnerId);
    if (partner) {
        func_00106E50(partner->id, 0, 2, 3, 0);
    }
}
