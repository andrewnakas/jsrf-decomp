extern "C" void *memset(void *destination, int value, unsigned int size);

// A vertex and index buffer object (table 0x1E1150): slots 4 and 5 lock and unlock the vertices, 6 and 7 the
// indices.
struct Buffers {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual long __stdcall slot4(void **data, unsigned long flags);
    virtual unsigned long __stdcall slot5();
    virtual long __stdcall slot6(void **data, unsigned long flags);
    virtual unsigned long __stdcall slot7();
};

// The device (the object at 0x265110); slot 54 makes a vertex and index buffer object (0x14D800).
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
    virtual long __stdcall slot54(unsigned long format, unsigned long vertices, unsigned long indices,
                                  unsigned long flags, Buffers **object);
};

extern Interface_00265110 *data_00265110;

// The base of the classes whose tables are at 0x1E1508, 0x1E1538 and 0x1E1568 (created by 0x158A80).
struct Object_001E14D8 {
    virtual long __stdcall slot0();

    long __stdcall func_001585D0(unsigned long first, unsigned long second);

    char unknown_04[0x100];
    Buffers *buffers;
    unsigned long count;
};

// Makes the buffers for count items (kept at +0x104, the count at +0x108) of the kind in the low four bits of
// flags: 0 is count points (format 0x42, 16 bytes), 1 count / 2 rectangles of two triangles and 2 a strip of count
// - 1 of them (format 0x142, 24 bytes each). The vertices are cleared and the indices of the rectangles' triangles
// (0 1 2, 1 3 2) written. Bit 8 of flags goes to the device. E_INVALIDARG for no items.
long __stdcall Object_001E14D8::func_001585D0(unsigned long first, unsigned long second)
{
    if (first) {
        unsigned long format = 0;
        unsigned long stride = 0;
        unsigned long vertices = 0;
        unsigned long indices = 0;
        switch (second & 0xF) {
        case 0:
            format = 0x42;
            stride = 0x10;
            vertices = first;
            indices = 0;
            break;
        case 1:
            format = 0x142;
            stride = 0x18;
            vertices = first * 2;
            indices = ((first + 1) & ~1) * 3;
            break;
        case 2:
            format = 0x142;
            stride = 0x18;
            vertices = (first - 1) * 4;
            indices = (first - 1) * 6;
            break;
        }
        Buffers *object = 0;
        long result = data_00265110->slot54(format, vertices, indices, second & 0x100, &object);
        if (result < 0)
            return result;
        void *data = 0;
        if (object->slot4(&data, 0) >= 0) {
            memset(data, 0, vertices * stride);
            object->slot5();
        }
        if (indices) {
            if (object->slot6(&data, 0) >= 0) {
                unsigned short *index = (unsigned short *)data;
                unsigned long vertex = 0;
                for (unsigned long i = 0; i < indices; i += 6) {
                    index[0] = (unsigned short)vertex;
                    index[1] = (unsigned short)(vertex + 1);
                    index[2] = (unsigned short)(vertex + 2);
                    index[3] = (unsigned short)(vertex + 1);
                    index[4] = (unsigned short)(vertex + 3);
                    index[5] = (unsigned short)(vertex + 2);
                    index += 6;
                    vertex += 4;
                }
                object->slot7();
            }
        }
        buffers = object;
        count = first;
        return 0;
    }
    return 0x80070057;
}
