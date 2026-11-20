/* sym: ??0Object_000C12F0@@QAE@XZ = 0x000C12F0 */
/* sym: ??0Object_000BFF60@@QAE@XZ = 0x000BFF60 */
// The class whose only virtual function is its destructor (table 0x1CDC58); the object in data_00257CE8.
struct Object_000C12F0 {
    Object_000C12F0();
    virtual ~Object_000C12F0() {}
};

struct Object_00157F10;

// The table of boxes at data_00257CE0 (0x1c bytes).
struct Object_000BFF60 {
    Object_000BFF60();

    void *data;
    unsigned char *tables[3];
    char unknown_10[0xc];
};

extern Object_00157F10 *data_00257CE8;
extern Object_000BFF60 *data_00257CE0;

// The message the debug output gets when an object is made twice.
extern const char data_001CDBE4[];

void __stdcall func_001473E1(const char *text);

// Object 0x12b1 (table 0x1CDC18).
struct Object_000C0A90 {
    char unknown_00[0x44];
    int value_44;
    int value_48;

    void func_000C04D0();
};

// Makes the objects in data_00257CE8 (func_000C12F0) and data_00257CE0 (func_000BFF60); one that already exists
// gets the message at 0x1CDBE4 sent to the debug output (func_001473E1) instead. Then clears 0x44 and 0x48.
void Object_000C0A90::func_000C04D0()
{
    if (!data_00257CE8) {
        data_00257CE8 = (Object_00157F10 *)new Object_000C12F0;
    } else {
        func_001473E1(data_001CDBE4);
    }
    if (!data_00257CE0) {
        data_00257CE0 = new Object_000BFF60;
    } else {
        func_001473E1(data_001CDBE4);
    }
    value_44 = 0;
    value_48 = 0;
}
