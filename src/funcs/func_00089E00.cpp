struct Entry_0003E720 {
    char unknown_00[0xc8];
    float level;
};

struct Object_0003E750 {
    Entry_0003E720 *func_0003E720(int key);
    int func_0003F450(int key);
};

extern Object_0003E750 data_002314B0;

struct Object_000A1C50 {
    char unknown_0000[0x103c];
    int watching;
    int key;
    float level;
    int rising;

    void func_000A2080();
    void func_00089E00();
};

// Watches the level (+0xc8) of the entry registered under a key at 0x2314B0: when it is positive and has dropped
// below the one kept at +0x1044, runs func_000A2080 once (if the entry's word at +0xa0 is set); keeps the level.
void Object_000A1C50::func_00089E00()
{
    if (watching) {
        Entry_0003E720 *entry = data_002314B0.func_0003E720(key);
        if (entry && entry->level > 0.0f) {
            if (level > entry->level) {
                if (!rising) {
                    if (data_002314B0.func_0003F450(key)) {
                        func_000A2080();
                    }
                    rising = 1;
                }
            } else {
                rising = 0;
            }
            level = entry->level;
        }
    }
}
