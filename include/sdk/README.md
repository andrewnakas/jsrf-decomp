# include/sdk

Clean-room declarations for the platform: only what units need, written from Microsoft's public Win32 and
Direct3D 8 documentation and from what the executable itself shows. Nothing here is copied from the Xbox
Development Kit or from any compiler's headers (see PROVENANCE.md). Maintainer-only.

| Header | What |
|---|---|
| `stdarg.h` | `va_list`, `va_start`, `va_arg`, `va_end` for 32-bit x86 cdecl functions, written from the calling convention itself (each argument takes a multiple of 4 bytes on the stack). |
