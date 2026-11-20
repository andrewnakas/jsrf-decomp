void __fastcall func_0018E930(unsigned long method, unsigned long value);
void __stdcall func_0018E8A0(unsigned long value);
void __stdcall func_0018E8D0(unsigned long value);
void __stdcall func_0018E900(unsigned long value);
void __stdcall func_0018EB00(unsigned long value);
void __stdcall func_0018EB40(unsigned long value);
void __stdcall func_0018EB80(unsigned long value);
void __stdcall func_0018EBD0(unsigned long value);
void __stdcall func_0018EC40(unsigned long value);
void __stdcall func_0018EC80(unsigned long value);
void __stdcall func_0018ECC0(unsigned long value);
void __stdcall func_0018ED20(unsigned long value);
void __stdcall func_0018ED90(unsigned long value);
void __stdcall func_0018EE10(unsigned long value);
void __stdcall func_0018EE90(unsigned long value);
void __stdcall func_0018EEF0(unsigned long value);
void __stdcall func_0018EF40(unsigned long value);
void __stdcall func_0018EFA0(unsigned long value);
void __stdcall func_0018F010(int enable);
void __stdcall func_0018F6C0(unsigned long value);
void __stdcall func_0018F760(unsigned long value);
void __stdcall func_0018F7F0(unsigned long value);
void __stdcall func_0018F860(unsigned long value);
void __stdcall func_0018F890(unsigned long value);
void __stdcall func_0018F900(unsigned long value);
void __stdcall func_0018F970(unsigned long value);
void __stdcall func_0018F990(unsigned long value);
void __stdcall func_0018F9B0(unsigned long value);
void __stdcall func_0018F9D0(unsigned long value);
void __stdcall func_0018FA30(unsigned long value);

// Direct3D's state: the dirty flags and the render-state table; for the render states below 0x52 the push-buffer
// method (0x1C4248), for 0x52 to 0x74 the dirty flags they mark (0x1C4070).
extern unsigned long data_0019DED8;
extern unsigned long data_0019E0E0[];
extern const unsigned long data_001C4248[];
extern const unsigned long data_001C4070[];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_001504D0(unsigned long argument1, unsigned long argument2);  // slot 62
};

// Slot 62: sets render state argument1 to argument2. States below 0x52 are sent to the graphics processor at once
// and kept in the render-state table; 0x52 to 0x74 are kept and mark their dirty flags; 0x75 to 0x91 each go to
// their own function. Always 0.
long __stdcall Object_001E0F00::func_001504D0(unsigned long argument1, unsigned long argument2)
{
    int state = (int)argument1;
    unsigned long value = argument2;
    if (state < 0x52) {
        func_0018E930(data_001C4248[state], value);
        data_0019E0E0[state] = value;
    } else if (state < 0x75) {
        data_0019DED8 |= data_001C4070[state];
        data_0019E0E0[state] = value;
    } else if (state == 0x75) {
        func_0018E900(value);
    } else if (state == 0x76) {
        func_0018F010((int)value);
    } else if (state == 0x77) {
        func_0018EB80(value);
    } else if (state == 0x78) {
        func_0018EEF0(value);
    } else if (state == 0x79) {
        func_0018EF40(value);
    } else if (state == 0x7A) {
        func_0018EFA0(value);
    } else if (state == 0x7B) {
        func_0018EC80(value);
    } else if (state == 0x7C) {
        func_0018F6C0(value);
    } else if (state == 0x7D) {
        func_0018F760(value);
    } else if (state == 0x7E) {
        func_0018F7F0(value);
    } else if (state == 0x80) {
        func_0018EBD0(value);
    } else if (state == 0x7F) {
        func_0018EC40(value);
    } else if (state == 0x81) {
        func_0018ECC0(value);
    } else if (state == 0x82) {
        func_0018EE10(value);
    } else if (state == 0x83) {
        func_0018EE90(value);
    } else if (state == 0x84) {
        func_0018EB00(value);
    } else if (state == 0x85) {
        func_0018F9D0(value);
    } else if (state == 0x86) {
        func_0018FA30(value);
    } else if (state == 0x87) {
        func_0018E8A0(value);
    } else if (state == 0x88) {
        func_0018E8D0(value);
    } else if (state == 0x89) {
        func_0018EB40(value);
    } else if (state == 0x8A) {
        func_0018ED20(value);
    } else if (state == 0x8B) {
        func_0018ED90(value);
    } else if (state == 0x8C) {
        func_0018F860(value);
    } else if (state == 0x8D) {
        func_0018F890(value);
    } else if (state == 0x8E) {
        func_0018F900(value);
    } else if (state == 0x8F) {
        func_0018F970(value);
    } else if (state == 0x90) {
        func_0018F990(value);
    } else if (state == 0x91) {
        func_0018F9B0(value);
    }
    return 0;
}
