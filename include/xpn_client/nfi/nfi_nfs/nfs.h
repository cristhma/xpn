/*
 *  Copyright 2000-2023 Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos, Luis Miguel Sanchez Garcia, Borja Bergua Guerra
 *
 *  This file is part of Expand.
 *
 *  Expand is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Expand is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with Expand.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * @file nfs.h
 * @brief Header file to 'TODO'.
 *
 * Header file to 'TODO'.
 *
 * @authors Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos, Luis Miguel Sanchez Garcia, Borja Bergua Guerra
 * @date  Jul 22, 2021
 * @bug No known bugs.
 */

#ifndef _NFS_H_
#define _NFS_H_

/************************************************
 *  ... Includes
 ***********************************************/
#include "all_system.h"
#include "base/path_misc.h"

#define NFS_TCP 1
#define NFS_UDP 0

/* tama�o del buffer de envio de datos */
#define SENDSZ (unsigned int)(128 * 1024)
/* tama�o del buffer de recepci�n de datos */
#define RECVSZ (unsigned int)(128 * 1024)

#define MNTPATHLEN 1024
#define MNTNAMLEN 255

#define NFSPATHLEN MNTPATHLEN

/* tama�o de los manejadores en bytes */
#define FHSIZE 32

/* numero de programa del servicio mount */
#define MOUNT1_PROGRAM ((u_long)100005)
/* version de programa del servicio mount */
#define MOUNT1_VERSION ((u_long)1)

/* numero de programa del servicio nfs */
#define NFS2_PROGRAM ((u_long)100003)
/* version de programa del servicio nfs */
#define NFS2_VERSION ((u_long)2)

#ifdef WIN32

typedef char fhandle[FHSIZE];

#ifdef __cplusplus
extern "C"
{
	bool_t xdr_fhandle(...);
}
#else
bool_t xdr_fhandle();
#endif

typedef char *dirpath;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_dirpath(...);
}
#else
bool_t xdr_dirpath();
#endif

typedef char *name;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_name(...);
}
#else
bool_t xdr_name();
#endif

struct fhd
{
	char fh[FHSIZE];
};
typedef struct fhd fhd;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_fhd(...);
}
#else
bool_t xdr_fhd();
#endif

struct fhstatus
{
	u_long status;
	union
	{
		fhandle directory;
	} fhstatus_u;
};
typedef struct fhstatus fhstatus;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_fhstatus(...);
}
#else
bool_t xdr_fhstatus();
#endif

typedef struct mountbody *mountlist;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_mountlist(...);
}
#else
bool_t xdr_mountlist();
#endif

struct mountbody
{
	name ml_hostname;
	dirpath ml_directory;
	mountlist ml_next;
};
typedef struct mountbody mountbody;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_mountbody(...);
}
#else
bool_t xdr_mountbody();
#endif

typedef struct groupnode *groups;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_groups(...);
}
#else
bool_t xdr_groups();
#endif

struct groupnode
{
	name gr_name;
	groups gr_next;
};
typedef struct groupnode groupnode;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_groupnode(...);
}
#else
bool_t xdr_groupnode();
#endif

typedef struct exportnode *exports;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_exports(...);
}
#else
bool_t xdr_exports();
#endif

struct exportnode
{
	dirpath ex_dir;
	groups ex_groups;
	exports ex_next;
};
typedef struct exportnode exportnode;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_exportnode(...);
}
#else
bool_t xdr_exportnode();
#endif

#define MOUNTPROC_NULL ((u_long)0)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat mountproc_null_1(...);
}
#else
extern enum clnt_stat mountproc_null_1();
#endif /* __cplusplus */
#define MOUNTPROC_MNT ((u_long)1)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat mountproc_mnt_1(...);
}
#else
extern enum clnt_stat mountproc_mnt_1();
#endif /* __cplusplus */
#define MOUNTPROC_DUMP ((u_long)2)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat mountproc_dump_1(...);
}
#else
extern enum clnt_stat mountproc_dump_1();
#endif /* __cplusplus */
#define MOUNTPROC_UMNT ((u_long)3)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat mountproc_umnt_1(...);
}
#else
extern enum clnt_stat mountproc_umnt_1();
#endif /* __cplusplus */
#define MOUNTPROC_UMNTALL ((u_long)4)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat mountproc_umntall_1(...);
}
#else
extern enum clnt_stat mountproc_umntall_1();
#endif /* __cplusplus */
#define MOUNTPROC_EXPORT ((u_long)5)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat mountproc_export_1(...);
}
#else
extern enum clnt_stat mountproc_export_1();
#endif /* __cplusplus */

// #define MAXDATA 8192
// #define MAXDATA (32*1024)
#define MAXDATA (64 * 1024)
#define NFSMAXPATHLEN 1024
#define NFSMAXNAMLEN 255
#define COOKIESIZE 4

typedef char *filename;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_filename(...);
}
#else
bool_t xdr_filename();
#endif

typedef char *path;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_path(...);
}
#else
bool_t xdr_path();
#endif

typedef char nfscookie[COOKIESIZE];
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_nfscookie(...);
}
#else
bool_t xdr_nfscookie();
#endif

typedef struct
{
	u_long nfsdata_len;
	char *nfsdata_val;
} nfsdata;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_nfsdata(...);
}
#else
bool_t xdr_nfsdata();
#endif

enum nfs_stat
{
	/* OK */
	NFS_OK = 0,
	/* errores de nfs */
	NFSERR_PERM = 1,
	NFSERR_NOENT = 2,
	NFSERR_IO = 5,
	NFSERR_NXIO = 6,
	NFSERR_ACCES = 13,
	NFSERR_EXIST = 17,
	NFSERR_NODEV = 19,
	NFSERR_NOTDIR = 20,
	NFSERR_ISDIR = 21,
	NFSERR_FBIG = 27,
	NFSERR_NOSPC = 28,
	NFSERR_ROFS = 30,
	NFSERR_NAMETOOLONG = 63,
	NFSERR_NOTEMPTY = 66,
	NFSERR_DQUOT = 69,
	NFSERR_STALE = 70,
	NFSERR_WFLUSH = 99,
	/* */

