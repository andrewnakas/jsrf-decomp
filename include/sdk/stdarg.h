/* Variable arguments for 32-bit x86 cdecl functions: the arguments after the last named one follow it on
 * the stack, each taking a multiple of 4 bytes. Written for this project. */
#ifndef JSRF_STDARG_H
#define JSRF_STDARG_H

typedef char *va_list;

#define JSRF_VA_SIZE(type) ((sizeof(type) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, last) ((ap) = (va_list)&(last) + JSRF_VA_SIZE(last))
#define va_arg(ap, type) (*(type *)(((ap) += JSRF_VA_SIZE(type)) - JSRF_VA_SIZE(type)))
#define va_end(ap) ((ap) = (va_list)0)

#endif
