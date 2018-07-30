/** 
* @file         mjc_mem.h 
* @brief        mjc交互模块内存头文件 
* @details      重新封装malloc以及free函数
* @author       林展翔 
* @version      V1.0 
* @par History:          
*  
*/ 

#ifndef _MEM_H_
#define _MEM_H_

/** 
 * mjc交互模块内存申请. 
 * 封装malloc函数 
 * @param[in]   申请内存大小. 
 * @param[out]  出错数据指针赋值NULL,未出错指向相应申请的内存.  
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-22创建 
 */
void* mjc_malloc(size_t malloc_size);
/** 
 * mjc交互模块内存释放. 
 * 封装free函数 
 * @param[in]   所需释放的指针. 
 * @param[out]  NULL.  
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-22创建 
 */
void *mjc_free(void *mjc_ptr);
#endif