	NFSERR_NULL = -3,
	NFSERR_CONNECT = -7,
	NFSERR_EOFDIR = -47,

};
typedef enum nfs_stat nfs_stat;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_nfs_stat(...);
}
#else
bool_t xdr_nfs_stat();
#endif

enum ftype
{
	NFNON = 0,
	NFREG = 1,
	NFDIR = 2,
	NFBLK = 3,
	NFCHR = 4,
	NFLNK = 5,
};
typedef enum ftype ftype;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_ftype(...);
}
#else
bool_t xdr_ftype();
#endif

struct timevalNfs
{
	u_long seconds;
	u_long useconds;
};
typedef struct timevalNfs timevalNfs;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_timevalNfs(...);
}
#else
bool_t xdr_timevalNfs();
#endif

struct fattr
{
	ftype type;
	u_long mode;
	u_long nlink;
	u_long uid;
	u_long gid;
	u_long size;
	u_long blocksize;
	u_long rdev;
	u_long blocks;
	u_long fsid;
	u_long fileid;
	timevalNfs atime;
	timevalNfs mtime;
	timevalNfs ctime;
};
typedef struct fattr fattr;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_fattr(...);
}
#else
bool_t xdr_fattr();
#endif

struct sattr
{
	u_long mode;
	u_long uid;
	u_long gid;
	u_long size;
	timevalNfs atime;
	timevalNfs mtime;
};
typedef struct sattr sattr;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_sattr(...);
}
#else
bool_t xdr_sattr();
#endif

struct attrstat
{
	nfs_stat status;
	union
	{
		fattr attributes;
	} attrstat_u;
};
typedef struct attrstat attrstat;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_attrstat(...);
}
#else
bool_t xdr_attrstat();
#endif

struct diropargs
{
	fhandle dir;
	filename name;
};
typedef struct diropargs diropargs;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_diropargs(...);
}
#else
bool_t xdr_diropargs();
#endif

struct diropok
{
	fhandle file;
	fattr attributes;
};
typedef struct diropok diropok;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_diropok(...);
}
#else
bool_t xdr_diropok();
#endif

struct diropres
{
	nfs_stat status;
	union
	{
		diropok fhand_attr;
	} diropres_u;
};
typedef struct diropres diropres;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_diropres(...);
}
#else
bool_t xdr_diropres();
#endif

struct sattrargs
{
	fhandle file;
	sattr attributes;
};
typedef struct sattrargs sattrargs;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_sattrargs(...);
}
#else
bool_t xdr_sattrargs();
#endif

struct readlinkres
{
	nfs_stat status;
	union
	{
		path data;
	} readlinkres_u;
};
typedef struct readlinkres readlinkres;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_readlinkres(...);
}
#else
bool_t xdr_readlinkres();
#endif

struct readargs
{
	fhandle file;
	u_long offset;
	u_long count;
	u_long totalcount;
};
typedef struct readargs readargs;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_readargs(...);
}
#else
bool_t xdr_readargs();
#endif

struct datosRes
{
	fattr attributes;
	nfsdata data;
};
typedef struct datosRes datosRes;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_datosRes(...);
}
#else
bool_t xdr_datosRes();
#endif

struct readres
{
	nfs_stat status;
	union
	{
		datosRes fich_read;
	} readres_u;
};
typedef struct readres readres;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_readres(...);
}
#else
bool_t xdr_readres();
#endif

struct writeargs
{
	fhandle file;
	u_long beginoffset;
	u_long offset;
	u_long totalcount;
	nfsdata data;
};
typedef struct writeargs writeargs;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_writeargs(...);
}
#else
bool_t xdr_writeargs();
#endif

struct createargs
{
	diropargs where;
	sattr attributes;
};
typedef struct createargs createargs;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_createargs(...);
}
#else
bool_t xdr_createargs();
#endif

struct renameargs
{
	diropargs from;
	diropargs to;
};
typedef struct renameargs renameargs;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_renameargs(...);
}
#else
bool_t xdr_renameargs();
#endif

struct linkargs
{
	fhandle from;
	diropargs to;
};
typedef struct linkargs linkargs;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_linkargs(...);
}
#else
bool_t xdr_linkargs();
#endif

struct symlinkargs
{
	diropargs from;
	path to;
	sattr attributes;
};
typedef struct symlinkargs symlinkargs;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_symlinkargs(...);
}
#else
bool_t xdr_symlinkargs();
#endif

struct readdirargs
{
	fhandle dir;
	nfscookie cookie;
	u_long count;
};
typedef struct readdirargs readdirargs;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_readdirargs(...);
}
#else
bool_t xdr_readdirargs();
#endif

struct entry
{
	u_long fileid;
	filename name;
	nfscookie cookie;
	struct entry *nextentry;
};
typedef struct entry entry;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_entry(...);
}
#else
bool_t xdr_entry();
#endif

struct readdirok
{
	entry *entries;
	bool_t eof;
};
typedef struct readdirok readdirok;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_readdirok(...);
}
#else
bool_t xdr_readdirok();
#endif

struct readdirres
{
	nfs_stat status;
	union
	{
		readdirok entradasDir;
	} readdirres_u;
};
typedef struct readdirres readdirres;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_readdirres(...);
}
#else
bool_t xdr_readdirres();
#endif

struct nfs_info
{
	u_long tsize;
	u_long bsize;
	u_long blocks;
	u_long bfree;
	u_long bavail;
};
typedef struct nfs_info nfs_info;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_nfs_info(...);
}
#else
bool_t xdr_nfs_info();
#endif

struct statfsres
{
	nfs_stat status;
	union
	{
		struct nfs_info inf;
	} statfsres_u;
};
typedef struct statfsres statfsres;
#ifdef __cplusplus
extern "C"
{
	bool_t xdr_statfsres(...);
}
#else
bool_t xdr_statfsres();
#endif

