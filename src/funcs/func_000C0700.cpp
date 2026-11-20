/* sym: ??0Object_000C3BE0@@QAE@XZ = 0x000C3B60 */
/* sym: ??0Object_000C39E0@@QAE@PAUNode@@HIPAUData_000C2700@@@Z = 0x000C3860 */
struct Node;
struct Data_000C2700;

struct Game {
    int func_000128E0(int first, int last);
};

extern Game *data_0022FCE0;

// The object in data_00257CEC (table 0x1CDDA0: only the destructor; 0xcc bytes).
struct Object_000C3BE0 {
    Object_000C3BE0();
    virtual ~Object_000C3BE0();

    char unknown_04[0xc8];
};

extern Object_000C3BE0 *data_00257CEC;

// The node func_000C3860 builds (0x4c bytes).
struct Object_000C39E0 {
    Object_000C39E0(Node *owner, int id, unsigned int flags, Data_000C2700 *data);

    char unknown_00[0x4c];
};

// The object of 0x59F30 calls this with itself in ecx; it does not use it.
struct Object_000C0700 {
    int func_000C0700(Node *owner, Data_000C2700 *data);
};

// Makes the shared data_00257CEC on first use, then an Object_000C39E0 under the owner with a free id in
// 0x12b2..0x13b2, and returns the id.
int Object_000C0700::func_000C0700(Node *owner, Data_000C2700 *data)
{
    if (data_00257CEC == 0) {
        data_00257CEC = new Object_000C3BE0;
    }
    int id = data_0022FCE0->func_000128E0(0x12b2, 0x13b2);
    new Object_000C39E0(owner, id, 0, data);
    return id;
}
