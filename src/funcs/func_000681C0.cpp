/* const: 0x10003 */
struct Node;
struct Info_00047080;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

/* sym: ??0Object_00067980@@QAE@PAUNode@@HIHPAUInfo_00047080@@@Z = 0x00067B60 */

// The node 0x12af (table 0x1CB0F8, destructor 0x67980): a child of Object_00012170, 0x6bc bytes.
struct Object_00067980 {
    Object_00067980(Node *owner, int id, unsigned int flags, int value, Info_00047080 *info);

    char unknown_000[0x6bc];
};

// Unless node 0x12af exists: makes it under node 0 (flags 0x10003) with the value and the record (or none).
void func_000681C0(int value, int info)
{
    if (!data_0022FCE0->func_000128C0(0x12af)) {
        new Object_00067980((Node *)data_0022FCE0->func_000128C0(0), 0x12af, 0x10003, value, (Info_00047080 *)info);
    }
}
