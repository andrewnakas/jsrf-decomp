/* sym: ?func_00157F30_1@Object_001E17E0@@UAGXKK@Z = 0x0015F770 */
struct Keys {
    int unknown_00;
    int count;
    char *data;
    int stride;
    char *current;
    char *next;
};

unsigned int func_0014C6A0(float value);
// The first and the last key, and the key pair around a position (hand-written helpers).
void __fastcall func_0015F600(void *out, Keys *keys);
void __fastcall func_0015F610(void *out, Keys *keys);
void __fastcall func_0015F630(Keys *keys, int index);
void __fastcall func_0015F6B0(Keys *keys, void *out, float time);

// The base of the classes whose tables are at 0x1E17BC (constructor 0x15F1C0) and 0x1E17E0 (constructor 0x15F280).
struct Object_001E17BC {
    virtual void __stdcall func_00157F30_1(unsigned long first, unsigned long second);  // slot 8: folded

    char unknown_04[0x40];
    Keys *keys;
    float length;
};

// The class whose table is at 0x1E17E0 (constructor 0x15F280).
struct Object_001E17E0 : Object_001E17BC {
    virtual void __stdcall func_00157F30_1(unsigned long first, unsigned long second);  // slot 8, at 0x15F770
};

// Slot 8: writes the keys' value at time second (a float from 0 to 1) to first: the first key at 0, the last at 1,
// otherwise the pair of keys around second times the length at +0x48, mixed by the fraction (func_0015F6B0).
void __stdcall Object_001E17E0::func_00157F30_1(unsigned long first, unsigned long second)
{
    float time = *(float *)&second;
    if (time != 0.0f) {
        if (time != 1.0f) {
            float position = time * length;
            int index = func_0014C6A0(position);
            func_0015F630(keys, index);
            func_0015F6B0(keys, (void *)first, position - (float)index);
        } else {
            func_0015F610((void *)first, keys);
        }
    } else {
        func_0015F600((void *)first, keys);
    }
}
