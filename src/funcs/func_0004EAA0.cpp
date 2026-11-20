// Maps 0 to 0x100 and 1 to 0x101; anything else gives -1.
int func_0004EAA0(int index)
{
    switch (index) {
    case 0:
        return 0x100;
    case 1:
        return 0x101;
    }
    return -1;
}
