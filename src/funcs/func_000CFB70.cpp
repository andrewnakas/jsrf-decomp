/* sym: ??0Object_000CFB70@@QAE@PAUObject_000D01A0@@PAUVector3@@H@Z = 0x000CFB70 */
/* sym: ??1Object_000CFB70@@UAE@XZ = 0x000CFC70 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *position, Vector3 *direction);
};

struct Mesh_00017F60;

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_002166DC;

void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
void __fastcall func_0014CD50(Vector3 *out, const Vector3 *in);

// A resource with a COM-style table: slot 2 releases it.
struct Interface_000CFB70 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

// The device in data_00251D6C: slot 54 makes a buffer.
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
    virtual long __stdcall slot54(int kind, unsigned long size, unsigned long third, unsigned long flags,
                                  Interface_000CFB70 **buffer);
};

extern Device_00251D6C *data_00251D6C;

// The object func_000D01A0 builds: its position at 0x74.
struct Object_000D01A0 {
    char unknown_00[0x74];
    Vector3 position;
};

// A direction with a spare word.
struct Heading_000CFB70 {
    Vector3 vector;
    float w;
};

// One of the ten entries at 0x1c40 (0x24 bytes each).
struct Entry_000CFB70 {
    int kind;
    int size;
    Mesh_00017F60 *item;
    int value_0c;
    char unknown_10[0x14];
};

// A part of func_000D01A0's object (table 0x1CE3F8, destructor func_000CFC70): slot 0 is the destructor.
struct Object_000CFB70 {
    Object_000CFB70(Object_000D01A0 *owner, Vector3 *direction, int angle);
    virtual ~Object_000CFB70();

    Vector3 position;
    char unknown_0010[0x1c14];
    Vector3 direction;
    int value_1c30;
    int angle;
    int key;
    Object_000D01A0 *owner;
    Entry_000CFB70 entries[10];
    Interface_000CFB70 *resource;
};

// Starts at the owner's position (0x74) with the direction normalised (func_0014C410) and the angle; makes the ten
// entries' items from the mesh at data_002166DC (func_00019680) and a buffer (device slot 54, 0x4b0 bytes); tells
// node 0xe8 about it (kind 0x83, func_000651E0) and keeps the answer at 0x1c38.
Object_000CFB70::Object_000CFB70(Object_000D01A0 *owner, Vector3 *direction, int angle)
{
    this->owner = owner;
    position = owner->position;
    func_0014C410(&this->direction, direction);
    value_1c30 = 0;
    this->angle = angle;
    for (int i = 0; i < 10; i++) {
        entries[i].item = data_0022FCE8.func_00019680(&data_002166DC);
        entries[i].kind = 0x10;
        entries[i].size = 0x400;
        entries[i].value_0c = 0;
    }
    data_00251D6C->slot54(0x142, 0x4b0, 0, 0, &resource);
    Heading_000CFB70 heading;
    func_0014CD50(&heading.vector, direction);
    Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (node) {
        key = node->func_000651E0(0x83, &position, &heading.vector);
    }
}
