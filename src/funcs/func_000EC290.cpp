struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int index);
};

extern Object_00046670 data_001F93C8;

struct Set_000ECB50 {
    Motion_0005F060 *motions[32];
};

// The object func_000ECB50 builds (Node and a chain link at 0x44); this is a handler of the table at 0x258520 its
// slot 1 (func_000ECDB0) runs, filled in by the dynamic initializer func_0018C0C0.
struct Object_000ECB50 {
    char unknown_000[0x48];
    Vector3 position;
    char unknown_054[0x34];
    float height;
    char unknown_08c[0x9c];
    int next;
    int phase;
    char unknown_130[4];
    int index;
    int value_138;
    char unknown_13c[8];
    Set_000ECB50 *set;
    Motion_0005F060 *motion;
    Motion_0005F060 *motion_b;
    char unknown_150[4];
    float time;
    char unknown_158[4];
    int value_15c;
    int value_160;
    int effects[4];
    char unknown_174[0x50];
    int effect_1c4;

    void func_000EC290();
};

// Entry 0 of the handlers at 0x258520: state 1 with the phase, index and 0x138 cleared, motion 8 of the set at 0x144
// alone at time 0; object 0xE8, if there is one, makes four effects of kind 0x3b (kept at 0x164) and one of kind
// 0x3c (0x1c4); the height at 0x88 becomes func_000466C0 of the position on data_001F93C8.
void Object_000ECB50::func_000EC290()
{
    next = 1;
    phase = 0;
    index = 0;
    value_138 = 0;
    motion = set->motions[8];
    motion_b = 0;
    value_160 = 0;
    value_15c = 0;
    time = 0.0f;
    Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (node) {
        for (int i = 0; i < 4; i++) {
            effects[i] = node->func_000651E0(0x3b, 0, 0);
        }
        effect_1c4 = node->func_000651E0(0x3c, 0, 0);
    }
    height = data_001F93C8.func_000466C0(&position, -1);
}
