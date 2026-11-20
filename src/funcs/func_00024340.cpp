int __stdcall func_00145F8B(void *file, void *buffer, unsigned long size, unsigned long *done, void *overlapped);

// Transfers up to a size through func_00145F8B (no overlapped block) and returns the count it reports.
unsigned long func_00024340(void *file, void *buffer, unsigned long size)
{
    unsigned long done = 0;
    func_00145F8B(file, buffer, size, &done, 0);
    return done;
}
