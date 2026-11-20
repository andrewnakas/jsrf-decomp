void *func_00025700(unsigned int kind, int first, int second, int third);
void *operator new(unsigned int size);

struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

// A track of an effect's data: how many keys it has at +0x4.
struct Track_0006CF80 {
    int unknown_00;
    unsigned int count;
};

// What func_00025700 (8) gives for an effect: per variant (+0x4) a count (+0xc) and a flag (+0x20), the list at
// +0xa4, four tracks at +0xa8, four words at +0xb8 and one at +0xc8.
struct Data_0006CF80 {
    int unknown_00;
    int variant;
    int unknown_08;
    unsigned int counts[5];
    int flags[0x21];
    int *list;
    Track_0006CF80 *tracks[4];
    int values[4];
    int unknown_c8;
};

struct Object_0006CEE0 : Node {
    char unknown_044[8];
    int kind;
    char unknown_050[0xc];
    Data_0006CF80 *data;
    unsigned int count;
    int *list;
    char unknown_068[8];
    int unknown_070;
    char unknown_074[0xc];
    Track_0006CF80 *tracks[4];
    int values[4];
    char unknown_0a0[0x28];
    float lengths[4];
    char unknown_0d8[0x80];
    int unknown_158;

    void func_0006CF80();
};

// Takes the effect's data (func_00025700 (8, +0x4c)), copies the list of its variant's count, its first flag word
// when the variant's flag is set, its four tracks with their key counts as floats and four words, and the word at
// +0xc8.
void Object_0006CEE0::func_0006CF80()
{
    Data_0006CF80 *data = (Data_0006CF80 *)func_00025700(8, kind, 0, 0);
    this->data = data;
    count = data->counts[data->variant];
    if (count) {
        list = (int *)operator new(count * 4);
        for (unsigned int i = 0; i < count; i++) {
            list[i] = data->list[i];
        }
    }
    if (data->flags[data->variant]) {
        unknown_070 = data->flags[0];
    }
    tracks[0] = data->tracks[0];
    lengths[0] = (float)data->tracks[0]->count;
    values[0] = data->values[0];
    tracks[1] = data->tracks[1];
    lengths[1] = (float)data->tracks[1]->count;
    values[1] = data->values[1];
    tracks[2] = data->tracks[2];
    lengths[2] = (float)data->tracks[2]->count;
    values[2] = data->values[2];
    tracks[3] = data->tracks[3];
    lengths[3] = (float)data->tracks[3]->count;
    values[3] = data->values[3];
    unknown_158 = data->unknown_c8;
}
