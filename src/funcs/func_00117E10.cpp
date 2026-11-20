/* sym: ??1Object_00117E10@@QAE@XZ = 0x00117E10 */
// A sound bank of object 4 (func_001188C0 deletes it): its destructor frees the nine buffers it holds.
struct Object_00117E10 {
    char unknown_00[0x14];
    void *buffer_14;
    void *buffer_18;
    void *buffer_1c;
    void *buffer_20;
    void *buffer_24;
    void *buffer_28;
    void *buffer_2c;
    void *buffer_30;
    void *buffer_34;

    ~Object_00117E10();
};

Object_00117E10::~Object_00117E10()
{
    if (buffer_28) {
        operator delete(buffer_28);
    }
    if (buffer_34) {
        operator delete(buffer_34);
    }
    if (buffer_30) {
        operator delete(buffer_30);
    }
    if (buffer_2c) {
        operator delete(buffer_2c);
    }
    if (buffer_24) {
        operator delete(buffer_24);
    }
    if (buffer_20) {
        operator delete(buffer_20);
    }
    if (buffer_1c) {
        operator delete(buffer_1c);
    }
    if (buffer_18) {
        operator delete(buffer_18);
    }
    if (buffer_14) {
        operator delete(buffer_14);
    }
}
