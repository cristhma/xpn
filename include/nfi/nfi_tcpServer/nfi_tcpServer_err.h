#ifndef _NFI_TCPSERVER_ERR_H_
#define _NFI_TCPSERVER_ERR_H_


 #ifdef  __cplusplus
    extern "C" {
 #endif


enum nfi_tcpServer_err{
	TCPSERVERERR_PARAM = 0,
	TCPSERVERERR_MEMORY = 1,
	TCPSERVERERR_URL = 2,
	TCPSERVERERR_MNTCONNECTION = 3,
	TCPSERVERERR_MOUNT = 4,
	TCPSERVERERR_NFSCONNECTION = 5,		
	TCPSERVERERR_GETATTR = 6,
	TCPSERVERERR_LOOKUP = 7,
	TCPSERVERERR_READ = 8,
	TCPSERVERERR_WRITE = 9,
	TCPSERVERERR_CREATE = 10,
	TCPSERVERERR_REMOVE = 11,
	TCPSERVERERR_MKDIR = 12,
	TCPSERVERERR_READDIR = 13,
	TCPSERVERERR_STATFS = 14,
	TCPSERVERERR_NOTDIR = 15,
};


void tcpServer_err(int err);


 #ifdef  __cplusplus
     }
 #endif


#endif