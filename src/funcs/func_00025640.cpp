extern "C" char *strcpy(char *destination, const char *source);

int __stdcall func_00146949(const char *path, void *attributes);

struct Object_000265A0 {
    void func_00025640(const char *path);
};

// Called with "D:\Media\..." paths: copies the path, puts drive Z in place of its first letter and passes it to the
// library function at 0x146949 (with 0).
void Object_000265A0::func_00025640(const char *path)
{
    char copy[0x104];
    strcpy(copy, path);
    copy[0] = 'Z';
    func_00146949(copy, 0);
}
