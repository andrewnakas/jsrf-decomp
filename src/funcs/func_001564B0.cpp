/* const: 0x40300 */
/* const: 0x40304 */
/* const: 0x40310 */
/* const: 0x4033c */
/* const: 0x40340 */
/* const: 0x40344 */
/* const: 0x40348 */
/* const: 0x40350 */
/* const: 0x40354 */
/* const: 0x40360 */
/* const: 0x40364 */
/* const: 0x40368 */
/* const: 0x4036c */
/* const: 0x40374 */
/* const: 0x40378 */
/* const: 0x4037c */
/* const: 0x4035c */
void __fastcall func_0018E930(unsigned long method, unsigned long value);
void __stdcall func_0018EB00(unsigned long value);
void __stdcall func_0018EB80(unsigned long value);
void __stdcall func_0018EBD0(unsigned long value);
void __stdcall func_0018EC80(unsigned long value);
void __stdcall func_0018ECC0(unsigned long value);
void __stdcall func_0018ED20(unsigned long value);
void __stdcall func_0018EE10(unsigned long value);
void __stdcall func_0018EEF0(unsigned long value);
void __stdcall func_0018F010(int enable);
void __stdcall func_0018F060(unsigned long first, unsigned long second);
void __stdcall func_0018F180(unsigned long stage, int type, unsigned long value);
void __stdcall func_0018F230(unsigned long stage, unsigned long value);
void __stdcall func_0018F6C0(unsigned long value);
void __stdcall func_0018F760(unsigned long value);
void __stdcall func_0018F7F0(unsigned long value);

// Direct3D's state: the dirty flags, the texture-stage state table (4 stages of 32 entries) and the render-state
// table.
extern unsigned long data_0019DED8;
extern unsigned long data_0019DEE0[4][32];
extern unsigned long data_0019E0E0[];

extern unsigned char data_0026509C;
extern unsigned long data_002650B0;

// What the device is set up with (0x38 bytes, kept at +0xA8): the word at +4, the size at +8 and the rest.
struct Params {
    unsigned long unknown_00;
    unsigned long value_04;
    unsigned long width;
    unsigned long height;
    unsigned long unknown_10[10];
};

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
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
    virtual long __stdcall func_00154420(int state, const void *matrix);  // slot 27

    long func_001564B0(const Params *params);
    long func_00151130(void *parameters);

    char unknown_04[0x84];
    unsigned long value_88;
    char unknown_8C[0xC];
    unsigned long value_98;
};

// A render state sent to the graphics processor at once (method) and kept in the table.
static inline void SendState(int state, unsigned long method, unsigned long value)
{
    func_0018E930(method, value);
    data_0019E0E0[state] = value;
}

// A render state kept in the table until the next draw; it marks its dirty flags.
static inline void MarkState(int state, unsigned long flags, unsigned long value)
{
    data_0019DED8 |= flags;
    data_0019E0E0[state] = value;
}

// A texture-stage state kept in the table; it marks its dirty flags.
static inline void MarkStageState(unsigned long stage, int type, unsigned long flags, unsigned long value)
{
    data_0019DED8 |= flags;
    data_0019DEE0[stage][type] = value;
}

static inline unsigned long FloatBits(float value)
{
    return *(unsigned long *)&value;
}

