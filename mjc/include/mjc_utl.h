/** 
* @file         mjc_utl.h 
* @brief        用来mjc存放一些通用函数 
* @details      目前只有对e_data进行初始化/填充/释放
* @author       林展翔 
* @version      V1.0 
* @par History:          
*  
*/  

#ifndef _MJC_UTL_H_
#define _MJC_UTL_H_

/** 
 * 初始化E_DATA结构体函数. 
 * 将E_DATA结构体内数据置空. 
 * @param[in]   E_DATA结构体指针. 
 * @param[out]  出错数据相应错误,未出错回参数0.  
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-22创建 
 */  
int e_data_init(E_DATA *e_data);
/** 
 * 对E_DATA结构体进行赋值. 
 * 为E_DATA结构体内数据申请内存,并赋值. 
 * @param[in]   E_DATA结构体指针,事件处理结构体指正,消息数据,消息数组长度. 
 * @param[out]  出错数据相应错误,未出错回参数0.  
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-22创建 
 */
int e_data_fill(E_DATA *e_data, E_HANDLER *e_tmp, char **data_tmp, int data_arraysize);
/** 
 * 释放E_DATA结构体内存. 
 * 先释放E_DATA结构体内部数据内存,最后释放E_DATA结构体内存. 
 * @param[in]   E_DATA结构体指针. 
 * @param[out]  出错数据相应错误,未出错回参数0.  
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-22创建 
 */
int e_data_free(E_DATA *e_data);

/** 
 * 通用函数：字符转化成数值. 
 * 将十六进制字符转化为相应的数值. 
 * @param[in]   十六进制字符. 
 * @param[out]  字符对应的数值.  
 * @par 标识符 
 *      保留 
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-30创建 
 */
int mjc_c2i_util(char ch);

/** 
 * 通用函数：十六进制转化成数值. 
 * 将十六进制字符串转换为16位数值. 
 * @param[in]   十六进制字符串. 
 * @param[out]  字符串对应的数值,错误返回0.  
 * @par 标识符 
 *      保留 
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-30创建 
 */
U16 mjc_hex2dec_util(char *hex);

#endif
