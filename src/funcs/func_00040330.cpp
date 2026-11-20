/* sym: ??0Object_0003ED40@@QAE@PAUNode@@HIHHPAUInfo_00040330@@@Z = 0x00040330 */
/* sym: ??1Object_0003ED40@@UAE@XZ = 0x0003ED40 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    char unknown_34[0x10];
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Info_000B9E70;

// Object 0xeb (constructor func_000BB1A0, destructor func_000BAC20).
struct Object_000BAC20 {
    int func_000BAC30(Info_000B9E70 *info, int value, int unused1, int unused2);
};

int func_0003FE20(Node *owner, int first, int second, int third, int fourth);

// An entry of the list the constructor is given: its kind and two values.
struct Record_00040330 {
    int kind;
    int unknown_04;
    int unknown_08;
};

// What the constructor is given last: a list of entries (+0x0) and its count (+0x4).
struct Info_00040330 {
    Record_00040330 *records;
    unsigned int count;
};

// What the object keeps for each entry: its kind and the id made for it.
struct Entry_00040330 {
    int kind;
    int id;
};

// The node class whose table at 0x1CA510 repeats Node's slots 1 to 15.
struct Object_0003ED40 : Node {
    Object_0003ED40(Node *owner, int id, unsigned int flags, int first, int second, Info_00040330 *info);
    virtual ~Object_0003ED40();

    int first;
    int second;
    Info_00040330 *info;
    Entry_00040330 *entries;
    unsigned int count;
};

// Keeps the arguments at +0x44, and makes an entry (+0x50) for each of the info's records: kind 0 through
// func_0003FE20, kinds 1 and 2 through func_000BAC30 of a new object 0xeb (given the record's +0x8 by address).
Object_0003ED40::Object_0003ED40(Node *owner, int id, unsigned int flags, int first, int second, Info_00040330 *info)
    : Node(owner, id, flags)
{
    this->first = first;
    this->second = second;
    this->info = info;
    count = info->count;
    entries = new Entry_00040330[count];
    for (unsigned int i = 0; i < count; i++) {
        switch (this->info->records[i].kind) {
        case 0:
            entries[i].kind = 0;
            entries[i].id = func_0003FE20(this, this->first, this->second, this->info->records[i].unknown_04,
                                          this->info->records[i].unknown_08);
            break;
        case 1: {
            Object_000BAC20 *object = (Object_000BAC20 *)data_0022FCE0->func_000128C0(0xeb);
            if (object) {
                int value = this->info->records[i].unknown_08;
                entries[i].kind = 1;
                entries[i].id = object->func_000BAC30((Info_000B9E70 *)&value, this->second,
                                                      this->info->records[i].unknown_04, -1);
            }
            break;
        }
        case 2: {
            Object_000BAC20 *object = (Object_000BAC20 *)data_0022FCE0->func_000128C0(0xeb);
            if (object) {
                int value = this->info->records[i].unknown_08;
                entries[i].kind = 2;
                entries[i].id = object->func_000BAC30((Info_000B9E70 *)&value, this->second,
                                                      this->info->records[i].unknown_04, -1);
            }
            break;
        }
        }
    }
}
