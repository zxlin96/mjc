#include "mjc.h"
#include "log.h"
#include "mjc_strutl.h"
#include "mjc_json.h"
#include "mjc_api.h"

int mjc_api_send(void *data, char *event)
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


    if(!mjc_strncmp(event, MJC_E_M0, sizeof(MJC_E_M0)))
    {
        M0_DATA *m0_tmp = NULL;
        E_DATA *req_data = NULL;

        m0_tmp = (M0_DATA *)data;
        req_data = mjc_malloc(sizeof(E_DATA));
        e_data_init(req_data);
        req_data->e_handler = mjc_malloc(sizeof(E_HANDLER));
        mjc_json_get_event_handle_struct(req_data->e_handler, MJC_E_M0);
        DBG_PRINTF("evevt :%s\n",req_data->e_handler->event);
        req_data->data_arraysize = req_data->e_handler->event_arraysize + req_data->e_handler->sub_arraysize + 1;

        req_data->data[MJC_M0_EVENT_ENUM] = mjc_malloc(mjc_strlen(m0_tmp->event)+1);
        //DBG_PRINTF("event :%s, event_len: %d\n", m0_tmp->event, mjc_strlen(m0_tmp->event)+1);
        mjc_strncpy(req_data->data[MJC_M0_EVENT_ENUM], m0_tmp->event, mjc_strlen(m0_tmp->event)+1);
        req_data->data[MJC_M0_FROM_ENUM] = mjc_malloc(mjc_strlen(m0_tmp->form)+1);
        mjc_strncpy(req_data->data[MJC_M0_FROM_ENUM], m0_tmp->form, mjc_strlen(m0_tmp->form)+1);
        req_data->data[MJC_M0_ORDER_ENUM] = mjc_malloc(mjc_strlen(m0_tmp->order)+1);
        mjc_strncpy(req_data->data[MJC_M0_ORDER_ENUM], m0_tmp->order, mjc_strlen(m0_tmp->order)+1);
        req_data->data[MJC_M0_SUB_ENUM] = mjc_malloc(mjc_strlen(m0_tmp->sub)+1);
        mjc_strncpy(req_data->data[MJC_M0_SUB_ENUM], m0_tmp->sub, mjc_strlen(m0_tmp->sub)+1);
        req_data->data[MJC_M0_S_ENUM] = mjc_malloc(mjc_strlen(m0_tmp->s)+1);
        mjc_strncpy(req_data->data[MJC_M0_S_ENUM], m0_tmp->s, mjc_strlen(m0_tmp->s)+1);
        req_data->data[MJC_M0_GATEWAY_ENUM] = mjc_malloc(mjc_strlen(m0_tmp->gateway)+1);
        mjc_strncpy(req_data->data[MJC_M0_GATEWAY_ENUM], m0_tmp->gateway, mjc_strlen(m0_tmp->gateway)+1);

        mjc_json_pkt(req_data);

        e_data_free(req_data);
    }
    else if(!mjc_strncmp(event, MJC_E_M2, sizeof(MJC_E_M2)))
    {
        M2_DATA *m2_tmp = NULL;
        E_DATA *req_data = NULL;

        m2_tmp = (M2_DATA *)data;
        req_data = mjc_malloc(sizeof(E_DATA));
        e_data_init(req_data);
        req_data->e_handler = mjc_malloc(sizeof(E_HANDLER));
        mjc_json_get_event_handle_struct(req_data->e_handler, MJC_E_M2);
        DBG_PRINTF("evevt :%s\n",req_data->e_handler->event);
        req_data->data_arraysize = req_data->e_handler->event_arraysize + req_data->e_handler->sub_arraysize + 1;

        req_data->data[MJC_M2_EVENT_ENUM] = mjc_malloc(mjc_strlen(m2_tmp->event)+1);
        //DBG_PRINTF("event :%s, event_len: %d\n", m0_tmp->event, mjc_strlen(m0_tmp->event)+1);
        mjc_strncpy(req_data->data[MJC_M2_EVENT_ENUM], m2_tmp->event, mjc_strlen(m2_tmp->event)+1);
        req_data->data[MJC_M2_FROM_ENUM] = mjc_malloc(mjc_strlen(m2_tmp->form)+1);
        mjc_strncpy(req_data->data[MJC_M2_FROM_ENUM], m2_tmp->form, mjc_strlen(m2_tmp->form)+1);
        req_data->data[MJC_M2_ORDER_ENUM] = mjc_malloc(mjc_strlen(m2_tmp->order)+1);
        mjc_strncpy(req_data->data[MJC_M2_ORDER_ENUM], m2_tmp->order, mjc_strlen(m2_tmp->order)+1);

        mjc_json_pkt(req_data);

        e_data_free(req_data);
    }
    else if(!mjc_strncmp(event, MJC_E_M4, sizeof(MJC_E_M4)))
    {
        M4_DATA *m4_tmp = NULL;
        E_DATA *req_data = NULL;

        m4_tmp = (M4_DATA *)data;
        req_data = mjc_malloc(sizeof(E_DATA));
        e_data_init(req_data);
        req_data->e_handler = mjc_malloc(sizeof(E_HANDLER));
        mjc_json_get_event_handle_struct(req_data->e_handler, MJC_E_M4);
        DBG_PRINTF("evevt :%s\n",req_data->e_handler->event);
        req_data->data_arraysize = req_data->e_handler->event_arraysize + req_data->e_handler->sub_arraysize + 1;

        req_data->data[MJC_M4_EVENT_ENUM] = mjc_malloc(mjc_strlen(m4_tmp->event)+1);
        //DBG_PRINTF("event :%s, event_len: %d\n", m4_tmp->event, mjc_strlen(m4_tmp->event)+1);
        mjc_strncpy(req_data->data[MJC_M4_EVENT_ENUM], m4_tmp->event, mjc_strlen(m4_tmp->event)+1);
        req_data->data[MJC_M4_FROM_ENUM] = mjc_malloc(mjc_strlen(m4_tmp->form)+1);
        mjc_strncpy(req_data->data[MJC_M4_FROM_ENUM], m4_tmp->form, mjc_strlen(m4_tmp->form)+1);
        req_data->data[MJC_M4_ORDER_ENUM] = mjc_malloc(mjc_strlen(m4_tmp->order)+1);
        mjc_strncpy(req_data->data[MJC_M4_ORDER_ENUM], m4_tmp->order, mjc_strlen(m4_tmp->order)+1);
        req_data->data[MJC_M4_SUB_ENUM] = mjc_malloc(mjc_strlen(m4_tmp->sub)+1);
        mjc_strncpy(req_data->data[MJC_M4_SUB_ENUM], m4_tmp->sub, mjc_strlen(m4_tmp->sub)+1);
        req_data->data[MJC_M4_REASON_ENUM] = mjc_malloc(mjc_strlen(m4_tmp->reason)+1);
        mjc_strncpy(req_data->data[MJC_M4_REASON_ENUM], m4_tmp->reason, mjc_strlen(m4_tmp->reason)+1);
        req_data->data[MJC_M4_DETIAL_ENUM] = mjc_malloc(mjc_strlen(m4_tmp->detail)+1);
        mjc_strncpy(req_data->data[MJC_M4_DETIAL_ENUM], m4_tmp->detail, mjc_strlen(m4_tmp->detail)+1);

        mjc_json_pkt(req_data);

        e_data_free(req_data);
    }
    else if(!mjc_strncmp(event, MJC_E_M7, sizeof(MJC_E_M7)))
    {
        M7_DATA *m7_tmp = NULL;
        E_DATA *req_data = NULL;

        m7_tmp = (M7_DATA *)data;
        req_data = mjc_malloc(sizeof(E_DATA));
        e_data_init(req_data);
        req_data->e_handler = mjc_malloc(sizeof(E_HANDLER));
        mjc_json_get_event_handle_struct(req_data->e_handler, MJC_E_M7);
        DBG_PRINTF("evevt :%s\n",req_data->e_handler->event);
        req_data->data_arraysize = req_data->e_handler->event_arraysize + req_data->e_handler->sub_arraysize + 1;

        req_data->data[MJC_M7_EVENT_ENUM] = mjc_malloc(mjc_strlen(m7_tmp->event)+1);
        //DBG_PRINTF("event :%s, event_len: %d\n", m0_tmp->event, mjc_strlen(m0_tmp->event)+1);
        mjc_strncpy(req_data->data[MJC_M7_EVENT_ENUM], m7_tmp->event, mjc_strlen(m7_tmp->event)+1);
        req_data->data[MJC_M7_FROM_ENUM] = mjc_malloc(mjc_strlen(m7_tmp->form)+1);
        mjc_strncpy(req_data->data[MJC_M7_FROM_ENUM], m7_tmp->form, mjc_strlen(m7_tmp->form)+1);
        req_data->data[MJC_M7_ORDER_ENUM] = mjc_malloc(mjc_strlen(m7_tmp->order)+1);
        mjc_strncpy(req_data->data[MJC_M7_ORDER_ENUM], m7_tmp->order, mjc_strlen(m7_tmp->order)+1);

        mjc_json_pkt(req_data);

        e_data_free(req_data);
    }
    else if(!mjc_strncmp(event, MJC_E_M8, sizeof(MJC_E_M8)))
    {
        M8_DATA *m8_tmp = NULL;
        E_DATA *req_data = NULL;

        m8_tmp = (M8_DATA *)data;
        req_data = mjc_malloc(sizeof(E_DATA));
        e_data_init(req_data);
        req_data->e_handler = mjc_malloc(sizeof(E_HANDLER));
        mjc_json_get_event_handle_struct(req_data->e_handler, MJC_E_M8);
        DBG_PRINTF("evevt :%s\n",req_data->e_handler->event);
        req_data->data_arraysize = req_data->e_handler->event_arraysize + req_data->e_handler->sub_arraysize + 1;

        req_data->data[MJC_M8_EVENT_ENUM] = mjc_malloc(mjc_strlen(m8_tmp->event)+1);
        //DBG_PRINTF("event :%s, event_len: %d\n", m0_tmp->event, mjc_strlen(m0_tmp->event)+1);
        mjc_strncpy(req_data->data[MJC_M8_EVENT_ENUM], m8_tmp->event, mjc_strlen(m8_tmp->event)+1);
        req_data->data[MJC_M8_FROM_ENUM] = mjc_malloc(mjc_strlen(m8_tmp->form)+1);
        mjc_strncpy(req_data->data[MJC_M8_FROM_ENUM], m8_tmp->form, mjc_strlen(m8_tmp->form)+1);
        req_data->data[MJC_M8_ORDER_ENUM] = mjc_malloc(mjc_strlen(m8_tmp->order)+1);
        mjc_strncpy(req_data->data[MJC_M8_ORDER_ENUM], m8_tmp->order, mjc_strlen(m8_tmp->order)+1);

        mjc_json_pkt(req_data);

        e_data_free(req_data);
    }
    else if(!mjc_strncmp(event, MJC_E_M11, sizeof(MJC_E_M11)))
    {
        M11_DATA *m11_tmp = NULL;
        E_DATA *req_data = NULL;

        m11_tmp = (M11_DATA *)data;
        req_data = mjc_malloc(sizeof(E_DATA));
        e_data_init(req_data);
        req_data->e_handler = mjc_malloc(sizeof(E_HANDLER));
        mjc_json_get_event_handle_struct(req_data->e_handler, MJC_E_M11);
        DBG_PRINTF("evevt :%s\n",req_data->e_handler->event);
        req_data->data_arraysize = req_data->e_handler->event_arraysize + req_data->e_handler->sub_arraysize + 1;

        req_data->data[MJC_M11_EVENT_ENUM] = mjc_malloc(mjc_strlen(m11_tmp->event)+1);
        //DBG_PRINTF("event :%s, event_len: %d\n", m0_tmp->event, mjc_strlen(m0_tmp->event)+1);
        mjc_strncpy(req_data->data[MJC_M11_EVENT_ENUM], m11_tmp->event, mjc_strlen(m11_tmp->event)+1);
        req_data->data[MJC_M11_FROM_ENUM] = mjc_malloc(mjc_strlen(m11_tmp->form)+1);
        mjc_strncpy(req_data->data[MJC_M11_FROM_ENUM], m11_tmp->form, mjc_strlen(m11_tmp->form)+1);
        req_data->data[MJC_M11_ORDER_ENUM] = mjc_malloc(mjc_strlen(m11_tmp->order)+1);
        mjc_strncpy(req_data->data[MJC_M11_ORDER_ENUM], m11_tmp->order, mjc_strlen(m11_tmp->order)+1);

        mjc_json_pkt(req_data);

        e_data_free(req_data);
    }
    else if(!mjc_strncmp(event, MJC_E_M13, sizeof(MJC_E_M13)))
    {
        M13_DATA *m13_tmp = NULL;
        E_DATA *req_data = NULL;

        m13_tmp = (M13_DATA *)data;
        req_data = mjc_malloc(sizeof(E_DATA));
        e_data_init(req_data);
        req_data->e_handler = mjc_malloc(sizeof(E_HANDLER));
        mjc_json_get_event_handle_struct(req_data->e_handler, MJC_E_M13);
        DBG_PRINTF("evevt :%s\n",req_data->e_handler->event);
        req_data->data_arraysize = req_data->e_handler->event_arraysize + req_data->e_handler->sub_arraysize + 1;

        req_data->data[MJC_M13_EVENT_ENUM] = mjc_malloc(mjc_strlen(m13_tmp->event)+1);
        //DBG_PRINTF("event :%s, event_len: %d\n", m0_tmp->event, mjc_strlen(m0_tmp->event)+1);
        mjc_strncpy(req_data->data[MJC_M13_EVENT_ENUM], m13_tmp->event, mjc_strlen(m13_tmp->event)+1);
        req_data->data[MJC_M13_FROM_ENUM] = mjc_malloc(mjc_strlen(m13_tmp->form)+1);
        mjc_strncpy(req_data->data[MJC_M13_FROM_ENUM], m13_tmp->form, mjc_strlen(m13_tmp->form)+1);
        req_data->data[MJC_M13_ORDER_ENUM] = mjc_malloc(mjc_strlen(m13_tmp->order)+1);
        mjc_strncpy(req_data->data[MJC_M13_ORDER_ENUM], m13_tmp->order, mjc_strlen(m13_tmp->order)+1);

        mjc_json_pkt(req_data);

        e_data_free(req_data);
    }
    else if(!mjc_strncmp(event, MJC_E_B1, sizeof(MJC_E_B1)))
    {
        B1_DATA *B1_tmp = NULL;
        E_DATA *req_data = NULL;

        B1_tmp = (B1_DATA *)data;
        req_data = mjc_malloc(sizeof(E_DATA));
        e_data_init(req_data);
        req_data->e_handler = mjc_malloc(sizeof(E_HANDLER));
        mjc_json_get_event_handle_struct(req_data->e_handler, MJC_E_B1);
        DBG_PRINTF("evevt :%s\n",req_data->e_handler->event);
        req_data->data_arraysize = req_data->e_handler->event_arraysize + req_data->e_handler->sub_arraysize + 1;

        req_data->data[MJC_B1_EVENT_ENUM] = mjc_malloc(mjc_strlen(B1_tmp->event)+1);
        //DBG_PRINTF("event :%s, event_len: %d\n", m0_tmp->event, mjc_strlen(m0_tmp->event)+1);
        mjc_strncpy(req_data->data[MJC_B1_EVENT_ENUM], B1_tmp->event, mjc_strlen(B1_tmp->event)+1);
        req_data->data[MJC_B1_FROM_ENUM] = mjc_malloc(mjc_strlen(B1_tmp->form)+1);
        mjc_strncpy(req_data->data[MJC_B1_FROM_ENUM], B1_tmp->form, mjc_strlen(B1_tmp->form)+1);
        req_data->data[MJC_B1_ORDER_ENUM] = mjc_malloc(mjc_strlen(B1_tmp->order)+1);
        mjc_strncpy(req_data->data[MJC_B1_ORDER_ENUM], B1_tmp->order, mjc_strlen(B1_tmp->order)+1);

        mjc_json_pkt(req_data);

        e_data_free(req_data);
    }
    else if(!mjc_strncmp(event, MJC_E_B2, sizeof(MJC_E_B2)))
    {
        B2_DATA *B2_tmp = NULL;
        E_DATA *req_data = NULL;

        B2_tmp = (B2_DATA *)data;
        req_data = mjc_malloc(sizeof(E_DATA));
        e_data_init(req_data);
        req_data->e_handler = mjc_malloc(sizeof(E_HANDLER));
        mjc_json_get_event_handle_struct(req_data->e_handler, MJC_E_B2);
        DBG_PRINTF("evevt :%s\n",req_data->e_handler->event);
        req_data->data_arraysize = req_data->e_handler->event_arraysize + req_data->e_handler->sub_arraysize + 1;

        req_data->data[MJC_B2_EVENT_ENUM] = mjc_malloc(mjc_strlen(B2_tmp->event)+1);
        //DBG_PRINTF("event :%s, event_len: %d\n", B2_tmp->event, mjc_strlen(B2_tmp->event)+1);
        mjc_strncpy(req_data->data[MJC_B2_EVENT_ENUM], B2_tmp->event, mjc_strlen(B2_tmp->event)+1);
        req_data->data[MJC_B2_FROM_ENUM] = mjc_malloc(mjc_strlen(B2_tmp->form)+1);
        mjc_strncpy(req_data->data[MJC_B2_FROM_ENUM], B2_tmp->form, mjc_strlen(B2_tmp->form)+1);
        req_data->data[MJC_B2_ORDER_ENUM] = mjc_malloc(mjc_strlen(B2_tmp->order)+1);
        mjc_strncpy(req_data->data[MJC_B2_ORDER_ENUM], B2_tmp->order, mjc_strlen(B2_tmp->order)+1);
        req_data->data[MJC_B2_SUB_ENUM] = mjc_malloc(mjc_strlen(B2_tmp->sub)+1);
        mjc_strncpy(req_data->data[MJC_B2_SUB_ENUM], B2_tmp->sub, mjc_strlen(B2_tmp->sub)+1);
        req_data->data[MJC_B2_RESULT_ENUM] = mjc_malloc(mjc_strlen(B2_tmp->result)+1);
        mjc_strncpy(req_data->data[MJC_B2_RESULT_ENUM], B2_tmp->result, mjc_strlen(B2_tmp->result)+1);
        req_data->data[MJC_B2_DETIAL_ENUM] = mjc_malloc(mjc_strlen(B2_tmp->detail)+1);
        mjc_strncpy(req_data->data[MJC_B2_DETIAL_ENUM], B2_tmp->detail, mjc_strlen(B2_tmp->detail)+1);

        mjc_json_pkt(req_data);

        e_data_free(req_data);
    }
    else if(!mjc_strncmp(event, MJC_E_B4, sizeof(MJC_E_B4)))
    {
        B4_DATA *B4_tmp = NULL;
        E_DATA *req_data = NULL;

        B4_tmp = (B4_DATA *)data;
        req_data = mjc_malloc(sizeof(E_DATA));
        e_data_init(req_data);
        req_data->e_handler = mjc_malloc(sizeof(E_HANDLER));
        mjc_json_get_event_handle_struct(req_data->e_handler, MJC_E_B4);
        DBG_PRINTF("evevt :%s\n",req_data->e_handler->event);
        req_data->data_arraysize = req_data->e_handler->event_arraysize + req_data->e_handler->sub_arraysize + 1;

        req_data->data[MJC_B4_EVENT_ENUM] = mjc_malloc(mjc_strlen(B4_tmp->event)+1);
        //DBG_PRINTF("event :%s, event_len: %d\n", B4_tmp->event, mjc_strlen(B4_tmp->event)+1);
        mjc_strncpy(req_data->data[MJC_B4_EVENT_ENUM], B4_tmp->event, mjc_strlen(B4_tmp->event)+1);
        req_data->data[MJC_B4_FROM_ENUM] = mjc_malloc(mjc_strlen(B4_tmp->form)+1);
        mjc_strncpy(req_data->data[MJC_B4_FROM_ENUM], B4_tmp->form, mjc_strlen(B4_tmp->form)+1);
        req_data->data[MJC_B4_ORDER_ENUM] = mjc_malloc(mjc_strlen(B4_tmp->order)+1);
        mjc_strncpy(req_data->data[MJC_B4_ORDER_ENUM], B4_tmp->order, mjc_strlen(B4_tmp->order)+1);
        req_data->data[MJC_B4_SUB_ENUM] = mjc_malloc(mjc_strlen(B4_tmp->sub)+1);
        mjc_strncpy(req_data->data[MJC_B4_SUB_ENUM], B4_tmp->sub, mjc_strlen(B4_tmp->sub)+1);
        req_data->data[MJC_B4_USER_ENUM] = mjc_malloc(mjc_strlen(B4_tmp->user)+1);
        mjc_strncpy(req_data->data[MJC_B4_USER_ENUM], B4_tmp->user, mjc_strlen(B4_tmp->user)+1);
        req_data->data[MJC_B4_POLICY_ENUM] = mjc_malloc(mjc_strlen(B4_tmp->policy)+1);
        mjc_strncpy(req_data->data[MJC_B4_POLICY_ENUM], B4_tmp->policy, mjc_strlen(B4_tmp->policy)+1);
        req_data->data[MJC_B4_TIME_ENUM] = mjc_malloc(mjc_strlen(B4_tmp->time_len)+1);
        mjc_strncpy(req_data->data[MJC_B4_TIME_ENUM], B4_tmp->time_len, mjc_strlen(B4_tmp->time_len)+1);

        mjc_json_pkt(req_data);

        e_data_free(req_data);
    }
    else if(!mjc_strncmp(event, MJC_E_B6, sizeof(MJC_E_B6)))
    {
        B6_DATA *B6_tmp = NULL;
        E_DATA *req_data = NULL;

        B6_tmp = (B6_DATA *)data;
        req_data = mjc_malloc(sizeof(E_DATA));
        e_data_init(req_data);
        req_data->e_handler = mjc_malloc(sizeof(E_HANDLER));
        mjc_json_get_event_handle_struct(req_data->e_handler, MJC_E_B6);
        DBG_PRINTF("evevt :%s\n",req_data->e_handler->event);
        req_data->data_arraysize = req_data->e_handler->event_arraysize + req_data->e_handler->sub_arraysize + 1;

        req_data->data[MJC_B6_EVENT_ENUM] = mjc_malloc(mjc_strlen(B6_tmp->event)+1);
        //DBG_PRINTF("event :%s, event_len: %d\n", B6_tmp->event, mjc_strlen(B6_tmp->event)+1);
        mjc_strncpy(req_data->data[MJC_B6_EVENT_ENUM], B6_tmp->event, mjc_strlen(B6_tmp->event)+1);
        req_data->data[MJC_B6_FROM_ENUM] = mjc_malloc(mjc_strlen(B6_tmp->form)+1);
        mjc_strncpy(req_data->data[MJC_B6_FROM_ENUM], B6_tmp->form, mjc_strlen(B6_tmp->form)+1);
        req_data->data[MJC_B6_ORDER_ENUM] = mjc_malloc(mjc_strlen(B6_tmp->order)+1);
        mjc_strncpy(req_data->data[MJC_B6_ORDER_ENUM], B6_tmp->order, mjc_strlen(B6_tmp->order)+1);
        req_data->data[MJC_B6_SUB_ENUM] = mjc_malloc(mjc_strlen(B6_tmp->sub)+1);
        mjc_strncpy(req_data->data[MJC_B6_SUB_ENUM], B6_tmp->sub, mjc_strlen(B6_tmp->sub)+1);
        req_data->data[MJC_B6_POLICY_ENUM] = mjc_malloc(mjc_strlen(B6_tmp->policy)+1);
        mjc_strncpy(req_data->data[MJC_B6_POLICY_ENUM], B6_tmp->policy, mjc_strlen(B6_tmp->policy)+1);
        req_data->data[MJC_B6_VALUE_ENUM] = mjc_malloc(mjc_strlen(B6_tmp->value)+1);
        mjc_strncpy(req_data->data[MJC_B6_VALUE_ENUM], B6_tmp->value, mjc_strlen(B6_tmp->value)+1);

        mjc_json_pkt(req_data);

        e_data_free(req_data);
    }
    else if(!mjc_strncmp(event, MJC_E_B9, sizeof(MJC_E_B9)))
    {
        B9_DATA *B9_tmp = NULL;
        E_DATA *req_data = NULL;

        B9_tmp = (B9_DATA *)data;
        req_data = mjc_malloc(sizeof(E_DATA));
        e_data_init(req_data);
        req_data->e_handler = mjc_malloc(sizeof(E_HANDLER));
        mjc_json_get_event_handle_struct(req_data->e_handler, MJC_E_B9);
        DBG_PRINTF("evevt :%s\n",req_data->e_handler->event);
        req_data->data_arraysize = req_data->e_handler->event_arraysize + req_data->e_handler->sub_arraysize + 1;

        req_data->data[MJC_B9_EVENT_ENUM] = mjc_malloc(mjc_strlen(B9_tmp->event)+1);
        //DBG_PRINTF("event :%s, event_len: %d\n", B9_tmp->event, mjc_strlen(B9_tmp->event)+1);
        mjc_strncpy(req_data->data[MJC_B9_EVENT_ENUM], B9_tmp->event, mjc_strlen(B9_tmp->event)+1);
        req_data->data[MJC_B9_FROM_ENUM] = mjc_malloc(mjc_strlen(B9_tmp->form)+1);
        mjc_strncpy(req_data->data[MJC_B9_FROM_ENUM], B9_tmp->form, mjc_strlen(B9_tmp->form)+1);
        req_data->data[MJC_B9_ORDER_ENUM] = mjc_malloc(mjc_strlen(B9_tmp->order)+1);
        mjc_strncpy(req_data->data[MJC_B9_ORDER_ENUM], B9_tmp->order, mjc_strlen(B9_tmp->order)+1);

        mjc_json_pkt(req_data);

        e_data_free(req_data);
    }

    DBG_PRINTF("=======================> mjc_api_resp_handle\n");
TAG_EXIT:
    return 0;
}
