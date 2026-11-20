struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void slot2();
    virtual void slot3(int argument);
};

// The base class's empty virtual function: slots 1 and 2 of Node's table both hold it.
void Node::func_00011C90()
{
}
