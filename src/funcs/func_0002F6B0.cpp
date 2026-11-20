struct Motion_0006EB20;
struct Header_0006EA40;

void __stdcall func_0006EB20(Motion_0006EB20 *motion);
void __stdcall func_0006EA40(Header_0006EA40 *header);

// One part of a loaded file: where its data is (from the file's start), where the next part is, and its size.
struct Part_0002EC50 {
    int offset;
    int next;
    unsigned int size;
};

// A loaded file: its part count at +4 and its first part at +0x10.
struct File_0002EC50 {
    int unknown_00;
    unsigned int count;
    char unknown_08[8];
    Part_0002EC50 first;
};

struct Object_000265A0 {
    void func_0002F6B0(void *data, void **misc);
};

// Walks the misc file `data`: each part of its part 0 (at most 9) is set up by func_0006EA40 and kept in misc[55 + j];
// each part of its part 1 (at most 5) is a motion (past an 8-byte header) set up by func_0006EB20 and kept in
// misc[64 + j]. Empty parts are skipped.
void Object_000265A0::func_0002F6B0(void *data, void **misc)
{
    File_0002EC50 *file = (File_0002EC50 *)data;
    Part_0002EC50 *part = &file->first;
    for (unsigned int i = 0; i < file->count; i++) {
        switch (i) {
        case 0:
            if (part->size) {
                File_0002EC50 *sub = (File_0002EC50 *)((char *)file + part->offset);
                Part_0002EC50 *entry = &sub->first;
                for (unsigned int j = 0; j < sub->count; j++) {
                    if (j >= 9)
                        break;
                    if (entry->size) {
                        Header_0006EA40 *header = (Header_0006EA40 *)((char *)sub + entry->offset);
                        func_0006EA40(header);
                        misc[55 + j] = header;
                    }
                    entry = (Part_0002EC50 *)((char *)sub + entry->next);
                }
            }
            break;
        case 1:
            if (part->size) {
                File_0002EC50 *sub = (File_0002EC50 *)((char *)file + part->offset);
                Part_0002EC50 *entry = &sub->first;
                for (unsigned int j = 0; j < sub->count; j++) {
                    if (j >= 5)
                        break;
                    if (entry->size) {
                        Motion_0006EB20 *motion = (Motion_0006EB20 *)((char *)sub + entry->offset + 8);
                        func_0006EB20(motion);
                        misc[64 + j] = motion;
                    }
                    entry = (Part_0002EC50 *)((char *)sub + entry->next);
                }
            }
            break;
        }
        part = (Part_0002EC50 *)((char *)file + part->next);
    }
}
