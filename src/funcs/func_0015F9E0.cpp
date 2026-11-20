typedef void (*Callback)();

void func_0015F9D0();
void __stdcall func_0018CE30(Callback callback);

// Installs the callback: null means the counter func_0015F9D0, -1 means none.
void __stdcall func_0015F9E0(Callback callback)
{
    if (callback == 0)
        callback = func_0015F9D0;
    else if (callback == (Callback)-1)
        callback = 0;
    func_0018CE30(callback);
}
