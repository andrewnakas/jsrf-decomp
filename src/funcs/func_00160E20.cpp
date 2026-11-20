/* sym: ??0exception@@QAE@XZ = 0x0017D632 */
/* sym: ??1exception@@UAE@XZ = 0x0017D692 */
/* sym: ?func_0017D6A8@logic_error@std@@UBEPBDXZ = 0x001608A0 */
/* sym: ??0logic_error@std@@QAE@ABUString@@@Z = 0x00160E20 */
void __cdecl operator delete(void *memory) throw();

// A std::string: the characters live in the 16-byte buffer while they fit (fewer than 16 reserved).
struct String {
    String(const String &other)
    {
        tidy();
        func_00160AE0(other, 0, 0xFFFFFFFF);
    }
    ~String()
    {
        if (reserved >= 16)
            operator delete(text.pointer);
        tidy();
    }
    char *pointer()
    {
        return reserved >= 16 ? text.pointer : text.buffer;
    }
    void tidy()
    {
        reserved = 15;
        pointer()[size = 0] = 0;
    }
    String &func_00160AE0(const String &other, unsigned int position, unsigned int count);

    char allocator;
    union {
        char buffer[16];
        char *pointer;
    } text;
    unsigned int size;
    unsigned int reserved;
};

// The executable names these classes in its exception type descriptors (".?AVexception@@" at 0x22EA1C,
// ".?AVlogic_error@std@@" at 0x22EA34, ".?AVlength_error@std@@" at 0x22EA54). exception is the C runtime's
// (0x17D632 ...); std::logic_error's table is at 0x1E18F4, std::length_error's at 0x1E194C.
class exception {
public:
    exception();
    virtual ~exception();
    virtual const char *func_0017D6A8() const;

private:
    const char *message;
    int ownsMessage;
};

namespace std {

class logic_error : public exception {
public:
    logic_error(const String &message);
    virtual ~logic_error()
    {
    }
    virtual const char *func_0017D6A8() const;

private:
    String message;
};

// Constructor: copies the message (0x160AE0).
logic_error::logic_error(const String &message) : message(message)
{
}

}
