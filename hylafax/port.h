/*
 * Warning, this file was automatically created by the HylaFAX configure script
 * VERSION:	 6.0.6
 * DATE:	 Fri Jul 21 22:40:07 IST 2017
 * TARGET:	 x86_64-unknown-linux-gnu
 * RELEASE:	 4.4.0-83-generic
 * CCOMPILER:	 /usr/bin/gcc-5.4.0
 * CXXCOMPILER:	 /usr/bin/g++-5.4.0
 */
#ifndef _PORT_
#define _PORT_ 1
#ifdef __cplusplus
extern "C" {
#endif
#define CONFIG_OPENFIFO O_RDWR
#define CONFIG_TIOCMBISBYREF yes
#define CONFIG_MAXGID 60002
#include <sys/types.h>
#define HAVE_STDINT_H 1
#define HAS_SELECT_H 1
#define fxSIGACTIONHANDLER (sig_t)
#define fxSIGHANDLER (sig_t)
#define HAS_MMAP 1
#define HAS_SYSCONF 1
#define HAS_ULIMIT 1
#define HAS_GETDTABLESIZE 1
#ifndef howmany
#define howmany(x, y)	(((x)+((y)-1))/(y))
#endif
struct sigvec;
extern int sigvec(int, const struct sigvec*, struct sigvec*);
#define HAS_FCHOWN 1
#define HAS_FCHMOD 1
#define HAS_LOCALE 1
//#include <paths.h>
#define HAS_LOGWTMP 1
#define HAS_LOGOUT 1
#define HAS_UTEXIT 1
#define HAS_POSIXSCHED 1
#define RT_PRIORITY 1
#define HAS_CRYPT_H 1
#define TIFFHeader	TIFFHeaderClassic
#define TIFF_VERSION	TIFF_VERSION_CLASSIC
#define NEED_TIFFDIRENTRY
#define tiff_runlen_t uint32
#define tiff_offset_t uint64
#define tiff_bytecount_t uint64
extern const char* HYLAFAX_VERSION_STRING;
#ifdef __cplusplus
}
#endif
#endif
