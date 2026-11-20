// Creates a vertex shader (Direct3D 8's CreateVertexShader: declaration, function, handle, usage).
long __stdcall func_0018FF90(const unsigned long *declaration, const unsigned long *function, unsigned long *handle,
                             unsigned long usage);

// The shader handle at +4 of Object_001E1220.
struct Shader {
    // Writes the vertex declaration for a flexible vertex format (count streams) into declaration.
    long func_00156190(unsigned long format, unsigned long *declaration, unsigned long count);

    unsigned long handle;
};

// A class whose table is at 0x1E1220 (6 slots; set up by 0x14E2F0).
struct Object_001E1220 {
    virtual long __stdcall func_0014E200(const void *iid, void **object);  // slot 0

    long func_0014E240(unsigned long *out, const unsigned long *function);

    Shader shader;
    unsigned long format;
    unsigned long value_0C;
    unsigned long count;
};

// Creates the vertex shader for the function: the format is either a declaration (a pointer) or a flexible vertex
// format, which func_00156190 turns into one. E_INVALIDARG for no function.
long Object_001E1220::func_0014E240(unsigned long *out, const unsigned long *function)
{
    long result = 0x80070057;
    if (function) {
        const unsigned long *declaration;
        unsigned long buffer[20];
        if (format & 0xffff0000) {
            declaration = (const unsigned long *)format;
        } else {
            result = shader.func_00156190(format, buffer, count);
            declaration = buffer;
            if (result < 0)
                return result;
        }
        unsigned long handle = 0;
        result = func_0018FF90(declaration, function, &handle, 0);
        if (result >= 0)
            *out = handle;
    }
    return result;
}
