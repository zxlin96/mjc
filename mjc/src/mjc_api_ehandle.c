#include "mjc_api.h"

int mjc_api_m6_handle(E_DATA *e_data)
{
    E_DATA *req_data;
    char *data_test[] = {"E7", "abc123", "1234"};
    //char *data_test2[] = {"E10", "abc123", "1234","","www.baidu.com","1.1.0"};
    int i = 0;

    DBG_PRINTF("=======================> m6_handle\n");
    if(e_data == NULL)
    {
        DBG_PRINTF("e_data is NULL\n");
        goto TAG_EXIT;
    }
    /*
    *这里应该先把e_data数据发给少滨的部分，获得相应的数据再将数据回复回去
    *我这里就假设以及获得了相应的数据，并将数据先尝试的发出去
    * */

    req_data = mjc_malloc(sizeof(E_DATA));
    e_data_init(req_data);
    req_data->e_handler = mjc_malloc(sizeof(E_HANDLER));
    mjc_json_get_event_handle_struct(req_data->e_handler, "M7");
    DBG_PRINTF("evevt :%s\n",req_data->e_handler->event);
    req_data->data_arraysize = 3;
    for (i = 0; i < req_data->data_arraysize; i++)
    {

        req_data->data[i] = mjc_malloc(strlen(data_test[i]) + 1);
        if (req_data->data[i] == NULL)
        {
            DBG_PRINTF("e_data->data[%d] malloc error\n", i);
            goto TAG_EXIT;
        }
        if (mjc_strncpy(req_data->data[i], data_test[i], strlen(data_test[i]) + 1) == NULL)
        {
            DBG_PRINTF("e_data->data[%d] strncpy error\n", i);
            goto TAG_EXIT;
        }
        DBG_PRINTF("data_test[%d]:  %s", i, data_test[i]);
    }

    mjc_json_pkt(req_data);
    e_data_free(req_data);
    DBG_PRINTF("<======================= m6_handle\n");


TAG_EXIT:
   return 0;
}

