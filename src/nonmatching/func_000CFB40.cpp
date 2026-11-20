/* fuzzy: 80.0 */
struct Object_000CFB40 {
    char unknown_00[0x70];
    unsigned char flags;

    int func_000CFB40();
};

// True when bit 0 of the flags byte is clear. Retail inverts the byte first and widens it afterwards
// (not al at 0x000CFB43, movzx at 0x000CFB45); this spelling widens first.
int Object_000CFB40::func_000CFB40()
{
    return (unsigned char)~flags & 1;
}
