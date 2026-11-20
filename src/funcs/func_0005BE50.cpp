// A part of a frame (0x20 bytes): two words handed to the surface, its texture at +0xc.
struct Part_0005BE50 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    unsigned int texture;
    char unknown_10[0x10];
};

// A frame (0x6c bytes): its word, its parts and their count.
struct Frame_000479D0 {
    int unknown_00;
    char unknown_04[8];
    Part_0005BE50 *parts;
    unsigned int count;
    char unknown_14[0x58];
};

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
    virtual void __stdcall slot81(int stage, int texture);
};

extern Device_00251D6C *data_00251D6C;

struct Surface_0005BE50 {
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
    virtual void __stdcall slot22(int frame, int first, int second);
};

struct Object_00047470 {
    virtual ~Object_00047470();

    Surface_0005BE50 *surface;
    char unknown_08[0x1c];
    unsigned int flags;

    int func_000476C0(unsigned int texture);
};

int func_0005BCE0(unsigned int flags, Frame_000479D0 *frame);

// Parts drawn, and the texture last given to the device.
extern int data_00251D40;
extern int data_00251D54;

// Handler 0 of 0x1FA1B0: when func_0005BCE0 lets the frame through, counts and draws each part: its texture
// (func_000476C0) to stage 0 of the device when it changed, then slot 22 of the surface with the frame's word and the
// part's two words.
void func_0005BE50(Object_00047470 *object, Frame_000479D0 *frame)
{
    if (func_0005BCE0(object->flags, frame)) {
        Part_0005BE50 *part = frame->parts;
        for (unsigned int i = 0; i < frame->count; part++, i++) {
            data_00251D40++;
            if (data_00251D54 != object->func_000476C0(part->texture)) {
                data_00251D54 = object->func_000476C0(part->texture);
                data_00251D6C->slot81(0, object->func_000476C0(part->texture));
            }
            object->surface->slot22(frame->unknown_00, part->unknown_00, part->unknown_04);
        }
    }
}