int mjc_api_resp_handle(void *data, char *event)
{
    DBG_PRINTF("=======================> mjc_api_resp_handle\n");
    if(data == NULL)
    {
        DBG_PRINTF("data is NULL\n");
        goto TAG_EXIT;
    }

    if(event == NULL)
    {
        DBG_PRINTF("data is NULL\n");
        goto TAG_EXIT;
    }

    if(!mjc_strncmp(event, MJC_E_M1, sizeof(MJC_E_M1)))
    {
        M1_DATA *m1_tmp;
        m1_tmp = (M1_DATA *)data;
        //pthread_t pid;

        printf("event:%s\t\n",m1_tmp->event);
        printf("to:%s\t\n",m1_tmp->to);
        printf("order:%s\t\n",m1_tmp->order);
        printf("keep:%s\t\n",m1_tmp->keep);

        
        //if(m1_tmp->keep != NULL)
        if(atoi(m1_tmp->keep) != 0)
        {
            DBG_PRINTF("keep alive time is %d\n",atoi(m1_tmp->keep));
            //pthread_create();
        }
    }
    else if(!mjc_strncmp(event, MJC_E_M3, sizeof(MJC_E_M3)))
    {
        M3_DATA *m3_tmp;
        m3_tmp = (M3_DATA *)data;
        printf("event:%s\t\n",m3_tmp->event);
        printf("to:%s\t\n",m3_tmp->to);
        printf("order:%s\t\n",m3_tmp->order);
    }
    else if(!mjc_strncmp(event, MJC_E_M5, sizeof(MJC_E_M5)))
    {
        M5_DATA *m5_tmp;
        m5_tmp = (M5_DATA *)data;
        printf("event:%s\t\n",m5_tmp->event);
        printf("to:%s\t\n",m5_tmp->to);
        printf("order:%s\t\n",m5_tmp->order);
    }
    else if(!mjc_strncmp(event, MJC_E_M6, sizeof(MJC_E_M6)))
    {
        M6_DATA *m6_tmp;
        m6_tmp = (M6_DATA *)data;
        printf("event:%s\t\n",m6_tmp->event);
        printf("to:%s\t\n",m6_tmp->to);
        printf("order:%s\t\n",m6_tmp->order);
        printf("sub:%s\t\n", m6_tmp->sub);
        printf("p:%s\t\n", m6_tmp->p);
        printf("version:%s\t\n", m6_tmp->version);
        M7_DATA m7_data;
        m7_data.event = "M7";
        m7_data.form = "ZHKJ00000000F";
        m7_data.order = mjc_malloc(mjc_strlen(m6_tmp->order)+1);
        mjc_strncpy(m7_data.order, m6_tmp->order, mjc_strlen(m6_tmp->order)+1);
        //m7_data.order = "1234";
        mjc_api_send(&m7_data,"M7");
        mjc_free(m7_data.order);
    }
    else if(!mjc_strncmp(event, MJC_E_M9, sizeof(MJC_E_M9)))
    {
        M9_DATA *m9_tmp;
        m9_tmp = (M9_DATA *)data;
        printf("event:%s\t\n",m9_tmp->event);
        printf("to:%s\t\n",m9_tmp->to);
        printf("order:%s\t\n",m9_tmp->order);
    }
    else if(!mjc_strncmp(event, MJC_E_M10, sizeof(MJC_E_M10)))
    {
        M10_DATA *m10_tmp;
        m10_tmp = (M10_DATA *)data;
        printf("event:%s\t\n",m10_tmp->event);
        printf("to:%s\t\n",m10_tmp->to);
        printf("order:%s\t\n",m10_tmp->order);
        printf("sub:%s\t\n", m10_tmp->sub);
        printf("cfg:%s\t\n", m10_tmp->cfg);
        printf("version:%s\t\n", m10_tmp->version);
        M11_DATA m11_data;
        m11_data.event = "M11";
        m11_data.form = "ZHKJ00000000F";
        //m11_data.order = "1234";
        m11_data.order = mjc_malloc(mjc_strlen(m10_tmp->order)+1);
        mjc_strncpy(m11_data.order, m10_tmp->order, mjc_strlen(m10_tmp->order)+1);
        mjc_api_send(&m11_data,"M11");
        mjc_free(m11_data.order);
    }
    else if(!mjc_strncmp(event, MJC_E_M12, sizeof(MJC_E_M12)))
    {
        M12_DATA *m12_tmp;
        m12_tmp = (M12_DATA *)data;
        printf("event:%s\t\n",m12_tmp->event);
        printf("to:%s\t\n",m12_tmp->to);
        printf("order:%s\t\n",m12_tmp->order);
        M13_DATA m13_data;
        m13_data.event = "M13";
        m13_data.form = "ZHKJ00000000F";
        //m13_data.order = "1234";
        m13_data.order = mjc_malloc(mjc_strlen(m12_tmp->order)+1);
        mjc_strncpy(m13_data.order, m12_tmp->order, mjc_strlen(m12_tmp->order)+1);
        mjc_api_send(&m13_data,"M13");
        mjc_free(m13_data.order);
    }
    else if(!mjc_strncmp(event, MJC_E_B0, sizeof(MJC_E_B0)))
    {
        B0_DATA *b0_tmp;
        b0_tmp = (B0_DATA *)data;
        printf("event:%s\t\n",b0_tmp->event);
        printf("to:%s\t\n",b0_tmp->to);
        printf("order:%s\t\n",b0_tmp->order);
        printf("sub:%s\t\n", b0_tmp->sub);
        printf("user:%s\t\n", b0_tmp->user);
        printf("policy:%s\t\n", b0_tmp->policy);
        printf("time:%s\t\n", b0_tmp->time_len);
        B1_DATA b1_data;
        b1_data.event = "B1";
        b1_data.form = "ZHKJ0020000FF1";
        b1_data.order = mjc_malloc(mjc_strlen(b0_tmp->order)+1);
        mjc_strncpy(b1_data.order, b0_tmp->order, mjc_strlen(b0_tmp->order)+1);
        //b1_data.order = "1234";
        mjc_api_send(&b1_data,"B1");
        mjc_free(b1_data.order);
    }
    else if(!mjc_strncmp(event, MJC_E_B3, sizeof(MJC_E_B3)))
    {
        B3_DATA *b3_tmp;
        b3_tmp = (B3_DATA *)data;
        printf("event:%s\t\n",b3_tmp->event);
        printf("to:%s\t\n",b3_tmp->to);
        printf("order:%s\t\n",b3_tmp->order);

    }
    else if(!mjc_strncmp(event, MJC_E_B5, sizeof(MJC_E_B5)))
    {
        B5_DATA *b5_tmp;
        b5_tmp = (B5_DATA *)data;
        printf("event:%s\t\n",b5_tmp->event);
        printf("to:%s\t\n",b5_tmp->to);
        printf("order:%s\t\n",b5_tmp->order);
        printf("sub:%s\t\n", b5_tmp->sub);
        printf("result:%s\t\n", b5_tmp->result);
    }
    else if(!mjc_strncmp(event, MJC_E_B7, sizeof(MJC_E_B7)))
    {
        B7_DATA *b7_tmp;
        b7_tmp = (B7_DATA *)data;
        printf("event:%s\t\n",b7_tmp->event);
        printf("to:%s\t\n",b7_tmp->to);
        printf("order:%s\t\n",b7_tmp->order);

    }
    else if(!mjc_strncmp(event, MJC_E_B8, sizeof(MJC_E_B8)))
    {
        B8_DATA *b8_tmp;
        b8_tmp = (B8_DATA *)data;
        printf("event:%s\t\n",b8_tmp->event);
        printf("to:%s\t\n",b8_tmp->to);
        printf("order:%s\t\n",b8_tmp->order);
        B9_DATA b9_data;
        b9_data.event = "B9";
        b9_data.form = "ZHKJ0020000FF1";
        b9_data.order = mjc_malloc(mjc_strlen(b8_tmp->order)+1);
        mjc_strncpy(b9_data.order, b8_tmp->order, mjc_strlen(b8_tmp->order)+1);
        //b9_data.order = "9234";
        mjc_api_send(&b9_data,"B9");
        mjc_free(b9_data.order);
    }

    DBG_PRINTF("<======================= mjc_api_resp_handle\n");


TAG_EXIT:
   return 0;
}

int mjc_api_checkup(void *data, char *event)
{
    DBG_PRINTF("=======================> mjc_api_checkup\n");
    if(data == NULL)
    {
        DBG_PRINTF("data is NULL\n");
        goto TAG_EXIT;
    }

    if(event == NULL)
    {
        DBG_PRINTF("data is NULL\n");
        goto TAG_EXIT;
    }

    if(!mjc_strncmp(event, MJC_E_M1, sizeof(MJC_E_M1)))
    {

    }

    DBG_PRINTF("<======================= mjc_api_checkup\n");

TAG_EXIT:
   return 0;
}