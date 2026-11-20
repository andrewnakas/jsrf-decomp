// A direct child of Node (constructor func_0010E8F0, table 0x1D23F0); its slot 1 (func_0010EB10) runs the
// handlers of data_002216E0 by the mode at 0x160.
struct Object_0010E8F0 {
    char unknown_00[0x80];
    float frames;
    float seconds;

    void func_0010F3F0();
};

// Entries 0, 1, 4, 5 and 6 of data_002216E0: converts the frame count at 0x80 to seconds at 60 frames per second.
void Object_0010E8F0::func_0010F3F0()
{
    seconds = frames * 0.016666668f;
}
