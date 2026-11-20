// Returns the offset just past the first "$r" that ends a string (the bytes '$', 'r', 0) in the text.
int func_000FE690(const char *text)
{
    int i = 0;
    for (;;) {
        if (text[i++] != '$') {
            continue;
        }
        if (text[i++] != 'r') {
            continue;
        }
        if (text[i++] != 0) {
            continue;
        }
        return i;
    }
}
