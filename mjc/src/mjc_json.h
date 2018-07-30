/** 
* @file         mjc_json.h 
* @brief        mjc交互模块json头文件 
* @details      定义与json数据相关的的数据以及函数
* @author       林展翔 
* @version      V1.0 
* @par History:          
*  
*/ 
#ifndef _MJC_JSON_HANDLE_H_
#define _MJC_JSON_HANDLE_H_
#include "cJSON.h"
#include "mjc.h"
#include "mjc_type.h"

/** JSON数据 相应内容最大大小 */
#define JSON_MAX_SIZE 500
#define JSON_DATA_MAX_SIZE 200
#define JSON_EVENT_MAS_SIZE 5
#define JSON_ORDER_SIZE 4

/** mjc交互模块object_event */
#define MJC_OBJ_EVENT "E"
#define MJC_OBJ_FROM "F"
#define MJC_OBJ_TO "T"
#define MJC_OBJ_SUB "B"
#define MJC_OBJ_REASON "R"
#define MJC_OBJ_DETAIL "D"
#define MJC_OBJ_P "P"
#define MJC_OBJ_VERSION "V"
#define MJC_OBJ_CFG "C"
#define MJC_OBJ_USER "U"
#define MJC_OBJ_RESULT "R"
#define MJC_OBJ_POLICY "P"
#define MJC_OBJ_TIME "T"
#define MJC_OBJ_VALUE "V"
#define MJC_OBJ_ORDER "O"
#define MJC_OBJ_S "S"
#define MJC_OBJ_KEEP "K"
#define MJC_OBJ_GATEWAY "G"

/** object_event事件枚举 */
#define MJC_E_M0 "M0"
#define MJC_E_M1 "M1"
#define MJC_E_M2 "M2"
#define MJC_E_M3 "M3"
#define MJC_E_M4 "M4"
#define MJC_E_M5 "M5"
#define MJC_E_M6 "M6"
#define MJC_E_M7 "M7"
#define MJC_E_M8 "M8"
#define MJC_E_M9 "M9"
#define MJC_E_M10 "M10"
#define MJC_E_M11 "M11"
#define MJC_E_M12 "M12"
#define MJC_E_M13 "M13"
#define MJC_E_B0 "B0"
#define MJC_E_B1 "B1"
#define MJC_E_B2 "B2"
#define MJC_E_B3 "B3"
#define MJC_E_B4 "B4"
#define MJC_E_B5 "B5"
#define MJC_E_B6 "B6"
#define MJC_E_B7 "B7"
#define MJC_E_B8 "B8"
#define MJC_E_B9 "B9"

/** 
 * mjc交互模块JSON解析部分. 
 * 通过JSON数据获取到对应object的数据. 
 * @param[in]   E_DATA结构体指针,事件处理结构体指针. 
 * @param[out]  出错数据相应错误,未出错回参数0.  
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-22创建 
 */
int mjc_json_resolve(cJSON *json,E_HANDLER *e_tmp);
/** 
 * 去除引号. 
 * 将解析出来的数据的引号去除. 
 * @param[in]   目的支付指针,源字符指针. 
 * @param[out]  出错数据相应错误,未出错回参数0.  
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-22创建 
 */
int mjc_json_rm_qutation_mark(char *tmp,char *data);
/** 
 * json数据组包. 
 * 传入事件数据结构体将对应的数据组成json格式数据。
 * 当输入的E_DATA数据有带sub时，E_DATA结构体中数据部分，sub数据前，要增加一个空数据。 
 * @param[in]   E_DATA结构体指针. 
 * @param[out]  出错数据相应错误,未出错回参数0.   
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-22创建 
 */
int mjc_json_pkt(E_DATA *e_data);

/** 
 * 获取ID. 
 * 获取当前消息ID. 
 * @param[in]   NULL. 
 * @param[out]  当前可使用的消息ID.  
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-22创建 
 */
U16 mjc_get_id();
/** 
 * json数据处理. 
 * 将传入的字符串转化成JSON数据,并找出相应的事件,调用相应的回调函数. 
 * @param[in]   E_DATA结构体指针. 
 * @param[out]  出错数据相应错误,未出错回参数0.  
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-22创建 
 */
int mjc_json_handle(char *text);

/** 
 * 得到事件处理结构体. 
 * 传入事件处理结构体执政，获得相应事件的事件处理结构体，并存入. 
 * @param[in]   E_HANDLER指针,事件字符串. 
 * @param[out]  出错数据相应错误,未出错回参数0.  
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-27创建 
 */
int mjc_json_get_event_handle_struct(E_HANDLER *e_tmp, char *event);

#endif