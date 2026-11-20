struct Game {
    void *func_000128C0(int id);
};

struct Object_000732A0 {
    void func_000732A0();
};

// Object 0x1163 (constructor func_000FF230, destructor func_000FEC60).
struct Object_000FEDB0 {
    char unknown_000[0x12c];
    int id_12c;

    void func_000FEEF0(int keep);
};

extern Game *data_0022FCE0;

// Unless `keep` is set, takes out the object whose id is at 0x12c (func_000732A0), when there is one, and clears
// the id.
void Object_000FEDB0::func_000FEEF0(int keep)
{
    if (!keep && id_12c) {
        if (data_0022FCE0->func_000128C0(id_12c)) {
            ((Object_000732A0 *)data_0022FCE0->func_000128C0(id_12c))->func_000732A0();
        }
        id_12c = 0;
    }
}
