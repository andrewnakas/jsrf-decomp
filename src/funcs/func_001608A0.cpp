/* sym: ?func_0017D6A8@logic_error@std@@UBEPBDXZ = 0x001608A0 */
// The executable names these classes in its exception type descriptors (".?AVexception@@" at 0x22EA24,
// ".?AVlogic_error@std@@" at 0x22EA3C). std::logic_error's table is at 0x1E18F4; std::length_error's (0x1E194C)
// holds the same two functions.
struct String {
    char allocator;
    union {
        char buffer[16];
        char *pointer;
    } text;
    unsigned int size;
    unsigned int reserved;
};

class exception {
public:
    virtual ~exception();
    virtual const char *func_0017D6A8() const;

private:
    const char *message;
    int ownsMessage;
};

namespace std {

class logic_error : public exception {
public:
    virtual ~logic_error();
    virtual const char *func_0017D6A8() const;

private:
    String message;
};

// Slot 1 (what): the message's characters, kept in the string's own buffer while they fit in 16 bytes.
const char *logic_error::func_0017D6A8() const
{
    return message.reserved >= 16 ? message.text.pointer : message.text.buffer;
}

}
