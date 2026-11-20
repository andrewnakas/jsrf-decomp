struct Guid;
struct Sound;

// The two interface ids it asks for.
extern const Guid data_001E391C;
extern const Guid data_001E38FC;

// DirectSound's library code (0x19E000-0x1A1000).
long __stdcall func_0019E4BC(Sound *sound, void *window, unsigned long level);
unsigned long __stdcall func_0019E4DC(Sound *sound);

// The ADX library's setup calls.
void func_0013AF20(void *argument);
void func_0013AFA0(void *argument);
void func_0013AFB0();
void func_0013B330(void *argument);

// The interface data_002589F4 gives for data_001E391C; its slot 3 gives the DirectSound object.
struct Interface_00116EC0 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(const Guid &id, Sound **sound);
};

struct Interface_002589F4 {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

extern Interface_002589F4 *data_002589F4;

// Asks data_002589F4 for the interface data_001E391C and that for the DirectSound object (data_001E38FC), passes 2
// to 0x19E4BC and sets the ADX library up with the DirectSound object, then releases both. Returns the first
// failure, else 0.
long func_00116EC0()
{
    Interface_00116EC0 *object;
    Sound *sound;
    long result = data_002589F4->slot0(data_001E391C, (void **)&object);
    if (result < 0) {
        return result;
    }
    result = object->slot3(data_001E38FC, &sound);
    if (result < 0) {
        return result;
    }
    result = func_0019E4BC(sound, 0, 2);
    if (result < 0) {
        return result;
    }
    func_0013AF20(0);
    func_0013AFA0(sound);
    func_0013B330(0);
    func_0013AFB0();
    if (sound) {
        func_0019E4DC(sound);
        sound = 0;
    }
    if (object) {
        object->slot2();
    }
    return 0;
}
