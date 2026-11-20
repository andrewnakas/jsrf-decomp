/* sym: ?func_0015F1E0@Object_001E17E0@@UAGJKKK@Z = 0x0015F860 */
extern "C" void *__cdecl memset(void *destination, int value, unsigned int size);

// VirtualAlloc (address, size, allocation type, protection).
void *__stdcall func_00145A2F(void *address, unsigned long size, unsigned long type, unsigned long protect);

struct Storage {
    char unknown_00[0x40];
};

long __stdcall func_0015F0F0(Storage *storage, void *data, unsigned long size, unsigned long count);

// A float built from its bits.
union Bits {
    unsigned long bits;
    float value;
};

// The objects that share the weights table, the table (0x100 entries of four weights) and the scratch float its
// set-up builds each step's t in.
extern int data_00265168;
extern void *data_0026516C;
extern Bits data_00265170;

// The base of the classes whose tables are at 0x1E17BC (constructor 0x15F1C0) and 0x1E17E0 (constructor 0x15F280).
struct Object_001E17BC {
    virtual long __stdcall func_0015F1E0(unsigned long first, unsigned long second, unsigned long third);  // slot 3

    Storage storage;
    void **keys;
};

// The class whose table is at 0x1E17E0 (constructor 0x15F280).
struct Object_001E17E0 : Object_001E17BC {
    virtual long __stdcall func_0015F1E0(unsigned long first, unsigned long second, unsigned long third);  // slot 3
};

// Committed, cleared memory.
static inline void *Allocate(unsigned long size)
{
    void *memory = func_00145A2F(0, size, 0x3000, 4);
    if (memory)
        memset(memory, 0, size);
    return memory;
}

// Slot 3: sets up the storage at +4 (func_0015F0F0); the first object to do so builds the table of cubic weights
// for t = i / 256 (the four Lagrange weights for the points at -1, 0, 1 and 2), and every object keeps the table in
// its keys. E_OUTOFMEMORY, or the storage's failure.
long __stdcall Object_001E17E0::func_0015F1E0(unsigned long first, unsigned long second, unsigned long third)
{
    long result = func_0015F0F0(&storage, (void *)first, second, third);
    if (result < 0)
        return result;
    if (data_00265168 == 0) {
        float *weights = (float *)Allocate(0x100 * 4 * sizeof(float));
        data_0026516C = weights;
        if (weights) {
            for (unsigned int i = 0; i < 0x100; i++) {
                data_00265170.bits = (i | 0x7F00) << 15;
                data_00265170.value -= 1.0f;
                float a = data_00265170.value - 1.0f;
                float b = data_00265170.value - 2.0f;
                float d = data_00265170.value + 1.0f;
                float w = -(data_00265170.value * b * a);
                weights[0] = w * 0.16666667f;
                weights[1] = d * b * a * 0.5f;
                w = -(data_00265170.value * d * b);
                weights[2] = w * 0.5f;
                weights[3] = data_00265170.value * d * a * 0.16666667f;
                weights += 4;
            }
        } else {
            return 0x8007000e;
        }
    }
    *keys = data_0026516C;
    data_00265168++;
    return 0;
}
