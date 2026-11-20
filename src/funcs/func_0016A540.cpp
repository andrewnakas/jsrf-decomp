// The objects in the voices' lists (the class whose table is at 0x1E3B00).
struct Buffer;

// Copies the pointers from `first` up to `last` to `destination` and returns the end of the copy (the list's
// assignment 0x16AAD0 calls it).
Buffer **func_0016A540(Buffer **first, Buffer **last, Buffer **destination)
{
    for (; first != last; ++destination, ++first)
        *destination = *first;
    return destination;
}
