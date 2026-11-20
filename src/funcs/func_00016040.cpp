/* const: 0x60ae0 */
/* const: 0x2d1e0 */
/* const: 0x13560 */
/* sym: ??0Object_00016200@@QAE@XZ = 0x00016040 */
extern unsigned char data_00231D40[];

struct Item_00016040;
struct Mesh_0001B500;

// The collision world (data_0022FCE8): nine work blocks, a hash of items (+0x84 heads, +0x484 tails), a list at
// +0x884, the hash of deformed meshes (+0x890 heads, +0xc90 tails) and their list (+0x1090), and two cursors into
// 0x231D40.
struct Object_00016200 {
    Object_00016200();
    ~Object_00016200();

    char unknown_0000[0x48];
    void *blocks[4];
    int unknown_58;
    void *block_5c;
    char unknown_0060[0x10];
    void *blocks_70[4];
    int unknown_80;
    Item_00016040 *items[256];
    Item_00016040 **itemTails[256];
    Item_00016040 *head884;
    Item_00016040 **tail884;
    int serial;
    Mesh_0001B500 *meshes[256];
    Mesh_0001B500 **meshTails[256];
    Mesh_0001B500 *head2;
    Mesh_0001B500 **tail2;
    unsigned char *cursor1098;
    char unknown_109c[4];
    int unknown_10a0;
    int unknown_10a4;
    unsigned char *cursor10a8;
};

// Allocates the work blocks and sets up the empty hashes and lists, the serial (1), +0x80 (1), +0x10a0 / +0x10a4
// (16) and both cursors at 0x231D40.
Object_00016200::Object_00016200()
{
    blocks[0] = operator new(0x60ae0);
    blocks[1] = operator new(0x960);
    blocks[2] = operator new(0x2d1e0);
    blocks[3] = operator new(0x12c0);
    blocks_70[0] = operator new(0xce40);
    blocks_70[1] = operator new(0x4b00);
    blocks_70[2] = operator new(0x13560);
    blocks_70[3] = operator new(0x5dc0);
    block_5c = operator new(0xea60);
    for (int i = 0; i < 256; i++) {
        items[i] = 0;
        itemTails[i] = &items[i];
    }
    head884 = 0;
    tail884 = &head884;
    unknown_80 = 1;
    for (int j = 0; j < 256; j++) {
        meshes[j] = 0;
        meshTails[j] = &meshes[j];
    }
    tail2 = &head2;
    head2 = 0;
    serial = 1;
    cursor10a8 = data_00231D40;
    unknown_10a4 = 16;
    unknown_10a0 = 16;
    cursor1098 = data_00231D40;
}
