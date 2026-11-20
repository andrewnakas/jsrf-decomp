struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The target's body (at its 0x24): the values func_001084E0 reads and this sets.
struct Body_00108640 {
    char unknown_000[0xcd4];
    int value_cd4;
    int value_cd8;
    char unknown_cdc[0x2bc];
    int value_f98;
    int value_f9c;
    int value_fa0;
    int value_fa4;
    int value_fa8;
    int value_fac;
    int value_fb0;
    int value_fb4;
    char unknown_fb8[0xc];
    int value_fc4;
    int value_fc8;
    char unknown_fcc[0x4];
    int value_fd0;
};

// The target (id at 0x16b8).
struct Target_00108640 {
    char unknown_00[0x24];
    Body_00108640 *body;
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    char unknown_0000[0x16b8];
    int target;

    void func_00108640(int index, int value);
};

// Sets value `index` (0 to 12) of the body of the target (id at 0x16b8), when both exist; value 9 is stored less 1.
// func_001084E0 reads the same values.
void Object_00107FE0::func_00108640(int index, int value)
{
    Target_00108640 *object = (Target_00108640 *)data_0022FCE0->func_000128C0(target);
    if (object && object->body) {
        Body_00108640 *body = object->body;
        switch (index) {
        case 0:
            body->value_f9c = value;
            break;
        case 1:
            body->value_f98 = value;
            break;
        case 2:
            body->value_cd8 = value;
            break;
        case 3:
            body->value_cd4 = value;
            break;
        case 4:
            body->value_fa4 = value;
            break;
        case 5:
            body->value_fa0 = value;
            break;
        case 6:
            body->value_fa8 = value;
            break;
        case 7:
            body->value_fd0 = value;
            break;
        case 8:
            body->value_fc4 = value;
            break;
        case 9:
            body->value_fc8 = value - 1;
            break;
        case 10:
            body->value_fac = value;
            break;
        case 11:
            body->value_fb0 = value;
            break;
        case 12:
            body->value_fb4 = value;
            break;
        }
    }
}
