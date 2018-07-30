#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mjc_json.h"
#include "mjc.h"
#include "log.h"
#include "mjc_strutl.h"

#define STR_MJC_BODY "B"
#define STR_MJC_COUNT "C"
#define STR_MJC_FROM "F"
#define STR_MJC_TEST "C"
#define MJC_REQ_DATA 1

/*
xxx_data
{
    E_HANDLER_ST *
    char ** value;
    int value_nums;
    char * subname;
    char ** sub_value;
    int sub_value_nums;
}
init_xxx_data（××data）{
}

free_xxx_data()
*/
/*
*功能:将数据转成json格式,并调用发送函数
*/
int mjc_json_pkt(E_DATA *e_data)
{
    DBG_PRINTF("=================================> mjc_json_pkt \n");
    cJSON *root = NULL, *sub = NULL;
    char *out;
    int i = 0;
    if(e_data == NULL)
    {
        DBG_PRINTF("mjc_json_pkt e_data is NULL!!!\n");
        goto TAG_EXIT;
    }

    root = cJSON_CreateObject();
    if(root == NULL)
    {
        DBG_PRINTF("creat root is error");
        goto TAG_EXIT;
    }

    DBG_PRINTF("EVENT :%s\n",e_data->data[0]);
    cJSON_AddStringToObject(root, MJC_OBJ_EVENT, e_data->data[M6_E_INDX_ENUM]);
    for (i = 1;e_data->e_handler->param_event[i-1] != NULL && i < e_data->data_arraysize; i++)
    {
        //判断是否有sub，若有就添加一个sub，并接下去循环
        if(!mjc_strncmp(e_data->e_handler->param_event[i-1], e_data->e_handler->subname, mjc_strlen(e_data->e_handler->subname)+1))
        {
            cJSON_AddItemToObject(root, e_data->e_handler->subname, sub = cJSON_CreateObject());
            if(sub == NULL)
            {
                DBG_PRINTF("creat sub is error");
                goto TAG_EXIT;
            }
            else
            {
                DBG_PRINTF("creat sub is success!!");
            }
            //continue;
            break;
        }
        cJSON_AddStringToObject(root, e_data->e_handler->param_event[i-1], e_data->data[i]);
        DBG_PRINTF("data:%s\t,data_count:%d\n", e_data->data[i], i);
    }

    //&&e_data->e_handler->sub_event[i] != NULL 
    for (i = 0;e_data->e_handler->sub_arraysize != 0 && i+e_data->e_handler->event_arraysize +1 < e_data->data_arraysize; i++)
    {
        DBG_PRINTF("add sub object!!!!!\n");
        cJSON_AddStringToObject(sub, e_data->e_handler->sub_event[i], e_data->data[i+e_data->e_handler->event_arraysize+1]);
    }
    out = cJSON_Print(root);
    
    //if(e_data->e_handler->timer_en == MJC_REQ_DATA)
    //    mjc_mqtt_pub(out);
    //else
    mjc_mqtt_resp_pub(out);

    cJSON_Delete(root);
    printf("%s\n", out);
    mjc_free(out);

    DBG_PRINTF("<================================= mjc_json_pkt OUT\n");
TAG_EXIT:
    return 0;
}