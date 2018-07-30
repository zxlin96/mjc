#include <string.h>
#include "mjc.h"
#include "log.h"
#include "mjc_mem.h"
#include "mjc_strutl.h"
#include "mjc_json.h"

int e_data_init(E_DATA *e_data)
{
    if (e_data == NULL)
    {
        DBG_PRINTF("e_data is NULL\n");
        goto TAG_EXIT;
    }
    e_data->e_handler = NULL;
    e_data->data[0] = "";
    e_data->data_arraysize = 0;

TAG_EXIT:
    return 0;
}

//写一个关于e_data  fill填充的函数, 申请内存 以及 赋值   传参  是  E_HANDLER char** arraysize
/*
*释放了**datatmp 
*/
int e_data_fill(E_DATA *e_data, E_HANDLER *e_tmp, char **data_tmp, int data_arraysize)
{
    DBG_PRINTF("=======================>  e_data_fill");
    int i = 0;
    char rm_mark[JSON_DATA_MAX_SIZE] ={};

    if (e_data == NULL)
    {
        DBG_PRINTF("e_data is NULL\n");
        goto TAG_EXIT;
    }
    if (e_tmp == NULL)
    {
        DBG_PRINTF("e_tmp is NULL\n");
        goto TAG_EXIT;
    }
    if (data_tmp[0] == NULL)
    {
        DBG_PRINTF("data_tmp is NULL\n");
        goto TAG_EXIT;
    }
    e_data->e_handler = mjc_malloc(sizeof(E_HANDLER));
    if (e_data->e_handler == NULL)
    {
        DBG_PRINTF("e_data->e_handler malloc error\n");
        goto TAG_EXIT;
    }
    if (memcpy(e_data->e_handler, e_tmp, sizeof(E_HANDLER)) == NULL)
    {
        DBG_PRINTF("e_data->e_handler mcpy error\n");
        goto TAG_EXIT;
    }

    for (i = 0; i < data_arraysize; i++)
    {

        e_data->data[i] = mjc_malloc(strlen(data_tmp[i]) + 1);
        if (e_data->data[i] == NULL)
        {
            DBG_PRINTF("e_data->data[%d] malloc error\n", i);
            goto TAG_EXIT;
        }
        //rm_mark = malloc(sizeof(strlen(data_tmp[i])+1));
        mjc_json_rm_qutation_mark(rm_mark, data_tmp[i]);
        if (mjc_strncpy(e_data->data[i], rm_mark, strlen(data_tmp[i]) + 1) == NULL)
        {
            DBG_PRINTF("e_data->data[%d] strncpy error\n", i);
            goto TAG_EXIT;
        }
        memset(rm_mark, 0, sizeof(rm_mark));
        //mjc_free(rm_mark);
        //mjc_free(data_tmp[i]);
    }

    e_data->data_arraysize = data_arraysize;

    DBG_PRINTF("<=======================  e_data_fill");

TAG_EXIT:
    return 0;
}

int e_data_free(E_DATA *e_data)
{
    DBG_PRINTF("=============> e_data_free\n");
    int i = 0;

    if (e_data == NULL)
    {
        DBG_PRINTF("e_data is NULL\n");
        goto TAG_EXIT;
    }
    mjc_free(e_data->e_handler);
    DBG_PRINTF("free e_data->e_handler\n");
    for (i = 0; i < e_data->data_arraysize; i++)
    {
        mjc_free(e_data->data[i]);
    }
    mjc_free(e_data);
    DBG_PRINTF("<============= e_data_free\n");
TAG_EXIT:
    return 0;
}
