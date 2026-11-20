// The class whose table is at 0x1E1968.
struct Object_001E1968;

// The description at +0x26c of that class: the kind of object is the byte at +8 (+0x274 of the class).
struct Description {
    unsigned long unknown_0;
    unsigned long unknown_4;
    unsigned char kind;
};

// Two tables of values in .data: three for kind 0x12 and six for every other kind.
extern unsigned long data_0022EA74[3];
extern unsigned long data_0022EA80[6];

// Gives the value at `index` of the table for the kind of object (0x161E70 passes the description at +0x26c): for
// kind 0x13 there is none and it returns 1; an index past the table is 0x80070057 (E_INVALIDARG).
long __stdcall func_00161CD0(Object_001E1968 *self, const Description *description, unsigned int index,
                             unsigned long *value)
{
    switch (description->kind) {
    case 0x12:
        if (index < 3) {
            *value = data_0022EA74[index];
            return 0;
        }
        break;
    case 0x13:
        return 1;
    default:
        if (index < 6) {
            *value = data_0022EA80[index];
            return 0;
        }
        break;
    }
    return 0x80070057;
}
