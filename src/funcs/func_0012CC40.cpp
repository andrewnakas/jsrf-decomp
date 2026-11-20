/* const: 0x80000 */
/* const: 0x100000 */

struct Object_00120420 {
    void func_0012CC40();
};

extern void *data_0025B110;
extern void *data_0025B114;

// Allocates the two buffers at data_0025B110 (512 KiB) and data_0025B114 (1 MiB). Never reads this.
void Object_00120420::func_0012CC40()
{
    data_0025B110 = operator new(0x80000);
    data_0025B114 = operator new(0x100000);
}