// Part of the device set-up (0x155380): puts every render state, texture-stage state and transform into its
// starting state (stage 0 modulates the texture with the diffuse colour, the others are off), then calls
// func_00151130; its result if negative, else 0.
long Object_001E0F00::func_001564B0(const Params *params)
{
    unsigned long stage;
    func_0018F6C0(params->unknown_10[3]);
    SendState(64, 0x4035C, 1);
    SendState(57, 0x40354, 0x203);
    func_0018EE10(0);
    func_0018EEF0(0x1B02);
    SendState(66, 0x4037C, 0x1D01);
    func_0018EBD0(0x901);
    SendState(65, 0x40310, 1);
    MarkState(93, 0x3000, 0);
    func_0018EB00(0);
    func_0018F010(0);
    MarkState(92, 0x1200, 0);
    MarkState(105, 0x1000, 0);
    MarkState(95, 0x1000, 1);
    MarkState(103, 0x1000, 0);
    MarkState(102, 0x1000, 0);
    MarkState(101, 0x1000, 1);
    if (data_0026509C & 2)
        MarkState(100, 0x1000, 2);
    else
        MarkState(100, 0x1000, 1);
    MarkState(94, 0x1000, 0);
    func_0018EC80(0);
    SendState(59, 0x40304, 0);
    SendState(62, 0x40344, 0x302);
    SendState(63, 0x40348, 0x303);
    func_0018ECC0(0xFFFFFFFF);
    SendState(74, 0x40350, 0x8006);
    SendState(60, 0x40300, 0);
    SendState(61, 0x40340, 0);
    SendState(58, 0x4033C, 0x204);
    MarkState(82, 0x2000, 0);
    func_0018EB80(0xFFFFFF);
    MarkState(87, 0x2000, 0);
    MarkState(83, 0x2000, 3);
    MarkState(86, 0x2000, FloatBits(1.0f));
    MarkState(84, 0x2000, FloatBits(100.0f));
    MarkState(85, 0x2000, FloatBits(500.0f));
    func_0018F760(0);
    if (params->unknown_10[4]) {
        func_0018F7F0(0x1E00);
        SendState(68, 0x40374, 0x1E00);
        SendState(69, 0x40378, 0x1E01);
        SendState(70, 0x40364, 0x207);
        SendState(71, 0x40368, 0);
        SendState(72, 0x4036C, 0xFFFFFFFF);
        SendState(73, 0x40360, 0xFFFFFFFF);
    }
    MarkState(108, 0x900, 0);
    MarkState(109, 0x100, 0);
    MarkState(106, 0x100, FloatBits(1.0f));
    if (value_88) {
        MarkState(107, 0x100, FloatBits(0.0f));
        MarkState(113, 0x100, data_002650B0);
        MarkState(110, 0x100, FloatBits(0.0f));
        MarkState(111, 0x100, FloatBits(0.0f));
        MarkState(112, 0x100, FloatBits(1.0f));
    }
    func_0018ED20(FloatBits(1.0f));
    for (stage = 0; stage < 4; stage++) {
        func_0018F060(stage, stage);
        MarkStageState(stage, 12, 0x800, 1);
        MarkStageState(stage, 16, 0x800, 1);
        MarkStageState(stage, 3, 1 << stage, 2);
        MarkStageState(stage, 4, 1 << stage, 2);
        MarkStageState(stage, 5, 1 << stage, 0);
        MarkStageState(stage, 0, 1 << stage, 1);
        MarkStageState(stage, 1, 1 << stage, 1);
        if (value_98 && stage < 2) {
            func_0018F180(1, 22, FloatBits(1.0f));
            func_0018F180(1, 23, 0);
            func_0018F180(1, 25, 0);
            func_0018F180(1, 24, FloatBits(1.0f));
            func_0018F180(1, 26, FloatBits(1.0f));
            func_0018F180(1, 27, 0);
        }
        MarkStageState(stage, 21, 0x400, 0);
        func_0018F230(stage, 0);
        MarkStageState(stage, 9, 1 << stage, 0);
    }
    MarkStageState(0, 14, 0x800, 2);
    MarkStageState(0, 15, 0x800, 0);
    MarkStageState(0, 12, 0x800, 4);
    MarkStageState(0, 18, 0x800, 2);
    MarkStageState(0, 19, 0x800, 0);
    MarkStageState(0, 16, 0x800, 4);
    for (stage = 0; stage < 4; stage++)
        func_00154420(stage + 6, 0);
    func_00154420(0, 0);
    for (stage = 2; stage < 6; stage++)
        func_00154420(stage + 2, 0);
    func_00154420(0, 0);
    func_00154420(1, 0);
    long result = func_00151130((void *)params);
    return result >= 0 ? 0 : result;
}
