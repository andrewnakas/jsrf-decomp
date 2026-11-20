struct Object_0010F3F0 {
    char unknown_00[0x80];
    float frames;
    float seconds;

    void func_0010F3F0();
};

// Converts a frame count to seconds at 60 frames per second.
void Object_0010F3F0::func_0010F3F0()
{
    seconds = frames * 0.016666668f;
}
