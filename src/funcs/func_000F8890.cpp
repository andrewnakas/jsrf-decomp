struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;

struct Object_00039BE0 {
    int func_00039FD0();
};

extern Object_00039BE0 data_001EFFB0;

int func_0017C6EB(const char *text);
void func_001087D0(int handle, unsigned int count, int *values, int value);

// The class whose slot 3 is func_000F8130 (table built by func_000F80C0).
struct Object_000F96A0 {
    int func_000F8890(const char *text, char *out);
};

// Called by func_000F9090 for a four-character code: the number in its last two characters less func_00039FD0 of
// data_001EFFB0 (at least 0), split into two digits (func_001087D0); each present digit goes to out as a full-width
// two-byte character, or as an ASCII digit when func_00043700 of data_001FC724 is not 0. Gives the bytes written.
int Object_000F96A0::func_000F8890(const char *text, char *out)
{
    int count = 0;
    int ascii = data_001FC724.func_00043700();
    char number[3];
    number[0] = text[2];
    number[1] = text[3];
    number[2] = 0;
    int value = func_0017C6EB(number) - data_001EFFB0.func_00039FD0();
    if (value < 0) {
        value = 0;
    }
    int digits[2];
    func_001087D0(value, 2, digits, -1);
    for (int i = 0; i < 2; i++) {
        if (digits[i] >= 0) {
            if (!ascii) {
                unsigned short c = (char)digits[i] + 0x824f;
                out[count++] = c >> 8;
                out[count++] = (char)c;
            } else {
                out[count++] = digits[i] + '0';
            }
        }
    }
    return count;
}
