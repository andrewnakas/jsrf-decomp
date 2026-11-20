struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    Node *func_00011BD0();
};

struct Object_000A1C50 {
    char unknown_000[0xca4];
    Vector3 position;
};

struct Object_000A4D80 {
    char unknown_000[0x1f0];
    Vector3 anchor;
    char unknown_1fc[0x1c];
    Vector3 focus;

    void func_000A4840();
};

// A handler (entry 11) of the member-function table at data_002155AC: takes the player's position (+0xca4)
// 14 units up as the anchor (+0x1f0) and the focus (+0x218).
void Object_000A4D80::func_000A4840()
{
    Object_000A1C50 *player = (Object_000A1C50 *)((Node *)this)->func_00011BD0();
    anchor = player->position;
    anchor.y += 14.0f;
    focus = anchor;
}
