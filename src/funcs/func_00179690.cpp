struct Guid;
struct Unknown;

// The interface the class factories give out (COM's IClassFactory): slot 3 creates an object.
struct ClassFactory {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(Unknown *outer, const Guid &id, void **object);
};

// The interface every object gives out (COM's IUnknown).
struct Object {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The class factory's interface id (IID_IClassFactory).
extern const Guid data_001E4C84;

// Gets MEvent's class factory (0x179610).
long __stdcall func_00179610(const Guid &classId, const Guid &id, void **object);

// Creates an object of the class through its factory and asks it for the interface (the module's own
// CoCreateInstance; the context is not looked at). The factory and the creation reference are let go of.
long __stdcall func_00179690(const Guid &classId, Unknown *outer, unsigned long context, const Guid &id,
                             void **object)
{
    ClassFactory *factory;
    long result = func_00179610(classId, data_001E4C84, (void **)&factory);
    if (result >= 0) {
        Object *instance;
        result = factory->slot3(outer, id, (void **)&instance);
        if (result >= 0) {
            result = instance->slot0(id, object);
            if (instance) {
                instance->slot2();
                instance = 0;
            }
        }
        if (factory)
            factory->slot2();
    }
    return result;
}
