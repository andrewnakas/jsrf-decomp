// Direct3D's state: the dirty flags and the texture-stage state table (4 stages of 32 entries, just below the
// render-state table at 0x19E0E0).
extern unsigned long data_0019DED8;
extern unsigned long data_0019DEE0[4][32];

// A stage's colour and alpha operations with their arguments (entries 12, 14, 15, 16, 18 and 19 of the stage).
struct Blend {
    unsigned long colorArgument1;
    unsigned long colorArgument2;
    unsigned long colorOperation;
    unsigned long alphaArgument1;
    unsigned long alphaArgument2;
    unsigned long alphaOperation;
};

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014FEF0(unsigned long argument1, unsigned long argument2);  // slot 82
};

// Keeps one texture-stage state and marks it dirty; colour operations from 0x19 on mark more.
static inline void MarkColorOperation(unsigned long stage, unsigned long operation)
{
    data_0019DED8 |= operation < 0x19 ? 0x800 : 0x480F;
    data_0019DEE0[stage][12] = operation;
}

static inline void MarkStageState(unsigned long stage, unsigned long state, unsigned long value)
{
    data_0019DED8 |= 0x800;
    data_0019DEE0[stage][state] = value;
}

// Slot 82: sets the colour and alpha blending of stage argument1 (entries 12 to 19 of its texture-stage states)
// from one of ten presets (argument2 0 to 9) or, for anything larger, from the Blend argument2 points at. The
// second arguments of the presets are 0 for stage 0 and 1 for the others.
long __stdcall Object_001E0F00::func_0014FEF0(unsigned long argument1, unsigned long argument2)
{
    unsigned long stage = argument1;
    unsigned long previous = stage != 0;
    switch (argument2) {
    case 0:
        MarkColorOperation(stage, 1);
        MarkStageState(stage, 16, 1);
        return 0;
    case 1:
        MarkColorOperation(stage, 4);
        MarkStageState(stage, 14, 2);
        MarkStageState(stage, 15, previous);
        MarkStageState(stage, 16, 3);
        MarkStageState(stage, 19, previous);
        return 0;
    case 2:
        MarkColorOperation(stage, 4);
        MarkStageState(stage, 14, 2);
        MarkStageState(stage, 15, previous);
        MarkStageState(stage, 16, 4);
        MarkStageState(stage, 18, 2);
        MarkStageState(stage, 19, previous);
        return 0;
    case 3:
        MarkColorOperation(stage, 7);
        MarkStageState(stage, 14, 2);
        MarkStageState(stage, 15, previous);
        MarkStageState(stage, 16, 3);
        MarkStageState(stage, 19, previous);
        return 0;
    case 4:
        MarkColorOperation(stage, 7);
        MarkStageState(stage, 14, 2);
        MarkStageState(stage, 15, previous);
        MarkStageState(stage, 16, 7);
        MarkStageState(stage, 18, 2);
        MarkStageState(stage, 19, previous);
        return 0;
    case 5:
        MarkColorOperation(stage, 2);
        MarkStageState(stage, 14, 2);
        MarkStageState(stage, 16, 2);
        MarkStageState(stage, 18, 2);
        return 0;
    case 6:
        MarkColorOperation(stage, 0xE);
        MarkStageState(stage, 14, 2);
        MarkStageState(stage, 15, previous);
        MarkStageState(stage, 16, 3);
        MarkStageState(stage, 19, previous);
        return 0;
    case 7:
        MarkColorOperation(stage, 0x1A);
        MarkStageState(stage, 14, 2);
        MarkStageState(stage, 15, previous);
        MarkStageState(stage, 16, 3);
        MarkStageState(stage, 19, previous);
        return 0;
    case 8:
        MarkColorOperation(stage, 0xF);
        MarkStageState(stage, 14, 2);
        MarkStageState(stage, 15, previous);
        MarkStageState(stage, 16, 3);
        MarkStageState(stage, 19, previous);
        return 0;
    case 9:
        MarkColorOperation(stage, 0xF);
        MarkStageState(stage, 14, 2);
        MarkStageState(stage, 15, previous);
        MarkStageState(stage, 16, 0xF);
        MarkStageState(stage, 18, 2);
        MarkStageState(stage, 19, previous);
        return 0;
    }
    const Blend *blend = (const Blend *)argument2;
    MarkColorOperation(stage, blend->colorOperation);
    MarkStageState(stage, 14, blend->colorArgument1);
    MarkStageState(stage, 15, blend->colorArgument2);
    MarkStageState(stage, 16, blend->alphaOperation);
    MarkStageState(stage, 18, blend->alphaArgument1);
    MarkStageState(stage, 19, blend->alphaArgument2);
    return 0;
}
