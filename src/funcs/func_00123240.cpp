// The Direct3D device.
struct Device_00251D6C {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33(float bias);
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37();
    virtual void __stdcall slot38();
    virtual void __stdcall slot39();
    virtual void __stdcall slot40();
    virtual void __stdcall slot41();
    virtual void __stdcall slot42();
    virtual void __stdcall slot43();
    virtual void __stdcall slot44();
    virtual void __stdcall slot45();
    virtual void __stdcall slot46();
    virtual void __stdcall slot47();
    virtual void __stdcall slot48();
    virtual void __stdcall slot49();
    virtual void __stdcall slot50();
    virtual void __stdcall slot51();
    virtual void __stdcall slot52();
    virtual void __stdcall slot53();
    virtual void __stdcall slot54();
    virtual void __stdcall slot55();
    virtual void __stdcall slot56();
    virtual void __stdcall slot57();
    virtual void __stdcall slot58();
    virtual void __stdcall slot59();
    virtual void __stdcall slot60();
    virtual void __stdcall slot61();
    virtual void __stdcall slot62();
    virtual void __stdcall slot63();
    virtual void __stdcall slot64();
    virtual void __stdcall slot65();
    virtual void __stdcall slot66();
    virtual void __stdcall slot67();
    virtual void __stdcall slot68();
    virtual void __stdcall slot69();
    virtual void __stdcall slot70();
    virtual void __stdcall slot71();
    virtual void __stdcall slot72();
    virtual void __stdcall slot73();
    virtual void __stdcall slot74();
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81();
    virtual void __stdcall slot82();
    virtual void __stdcall slot83(int first, int second);
};

extern Device_00251D6C *data_00251D6C;

// The part at +4 of a glyph model.
struct Part_00123240 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12(int stage, int flags);
    virtual void __stdcall slot13(int stage);
    virtual void __stdcall slot14(int stage, float *matrix);
};

// A glyph model: slot 5 draws it.
struct Model_00123240 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);

    Part_00123240 *part;
};

// One shown character: its glyph number and kind.
struct Entry_00123240 {
    int glyph;
    char kind;
    char unknown_05[0x2b];
};

// Each glyph's place in the font texture.
struct Glyph_00123240 {
    float u;
    float v;
};

extern Glyph_00123240 data_00226058[];

// The texture matrix the glyphs are drawn with.
extern float data_002266E0[16];

void func_001BA9C0();
void __fastcall func_001BAA50();
void func_001BAA60(float x, float y, float z);

struct Object_00120420 {
    char unknown_0000[0x1cc];
    int step;
    char unknown_01d0[0x2c0];
    float x;
    float y;
    float z;
    char unknown_049c[0x90c];
    Entry_00123240 entries[1];
    char unknown_0dd8[0x16c0];
    Model_00123240 *models[0x7c];
    char unknown_2688[0x814];
    char shown[0x7c];

    void func_00123240();
};

// Draws the shown characters 0x5e-0x6c (0x6d-0x7b at step 8) with the entries from 0xda8 (counted from 0): each
// glyph number from 0 (kind 1 adds 0x38, kind 2 maps 0x3d-0x41 to 0x94-0x98, other kinds map 0x5d to 0x5b; from 0x5e
// on add 0x3b) picks the texture offset (0x226058) of the matrix at 0x2266E0 given to the model's part on stage 0;
// the model is drawn at the point at 0x490 with device bias -11. Then stage 0 of the first model's part is reset.
void Object_00120420::func_00123240()
{
    unsigned int first;
    unsigned int last;
    if (step == 8) {
        first = 0x6d;
        last = 0x7b;
    } else {
        first = 0x5e;
        last = 0x6c;
    }
    unsigned int i;
    int j;
    for (i = first, j = 0; i <= last; j++, i++) {
        if (shown[i]) {
            Entry_00123240 *entry = &entries[j];
            func_001BA9C0();
            if (entry->glyph >= 0) {
                unsigned int index = entry->glyph;
                if (index < 0x5e) {
                    if (entry->kind == 1) {
                        index += 0x38;
                    } else if (entry->kind == 2) {
                        if (entry->glyph == 0x3d) {
                            index = 0x94;
                        }
                        if (entry->glyph == 0x3e) {
                            index = 0x95;
                        }
                        if (entry->glyph == 0x3f) {
                            index = 0x96;
                        }
                        if (entry->glyph == 0x40) {
                            index = 0x97;
                        }
                        if (entry->glyph == 0x41) {
                            index = 0x98;
                        }
                    } else if (index == 0x5d) {
                        index = 0x5b;
                    }
                } else {
                    index += 0x3b;
                }
                data_00251D6C->slot33(-11.0f);
                data_002266E0[2] = data_00226058[index].u;
                data_002266E0[5] = data_00226058[index].v;
                models[i]->part->slot12(0, 7);
                models[i]->part->slot14(0, data_002266E0);
                func_001BAA60(x, y, z);
                models[i]->slot5(0, 0);
                models[i]->part->slot13(0);
                data_00251D6C->slot83(0, 0);
                data_00251D6C->slot33(0.0f);
            }
            func_001BAA50();
        }
    }
    models[0]->part->slot12(0, 0);
    models[0]->part->slot13(0);
}
