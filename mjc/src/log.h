/** 
* @file         log.h 
* @brief        确定debug等级 
* @details      当定义了debug为1时输出相应的debug数据,当debug为0时不输出相应的debug内容
* @author       林展翔 
* @version      V1.0 
* @par History:          
*  
*/  

#ifndef _LOG_H_
#define _LOG_H_

#define debug 1
#define DBG_PRINTF(x, args...) if (debug) printf("\nDEBUG: "x, ## args)

#endif