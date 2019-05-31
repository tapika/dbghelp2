#pragma once
//------------------------------------------------------------------------------------------------
// Defines
//------------------------------------------------------------------------------------------------

// Mimic wine config.h
#define __WINE_CONFIG_H

// Brings all FIXME defines, etc...
#define __WINESRC__

// elf_module.c, want to enable ELF support
#define __ELF__
#define HAVE_ELF_H

// CPU mapping probe from ms compiler to CPU defines
#ifdef _WIN64
    #define __x86_64__
#else
    #define __i386__
#endif

// wine: include/winnls.h
//#define CP_UNIXCP     65010 /* Wine extension */
#define CP_UNIXCP     CP_ACP

// Affects wine/exception.h / __EXCEPT_PAGE_FAULT macro
#define USE_COMPILER_EXCEPTIONS


// Used in various modules
#define strlenW wcslen
#define strcmpW wcscmp
#define strcatW wcscat
#define strchrW wcschr
#define strrchrW wcsrchr
#define strcpyW wcscpy
#define tolowerW towlower
#define toupperW towupper
#define strncmpiW _wcsnicmp
//#define strncmpW wcsncmp
#define strcmpiW _wcsicmp
#define strstrW wcsstr

//------------------------------------------------------------------------------------------------
// Other includes
//------------------------------------------------------------------------------------------------

// wine: include/winnt.h:
#define DECLSPEC_HIDDEN

// wine: include/winnt.h
#if defined(__GNUC__) && ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3)))
#define __WINE_ALLOC_SIZE(x) __attribute__((__alloc_size__(x)))
#else
#define __WINE_ALLOC_SIZE(x)
#endif

// wine: include/windef.h
#ifndef __ms_va_list
# if (defined(__x86_64__) || defined(__aarch64__)) && defined (__GNUC__)
#  define __ms_va_list __builtin_ms_va_list
#  define __ms_va_start(list,arg) __builtin_ms_va_start(list,arg)
#  define __ms_va_end(list) __builtin_ms_va_end(list)
#  define __ms_va_copy(dest,src) __builtin_ms_va_copy(dest,src)
# else
#  define __ms_va_list va_list
#  define __ms_va_start(list,arg) va_start(list,arg)
#  define __ms_va_end(list) va_end(list)
#  ifdef va_copy
#   define __ms_va_copy(dest,src) va_copy(dest,src)
#  else
#   define __ms_va_copy(dest,src) ((dest) = (src))
#  endif
# endif
#endif

// wine: include/winnt.h
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

// glibc/link.h

/* We use this macro to refer to ELF types independent of the native wordsize.
   `ElfW(TYPE)' is used in place of `Elf32_TYPE' or `Elf64_TYPE'.  */
#define ElfW(type)	_ElfW (Elf, __ELF_NATIVE_CLASS, type)
#define _ElfW(e,w,t)	_ElfW_1 (e, w, _##t)
#define _ElfW_1(e,w,t)	e##w##t

//wordsize.h
#define __WORDSIZE 
//elfclass.h
#define __ELF_NATIVE_CLASS __WORDSIZE