#define NFSPROC_NULL ((u_long)0)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_null_2(...);
}
#else
extern enum clnt_stat nfsproc_null_2();
#endif /* __cplusplus */
#define NFSPROC_GETATTR ((u_long)1)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_getattr_2(...);
}
#else
extern enum clnt_stat nfsproc_getattr_2();
#endif /* __cplusplus */
#define NFSPROC_SETATTR ((u_long)2)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_setattr_2(...);
}
#else
extern enum clnt_stat nfsproc_setattr_2();
#endif /* __cplusplus */
#define NFSPROC_ROOT ((u_long)3)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_root_2(...);
}
#else
extern enum clnt_stat nfsproc_root_2();
#endif /* __cplusplus */
#define NFSPROC_LOOKUP ((u_long)4)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_lookup_2(...);
}
#else
extern enum clnt_stat nfsproc_lookup_2();
#endif /* __cplusplus */
#define NFSPROC_READLINK ((u_long)5)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_readlink_2(...);
}
#else
extern enum clnt_stat nfsproc_readlink_2();
#endif /* __cplusplus */
#define NFSPROC_READ ((u_long)6)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_read_2(...);
}
#else
extern enum clnt_stat nfsproc_read_2();
#endif /* __cplusplus */
#define NFSPROC_WRITECACHE ((u_long)7)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_writecache_2(...);
}
#else
extern enum clnt_stat nfsproc_writecache_2();
#endif /* __cplusplus */
#define NFSPROC_WRITE ((u_long)8)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_write_2(...);
}
#else
extern enum clnt_stat nfsproc_write_2();
#endif /* __cplusplus */
#define NFSPROC_CREATE ((u_long)9)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_create_2(...);
}
#else
extern enum clnt_stat nfsproc_create_2();
#endif /* __cplusplus */
#define NFSPROC_REMOVE ((u_long)10)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_remove_2(...);
}
#else
extern enum clnt_stat nfsproc_remove_2();
#endif /* __cplusplus */
#define NFSPROC_RENAME ((u_long)11)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_rename_2(...);
}
#else
extern enum clnt_stat nfsproc_rename_2();
#endif /* __cplusplus */
#define NFSPROC_LINK ((u_long)12)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_link_2(...);
}
#else
extern enum clnt_stat nfsproc_link_2();
#endif /* __cplusplus */
#define NFSPROC_SYMLINK ((u_long)13)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_symlink_2(...);
}
#else
extern enum clnt_stat nfsproc_symlink_2();
#endif /* __cplusplus */
#define NFSPROC_MKDIR ((u_long)14)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_mkdir_2(...);
}
#else
extern enum clnt_stat nfsproc_mkdir_2();
#endif /* __cplusplus */
#define NFSPROC_RMDIR ((u_long)15)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_rmdir_2(...);
}
#else
extern enum clnt_stat nfsproc_rmdir_2();
#endif /* __cplusplus */
#define NFSPROC_READDIR ((u_long)16)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_readdir_2(...);
}
#else
extern enum clnt_stat nfsproc_readdir_2();
#endif /* __cplusplus */
#define NFSPROC_STATFS ((u_long)17)
#ifdef __cplusplus
extern "C"
{
	extern enum clnt_stat nfsproc_statfs_2(...);
}
#else
extern enum clnt_stat nfsproc_statfs_2();
#endif /* __cplusplus */

#endif /* Windows nfs.h */

/************************************************************************************************************/
/************************************************************************************************************/

#ifdef LINUX

