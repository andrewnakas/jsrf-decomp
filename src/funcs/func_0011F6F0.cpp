struct Object_0011F530 {
    void func_0011F6F0(const char *text, char *out);
};

// Copies a text without its "$n" sequences.
void Object_0011F530::func_0011F6F0(const char *text, char *out)
{
    int length = 0;
    int skip = 0;
    while (*text) {
        if (text[skip] == '$' && text[skip + 1] == 'n') {
            skip += 2;
        } else {
            out[length] = text[skip];
            length++;
            text++;
        }
    }
    out[length] = 0;
}
