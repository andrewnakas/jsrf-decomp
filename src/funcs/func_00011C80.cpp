struct Node {
    virtual ~Node();
    virtual void slot1();
    virtual void slot2();
    virtual void func_00011C80(int argument);
};

// The base class's empty slot 3. The tree walkers call the slot between func_001BA9C0 and func_001BAA50 (0x1123b).
void Node::func_00011C80(int)
{
}
