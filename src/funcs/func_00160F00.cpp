/* sym: ??0exception@@QAE@ABV0@@Z = 0x0017D643 */
/* sym: ??1exception@@UAE@XZ = 0x0017D692 */
/* sym: ?func_0017D6A8@logic_error@std@@UBEPBDXZ = 0x001608A0 */
/* sym: ??_7type_info@@6B@ = 0x001E42A0 */
/* sym: ??0logic_error@std@@QAE@ABUString@@@Z = 0x00160E20 */
/* sym: ??0logic_error@std@@QAE@ABV01@@Z = 0x00160F80 */
extern "C" unsigned int __cdecl strlen(const char *text);
void __cdecl operator delete(void *memory) throw();

// A std::string: the characters live in the 16-byte buffer while they fit (fewer than 16 reserved).
struct String {
    String(const char *text)
    {
        tidy();
        func_00160B90(text, strlen(text));
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
    String &func_00160B90(const char *text, unsigned int size);

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
    exception(const exception &other);
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
    logic_error(const logic_error &other);
    virtual ~logic_error()
    {
    }
    virtual const char *func_0017D6A8() const;

private:
    String message;
};

class length_error : public logic_error {
public:
    length_error(const String &message) : logic_error(message)
    {
    }
};

}

// The vector of registered objects (0x161780 adds to it): a std::vector of pointers.
struct RegisteredList {
    void func_00160F00() const;
};

// Throws std::length_error("vector<T> too long"): the vector cannot grow that far.
void RegisteredList::func_00160F00() const
{
    throw std::length_error(String("vector<T> too long"));
}
