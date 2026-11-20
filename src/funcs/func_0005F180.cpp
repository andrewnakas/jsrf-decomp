/* sym: ??0Context_00251D7C@@QAE@XZ = 0x0005F180 */
/* sym: ??1Context_00251D7C@@UAE@XZ = 0x0005F1D0 */
struct Interface_00251D64;
struct Interface_00251D68;
struct Device_00251D6C;
struct Interface_00251D70;
struct Interface_00251D74;
struct Interface_00251D78;
struct Interface_002589F4;

extern Interface_00251D64 *data_00251D64;
extern Interface_00251D68 *data_00251D68;
extern Device_00251D6C *data_00251D6C;
extern Interface_00251D70 *data_00251D70;
extern Interface_00251D74 *data_00251D74;
extern Interface_00251D78 *data_00251D78;
extern Interface_002589F4 *data_002589F4;

// The object at 0x251D7C (made at 0x12210, table 0x1CAF70, destructor 0x5F1D0) that owns the device and its interfaces.
struct Context_00251D7C {
    Context_00251D7C();
    virtual ~Context_00251D7C();

    int unknown_004;
    int unknown_008;
    int unknown_00c;
    int unknown_010;
    char unknown_014[0x2c0];
    int unknown_2d4;
};

// Clears the device and interface pointers and the words at +0xc, +0x10 and +0x2d4.
Context_00251D7C::Context_00251D7C()
{
    data_00251D6C = 0;
    data_00251D74 = 0;
    data_00251D78 = 0;
    data_00251D68 = 0;
    data_00251D64 = 0;
    data_00251D70 = 0;
    data_002589F4 = 0;
    unknown_00c = 0;
    unknown_010 = 0;
    unknown_2d4 = 0;
}
