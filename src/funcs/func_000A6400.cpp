int func_0003BF90();

struct Object_00014A80 {
    int func_00014C30(int *first, int *second);
    int func_00014C80(int value);
};

extern Object_00014A80 data_001EB938;

// A condition: its kind and a value to compare with.
struct Condition_000A6400 {
    int kind;
    int value;
};

// A direct child of Node (table 0x1CD570, constructor func_000A6980); slot 1 is func_000A76E0.
struct Object_000A6980 {
    char unknown_000[0x8a8];
    int second;

    int func_000A6400(Condition_000A6400 *condition);
};

// Whether a condition holds: kind 0 always; 1 when func_0003BF90 gives its value; 2 when func_00014C80 of
// data_001EB938 accepts the value at 0x8a8; 3 when func_00014C30 succeeds with a second result other than that
// value.
int Object_000A6980::func_000A6400(Condition_000A6400 *condition)
{
    switch (condition->kind) {
    case 0:
        return 1;
    case 1:
        if (func_0003BF90() == condition->value) {
            return 1;
        }
        break;
    case 2:
        if (data_001EB938.func_00014C80(second)) {
            return 1;
        }
        break;
    case 3: {
        int first;
        int found;
        if (data_001EB938.func_00014C30(&first, &found) && found != second) {
            return 1;
        }
        break;
    }
    }
    return 0;
}