#ifdef __cplusplus
extern "C"
{
#endif

	typedef char fhandle[FHSIZE];

	typedef char *nfs_dirpath;

	typedef char *nfs_name;

	struct fhd
	{
		char fh[FHSIZE];
	};
	typedef struct fhd fhd;

	struct fhstatus
	{
		u_long status;
		union
		{
			fhandle directory;
		} fhstatus_u;
	};
	typedef struct fhstatus fhstatus;

	typedef struct mountbody *mountlist;

	struct mountbody
	{
		nfs_name ml_hostname;
		nfs_dirpath ml_directory;
		mountlist ml_next;
	};
	typedef struct mountbody mountbody;

	typedef struct groupnode *groups;

	struct groupnode
	{
		nfs_name gr_name;
		groups gr_next;
	};
	typedef struct groupnode groupnode;

	typedef struct exportnode *exports;

	struct exportnode
	{
		nfs_dirpath ex_dir;
		groups ex_groups;
		exports ex_next;
	};
	typedef struct exportnode exportnode;
#define MAXDATA 8192
#define NFSMAXPATHLEN 1024
#define NFSMAXNAMLEN 255
#define COOKIESIZE 4

	typedef char *filename;

	typedef char *path;

	typedef char nfscookie[COOKIESIZE];

	typedef struct
	{
		u_long nfsdata_len;
		char *nfsdata_val;
	} nfsdata;

	enum nfs_stat
	{
		/* OK */
		NFS_OK = 0,
		/* errores de nfs */
		NFSERR_PERM = 1,
		NFSERR_NOENT = 2,
		NFSERR_IO = 5,
		NFSERR_NXIO = 6,
		NFSERR_ACCES = 13,
		NFSERR_EXIST = 17,
		NFSERR_NODEV = 19,
		NFSERR_NOTDIR = 20,
		NFSERR_ISDIR = 21,
		NFSERR_FBIG = 27,
		NFSERR_NOSPC = 28,
		NFSERR_ROFS = 30,
		NFSERR_NAMETOOLONG = 63,
		NFSERR_NOTEMPTY = 66,
		NFSERR_DQUOT = 69,
		NFSERR_STALE = 70,
		NFSERR_WFLUSH = 99,
		/* */
		NFSERR_NULL = -3,
		NFSERR_CONNECT = -7,
		NFSERR_EOFDIR = -47,
		/*  */
		/*
		XPNERR_NULL = -3,
		XPNERR_FILESERVER = -4,
		XPNERR_CONNECT = -7,
		XPNERR_FILEOPEN = -8,
		XPNERR_FILEMODE = -9,
		XPNERR_FORMAT = -10,
		XPNERR_DISTSERVER = -11,
		XPNERR_DIRMNT = -12,
		XPNERR_SVRMOUNT = -14,
		XPNERR_DIRMOUNT = -15,
		XPNERR_FULLTABLEFILE = -18,
		XPNERR_NOTENTRY = -24,
		XPNERR_FULLTABLEINIT = -25,
		XPNERR_FULLTABLEDIR = -26,
		XPNERR_NODEFINED = -29,
		XPNERR_NORESOLVHOST = -31,
		XPNERR_OFFSET = -32,
		XPNERR_ISDIR = -34,
		XPNERR_ISFILE = -42,
		XPNERR_DIRMOUNTPART = -37,
		XPNERR_INTERNAL = -38,
		XPNERR_DISTPART = -39,
		XPNERR_FULLTABLEHEADER = -41,
		XPNERR_EMPTYTABLE = -43,
		XPNERR_INVALIDFILE = -45,
		XPNERR_INVALIDCAB = -46,
		XPNERR_EOFDIR = -47,
		XPNERR_FILEXIST = -48,
		XPNERR_NOUNLOCK = -49,
		XPNERR_NOLOCK = -50,
		XPNERR_PATHFORMAT = -51,
		XPNERR_INVALARG = -52,
		XPNERR_NOIMPLEMENTED = -53,
		XPNERR_USED = -54,
		*/
	};
	typedef enum nfs_stat nfs_stat;

	enum ftype
	{
		NFNON = 0,
		NFREG = 1,
		NFDIR = 2,
		NFBLK = 3,
		NFCHR = 4,
		NFLNK = 5,
	};
	typedef enum ftype ftype;

	struct timevalNfs
	{
		u_long seconds;
		u_long useconds;
	};
	typedef struct timevalNfs timevalNfs;

	struct fattr
	{
		ftype type;
		u_long mode;
		u_long nlink;
		u_long uid;
		u_long gid;
		u_long size;
		u_long blocksize;
		u_long rdev;
		u_long blocks;
		u_long fsid;
		u_long fileid;
		timevalNfs atime;
		timevalNfs mtime;
		timevalNfs ctime;
	};
	typedef struct fattr fattr;

	struct sattr
	{
		u_long mode;
		u_long uid;
		u_long gid;
		u_long size;
		timevalNfs atime;
		timevalNfs mtime;
	};
	typedef struct sattr sattr;

	struct attrstat
	{
		nfs_stat status;
		union
		{
			fattr attributes;
		} attrstat_u;
	};
	typedef struct attrstat attrstat;

	struct diropargs
	{
		fhandle dir;
		filename name;
	};
	typedef struct diropargs diropargs;

	struct diropok
	{
		fhandle file;
		fattr attributes;
	};
	typedef struct diropok diropok;

	struct diropres
	{
		nfs_stat status;
		union
		{
			diropok fhand_attr;
		} diropres_u;
	};
	typedef struct diropres diropres;

	struct sattrargs
	{
		fhandle file;
		sattr attributes;
	};
	typedef struct sattrargs sattrargs;

	struct readlinkres
	{
		nfs_stat status;
		union
		{
			path data;
		} readlinkres_u;
	};
	typedef struct readlinkres readlinkres;

	struct readargs
	{
		fhandle file;
		u_long offset;
		u_long count;
		u_long totalcount;
	};
	typedef struct readargs readargs;

	struct datosRes
	{
		fattr attributes;
		nfsdata data;
	};
	typedef struct datosRes datosRes;

	struct readres
	{
		nfs_stat status;
		union
		{
			datosRes fich_read;
		} readres_u;
	};
	typedef struct readres readres;

	struct writeargs
	{
		fhandle file;
		u_long beginoffset;
		u_long offset;
		u_long totalcount;
		nfsdata data;
	};
	typedef struct writeargs writeargs;

	struct createargs
	{
		diropargs where;
		sattr attributes;
	};
	typedef struct createargs createargs;

	struct renameargs
	{
		diropargs from;
		diropargs to;
	};
	typedef struct renameargs renameargs;

	struct linkargs
	{
		fhandle from;
		diropargs to;
	};
	typedef struct linkargs linkargs;

	struct symlinkargs
	{
		diropargs from;
		path to;
		sattr attributes;
	};
	typedef struct symlinkargs symlinkargs;

	struct readdirargs
	{
		fhandle dir;
		nfscookie cookie;
		u_long count;
	};
	typedef struct readdirargs readdirargs;

	struct entry
	{
		u_long fileid;
		filename name;
		nfscookie cookie;
		struct entry *nextentry;
	};
	typedef struct entry entry;

	struct readdirok
	{
		entry *entries;
		bool_t eof;
	};
	typedef struct readdirok readdirok;

	struct readdirres
	{
		nfs_stat status;
		union
		{
			readdirok entradasDir;
		} readdirres_u;
	};
	typedef struct readdirres readdirres;

	struct nfs_info
	{
		u_long tsize;
		u_long bsize;
		u_long blocks;
		u_long bfree;
		u_long bavail;
	};
	typedef struct nfs_info nfs_info;

	struct statfsres
	{
		nfs_stat status;
		union
		{
			struct nfs_info inf;
		} statfsres_u;
	};
	typedef struct statfsres statfsres;

#if defined(__STDC__) || defined(__cplusplus)
#define MOUNTPROC_NULL 0
	extern enum clnt_stat mountproc_null_1(void *, void *, CLIENT *);
	extern bool_t mountproc_null_1_svc(void *, void *, struct svc_req *);
#define MOUNTPROC_MNT 1
	extern enum clnt_stat mountproc_mnt_1(nfs_dirpath *, fhstatus *, CLIENT *);
	extern bool_t mountproc_mnt_1_svc(nfs_dirpath *, fhstatus *, struct svc_req *);
#define MOUNTPROC_DUMP 2
	extern enum clnt_stat mountproc_dump_1(void *, mountlist *, CLIENT *);
	extern bool_t mountproc_dump_1_svc(void *, mountlist *, struct svc_req *);
#define MOUNTPROC_UMNT 3
	extern enum clnt_stat mountproc_umnt_1(nfs_dirpath *, void *, CLIENT *);
	extern bool_t mountproc_umnt_1_svc(nfs_dirpath *, void *, struct svc_req *);
#define MOUNTPROC_UMNTALL 4
	extern enum clnt_stat mountproc_umntall_1(void *, void *, CLIENT *);
	extern bool_t mountproc_umntall_1_svc(void *, void *, struct svc_req *);
#define MOUNTPROC_EXPORT 5
	extern enum clnt_stat mountproc_export_1(void *, exports *, CLIENT *);
	extern bool_t mountproc_export_1_svc(void *, exports *, struct svc_req *);
	extern int mountprog_1_freeresult(SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define MOUNTPROC_NULL 0
extern enum clnt_stat mountproc_null_1();
extern bool_t mountproc_null_1_svc();
#define MOUNTPROC_MNT 1
extern enum clnt_stat mountproc_mnt_1();
extern bool_t mountproc_mnt_1_svc();
#define MOUNTPROC_DUMP 2
extern enum clnt_stat mountproc_dump_1();
extern bool_t mountproc_dump_1_svc();
#define MOUNTPROC_UMNT 3
extern enum clnt_stat mountproc_umnt_1();
extern bool_t mountproc_umnt_1_svc();
#define MOUNTPROC_UMNTALL 4
extern enum clnt_stat mountproc_umntall_1();
extern bool_t mountproc_umntall_1_svc();
#define MOUNTPROC_EXPORT 5
extern enum clnt_stat mountproc_export_1();
extern bool_t mountproc_export_1_svc();
extern int mountprog_1_freeresult();
#endif /* K&R C */

#if defined(__STDC__) || defined(__cplusplus)
#define NFSPROC_NULL 0
	extern enum clnt_stat nfsproc_null_2(void *, void *, CLIENT *);
	extern bool_t nfsproc_null_2_svc(void *, void *, struct svc_req *);
#define NFSPROC_GETATTR 1
	extern enum clnt_stat nfsproc_getattr_2(char *, attrstat *, CLIENT *);
	extern bool_t nfsproc_getattr_2_svc(char *, attrstat *, struct svc_req *);
#define NFSPROC_SETATTR 2
	extern enum clnt_stat nfsproc_setattr_2(sattrargs *, attrstat *, CLIENT *);
	extern bool_t nfsproc_setattr_2_svc(sattrargs *, attrstat *, struct svc_req *);
#define NFSPROC_ROOT 3
	extern enum clnt_stat nfsproc_root_2(void *, void *, CLIENT *);
	extern bool_t nfsproc_root_2_svc(void *, void *, struct svc_req *);
#define NFSPROC_LOOKUP 4
	extern enum clnt_stat nfsproc_lookup_2(diropargs *, diropres *, CLIENT *);
	extern bool_t nfsproc_lookup_2_svc(diropargs *, diropres *, struct svc_req *);
#define NFSPROC_READLINK 5
	extern enum clnt_stat nfsproc_readlink_2(char *, readlinkres *, CLIENT *);
	extern bool_t nfsproc_readlink_2_svc(char *, readlinkres *, struct svc_req *);
#define NFSPROC_READ 6
	extern enum clnt_stat nfsproc_read_2(readargs *, readres *, CLIENT *);
	extern bool_t nfsproc_read_2_svc(readargs *, readres *, struct svc_req *);
#define NFSPROC_WRITECACHE 7
	extern enum clnt_stat nfsproc_writecache_2(void *, void *, CLIENT *);
	extern bool_t nfsproc_writecache_2_svc(void *, void *, struct svc_req *);
#define NFSPROC_WRITE 8
	extern enum clnt_stat nfsproc_write_2(writeargs *, attrstat *, CLIENT *);
	extern bool_t nfsproc_write_2_svc(writeargs *, attrstat *, struct svc_req *);
#define NFSPROC_CREATE 9
	extern enum clnt_stat nfsproc_create_2(createargs *, diropres *, CLIENT *);
	extern bool_t nfsproc_create_2_svc(createargs *, diropres *, struct svc_req *);
#define NFSPROC_REMOVE 10
	extern enum clnt_stat nfsproc_remove_2(diropargs *, nfs_stat *, CLIENT *);
	extern bool_t nfsproc_remove_2_svc(diropargs *, nfs_stat *, struct svc_req *);
#define NFSPROC_RENAME 11
	extern enum clnt_stat nfsproc_rename_2(renameargs *, nfs_stat *, CLIENT *);
	extern bool_t nfsproc_rename_2_svc(renameargs *, nfs_stat *, struct svc_req *);
#define NFSPROC_LINK 12
	extern enum clnt_stat nfsproc_link_2(linkargs *, nfs_stat *, CLIENT *);
	extern bool_t nfsproc_link_2_svc(linkargs *, nfs_stat *, struct svc_req *);
#define NFSPROC_SYMLINK 13
	extern enum clnt_stat nfsproc_symlink_2(symlinkargs *, nfs_stat *, CLIENT *);
	extern bool_t nfsproc_symlink_2_svc(symlinkargs *, nfs_stat *, struct svc_req *);
#define NFSPROC_MKDIR 14
	extern enum clnt_stat nfsproc_mkdir_2(createargs *, diropres *, CLIENT *);
	extern bool_t nfsproc_mkdir_2_svc(createargs *, diropres *, struct svc_req *);
#define NFSPROC_RMDIR 15
	extern enum clnt_stat nfsproc_rmdir_2(diropargs *, nfs_stat *, CLIENT *);
	extern bool_t nfsproc_rmdir_2_svc(diropargs *, nfs_stat *, struct svc_req *);
#define NFSPROC_READDIR 16
	extern enum clnt_stat nfsproc_readdir_2(readdirargs *, readdirres *, CLIENT *);
	extern bool_t nfsproc_readdir_2_svc(readdirargs *, readdirres *, struct svc_req *);
	extern int nfs_program_2_freeresult(SVCXPRT *, xdrproc_t, caddr_t);
#define NFSPROC_STATFS 17
	extern enum clnt_stat nfsproc_statfs_2(char *, statfsres *, CLIENT *);
	extern bool_t nfsproc_statfs_2_svc(char *, statfsres *, struct svc_req *);
	extern int nfs_program_2_freeresult(SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define NFSPROC_NULL 0
extern enum clnt_stat nfsproc_null_2();
extern bool_t nfsproc_null_2_svc();
#define NFSPROC_GETATTR 1
extern enum clnt_stat nfsproc_getattr_2();
extern bool_t nfsproc_getattr_2_svc();
#define NFSPROC_SETATTR 2
extern enum clnt_stat nfsproc_setattr_2();
extern bool_t nfsproc_setattr_2_svc();
#define NFSPROC_ROOT 3
extern enum clnt_stat nfsproc_root_2();
extern bool_t nfsproc_root_2_svc();
#define NFSPROC_LOOKUP 4
extern enum clnt_stat nfsproc_lookup_2();
extern bool_t nfsproc_lookup_2_svc();
#define NFSPROC_READLINK 5
extern enum clnt_stat nfsproc_readlink_2();
extern bool_t nfsproc_readlink_2_svc();
#define NFSPROC_READ 6
extern enum clnt_stat nfsproc_read_2();
extern bool_t nfsproc_read_2_svc();
#define NFSPROC_WRITECACHE 7
extern enum clnt_stat nfsproc_writecache_2();
extern bool_t nfsproc_writecache_2_svc();
#define NFSPROC_WRITE 8
extern enum clnt_stat nfsproc_write_2();
extern bool_t nfsproc_write_2_svc();
#define NFSPROC_CREATE 9
extern enum clnt_stat nfsproc_create_2();
extern bool_t nfsproc_create_2_svc();
#define NFSPROC_REMOVE 10
extern enum clnt_stat nfsproc_remove_2();
extern bool_t nfsproc_remove_2_svc();
#define NFSPROC_RENAME 11
extern enum clnt_stat nfsproc_rename_2();
extern bool_t nfsproc_rename_2_svc();
#define NFSPROC_LINK 12
extern enum clnt_stat nfsproc_link_2();
extern bool_t nfsproc_link_2_svc();
#define NFSPROC_SYMLINK 13
extern enum clnt_stat nfsproc_symlink_2();
extern bool_t nfsproc_symlink_2_svc();
#define NFSPROC_MKDIR 14
extern enum clnt_stat nfsproc_mkdir_2();
extern bool_t nfsproc_mkdir_2_svc();
#define NFSPROC_RMDIR 15
extern enum clnt_stat nfsproc_rmdir_2();
extern bool_t nfsproc_rmdir_2_svc();
#define NFSPROC_READDIR 16
extern enum clnt_stat nfsproc_readdir_2();
extern bool_t nfsproc_readdir_2_svc();
extern int nfs_program_2_freeresult();
#define NFSPROC_STATFS 17
extern enum clnt_stat nfsproc_statfs_2();
extern bool_t nfsproc_statfs_2_svc();
extern int nfs_program_2_freeresult();
#endif /* K&R C */

	/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
	extern bool_t xdr_fhandle(XDR *, fhandle);
	extern bool_t xdr_dirpath(XDR *, nfs_dirpath *);
	extern bool_t xdr_name(XDR *, nfs_name *);
	extern bool_t xdr_fhd(XDR *, fhd *);
	extern bool_t xdr_fhstatus(XDR *, fhstatus *);
	extern bool_t xdr_mountlist(XDR *, mountlist *);
	extern bool_t xdr_mountbody(XDR *, mountbody *);
	extern bool_t xdr_groups(XDR *, groups *);
	extern bool_t xdr_groupnode(XDR *, groupnode *);
	extern bool_t xdr_exports(XDR *, exports *);
	extern bool_t xdr_exportnode(XDR *, exportnode *);
	extern bool_t xdr_filename(XDR *, filename *);
	extern bool_t xdr_path(XDR *, path *);
	extern bool_t xdr_nfscookie(XDR *, nfscookie);
	extern bool_t xdr_nfsdata(XDR *, nfsdata *);
	extern bool_t xdr_nfs_stat(XDR *, nfs_stat *);
	extern bool_t xdr_ftype(XDR *, ftype *);
	extern bool_t xdr_timevalNfs(XDR *, timevalNfs *);
	extern bool_t xdr_fattr(XDR *, fattr *);
	extern bool_t xdr_sattr(XDR *, sattr *);
	extern bool_t xdr_attrstat(XDR *, attrstat *);
	extern bool_t xdr_diropargs(XDR *, diropargs *);
	extern bool_t xdr_diropok(XDR *, diropok *);
	extern bool_t xdr_diropres(XDR *, diropres *);
	extern bool_t xdr_sattrargs(XDR *, sattrargs *);
	extern bool_t xdr_readlinkres(XDR *, readlinkres *);
	extern bool_t xdr_readargs(XDR *, readargs *);
	extern bool_t xdr_datosRes(XDR *, datosRes *);
	extern bool_t xdr_readres(XDR *, readres *);
	extern bool_t xdr_writeargs(XDR *, writeargs *);
	extern bool_t xdr_createargs(XDR *, createargs *);
	extern bool_t xdr_renameargs(XDR *, renameargs *);
	extern bool_t xdr_linkargs(XDR *, linkargs *);
	extern bool_t xdr_symlinkargs(XDR *, symlinkargs *);
	extern bool_t xdr_readdirargs(XDR *, readdirargs *);
	extern bool_t xdr_entry(XDR *, entry *);
	extern bool_t xdr_readdirok(XDR *, readdirok *);
	extern bool_t xdr_readdirres(XDR *, readdirres *);
	extern bool_t xdr_nfs_info(XDR *, nfs_info *);
	extern bool_t xdr_statfsres(XDR *, statfsres *);

#else /* K&R C */
extern bool_t xdr_fhandle();
extern bool_t xdr_dirpath();
extern bool_t xdr_name();
extern bool_t xdr_fhd();
extern bool_t xdr_fhstatus();
extern bool_t xdr_mountlist();
extern bool_t xdr_mountbody();
extern bool_t xdr_groups();
extern bool_t xdr_groupnode();
extern bool_t xdr_exports();
extern bool_t xdr_exportnode();
extern bool_t xdr_filename();
extern bool_t xdr_path();
extern bool_t xdr_nfscookie();
extern bool_t xdr_nfsdata();
extern bool_t xdr_nfs_stat();
extern bool_t xdr_ftype();
extern bool_t xdr_timevalNfs();
extern bool_t xdr_fattr();
extern bool_t xdr_sattr();
extern bool_t xdr_attrstat();
extern bool_t xdr_diropargs();
extern bool_t xdr_diropok();
extern bool_t xdr_diropres();
extern bool_t xdr_sattrargs();
extern bool_t xdr_readlinkres();
extern bool_t xdr_readargs();
extern bool_t xdr_datosRes();
extern bool_t xdr_readres();
extern bool_t xdr_writeargs();
extern bool_t xdr_createargs();
extern bool_t xdr_renameargs();
extern bool_t xdr_linkargs();
extern bool_t xdr_symlinkargs();
extern bool_t xdr_readdirargs();
extern bool_t xdr_entry();
extern bool_t xdr_readdirok();
extern bool_t xdr_readdirres();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* LINUX nfs.h */

/************************************************
 *  ... Functions
 ***********************************************/

/**
 * @brief Create connection client-server.
 *
 * This function creates a connection between the client
 * and the MNT server. The established connection protocol
 * can be TCP or UDP, although UDP is used by default.
 * This connection can only be used by one process at a time.
 *
 * @param name NFS server name.
 * @param type  'TODO'.
 * @return A pointer to a CLIENT structure (it is the connection
 * made). If it returns NULL, an error has occurred in the process.
 */
CLIENT *create_connection_mount(char *name, int type);

/**
 * @brief Close connection client-server.
 *
 * This function deletes a connection made to an MNT server.
 *
 * @param cl Pointer to the CLIENT structure.
 * @par Returns
 *    Nothing.
 */
void close_connection_mount(CLIENT *cl);

/**
 * @brief Get initial handler.
 *
 * This function obtains the initial handler.
 * It is obtained by mounting the directory passed by parameter.
 *
 * @param dir The absolute path from which the handler is to be obtained.
 * @param fhand A handler, which will be the path handler in case of a successful call.
 * @param cl Pointer to the CLIENT structure (i.e. the MNT connection).
 * 
 * @return An integer that indicates error in case of a
 * negative value, and success in case of a value equal to 0.
 */
int nfs_mount(char *dir, fhandle fhand, CLIENT *cl);

/**
 * @brief NFS umount.
 *
 * This function deletes the entry in the table
 * of path's mounted on the server.
 *
 * @param path The absolute path of a mounted directory.
 * @param cl Pointer to the CLIENT structure (i.e. the MNT connection).
 * 
 * @return An integer indicating error if negative,
 * and success in case of being equal to 0.
 */
int nfs_umount(char *path, CLIENT *cl);

/**
 * @brief Directories exported.
 *
 * This function collects all the directories
 * exported by a server.
 *
 * @param exp Pointer to a structure of type exports,
 * which on success will point to a list containing the
 * directories exported by the server, along with the
 * permissions associated with the directory.
 * @param cl Pointer to the CLIENT structure (i.e. the MNT connection).
 * 
 * @return An integer indicating error in case of being negative, and success in case of being equal to 0.
 */
int nfs_export(exports *exp, CLIENT *cl);

/**
 * @brief Create connection.
 *
 * This function creates a connection between the client
 * and the NFS server. The established connection protocol
 * can be TCP or UDP, although UDP is used by default.
 * This connection can only be used by one process at a time.
 *
 * @param name NFS server name.
 * @param type 'TODO'
 * @return A pointer to a CLIENT structure (this is
 * the connection made). If it returns NULL, an error has
 * occurred in the process.
 */
CLIENT *create_connection_nfs(char *name, int type);

/**
 * @brief Close connection.
 *
 * This function deletes a connection made to an NFS server.
 *
 * @param cl Pointer to the CLIENT structure.
 * @par Returns
 *    Nothing.
 */
void close_connection_nfs(CLIENT *cl);

/**
 * @brief Get attributes.
 *
 * This function gets the attributes of the file system object
 * for which you have the handle.
 *
 * @param fh  handler, which will be the handler of the object
 * from which you want to obtain the attributes.
 * @param fatt Pointer to a structure of type fatt
 * (reserved by the user) that will be filled in case
 * the call is successful.
 * @param cl Pointer to the CLIENT structure (i.e. the NFS connection).
 * @return An integer indicating error if negative,
 * and success in case of being equal to 0.
 */
int nfs_getattr(fhandle fh, fattr *fatt, CLIENT *cl);

/**
 * @brief Set attributes.
 *
 * This function incorporates the attributes into a
 * file system object for which you have the handle.
 *
 * @param fh A handler, which will be the handler of the object from which you want to get the attributes.
 * @param fatt A pointer to a structure of type fatt (reserved by the user) that will be filled in case the call succeeds.
 * @param cl A pointer to the CLIENT structure (i.e. the NFS connection).
 * @return An integer indicating error in case of being negative, and success in case of being equal to 0.
 */
int nfs_setattr(fhandle fh, fattr *fatt, CLIENT *cl);

/**
 * @brief Get Handle.
 *
 * This function gets the handle to a path passed
 * as a parameter, via the handle to the directory
 * containing that path.
 *
 * @param fhin The directory handle.
 * @param path The path from which the new handle is wanted.
 * @param fhout The new handle.
 * @param att Pointer to a structure of type fattr (reserved by the user)
 * that will be filled in case the call succeeds if it has a value other than NULL.
 * @param cl Pointer to the CLIENT structure (i.e. the NFS connection).
 * 
 * @return An integer that indicates error in case of being negative,
 * and success in case of being greater or equal to 0 (in this case,
 * it indicates the type of object of the file system from which
 * the handler has been obtained).
 */
int nfs_lookup(fhandle fhin, char *path, fhandle fhout, fattr *att, CLIENT *cl);

/**
 * @brief Read Data.
 *
 * This function reads data from a file.
 *
 * @param fh The file handle.
 * @param data The data buffer where the read data is stored.
 * @param offset The offset of the file, which indicates where to start reading from.
 * @param size The size of the data to be read.
 * @param cl Pointer to the CLIENT structure (i.e. the NFS connection).
 *
 * @return An integer indicating error if negative, and success
 * if greater than or equal to 0. In case of success the returned
 * value is the value of bytes read. If less bytes are read than
 * requested, the end of file has been reached.
 */
ssize_t nfs_read(fhandle fh, void *data, off_t offset, size_t size, CLIENT *cl);

/**
 * @brief Write Data.
 *
 * This function writes data to a file.
 *
 * @param fh The file handle.
 * @param data The buffer with the data to be written.
 * @param offset The offset of the file, which indicates where to start writing from.
 * @param size The size of the data to be written.
 * @param cl Pointer to the CLIENT structure (i.e. the NFS connection).
 *
 * @return An integer indicating error if negative, and success if greater
 * than or equal to 0. In case of success the returned value is the value
 * of bytes read. If less bytes are read than requested, the end of file has been reached.
 */
ssize_t nfs_write(fhandle fh, void *data, off_t offset, size_t size, CLIENT *cl);

/**
 * @brief Create file.
 *
 * This function creates a file.
 *
 * @param fhin The directory handle where the file is to be created.
 * @param file The name of the file to be created.
 * @param mode The access permissions of the file to be created.
 * @param fhout An output handle, which in case of success,
 * will be the handle of the created file.
 * @param at A pointer to a structure with the attributes of the file,
 * which in case of success will be filled in.
 * If you do not want to use it, set it to NULL.
 * @param cl A pointer to the CLIENT structure (i.e. the NFS connection).
 *
 * @return An integer that indicates error in case
 * of being negative, and success in case of being equal to 0.
 */
int nfs_create(fhandle fhin, char *file, mode_t mode, fhandle fhout, fattr *at, CLIENT *cl);

/**
 * @brief Remove File.
 *
 * This function deletes a file.
 *
 * @param fh The directory handle where the file is located.
 * @param file The name of the file to delete.
 * @param cl Pointer to the CLIENT structure (i.e. the NFS connection).
 *
 * @return An integer indicating error if negative, and success if 0.
 */
int nfs_remove(fhandle fh, char *file, CLIENT *cl);

/**
 * @brief Rename File or Directory.
 *
 * This function renames a file or directory.
 *
 * @param fh The directory handle where the file or directory is located.
 * @param name The name of the file or directory to rename.
 * @param fhR The directory handle of the directory where
 * the renamed file or directory is to be found.
 * @param nameR The new name of the file or directory.
 * @param cl Pointer to the CLIENT structure (i.e. the NFS connection).
 *
 * @return An integer indicating error if negative, and success if 0.
 */
int nfs_rename(fhandle fh, char *name, fhandle fhR, char *nameR, CLIENT *cl);

/**
 * @brief Create a Directory.
 *
 * This function creates a directory.
 *
 * @param fhin The directory handle where the directory is to be created.
 * @param dir The name of the directory to be created.
 * @param mode The access permissions of the directory to be created.
 * @param fhout An output handle, which in case of success, will be the handle of the created directory.
 * @param att A pointer to a structure with the attributes of the directory,
 * which in case of success will be filled in. If you do not want to use it, set it to NULL.
 * @param cl Pointer to the CLIENT structure (i.e. the NFS connection).
 *
 * @return An integer that indicates error in case of being negative, and success in case of being equal to 0.
 */
int nfs_mkdir(fhandle fhin, char *dir, mode_t mode, fhandle fhout, fattr *att, CLIENT *cl);

/**
 * @brief Remove a directory.
 *
 * This function deletes a directory.
 *
 * @param fh The directory handle where the directory is located.
 * @param dir The name of the directory to be deleted.
 * @param cl Pointer to the CLIENT structure (i.e. the NFS connection).
 *
 * @return An integer that indicates error in case of being negative,
 * and success in case of being equal to 0.
 */
int nfs_rmdir(fhandle fh, char *dir, CLIENT *cl);

/**
 * @brief Read entries.
 *
 * This function reads entries from a directory.
 *
 * @param fh The directory handle of the directory from which you want to read entries.
 * @param cookie A cookie, which is filled with the last entry read.
 * It is used to know where you want to start reading the entries.
 * If you want to read from the first entry, the cookie must have a value of 0.
 * @param entry A pointer to an array of strings, which is where,
 * in case of success, the entries will be stored.
 * @param cl Pointer to the CLIENT structure (i.e. the NFS connection).
 *
 * @return An integer that indicates error in case of being negative,
 * and success in case of being equal or greater than 0.
 * If greater than or equal to 0, this number indicates the number of entries read.
 */
int nfs_readdir(fhandle fh, nfscookie cookie, char *entry, CLIENT *cl);

/**
 * @brief Get features Server.
 *
 * This function obtains features from the NFS server.
 *
 * @param arg The directory handle.
 * @param inf A pointer to a structure of type info containing the server information, in case of success.
 * @param cl A pointer to the CLIENT structure (i.e. the NFS connection).
 *
 * @return An integer indicating error in case of being negative,
 * and success in case of being equal to 0.
 */
int nfs_statfs(fhandle arg, struct nfs_info *inf, CLIENT *cl);

#endif /* _NFS_H */
