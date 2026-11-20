struct Vector3 {
    float x;
    float y;
    float z;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

struct Object_00016200 {
    int func_00016360(const Box_00017CC0 *a, const Box_00017CC0 *b);
};

// 1 when the two boxes overlap (tested along x, z, then y), otherwise 0.
int Object_00016200::func_00016360(const Box_00017CC0 *a, const Box_00017CC0 *b)
{
    if (a->min.x > b->max.x) {
        return 0;
    }
    if (a->max.x < b->min.x) {
        return 0;
    }
    if (a->min.z > b->max.z) {
        return 0;
    }
    if (a->max.z < b->min.z) {
        return 0;
    }
    if (a->min.y > b->max.y) {
        return 0;
    }
    if (a->max.y < b->min.y) {
        return 0;
    }
    return 1;
}
