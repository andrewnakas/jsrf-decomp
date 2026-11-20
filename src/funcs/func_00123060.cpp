struct Object_00070850 {
    void func_00070960(int index);
};

// One of the 15 rows at +0xDB0 (0x30 bytes each).
struct Row_00123060 {
    unsigned short value;
    char unknown_02[0x2e];
};

struct Object_00120420 {
    char unknown_0000[0xda4];
    int row;
    char unknown_0da8[0x8];
    Row_00123060 rows[15];
    char unknown_1080[0x9e];
    unsigned short value;

    int func_00127070();
    void func_00123060();
};

// Steps the value of the current row (with no row, the shared value at +0x111E) up or down by the sign of
// func_00127070, wrapping within 0 to 79 and calling func_00070960 with 1 on each change; stores it back into the
// row and the shared value (with no row, into every row, and only after a change).
void Object_00120420::func_00123060()
{
    int value;
    if (row < 0) {
        value = this->value;
    } else {
        value = rows[row].value;
    }
    int changed = 0;
    if (func_00127070() > 0) {
        changed = 1;
        value++;
        ((Object_00070850 *)this)->func_00070960(changed);
    }
    if (func_00127070() < 0) {
        changed = 1;
        value--;
        ((Object_00070850 *)this)->func_00070960(changed);
    }
    if (value >= 0x50) {
        value = 0;
    } else if (value < 0) {
        value = 0x4f;
    }
    if (row < 0) {
        if (changed) {
            for (int i = 0; i < 15; i++) {
                rows[i].value = value;
            }
            this->value = value;
        }
    } else {
        rows[row].value = value;
        this->value = value;
    }
}
