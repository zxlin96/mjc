#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mjc_json.h"
#include "log.h"
#include "mjc_mem.h"
#include "mjc_strutl.h"
#include "mjc_utl.h"
#include "mjc_api.h"

static char *ParamM0[] = {MJC_OBJ_FROM, MJC_OBJ_ORDER, MJC_OBJ_SUB};
static char *ParamM0_B[] = {MJC_OBJ_S, MJC_OBJ_GATEWAY};
static char *ParamM1[] = {MJC_OBJ_TO, MJC_OBJ_ORDER, MJC_OBJ_KEEP};
static char *ParamM2[] = {MJC_OBJ_FROM, MJC_OBJ_ORDER};
static char *ParamM3[] = {MJC_OBJ_TO, MJC_OBJ_ORDER};
static char *ParamM4[] = {MJC_OBJ_FROM, MJC_OBJ_ORDER, MJC_OBJ_SUB};
static char *ParamM4_B[] = {MJC_OBJ_REASON, MJC_OBJ_DETAIL};
static char *ParamM5[] = {MJC_OBJ_TO, MJC_OBJ_ORDER};
static char *ParamM6[] = {MJC_OBJ_TO, MJC_OBJ_ORDER, MJC_OBJ_SUB};
static char *ParamM6_B[] = {MJC_OBJ_P, MJC_OBJ_VERSION};
static char *ParamM7[] = {MJC_OBJ_FROM, MJC_OBJ_ORDER};
static char *ParamM8[] = {MJC_OBJ_FROM, MJC_OBJ_ORDER};
static char *ParamM9[] = {MJC_OBJ_TO, MJC_OBJ_ORDER};
static char *ParamM10[] = {MJC_OBJ_TO, MJC_OBJ_ORDER, MJC_OBJ_SUB};
static char *ParamM10_B[] = {MJC_OBJ_CFG, MJC_OBJ_VERSION};
static char *ParamM11[] = {MJC_OBJ_FROM, MJC_OBJ_ORDER};
static char *ParamM12[] = {MJC_OBJ_TO, MJC_OBJ_ORDER};
static char *ParamM13[] = {MJC_OBJ_FROM, MJC_OBJ_ORDER};
static char *ParamB0[] = {MJC_OBJ_TO, MJC_OBJ_ORDER, MJC_OBJ_SUB};
static char *ParamB0_B[] = {MJC_OBJ_USER, MJC_OBJ_POLICY, MJC_OBJ_TIME};
static char *ParamB1[] = {MJC_OBJ_FROM, MJC_OBJ_ORDER};
static char *ParamB2[] = {MJC_OBJ_FROM, MJC_OBJ_ORDER, MJC_OBJ_SUB};
static char *ParamB2_B[] = {MJC_OBJ_RESULT, MJC_OBJ_DETAIL};
static char *ParamB3[] = {MJC_OBJ_TO, MJC_OBJ_ORDER};
static char *ParamB4[] = {MJC_OBJ_FROM, MJC_OBJ_ORDER, MJC_OBJ_SUB};
static char *ParamB4_B[] = {MJC_OBJ_USER, MJC_OBJ_POLICY, MJC_OBJ_TIME};
static char *ParamB5[] = {MJC_OBJ_TO, MJC_OBJ_ORDER, MJC_OBJ_SUB};
static char *ParamB5_B[] = {MJC_OBJ_RESULT};
static char *ParamB6[] = {MJC_OBJ_FROM, MJC_OBJ_ORDER, MJC_OBJ_SUB};
static char *ParamB6_B[] = {MJC_OBJ_POLICY, MJC_OBJ_VALUE};
static char *ParamB7[] = {MJC_OBJ_TO, MJC_OBJ_ORDER};
static char *ParamB8[] = {MJC_OBJ_TO, MJC_OBJ_ORDER};
static char *ParamB9[] = {MJC_OBJ_FROM, MJC_OBJ_ORDER};

