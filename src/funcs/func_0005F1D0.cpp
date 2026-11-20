/* sym: ??1Context_00251D7C@@UAE@XZ = 0x0005F1D0 */
int func_001165C0();
void func_001BB720();
void func_0014CAD0();

struct Device_00251D6C {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

struct Interface_00251D74 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

struct Interface_002589F4 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

extern Device_00251D6C *data_00251D6C;
extern Interface_00251D74 *data_00251D74;
extern Interface_002589F4 *data_002589F4;

// Releases each interface until its count reaches zero and clears the pointer.
#define RELEASE(p)                \
    if (p) {                      \
        while ((p)->slot2() != 0) \
            ;                     \
        (p) = 0;                  \
    }

// The object at 0x251D7C (table 0x1CAF70, constructor 0x5F180).
struct Context_00251D7C {
    Context_00251D7C();
    virtual ~Context_00251D7C();
};

// Runs func_001165C0, releases the interfaces at 0x2589F4 and 0x251D74 and the device, then frees the two buffers
// (func_001BB720, func_0014CAD0).
Context_00251D7C::~Context_00251D7C()
{
    func_001165C0();
    RELEASE(data_002589F4);
    RELEASE(data_00251D74);
    RELEASE(data_00251D6C);
    func_001BB720();
    func_0014CAD0();
}
