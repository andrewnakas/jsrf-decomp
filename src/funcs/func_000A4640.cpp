struct Vector3 {
    float x;
    float y;
    float z;
};

// A face: a point on it, its distance and its normal (+0x10).
struct Plane_0007F030 {
    Vector3 point;
    float distance;
    Vector3 normal;
};

float __fastcall func_0014BD00(Vector3 *out, const Vector3 *point, const Plane_0007F030 *plane);
void __fastcall func_0014C340(Vector3 *vector, const Vector3 *offset);

struct Node {
    Node *func_00011BD0();
};

// The player (only the fields used here).
struct Object_000A1C50 {
    char unknown_0000[0xca4];
    Vector3 position;
    char unknown_0cb0[0x21c];
    int mode;
    Vector3 point;
    Plane_0007F030 plane;
    char unknown_0ef8[4];
    float rate;
};

// The camera (only the fields this handler uses).
struct Object_000A4D80 {
    char unknown_000[0x158];
    Vector3 from;
    float time;
    char unknown_168[0x7c];
    Vector3 target;
    Vector3 anchor;
    char unknown_1fc[0x10];
    Vector3 eye;
    Vector3 focus;

    void func_000A4640();
};

// A handler (entry 10) of the member-function table at data_002155AC: anchors on the player's position 14 units up
// and, by the player's mode at 0xecc, aims at the point at 0xed0 (0), at the foot of the anchor on the player's face
// at 0xedc (1, func_0014BD00), at the position moved by that point (2, func_0014C340), or (3) eases from 0x158 toward
// the point by 1 - (1 - t)^2 of the time at 0x164, which runs up by 1/(60 rate) (rate 0xefc, else 1/60) to 1. Copies
// the anchor to the focus at 0x218 and the target to the eye at 0x20c.
void Object_000A4D80::func_000A4640()
{
    Object_000A1C50 *player = (Object_000A1C50 *)((Node *)this)->func_00011BD0();
    anchor = player->position;
    switch (player->mode) {
    case 0:
        anchor.y += 14.0f;
        target = player->point;
        break;
    case 1:
        anchor.y += 14.0f;
        func_0014BD00(&target, &anchor, &player->plane);
        break;
    case 2:
        target = player->position;
        anchor.y += 14.0f;
        func_0014C340(&target, &player->point);
        break;
    case 3: {
        anchor.y += 14.0f;
        float rest = 1.0f - time;
        float ease = 1.0f - rest * rest;
        target.x = (player->point.x - from.x) * ease + from.x;
        target.y = (player->point.y - from.y) * ease + from.y;
        target.z = (player->point.z - from.z) * ease + from.z;
        if (player->rate != 0.0f) {
            time += 1.0f / (player->rate * 60.0f);
        } else {
            time += 0.016666668f;
        }
        if (time > 1.0f) {
            time = 1.0f;
        }
        break;
    }
    }
    focus = anchor;
    eye = target;
}