static struct E_HANDLER_ST e_handle[] =
    {
        {MJC_E_M0, ParamM0, 3, MJC_OBJ_SUB, ParamM0_B, 2, 1, &mjc_json_resolve},
        {MJC_E_M1, ParamM1, 3, NULL, NULL, 0, 0, &mjc_json_resolve},
        {MJC_E_M2, ParamM2, 2, NULL, NULL, 0, 1, &mjc_json_resolve},
        {MJC_E_M3, ParamM3, 2, NULL, NULL, 0, 0, &mjc_json_resolve},
        {MJC_E_M4, ParamM4, 3, MJC_OBJ_SUB, ParamM4_B, 2, 1, &mjc_json_resolve},
        {MJC_E_M5, ParamM5, 2, NULL, NULL, 0, 0, &mjc_json_resolve},
        {MJC_E_M6, ParamM6, 3, MJC_OBJ_SUB, ParamM6_B, 2, 1, &mjc_json_resolve},
        {MJC_E_M7, ParamM7, 2, NULL, NULL, 0, 0, &mjc_json_resolve},
        {MJC_E_M8, ParamM8, 2, NULL, NULL, 0, 1, &mjc_json_resolve},
        {MJC_E_M9, ParamM9, 2, NULL, NULL, 0, 0, &mjc_json_resolve},
        {MJC_E_M10, ParamM10, 3, MJC_OBJ_SUB, ParamM10_B, 2, 1, &mjc_json_resolve},
        {MJC_E_M11, ParamM11, 2, NULL, NULL, 0, 0, &mjc_json_resolve},
        {MJC_E_M12, ParamM12, 2, NULL, NULL, 0, 1, &mjc_json_resolve},
        {MJC_E_M13, ParamM13, 2, NULL, NULL, 0, 0, &mjc_json_resolve},
        {MJC_E_B0, ParamB0, 3, MJC_OBJ_SUB, ParamB0_B, 3, 1, &mjc_json_resolve},
        {MJC_E_B1, ParamB1, 2, NULL, NULL, 0, 0, &mjc_json_resolve},
        {MJC_E_B2, ParamB2, 3, MJC_OBJ_SUB, ParamB2_B, 2, 1, &mjc_json_resolve},
        {MJC_E_B3, ParamB3, 2, NULL, NULL, 0, 0, &mjc_json_resolve},
        {MJC_E_B4, ParamB4, 3, MJC_OBJ_SUB, ParamB4_B, 3, 1, &mjc_json_resolve},
        {MJC_E_B5, ParamB5, 3, MJC_OBJ_SUB, ParamB5_B, 1, 0, &mjc_json_resolve},
        {MJC_E_B6, ParamB6, 3, MJC_OBJ_SUB, ParamB6_B, 2, 1, &mjc_json_resolve},
        {MJC_E_B7, ParamB7, 2, NULL, NULL, 0, 0, &mjc_json_resolve},
        {MJC_E_B8, ParamB8, 2, NULL, NULL, 0, 0, &mjc_json_resolve},
        {MJC_E_B9, ParamB9, 2, NULL, NULL, 0, 0, &mjc_json_resolve},
};

