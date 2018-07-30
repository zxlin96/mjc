#include "mjc.h"
#include "log.h"
#include "mjc_strutl.h"
#include "mjc_json.h"
#include "mjc_api.h"

int mjc_api_recv(E_DATA *e_data)
{
    DBG_PRINTF("==========================> mjc_api_recv IN\n");
    int i = 0;

    if(e_data == NULL)
    {
        DBG_PRINTF("e_data is NULL\n");
        goto TAG_EXIT;
    }
    DBG_PRINTF("E_DATA->E:%s\n",e_data->e_handler->event);
    for(i = 0; i < e_data->data_arraysize; i++)
    {
        printf("E_DATA:%s\n",e_data->data[i]);
    }

    if(!mjc_strncmp(e_data->data[0], MJC_E_M1, sizeof(MJC_E_M1)))
    {
        M1_DATA *data;
        data = mjc_malloc(sizeof(M1_DATA));
        data->event = mjc_malloc(mjc_strlen(e_data->data[MJC_M1_EVENT_ENUM])+1);
        mjc_strncpy(data->event, e_data->data[MJC_M1_EVENT_ENUM], mjc_strlen(e_data->data[MJC_M1_EVENT_ENUM])+1);
        data->to = mjc_malloc(mjc_strlen(e_data->data[MJC_M1_TO_ENUM])+1);
        mjc_strncpy(data->to, e_data->data[MJC_M1_TO_ENUM], mjc_strlen(e_data->data[MJC_M1_TO_ENUM])+1);
        data->order = mjc_malloc(mjc_strlen(e_data->data[MJC_M1_ORDER_ENUM])+1);
        mjc_strncpy(data->order, e_data->data[MJC_M1_ORDER_ENUM], mjc_strlen(e_data->data[MJC_M1_ORDER_ENUM])+1);
        data->keep = mjc_malloc(mjc_strlen(e_data->data[MJC_M1_KEEP_ENUM])+1);
        mjc_strncpy(data->keep, e_data->data[MJC_M1_KEEP_ENUM], mjc_strlen(e_data->data[MJC_M1_KEEP_ENUM])+1);

        mjc_api_resp_handle(data, MJC_E_M1);

        mjc_free(data->event);
        mjc_free(data->to);
        mjc_free(data->order);
        mjc_free(data->keep);
        mjc_free(data); 
    }
    else if(!mjc_strncmp(e_data->data[0], MJC_E_M3, sizeof(MJC_E_M3)))
    {
        M3_DATA *data;
        data = mjc_malloc(sizeof(M3_DATA));
        data->event = mjc_malloc(mjc_strlen(e_data->data[MJC_M3_EVENT_ENUM])+1);
        mjc_strncpy(data->event, e_data->data[MJC_M3_EVENT_ENUM], mjc_strlen(e_data->data[MJC_M3_EVENT_ENUM])+1);
        data->to = mjc_malloc(mjc_strlen(e_data->data[MJC_M3_TO_ENUM])+1);
        mjc_strncpy(data->to, e_data->data[MJC_M3_TO_ENUM], mjc_strlen(e_data->data[MJC_M3_TO_ENUM])+1);
        data->order = mjc_malloc(mjc_strlen(e_data->data[MJC_M3_ORDER_ENUM])+1);
        mjc_strncpy(data->order, e_data->data[MJC_M3_ORDER_ENUM], mjc_strlen(e_data->data[MJC_M3_ORDER_ENUM])+1);

        mjc_api_resp_handle(data, MJC_E_M3);

        mjc_free(data->event);
        mjc_free(data->to);
        mjc_free(data->order);
        mjc_free(data); 
    }
    else if(!mjc_strncmp(e_data->data[0], MJC_E_M5, sizeof(MJC_E_M5)))
    {
        M5_DATA *data;
        data = mjc_malloc(sizeof(M5_DATA));
        data->event = mjc_malloc(mjc_strlen(e_data->data[MJC_M5_EVENT_ENUM])+1);
        mjc_strncpy(data->event, e_data->data[MJC_M5_EVENT_ENUM], mjc_strlen(e_data->data[MJC_M5_EVENT_ENUM])+1);
        data->to = mjc_malloc(mjc_strlen(e_data->data[MJC_M5_TO_ENUM])+1);
        mjc_strncpy(data->to, e_data->data[MJC_M5_TO_ENUM], mjc_strlen(e_data->data[MJC_M5_TO_ENUM])+1);
        data->order = mjc_malloc(mjc_strlen(e_data->data[MJC_M5_ORDER_ENUM])+1);
        mjc_strncpy(data->order, e_data->data[MJC_M5_ORDER_ENUM], mjc_strlen(e_data->data[MJC_M5_ORDER_ENUM])+1);

        mjc_api_resp_handle(data, MJC_E_M5);

        mjc_free(data->event);
        mjc_free(data->to);
        mjc_free(data->order);
        mjc_free(data); 
    }
    else if(!mjc_strncmp(e_data->data[0], MJC_E_M6, sizeof(MJC_E_M6)))
    {
        M6_DATA *data;
        data = mjc_malloc(sizeof(M6_DATA));
        data->event = mjc_malloc(mjc_strlen(e_data->data[MJC_M6_EVENT_ENUM])+1);
        mjc_strncpy(data->event, e_data->data[MJC_M6_EVENT_ENUM], mjc_strlen(e_data->data[MJC_M6_EVENT_ENUM])+1);
        data->to = mjc_malloc(mjc_strlen(e_data->data[MJC_M6_TO_ENUM])+1);
        mjc_strncpy(data->to, e_data->data[MJC_M6_TO_ENUM], mjc_strlen(e_data->data[MJC_M6_TO_ENUM])+1);
        data->order = mjc_malloc(mjc_strlen(e_data->data[MJC_M6_ORDER_ENUM])+1);
        mjc_strncpy(data->order, e_data->data[MJC_M6_ORDER_ENUM], mjc_strlen(e_data->data[MJC_M6_ORDER_ENUM])+1);
        data->sub = mjc_malloc(mjc_strlen(e_data->data[MJC_M6_SUB_ENUM])+1);
        mjc_strncpy(data->sub, e_data->data[MJC_M6_SUB_ENUM], mjc_strlen(e_data->data[MJC_M6_SUB_ENUM])+1);
        data->p = mjc_malloc(mjc_strlen(e_data->data[MJC_M6_P_ENUM])+1);
        mjc_strncpy(data->p, e_data->data[MJC_M6_P_ENUM], mjc_strlen(e_data->data[MJC_M6_P_ENUM])+1);
        data->version = mjc_malloc(mjc_strlen(e_data->data[MJC_M6_VERSION_ENUM])+1);
        mjc_strncpy(data->version, e_data->data[MJC_M6_VERSION_ENUM], mjc_strlen(e_data->data[MJC_M6_VERSION_ENUM])+1);


        mjc_api_resp_handle(data, MJC_E_M6);

        mjc_free(data->event);
        mjc_free(data->to);
        mjc_free(data->order);
        mjc_free(data->sub);
        mjc_free(data->p);
        mjc_free(data->version);
        mjc_free(data);
        //DBG_PRINTF("\nM6\n");
        //mjc_api_m6_handle(e_data);
    }
    else if(!mjc_strncmp(e_data->data[0], MJC_E_M9, sizeof(MJC_E_M9)))
    {
        M9_DATA *data;
        data = mjc_malloc(sizeof(M9_DATA));
        data->event = mjc_malloc(mjc_strlen(e_data->data[MJC_M9_EVENT_ENUM])+1);
        mjc_strncpy(data->event, e_data->data[MJC_M9_EVENT_ENUM], mjc_strlen(e_data->data[MJC_M9_EVENT_ENUM])+1);
        data->to = mjc_malloc(mjc_strlen(e_data->data[MJC_M9_TO_ENUM])+1);
        mjc_strncpy(data->to, e_data->data[MJC_M9_TO_ENUM], mjc_strlen(e_data->data[MJC_M9_TO_ENUM])+1);
        data->order = mjc_malloc(mjc_strlen(e_data->data[MJC_M9_ORDER_ENUM])+1);
        mjc_strncpy(data->order, e_data->data[MJC_M9_ORDER_ENUM], mjc_strlen(e_data->data[MJC_M9_ORDER_ENUM])+1);

        mjc_api_resp_handle(data, MJC_E_M9);

        mjc_free(data->event);
        mjc_free(data->to);
        mjc_free(data->order);
        mjc_free(data); 
    }
    else if(!mjc_strncmp(e_data->data[0], MJC_E_M10, sizeof(MJC_E_M10)))
    {
        M10_DATA *data;
        data = mjc_malloc(sizeof(M10_DATA));
        data->event = mjc_malloc(mjc_strlen(e_data->data[MJC_M10_EVENT_ENUM])+1);
        mjc_strncpy(data->event, e_data->data[MJC_M10_EVENT_ENUM], mjc_strlen(e_data->data[MJC_M10_EVENT_ENUM])+1);
        data->to = mjc_malloc(mjc_strlen(e_data->data[MJC_M10_TO_ENUM])+1);
        mjc_strncpy(data->to, e_data->data[MJC_M10_TO_ENUM], mjc_strlen(e_data->data[MJC_M10_TO_ENUM])+1);
        data->order = mjc_malloc(mjc_strlen(e_data->data[MJC_M10_ORDER_ENUM])+1);
        mjc_strncpy(data->order, e_data->data[MJC_M10_ORDER_ENUM], mjc_strlen(e_data->data[MJC_M10_ORDER_ENUM])+1);
        data->sub = mjc_malloc(mjc_strlen(e_data->data[MJC_M10_SUB_ENUM])+1);
        mjc_strncpy(data->sub, e_data->data[MJC_M10_SUB_ENUM], mjc_strlen(e_data->data[MJC_M10_SUB_ENUM])+1);
        data->cfg = mjc_malloc(mjc_strlen(e_data->data[MJC_M10_CFG_ENUM])+1);
        mjc_strncpy(data->cfg, e_data->data[MJC_M10_CFG_ENUM], mjc_strlen(e_data->data[MJC_M10_CFG_ENUM])+1);
        data->version = mjc_malloc(mjc_strlen(e_data->data[MJC_M10_VERSION_ENUM])+1);
        mjc_strncpy(data->version, e_data->data[MJC_M10_VERSION_ENUM], mjc_strlen(e_data->data[MJC_M10_VERSION_ENUM])+1);


        mjc_api_resp_handle(data, MJC_E_M10);

        mjc_free(data->event);
        mjc_free(data->to);
        mjc_free(data->order);
        mjc_free(data->sub);
        mjc_free(data->cfg);
        mjc_free(data->version);
        mjc_free(data);
        //DBG_PRINTF("\nM10\n");
        //mjc_api_m10_handle(e_data);
    }
    else if(!mjc_strncmp(e_data->data[0], MJC_E_M12, sizeof(MJC_E_M12)))
    {
        M12_DATA *data;
        data = mjc_malloc(sizeof(M12_DATA));
        data->event = mjc_malloc(mjc_strlen(e_data->data[MJC_M12_EVENT_ENUM])+1);
        mjc_strncpy(data->event, e_data->data[MJC_M12_EVENT_ENUM], mjc_strlen(e_data->data[MJC_M12_EVENT_ENUM])+1);
        data->to = mjc_malloc(mjc_strlen(e_data->data[MJC_M12_TO_ENUM])+1);
        mjc_strncpy(data->to, e_data->data[MJC_M12_TO_ENUM], mjc_strlen(e_data->data[MJC_M12_TO_ENUM])+1);
        data->order = mjc_malloc(mjc_strlen(e_data->data[MJC_M12_ORDER_ENUM])+1);
        mjc_strncpy(data->order, e_data->data[MJC_M12_ORDER_ENUM], mjc_strlen(e_data->data[MJC_M12_ORDER_ENUM])+1);

        mjc_api_resp_handle(data, MJC_E_M12);

        mjc_free(data->event);
        mjc_free(data->to);
        mjc_free(data->order);
        mjc_free(data);
        //DBG_PRINTF("\nM12\n");
        //mjc_api_m12_handle(e_data);
    }
    else if(!mjc_strncmp(e_data->data[0], MJC_E_B0, sizeof(MJC_E_B0)))
    {
        B0_DATA *data;
        data = mjc_malloc(sizeof(B0_DATA));
        data->event = mjc_malloc(mjc_strlen(e_data->data[MJC_B0_EVENT_ENUM])+1);
        mjc_strncpy(data->event, e_data->data[MJC_B0_EVENT_ENUM], mjc_strlen(e_data->data[MJC_B0_EVENT_ENUM])+1);
        data->to = mjc_malloc(mjc_strlen(e_data->data[MJC_B0_TO_ENUM])+1);
        mjc_strncpy(data->to, e_data->data[MJC_B0_TO_ENUM], mjc_strlen(e_data->data[MJC_B0_TO_ENUM])+1);
        data->order = mjc_malloc(mjc_strlen(e_data->data[MJC_B0_ORDER_ENUM])+1);
        mjc_strncpy(data->order, e_data->data[MJC_B0_ORDER_ENUM], mjc_strlen(e_data->data[MJC_B0_ORDER_ENUM])+1);
        data->sub = mjc_malloc(mjc_strlen(e_data->data[MJC_B0_SUB_ENUM])+1);
        mjc_strncpy(data->sub, e_data->data[MJC_B0_SUB_ENUM], mjc_strlen(e_data->data[MJC_B0_SUB_ENUM])+1);
        data->user = mjc_malloc(mjc_strlen(e_data->data[MJC_B0_USER_ENUM])+1);
        mjc_strncpy(data->user, e_data->data[MJC_B0_USER_ENUM], mjc_strlen(e_data->data[MJC_B0_USER_ENUM])+1);
        data->policy = mjc_malloc(mjc_strlen(e_data->data[MJC_B0_POLICY_ENUM])+1);
        mjc_strncpy(data->policy, e_data->data[MJC_B0_POLICY_ENUM], mjc_strlen(e_data->data[MJC_B0_POLICY_ENUM])+1);
        data->time_len = mjc_malloc(mjc_strlen(e_data->data[MJC_B0_TIME_ENUM])+1);
        mjc_strncpy(data->time_len, e_data->data[MJC_B0_TIME_ENUM], mjc_strlen(e_data->data[MJC_B0_TIME_ENUM])+1);


        mjc_api_resp_handle(data, MJC_E_B0);

        mjc_free(data->event);
        mjc_free(data->to);
        mjc_free(data->order);
        mjc_free(data->sub);
        mjc_free(data->user);
        mjc_free(data->policy);
        mjc_free(data->time_len);
        mjc_free(data);
        //DBG_PRINTF("\nB0\n");
        //mjc_api_B0_handle(e_data);
    }
    else if(!mjc_strncmp(e_data->data[0], MJC_E_B3, sizeof(MJC_E_B3)))
    {
        B3_DATA *data;
        data = mjc_malloc(sizeof(B3_DATA));
        data->event = mjc_malloc(mjc_strlen(e_data->data[MJC_B3_EVENT_ENUM])+1);
        mjc_strncpy(data->event, e_data->data[MJC_B3_EVENT_ENUM], mjc_strlen(e_data->data[MJC_B3_EVENT_ENUM])+1);
        data->to = mjc_malloc(mjc_strlen(e_data->data[MJC_B3_TO_ENUM])+1);
        mjc_strncpy(data->to, e_data->data[MJC_B3_TO_ENUM], mjc_strlen(e_data->data[MJC_B3_TO_ENUM])+1);
        data->order = mjc_malloc(mjc_strlen(e_data->data[MJC_B3_ORDER_ENUM])+1);
        mjc_strncpy(data->order, e_data->data[MJC_B3_ORDER_ENUM], mjc_strlen(e_data->data[MJC_B3_ORDER_ENUM])+1);

        mjc_api_resp_handle(data, MJC_E_B3);

        mjc_free(data->event);
        mjc_free(data->to);
        mjc_free(data->order);
        mjc_free(data); 
    }
    else if(!mjc_strncmp(e_data->data[0], MJC_E_B5, sizeof(MJC_E_B5)))
    {
        B5_DATA *data;
        data = mjc_malloc(sizeof(B5_DATA));
        data->event = mjc_malloc(mjc_strlen(e_data->data[MJC_B5_EVENT_ENUM])+1);
        mjc_strncpy(data->event, e_data->data[MJC_B5_EVENT_ENUM], mjc_strlen(e_data->data[MJC_B5_EVENT_ENUM])+1);
        data->to = mjc_malloc(mjc_strlen(e_data->data[MJC_B5_TO_ENUM])+1);
        mjc_strncpy(data->to, e_data->data[MJC_B5_TO_ENUM], mjc_strlen(e_data->data[MJC_B5_TO_ENUM])+1);
        data->order = mjc_malloc(mjc_strlen(e_data->data[MJC_B5_ORDER_ENUM])+1);
        mjc_strncpy(data->order, e_data->data[MJC_B5_ORDER_ENUM], mjc_strlen(e_data->data[MJC_B5_ORDER_ENUM])+1);
        data->sub = mjc_malloc(mjc_strlen(e_data->data[MJC_B5_SUB_ENUM])+1);
        mjc_strncpy(data->sub, e_data->data[MJC_B5_SUB_ENUM], mjc_strlen(e_data->data[MJC_B5_SUB_ENUM])+1);
        data->result = mjc_malloc(mjc_strlen(e_data->data[MJC_B5_RESULT_ENUM])+1);
        mjc_strncpy(data->result, e_data->data[MJC_B5_RESULT_ENUM], mjc_strlen(e_data->data[MJC_B5_RESULT_ENUM])+1);


        mjc_api_resp_handle(data, MJC_E_B5);

        mjc_free(data->event);
        mjc_free(data->to);
        mjc_free(data->order);
        mjc_free(data->sub);
        mjc_free(data->result);
        mjc_free(data);
        //DBG_PRINTF("\nB5\n");
        //mjc_api_B5_handle(e_data);
    }
    else if(!mjc_strncmp(e_data->data[0], MJC_E_B7, sizeof(MJC_E_B7)))
    {
        B7_DATA *data;
        data = mjc_malloc(sizeof(B7_DATA));
        data->event = mjc_malloc(mjc_strlen(e_data->data[MJC_B7_EVENT_ENUM])+1);
        mjc_strncpy(data->event, e_data->data[MJC_B7_EVENT_ENUM], mjc_strlen(e_data->data[MJC_B7_EVENT_ENUM])+1);
        data->to = mjc_malloc(mjc_strlen(e_data->data[MJC_B7_TO_ENUM])+1);
        mjc_strncpy(data->to, e_data->data[MJC_B7_TO_ENUM], mjc_strlen(e_data->data[MJC_B7_TO_ENUM])+1);
        data->order = mjc_malloc(mjc_strlen(e_data->data[MJC_B7_ORDER_ENUM])+1);
        mjc_strncpy(data->order, e_data->data[MJC_B7_ORDER_ENUM], mjc_strlen(e_data->data[MJC_B7_ORDER_ENUM])+1);

        mjc_api_resp_handle(data, MJC_E_B7);

        mjc_free(data->event);
        mjc_free(data->to);
        mjc_free(data->order);
        mjc_free(data); 
    }
    else if(!mjc_strncmp(e_data->data[0], MJC_E_B8, sizeof(MJC_E_B8)))
    {
        B8_DATA *data;
        data = mjc_malloc(sizeof(B8_DATA));
        data->event = mjc_malloc(mjc_strlen(e_data->data[MJC_B8_EVENT_ENUM])+1);
        mjc_strncpy(data->event, e_data->data[MJC_B8_EVENT_ENUM], mjc_strlen(e_data->data[MJC_B8_EVENT_ENUM])+1);
        data->to = mjc_malloc(mjc_strlen(e_data->data[MJC_B8_TO_ENUM])+1);
        mjc_strncpy(data->to, e_data->data[MJC_B8_TO_ENUM], mjc_strlen(e_data->data[MJC_B8_TO_ENUM])+1);
        data->order = mjc_malloc(mjc_strlen(e_data->data[MJC_B8_ORDER_ENUM])+1);
        mjc_strncpy(data->order, e_data->data[MJC_B8_ORDER_ENUM], mjc_strlen(e_data->data[MJC_B8_ORDER_ENUM])+1);

        mjc_api_resp_handle(data, MJC_E_B8);

        mjc_free(data->event);
        mjc_free(data->to);
        mjc_free(data->order);
        mjc_free(data); 
    }
    
    DBG_PRINTF("<========================== mjc_api_recv OUT\n");
TAG_EXIT:
    return 0;
}