/** 
* @file         mjc_api.h 
* @brief        提供借口 
* @details      提供了一个接受数据的借口
* @author       林展翔 
* @version      V1.0 
* @par History:          
*  
*/

#ifndef _MJC_API_H_
#define _MJC_API_H_
#include "mjc.h"
#include "mjc_json.h"
#include "log.h"
#include "mjc_utl.h"
#include "mjc_strutl.h"

/** 事件内对应数据的枚举类型 */
#define MJC_M0_EVENT_ENUM     0
#define MJC_M0_FROM_ENUM      1
#define MJC_M0_ORDER_ENUM     2
#define MJC_M0_SUB_ENUM       3
#define MJC_M0_S_ENUM         4
#define MJC_M0_GATEWAY_ENUM   5

#define MJC_M1_EVENT_ENUM     0
#define MJC_M1_TO_ENUM        1
#define MJC_M1_ORDER_ENUM     2
#define MJC_M1_KEEP_ENUM      3

#define MJC_M2_EVENT_ENUM     0
#define MJC_M2_FROM_ENUM      1
#define MJC_M2_ORDER_ENUM     2 

#define MJC_M3_EVENT_ENUM     0
#define MJC_M3_TO_ENUM        1
#define MJC_M3_ORDER_ENUM     2

#define MJC_M4_EVENT_ENUM     0
#define MJC_M4_FROM_ENUM      1
#define MJC_M4_ORDER_ENUM     2
#define MJC_M4_SUB_ENUM       3
#define MJC_M4_REASON_ENUM    4
#define MJC_M4_DETIAL_ENUM    5

#define MJC_M5_EVENT_ENUM     0
#define MJC_M5_TO_ENUM        1
#define MJC_M5_ORDER_ENUM     2

#define MJC_M6_EVENT_ENUM     0
#define MJC_M6_TO_ENUM        1
#define MJC_M6_ORDER_ENUM     2
#define MJC_M6_SUB_ENUM       3 
#define MJC_M6_P_ENUM         4
#define MJC_M6_VERSION_ENUM   5

#define MJC_M7_EVENT_ENUM     0
#define MJC_M7_FROM_ENUM      1
#define MJC_M7_ORDER_ENUM     2

#define MJC_M8_EVENT_ENUM     0
#define MJC_M8_FROM_ENUM      1
#define MJC_M8_ORDER_ENUM     2

#define MJC_M9_EVENT_ENUM     0 
#define MJC_M9_TO_ENUM        1
#define MJC_M9_ORDER_ENUM     2

#define MJC_M10_EVENT_ENUM    0
#define MJC_M10_TO_ENUM       1
#define MJC_M10_ORDER_ENUM    2
#define MJC_M10_SUB_ENUM      3
#define MJC_M10_CFG_ENUM      4
#define MJC_M10_VERSION_ENUM  5

#define MJC_M11_EVENT_ENUM    0
#define MJC_M11_FROM_ENUM     1
#define MJC_M11_ORDER_ENUM    2

#define MJC_M12_EVENT_ENUM    0
#define MJC_M12_TO_ENUM       1
#define MJC_M12_ORDER_ENUM    2

#define MJC_M13_EVENT_ENUM    0
#define MJC_M13_FROM_ENUM     1
#define MJC_M13_ORDER_ENUM    2

#define MJC_B0_EVENT_ENUM     0
#define MJC_B0_TO_ENUM        1
#define MJC_B0_ORDER_ENUM     2
#define MJC_B0_SUB_ENUM       3
#define MJC_B0_USER_ENUM      4
#define MJC_B0_POLICY_ENUM    5
#define MJC_B0_TIME_ENUM      6

#define MJC_B1_EVENT_ENUM     0
#define MJC_B1_FROM_ENUM      1
#define MJC_B1_ORDER_ENUM     2

#define MJC_B2_EVENT_ENUM     0
#define MJC_B2_FROM_ENUM      1
#define MJC_B2_ORDER_ENUM     2
#define MJC_B2_SUB_ENUM       3
#define MJC_B2_RESULT_ENUM    4
#define MJC_B2_DETIAL_ENUM    5

#define MJC_B3_EVENT_ENUM     0
#define MJC_B3_TO_ENUM        1
#define MJC_B3_ORDER_ENUM     2

#define MJC_B4_EVENT_ENUM     0
#define MJC_B4_FROM_ENUM      1
#define MJC_B4_ORDER_ENUM     2
#define MJC_B4_SUB_ENUM       3
#define MJC_B4_USER_ENUM      4
#define MJC_B4_POLICY_ENUM    5
#define MJC_B4_TIME_ENUM      6

#define MJC_B5_EVENT_ENUM     0
#define MJC_B5_TO_ENUM        1
#define MJC_B5_ORDER_ENUM     2
#define MJC_B5_SUB_ENUM       3
#define MJC_B5_RESULT_ENUM    4

#define MJC_B6_EVENT_ENUM     0
#define MJC_B6_FROM_ENUM      1
#define MJC_B6_ORDER_ENUM     2
#define MJC_B6_SUB_ENUM       3
#define MJC_B6_POLICY_ENUM    4
#define MJC_B6_VALUE_ENUM     5

#define MJC_B7_EVENT_ENUM     0
#define MJC_B7_TO_ENUM        1
#define MJC_B7_ORDER_ENUM     2

#define MJC_B8_EVENT_ENUM     0
#define MJC_B8_TO_ENUM        1
#define MJC_B8_ORDER_ENUM     2

#define MJC_B9_EVENT_ENUM     0
#define MJC_B9_FROM_ENUM      1
#define MJC_B9_ORDER_ENUM     2

/** 
 * 接受数据借口. 
 * 将事件对应数据输出,并按照不通的执行不同的操作. 
 * @param[in]   E_DATA结构体指针. 
 * @param[out]  出错数据相应错误,未出错回参数0.  
 * @par 标识符 
 *      保留 
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-22创建 
 */
int mjc_api_recv(E_DATA *e_data);

/** 
 * m6消息处理函数. 
 * m6消息处理函数接口. 
 * @param[in]   E_DATA结构体指针. 
 * @param[out]  出错数据相应错误,未出错回参数0.  
 * @par 标识符 
 *      保留 
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-28创建 
 */
int mjc_api_m6_handle(E_DATA *e_data);

/*
*再说   简单判断的函数并输出对应的值
*/
/** 
 * mjc模块回复处理接口. 
 * 对于平台发送的事件的数据进行不同的处理，并打印. 
 * @param[in]   事件数据指针以及事件. 
 * @param[out]  出错数据相应错误,未出错回参数0.  
 * @par 标识符 
 *      保留 
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-28创建 
 */
int mjc_api_resp_handle(void *data, char *event);

/** 
 * mjc模块网关发送接口. 
 * 将接收到的数据安装不同的事件进行不同的组合，再发送. 
 * @param[in]   事件数据指针以及事件. 
 * @param[out]  出错数据相应错误,未出错回参数0.  
 * @par 标识符 
 *      保留 
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-28创建 
 */
int mjc_api_send(void *data, char *event);

#endif