/*
*从字符串获取json数据，再解析出第一个数据，调用相应的回调函数
*/
int mjc_json_handle(char *text)
{
    DBG_PRINTF("=======================>  mjc_json_handle IN\n");
    cJSON *json = NULL, *value = NULL;
    char *out_str = NULL, *key = NULL;
    int i;
    char s[10];
    
    if(text == NULL)
    {
        printf("text is NULL\n");
        goto TAG_EXIT;
    }
    DBG_PRINTF("%s", text);
    json = cJSON_Parse(text);
    if (!json)
    {
        printf("Error before: [%s]\n", cJSON_GetErrorPtr());
        goto TAG_EXIT;
    }
    out_str = cJSON_Print(json);
    printf("\nJSON_DATA:\n%s\nDATA_SIZE:%ld\n", out_str, strlen(out_str));
    if (out_str == NULL)
    {
        DBG_PRINTF("get json data error\n");
        goto TAG_EXIT;
    }

    value = cJSON_GetObjectItem(json, "E");
    key = cJSON_Print(value);
    DBG_PRINTF("key:%s\n", key);
    if (!value)
    {
        printf("Error before: [%s]\n", cJSON_GetErrorPtr());
        goto TAG_EXIT;
    }
    if (key == NULL)
    {
        DBG_PRINTF("get json data error\n");
        goto TAG_EXIT;
    }

    /*
    *比对第一个数据判断有无相应的指令
    */
    for (i = 0; e_handle[i].event != NULL; i++)
    {
        sprintf(s, "\"%s\"", e_handle[i].event);
        DBG_PRINTF("s：%s\n", s);
        if (!strcmp(key, s))
        {
            DBG_PRINTF("1%s\n", key);
            //调用回调函数
            e_handle[i].func(json, &e_handle[i]);
            if (e_handle[i].timer_en)
            {
                /*
                *启用记时过程，或许不是放在这，放在获取参数的后面
                */
            }
            //DBG_PRINTF("%s\n", e_handle[i].event);
            break;
        }
    }

    mjc_free(out_str);
    mjc_free(key);
    //cJSON_Delete(value);  //这里注意一下是什么问题  在deletejson时候会把子项目给delete  所以 一般只delete主
    cJSON_Delete(json);
    DBG_PRINTF("<==========================  mjc_json_handle OUT\n");

TAG_EXIT:
    return 0;
}


/*
*回调函数从中处理处理出想要的数据
*/
int mjc_json_resolve(cJSON *json,E_HANDLER *e_tmp)
{
    DBG_PRINTF("=====================>  mjc_json_resolve IN\n");
    int i, data_count;
    cJSON *value, *sub, *value_sub;
    char *data_tmp = NULL;
    char *data_a[JSON_OBJ_MAX_SIZE] = {};
    E_DATA *send_data = NULL;

    if(json == NULL)
    {
        DBG_PRINTF("json is NULL\n");
        goto TAG_EXIT;
    }
    if(e_tmp == NULL)
    {
        DBG_PRINTF("e_tmp is NULL\n");
        goto TAG_EXIT;
    }
    send_data = mjc_malloc(sizeof(E_DATA));
    if(send_data == NULL)
    {
        DBG_PRINTF("send_data malloc error!\n");
        goto TAG_EXIT;
    }
    if(e_data_init(send_data))
    {
        DBG_PRINTF("e_data init error!\n");
        goto TAG_EXIT;
    }
    data_count = 0;
    DBG_PRINTF("I'm in here\n");
    data_a[data_count] = (char *)mjc_malloc(strlen(e_tmp->event)+1);
    mjc_strncpy(data_a[data_count], e_tmp->event,strlen(e_tmp->event)+1);
    //data_a[data_count] = e_tmp->event;
    DBG_PRINTF("E:%s\n", data_a[data_count]);
    data_count++;
    DBG_PRINTF("data_count:%d\n", data_count);

    /*
    *获取事件event数据
    */
    
    for (i = 0; i < e_tmp->event_arraysize; i++)
    {
        value = cJSON_GetObjectItem(json, e_tmp->param_event[i]);
        if(value == NULL)
        {
            if(!mjc_strncmp(e_tmp->event, MJC_E_M1, sizeof(MJC_E_M1)) && !mjc_strncmp(e_tmp->param_event[i], MJC_OBJ_KEEP, sizeof(MJC_OBJ_KEEP)))
            {
                DBG_PRINTF("this M1.K error!\n");
                data_a[data_count] = (char *)mjc_malloc(strlen("")+1);
                mjc_strncpy(data_a[data_count], "",strlen("")+1);
                data_count++;
                continue;
            }
            DBG_PRINTF("error object %s",e_tmp->param_event[i]);
            goto TAG_EXIT;
        }
        DBG_PRINTF("%s", e_tmp->param_event[i]);
        data_tmp = cJSON_Print(value);
        data_a[data_count] = (char *)mjc_malloc(strlen(data_tmp)+1);
        mjc_strncpy(data_a[data_count], data_tmp,strlen(data_tmp)+1);
        DBG_PRINTF("%s\n", data_a[data_count]);
        data_count++;
        mjc_free(data_tmp);
    }

    DBG_PRINTF("e_arraysize:%d,i:%d\n", e_tmp->event_arraysize, i);
    DBG_PRINTF("data_count:%d\n", data_count);
    DBG_PRINTF("E:%s,T:%s\n", data_a[0], data_a[1]);

    if (e_tmp->sub_arraysize > 0)
    {
        sub = cJSON_GetObjectItem(json, e_tmp->subname);
        if (sub == NULL)
            return 0;
    }

    /*
    *B消息体数据
    */
    for (i = 0; i < e_tmp->sub_arraysize; i++)
    {
        value_sub = cJSON_GetObjectItem(sub, e_tmp->sub_event[i]);
        if(value_sub == NULL)
        {
            DBG_PRINTF("error object %s",e_tmp->param_event[i]);
            goto TAG_EXIT;
        }
        DBG_PRINTF("%s", e_tmp->sub_event[i]);
        data_tmp = cJSON_Print(value_sub);
        data_a[data_count] = (char *)mjc_malloc(strlen(data_tmp)+1);
        mjc_strncpy(data_a[data_count], data_tmp,strlen(data_tmp)+1);
        DBG_PRINTF("%s\n", data_a[data_count]);
        data_count++;
        mjc_free(data_tmp);
    }

    for(i = 0; i < data_count; i++)
    {
        DBG_PRINTF("data:\t%s\n",data_a[i]);
    }

    e_data_fill(send_data, e_tmp, data_a, data_count);
    DBG_PRINTF("EVENT: %s\n",send_data->e_handler->event);
    mjc_api_recv(send_data);
    //DBG_PRINTF("EVENT%d\n",send_data.e_handler->event_arraysize);
    //写一个关于e_data  fill填充的函数, 申请内存 以及 赋值   传参  是  E_HANDLER char** arraysize
    //释放 的时候要先把里面的东西释放掉 再释放最外面的
    
TAG_EXIT:
    DBG_PRINTF("<============================ mjc_json_resolve OUT \n");
    //for (i = 0; i < e_tmp->sub_arraysize; i++)
    for (i = 0; i < data_count; i++)
    {
        mjc_free(data_a[i]);
    }
    e_data_free(send_data);
    return 0;
}

