#ifndef _ALL_H_SYSTEM_H
#define _ALL_H_SYSTEM_H


/*
 * Common sizes
 */
#ifndef KB
	#define KB	(1024)
#endif
#ifndef MB
	#define MB	(KB*KB)
#endif
#ifndef GB
	#define GB	(KB*KB*KB)
#endif

#ifndef TRUE
	#define TRUE 1
#endif
#ifndef FALSE
	#define FALSE 0
#endif


/*
 * Get config*.h
 */
#if   defined(HAVE_CONFIG_H)
	#include "config.h"
#elif defined(LINUX)
	#include "config_linux.h"
#endif


#include "xpn_debug.h"


/*
 * Include common headers
 */
#ifndef NOT_TO_USE_STDLIB_H
        #include <stdlib.h>
#endif
#include <stdio.h>
#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <math.h>

#include <sys/types.h>
#include <sys/stat.h>

//#include <linux/linux.h>
//#include <sys/ioctl.h>
//#include <dlfcn.h>

/*
 * Include detected headers
 */
#if defined(HAVE_DIRENT_H)
	#include <dirent.h>
#endif

#if defined(HAVE_STRINGS_H)
	#include <strings.h>
#endif

#if defined(HAVE_STRING_H)
	#include <string.h>
#endif

#if defined(HAVE_PTHREAD_H)
	#include <pthread.h>
#endif

#if defined(HAVE_NETINET_IN_H)
	#include <netinet/in.h>
	#include <netinet/tcp.h>
	#include <netdb.h>
	#include <sys/socket.h>
#endif

#if defined(HAVE_UNISTD_H)
	#include <unistd.h>
#endif

#if defined(HAVE_SYS_TIME_H)
	#include <sys/time.h>
#endif

#if defined(HAVE_WINDOWS_H)
	#include <windows.h>
#endif

#if defined(HAVE_RPC_RPC_H)
	#include <rpc/rpc.h>
#endif

#if defined(HAVE_RPC_CLNT_H)
	#include <rpc/clnt.h>
#endif

#if defined(HAVE_RPC_TYPES_H)
	#include <rpc/types.h>
#endif

#if defined(HAVE_FCNTL_H)
        #ifndef NOT_TO_USE_FCNTL_H
            #include <fcntl.h>
        #endif
#endif


/*
 *
 */

#if defined(HAVE_UNISTD_H)
          #define NULL_DEVICE_PATH  "/dev/null"
#endif
#if defined(HAVE_WINDOWS_H)
          #define NULL_DEVICE_PATH  "NUL"
#endif

#if !defined(HAVE_FCNTL_H)
	#define O_ACCMODE          0003
	#define O_RDONLY             00
	#define O_WRONLY             01
	#define O_RDWR               02
	#define O_CREAT            0100 /* not fcntl */
	#define O_EXCL             0200 /* not fcntl */
	#define O_NOCTTY           0400 /* not fcntl */
	#define O_TRUNC           01000 /* not fcntl */
	#define O_APPEND          02000
	#define O_NONBLOCK        04000
	#define O_NDELAY        O_NONBLOCK
	#define O_SYNC           010000
	#define O_FSYNC          O_SYNC
	#define O_ASYNC          020000
#endif


#endif /* _ALL_H_SYSTEM_H */
