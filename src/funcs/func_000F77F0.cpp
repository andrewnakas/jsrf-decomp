// A screen vertex (0x18 bytes).
struct Vertex_000F7990 {
    float x;
    float y;
    char unknown_08[0x10];
};

// Object 0x1164 (constructor func_000F7990, table 0x1CF338): two strips of four vertices at 0x4c and 0xac and the
// layout at 0x10c.
struct Object_000F7990 {
    char unknown_000[0x4c];
    Vertex_000F7990 top[4];
    Vertex_000F7990 bottom[4];
    int mode;

    void func_000F77F0();
};

// Called by the constructor: the screen corners (640 x 480) for both strips; layout 0 closes the top strip at 0 and the
// bottom one at 480, layout 1 leaves bands 0-100 and 380-480, layout 2 meets both at 240.
void Object_000F7990::func_000F77F0()
{
    top[0].x = 0.0f;
    top[0].y = 0.0f;
    top[1].x = 640.0f;
    top[1].y = 0.0f;
    bottom[2].x = 0.0f;
    bottom[2].y = 480.0f;
    bottom[3].x = 640.0f;
    bottom[3].y = 480.0f;
    switch (mode) {
    case 0:
        top[2].y = 0.0f;
        top[3].y = 0.0f;
        bottom[0].y = 480.0f;
        bottom[1].y = 480.0f;
        top[2].x = 0.0f;
        bottom[0].x = 0.0f;
        top[3].x = 640.0f;
        bottom[1].x = 640.0f;
        break;
    case 1:
        top[2].y = 100.0f;
        top[3].y = 100.0f;
        top[2].x = 0.0f;
        bottom[0].x = 0.0f;
        bottom[0].y = 380.0f;
        bottom[1].y = 380.0f;
        top[3].x = 640.0f;
        bottom[1].x = 640.0f;
        break;
    case 2:
        top[2].y = 240.0f;
        top[3].y = 240.0f;
        bottom[0].y = 240.0f;
        bottom[1].y = 240.0f;
        top[2].x = 0.0f;
        bottom[0].x = 0.0f;
        top[3].x = 640.0f;
        bottom[1].x = 640.0f;
        break;
    }
}
