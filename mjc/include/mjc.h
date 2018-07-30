/** 
* @file         mjc.h 
* @brief        包含相应的通用头文件 
* @details      包含相应的通用头文件
* @author       林展翔 
* @version      V1.0 
* @par History:          
*  
*/

#ifndef _MJC_H_
#define _MJC_H_
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "mjc_type.h"
#include "mjc_mqtt.h"
#include "mjc_mem.h"
#include "mjc_strutl.h"

/** JSON数据object最大个数 */
#define JSON_OBJ_MAX_SIZE 10

/** 事件object对应的枚举数值 */
#define M0_E_INDX_ENUM 0
#define M0_F_INDX_ENUM 1
#define M0_I_INDX_ENUM 2
#define M0_B_INDX_ENUM 3
#define M0B_S_INDX_ENUM 4
#define M1_E_INDX_ENUM 0
#define M1_T_INDX_ENUM 1
#define M1_I_INDX_ENUM 2
#define M1_K_INDX_ENUM 3
#define M6_E_INDX_ENUM 0

/** 
 * 事件数据结构体. 
 * 存放事件处理结构体,事件对应数据,事件数据个数. 
 */
typedef struct E_DATA_ST
{
    E_HANDLER *e_handler;          //事件处理结构体
    char *data[JSON_OBJ_MAX_SIZE]; //事件对应数据
    int data_arraysize;            //事件数据个数
} E_DATA;

/** 
 * 具体事件数据结构体. 
 * 存放每一个事件对应的不同数据，以下类同. 
 */
typedef struct MJC_M0_DATA_ST
{
    char *event;   //事件
    char *form;    //充电终端序列号/网关序列号
    char *order;   //消息序号
    char *sub;     //主题
    char *s;       //插座数量
    char *gateway; //网关序列号
} M0_DATA;

typedef struct MJC_M1_DATA_ST
{
    char *event; //事件
    char *to;    //目标设备序列号
    char *order; //消息序号
    char *keep;  //保活时间
} M1_DATA;

typedef struct MJC_M2_DATA_ST
{
    char *event; //事件
    char *form;  //充电终端序列号
    char *order; //消息序号
} M2_DATA;

typedef struct MJC_M3_DATA_ST
{
    char *event; //事件
    char *to;    //目标设备序列号
    char *order; //消息序号
} M3_DATA;

typedef struct MJC_M4_DATA_ST
{
    char *event;  //事件
    char *form;   //充电终端序列号
    char *order;  //消息序号
    char *sub;    //主题
    char *reason; //原因
    char *detail; //细节
} M4_DATA;

typedef struct MJC_M5_DATA_ST
{
    char *event; //事件
    char *to;    //目标设备序列号
    char *order; //消息序号
} M5_DATA;

typedef struct MJC_M6_DATA_ST
{
    char *event;   //事件
    char *to;      //充电终端序列号
    char *order;   //消息序号
    char *sub;     //主题
    char *p;       //升级包链接地址
    char *version; //软件版本号
} M6_DATA;

typedef struct MJC_M7_DATA_ST
{
    char *event; //事件
    char *form;  //充电终端序列号
    char *order; //消息序号
} M7_DATA;

typedef struct MJC_M8_DATA_ST
{
    char *event; //事件
    char *form;  //充电终端序列号
    char *order; //消息序号
} M8_DATA;

typedef struct MJC_M9_DATA_ST
{
    char *event; //事件
    char *to;    //目标设备序列号
    char *order; //消息序号
} M9_DATA;

typedef struct MJC_M10_DATA_ST
{
    char *event;   //事件
    char *to;      //充电终端序列号
    char *order;   //消息序号
    char *sub;     //主题
    char *cfg;     //升级包链接地址
    char *version; //软件版本号
} M10_DATA;

typedef struct MJC_M11_DATA_ST
{
    char *event; //事件
    char *form;  //充电终端序列号
    char *order; //消息序号
} M11_DATA;

typedef struct MJC_M12_DATA_ST
{
    char *event; //事件
    char *to;    //充电终端序列号
    char *order; //消息序号
} M12_DATA;

typedef struct MJC_M13_DATA_ST
{
    char *event; //事件
    char *form;  //充电终端序列号
    char *order; //消息序号
} M13_DATA;

typedef struct MJC_B0_DATA_ST
{
    char *event;    //事件
    char *to;       //充电终端序列号
    char *order;    //消息序号
    char *sub;      //主题
    char *user;     //用户信息
    char *policy;   //供电策略
    char *time_len; //时长
} B0_DATA;

typedef struct MJC_B1_DATA_ST
{
    char *event; //事件
    char *form;  //充电终端序列号
    char *order; //消息序号
} B1_DATA;

typedef struct MJC_B2_DATA_ST
{
    char *event;  //事件
    char *form;   //充电终端序列号
    char *order;  //消息序号
    char *sub;    //主题
    char *result; //结果
    char *detail; //细节
} B2_DATA;

typedef struct MJC_B3_DATA_ST
{
    char *event; //事件
    char *to;    //目标设备序列号
    char *order; //消息序号
} B3_DATA;

typedef struct MJC_B4_DATA_ST
{
    char *event;    //事件
    char *form;     //充电终端序列号
    char *order;    //消息序号
    char *sub;      //主题
    char *user;     //用户信息
    char *policy;   //供电策略
    char *time_len; //时长
} B4_DATA;

typedef struct MJC_B5_DATA_ST
{
    char *event;  //事件
    char *to;     //充电终端序列号
    char *order;  //消息序号
    char *sub;    //主题
    char *result; //结果
} B5_DATA;

typedef struct MJC_B6_DATA_ST
{
    char *event;  //事件
    char *form;   //充电终端序列号
    char *order;  //消息序号
    char *sub;    //主题
    char *policy; //供电策略
    char *value;  //充电时长
} B6_DATA;

typedef struct MJC_B7_DATA_ST
{
    char *event; //事件
    char *to;    //目标设备序列号
    char *order; //消息序号
} B7_DATA;

typedef struct MJC_B8_DATA_ST
{
    char *event; //事件
    char *to;    //目标设备序列号
    char *order; //消息序号
} B8_DATA;

typedef struct MJC_B9_DATA_ST
{
    char *event; //事件
    char *form;  //充电终端序列号
    char *order; //消息序号
} B9_DATA;

/** 
 * 获取消息序列. 
 * 获取到当前能够使用的消息序列号. 
 * @param[in]   NULL. 
 * @param[out]  当前能使用的消息序列号.  
 * @par 标识符 
 *      保留 
 * @par 其它 
 *      无 
 * @par 修改日志 
 *      林展翔于2018-07-30创建 
 */
U16 mjc_get_order();

#endif
