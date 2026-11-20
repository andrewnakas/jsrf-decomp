/* const: 0xa2078 */
struct Interface;

// The device (the object at 0x265110); slot 55 makes a vertex shader (format, function, kind, object).
struct Interface_00265110 {
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
    virtual void __stdcall slot33();
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
    virtual long __stdcall slot55(unsigned long format, const unsigned long *function, unsigned long kind,
                                  Interface **object);
};

// The vertex shader made here.
extern Interface *data_0026514C;

// Makes the vertex shader data_0026514C on object for vertices with a position and a normal (format 0x12) from a
// built-in program: a header word and ten four-word instructions.
long func_0015AE80(Interface_00265110 *object)
{
    unsigned long program[41] = {
        0x000A2078,
        0x00000000, 0x00AC821B, 0x0836186C, 0x28200FF8,
        0x00000000, 0x038CA000, 0x24001800, 0x3F30F81C,
        0x00000000, 0x004CA01B, 0x34AA186C, 0x2F400FF8,
        0x00000000, 0x008C801B, 0x4436186C, 0x2F500FF8,
        0x00000000, 0x00EC001B, 0x5436186C, 0x20708800,
        0x00000000, 0x00EC201B, 0x5436186C, 0x20704800,
        0x00000000, 0x00EC401B, 0x5436186C, 0x20702800,
        0x00000000, 0x00EC601B, 0x5436186C, 0x20701800,
        0x00000000, 0x0647401B, 0xC4361BFF, 0x1078E800,
        0x00000000, 0x0087601B, 0xC400286C, 0x3070E801
    };
    return object->slot55(0x12, program, 1, &data_0026514C);
}
