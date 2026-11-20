struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014CB60(const Vector3 *from, const Vector3 *to);

// The object at data_00257CE4; its position is at 0x7c.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

// One point of the route: its position, the length of the leg to the next point and whether it can be chosen.
struct Point_000D8440 {
    Vector3 position;
    float length;
    unsigned int open;
    char unknown_14[0x4];
};

// The owner at 0x4: the point it heads for at 0xa8.
struct Owner_000D8440 {
    char unknown_00[0xa8];
    Point_000D8440 *target;
};

struct Object_000D8A40 {
    char unknown_000[0x4];
    Owner_000D8440 *owner;
    char unknown_008[0x34];
    unsigned int count;
    Point_000D8440 *points;
    int nearest;
    int current;
    int direction;

    void func_000D8440();
};

// Picks the open route point (0x40, count at 0x3c) nearest to the object at data_00257CE4 and keeps it at 0x44.
// When it is not the current point (0x48), walks the route both ways from the current point at once, adding up
// leg lengths, and takes the shorter way: 1 forward or -1 backward at 0x4c, added to the current point. The
// owner then heads for the current point.
void Object_000D8A40::func_000D8440()
{
    float best = 10000.0f;
    int found = 0;
    unsigned int i;
    for (i = 0; i < count; i++) {
        if (points[i].open > 0) {
            float distance = func_0014CB60(&data_00257CE4->position, &points[i].position);
            if (distance < best) {
                best = distance;
                found = i;
            }
        }
    }
    int behind = current;
    if (found != behind) {
        int total = count;
        float forward = 0.0f;
        float backward = 0.0f;
        int ahead = behind;
        for (i = 0; i < count; i++) {
            if (ahead != found) {
                forward += points[ahead].length;
                if (++ahead >= total) {
                    ahead = 0;
                }
            } else if (forward <= backward) {
                direction = 1;
                break;
            }
            if (behind != found) {
                if (--behind < 0) {
                    behind = total - 1;
                }
                backward += points[behind].length;
            } else if (backward <= forward) {
                direction = -1;
                break;
            }
        }
        current += direction;
    }
    nearest = found;
    owner->target = &points[current];
}
