unsigned int func_0014C690(float value);

struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

// The class whose table is at 0x1CCA80 (destructor 0x71040).
struct Object_00071040 : Node {
    char unknown_044[0x490];
    float rate;
    float fade;
    unsigned char colour[4];

    void func_00070320();
};

// Moves the fade by a thirtieth of the rate, turning the rate round when it reaches 1 going up or 0 going down, and
// sets the colour's second byte to 50 to 160 and its third and fourth to 50 to 0 by it.
void Object_00071040::func_00070320()
{
    fade += rate * 0.033333335f;
    if (rate > 0.0f) {
        if (fade >= 1.0f) {
            fade = 1.0f;
            rate *= -1.0f;
        }
    } else if (fade <= 0.0f) {
        fade = 0.0f;
        rate *= -1.0f;
    }
    colour[1] = (unsigned char)((float)(int)func_0014C690(fade * 110.0f) + 50.0f);
    colour[2] = (unsigned char)((float)(int)func_0014C690(fade * -50.0f) + 50.0f);
    colour[3] = (unsigned char)((float)(int)func_0014C690(fade * -50.0f) + 50.0f);
}
