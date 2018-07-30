/** 
* @file         mjc_type.h 
* @brief        mjc交互模块数据定义 
* @details      定义类型U8/S8/U16/S16/U32/S32/U64,定义E_HANDLER_st结构体
* @author       林展翔 
* @version      V1.0 
* @par History:          
*  
*/ 

#ifndef _MJC_TYPE_H_
#define _MJC_TYPE_H_

typedef unsigned    char      U8;
typedef signed      char      S8;
typedef unsigned    short     U16;
typedef signed      short     S16;
typedef unsigned    int       U32;
typedef signed      int       S32;
typedef unsigned    long long  U64;

/** 事件处理结构体 */
typedef struct E_HANDLER_ST
{
    char *event;                                    //事件名
    char **param_event;                             //事件参数
    int event_arraysize;                            //事件参数个数
    char *subname;                                  //主题名
    char **sub_event;                               //主题参数
    int sub_arraysize;                              //主题参数个数
    int timer_en;                                   //定时器使能
    int (*func)(cJSON *,struct E_HANDLER_ST * );    //事件处理回调函数
} E_HANDLER;

#endif