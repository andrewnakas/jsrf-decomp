// A part of a model entry (0x20 bytes): a link at +0x1c, stored as an offset (-1 and 0xcdcdcdcd mean none).
struct Part_0006E970 {
    char unknown_00[0x1c];
    int link;
};

// What the first pointer of an entry points at: two more pointers at +0x0 and +0x10.
struct Mesh_0006E970 {
    int first;
    char unknown_04[0xc];
    int second;
};

// An entry of a model file (0x80 bytes); its pointers are stored as offsets from the first entry.
struct Entry_0006E970 {
    Mesh_0006E970 *mesh;
    int second;
    char unknown_08[0x58];
    int third;
    int fourth;
    char unknown_68[8];
    Part_0006E970 *parts;
    unsigned int partCount;
    char unknown_78[8];
};

// The header of a model file (0x10 bytes, the entries follow it): the entry count at +0x4.
struct Header_0006E970 {
    char unknown_00[4];
    unsigned int count;
    char unknown_08[8];
};

// Turns the offsets of every entry of a model file into pointers (from `entries`, the first entry): the mesh and its
// two pointers, the words at +0x4, +0x60 and +0x64, the parts and each part's link (none becomes 0). Its callers push
// both arguments and load no object, and it pops them: it is __stdcall.
void __stdcall func_0006E970(Header_0006E970 *header, Entry_0006E970 *entries)
{
    int base = (int)entries;
    Entry_0006E970 *entry = entries;
    for (unsigned int i = 0; i < header->count; entry++, i++) {
        if (entry->mesh) {
            Mesh_0006E970 *mesh = (Mesh_0006E970 *)((int)entry->mesh + base);
            entry->mesh = mesh;
            mesh->first += base;
            mesh->second += base;
        }
        if (entry->second) {
            entry->second += base;
        }
        if (entry->third) {
            entry->third += base;
        }
        if (entry->fourth) {
            entry->fourth += base;
        }
        if (entry->parts) {
            entry->parts = (Part_0006E970 *)((int)entry->parts + base);
            for (unsigned int j = 0; j < entry->partCount; j++) {
                if (entry->parts[j].link == -1) {
                    entry->parts[j].link = 0;
                } else if (entry->parts[j].link == 0xcdcdcdcd) {
                    entry->parts[j].link = 0;
                } else if (entry->parts[j].link) {
                    entry->parts[j].link += base;
                }
            }
        }
    }
}
