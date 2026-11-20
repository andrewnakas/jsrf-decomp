/* sym: ??0Object_000C20A0@@QAE@PAUData_000C2700@@@Z = 0x000C2010 */
/* sym: ??0Object_000C2420@@QAE@PAUData_000C2700@@@Z = 0x000C2420 */
/* sym: ??1Object_000C20A0@@UAE@XZ = 0x000C2030 */
/* sym: ?func_000C3140@Object_000C20A0@@UAEXXZ = 0x000C20D0 */
/* sym: ?func_000C31B0@Object_000C20A0@@UAEXXZ = 0x000C21B0 */
/* sym: ?func_000C36F0@Object_000C20A0@@UAEXXZ = 0x000C20A0 */
/* sym: ?func_000C2560@Object_000C20A0@@UAEXXZ = 0x00011C90 */
/* sym: ?func_000C25D0@Object_000C20A0@@UAEXXZ = 0x00011C90 */
/* sym: ?func_000C2AA0@Object_000C20A0@@UAEHXZ = 0x000C22C0 */
struct Data_000C2700 {
    char unknown_00[3];
    char kind;
};

struct Pair_000C3100 {
    short first;
    short second;
};

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470); slot 9 is the
// destructor.
struct Object_000C2420 {
    Object_000C2420(Data_000C2700 *data);
    virtual void func_000C2630();
    virtual void func_000C2700();
    virtual void func_000C3800();
    virtual void func_000C30C0();
    virtual void func_000C3100();
    virtual void func_000C3140();
    virtual void func_000C31B0();
    virtual void func_000C3350();
    virtual void func_000C33C0();
    virtual ~Object_000C2420();
    virtual void func_000C2480();
    virtual void func_000C36F0();
    virtual void func_000C2FE0();
    virtual void func_000C2500();
    virtual void func_000C2560();
    virtual void func_000C25D0();
    virtual int func_000C2AA0();

    char unknown_04[0x24];
    int value_28;
    char unknown_2c[4];
    unsigned int flags;
    unsigned int state;
    char unknown_38[0x40];
    Data_000C2700 *data;
    Pair_000C3100 *pair;
    float value;
};

// The class whose table is at 0x1CDC60 (constructor func_000C2010, destructor func_000C2030): overrides slots 5,
// 6, 11 and 16 of its base, and slots 14 and 15 with empty functions.
struct Object_000C20A0 : Object_000C2420 {
    Object_000C20A0(Data_000C2700 *data);
    virtual void func_000C3140();
    virtual void func_000C31B0();
    virtual ~Object_000C20A0();
    virtual void func_000C36F0();
    virtual void func_000C2560();
    virtual void func_000C25D0();
    virtual int func_000C2AA0();
};

Object_000C20A0::Object_000C20A0(Data_000C2700 *data) : Object_000C2420(data)
{
}
