/** 
* @file         mjc_strutl.h 
* @brief        字符串相关操作头文件 
* @details      将strncpy/strncmp/strlen重新封装成mjc_strncpy/mjc_strncmp/mjc_strlen
* @author       林展翔 
* @version      V1.0 
* @par History:          
*  
*/  

#ifndef _MJC_STRUTL_H_
#define _MJC_STRUTL_H_
#include "mjc.h"
typedef unsigned    int       U32;
typedef signed      int       S32;

char *mjc_strncpy(char *dest, const char *src, U32 dlen);
S32 mjc_strncmp(const char *s1, const char *s2, S32 n);
S32 mjc_strlen(const char *src);
#endif