int mjc_json_rm_qutation_mark(char *tmp,char *data)
{
    int i = 0;

    if(tmp == NULL || data == NULL)
    {
        DBG_PRINTF("input parameter error");
        goto TAG_EXIT;
    }

    while (*data != '\0')
    {
        if (*data != '\"')
        {
            tmp[i] = *data; //找到数字，存放到数组tmp里
            i++;
        }
        data++; //data指针指向字符串下一个字符
    }
    tmp[i] = '\0';

TAG_EXIT:
    return 0;
}

int mjc_json_get_event_handle_struct(E_HANDLER *e_tmp, char *event)
{
    int i = 0;
    int event_len = 0;

    DBG_PRINTF("==================================> get_event_handle_struct\n");
    
    if(e_handle == NULL)
    {
        printf("e_handle is NULL!!\n");
        goto TAG_EXIT;
    }

    if(event == NULL)
    {
        printf("event is NULL!!\n");
        goto TAG_EXIT;
    }

    event_len = mjc_strlen(event);
    DBG_PRINTF("event: %s  event_len： %d\n",event, event_len);
    for(i = 0; e_handle[i].event != NULL; i++)
    {
        if(!mjc_strncmp(event,e_handle[i].event,event_len))
        {
            DBG_PRINTF("I find it !!!!!!!!!!\n");
            if (memcpy(e_tmp, &e_handle[i], sizeof(E_HANDLER)) == NULL)
            {
                DBG_PRINTF("memcpy error\n");
                goto TAG_EXIT;
            } 
        }
    }

    

    DBG_PRINTF("<================================= get_event_handle_struct\n");
TAG_EXIT:
    return 0;
}