/** 
* @file         cJSON_est.c 
* @brief        测试使用的主函数 
* @details      创建订阅线程,一直订阅topic为topic_sub的主题
* @author       林展翔 
* @version      V1.0 
* @par History:          
*  
*/  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mjc.h"
#include "mjc_api.h"
#include "mjc_utl.h"


int main(int argc, const char *argv[])
{
    //char *text1 = "{\"E\":\"M1\",\"T\":\"abc123\", \"O\":\"666\", \"K\":\"60\"}";
    //char *text2 = "{\"E\":\"M0\",\"F\":\"abc123\", \"O\":\"666\", \"B\":{\"S\":\"10\"}}";
    //char *text3 = "{\"E\":\"M3\",\"T\":\"abc123\", \"O\":\"666\"}";
    //
    //char *text5 = "{\"E\":\"M5\",\"T\":\"abc123\", \"O\":\"666\"}";
    //char *text6 = "{\"E\":\"M6\",\"T\":\"X\", \"O\":\"666\", \"B\":{\"P\":\"192.168.1.1\", \"V\":\"1\"}}";
    //char *text10 = "{\"E\":\"M6\",\"T\":\"X\", \"O\":\"666\", \"B\":{\"C\":\"192.168.1.1\", \"V\":\"1\"}}";
    //char *text9 = "{\"E\":\"M9\",\"T\":\"abc123\", \"O\":\"666\"}";
    //char *text12 = "{\"E\":\"M12\",\"T\":\"X\", \"O\":\"666\"}";
    //char *textB0 = "{\"E\":\"B0\",\"T\":\"X\", \"O\":\"666\", \"B\":{\"U\":\"192.168.1.1\", \"P\":\"1\", \"T\":\"1\"}}";
    //char *textB3 = "{\"E\":\"B3\",\"T\":\"abc123\", \"O\":\"666\"}";
    //char *textB5 = "{\"E\":\"B5\",\"T\":\"X\", \"O\":\"666\", \"B\":{\"R\":\"192.168.1.1\"}}";
    //char *textB7 = "{\"E\":\"B7\",\"T\":\"abc123\", \"O\":\"666\"}";
    //char *textB8 = "{\"E\":\"B8\",\"T\":\"abc123\", \"O\":\"666\"}";
    //char *text_big = "{\"E\":\"M6\",\"T\":\"X\", \"O\":\"666\", \"B\":{\"P\":\"192.168.1.1111111111111111111\", \"V\":\"111111111111111111111111111111111111111111111\"}}";
    //char *data1[] = {"M0", "abc123", "1063", "60"};
    //mjc_json_handle(text2);
    //mjc_json_handle(text6);
    char cmd[10];

    mjc_mqtt_sub_init();
    //mjc_json_handle(text2);
    while(mjc_strncmp(cmd, "Q", sizeof("Q")))
    {
        scanf("%s", cmd);
        if(!mjc_strncmp(cmd, "M0_I", sizeof("M0_I")))
        {
            M0_DATA m0_data;
            m0_data.event = "M0";
            m0_data.form = "ZHKJ00000000F";
            m0_data.order = mjc_malloc(JSON_ORDER_SIZE);
            sprintf(m0_data.order, "%04X", mjc_get_order());
            //m0_data.order = "";
            m0_data.sub = NULL;
            m0_data.s = NULL;
            m0_data.gateway = NULL;
            mjc_api_send(&m0_data,"M0");
            mjc_free(m0_data.order);
        }
        else if(!mjc_strncmp(cmd, "M0", sizeof("M0")))
        {
            M0_DATA m0_data;
            m0_data.event = "M0";
            m0_data.form = "ZHKJ0010000FF";
            //m0_data.order = "1234";
            m0_data.order = mjc_malloc(JSON_ORDER_SIZE);
            sprintf(m0_data.order, "%04X", mjc_get_order());
            m0_data.sub = "B";
            m0_data.s = "10";
            m0_data.gateway = "ZHKJ00000000F";
            mjc_api_send(&m0_data,"M0");
            mjc_free(m0_data.order);
        }
        else if(!mjc_strncmp(cmd, "M2", sizeof("M2")))
        {
            M2_DATA m2_data;
            m2_data.event = "M2";
            m2_data.form = "ZHKJ00000000F";
            m2_data.order = mjc_malloc(JSON_ORDER_SIZE);
            sprintf(m2_data.order, "%04X", mjc_get_order());
            //m2_data.order = "1234";
            mjc_api_send(&m2_data,"M2");
            mjc_free(m2_data.order);
        }
        else if(!mjc_strncmp(cmd, "M4", sizeof("M4")))
        {
            M4_DATA m4_data;
            m4_data.event = "M4";
            m4_data.form = "ZHKJ0010000FF";
            m4_data.order = mjc_malloc(JSON_ORDER_SIZE);
            sprintf(m4_data.order, "%04X", mjc_get_order());
            //m4_data.order = "1234";
            m4_data.sub = "B";
            m4_data.reason = "0";
            m4_data.detail = "0";
            mjc_api_send(&m4_data,"M4");
            mjc_free(m4_data.order);
        }
        else if(!mjc_strncmp(cmd, "M8", sizeof("M8")))
        {
            M8_DATA m8_data;
            m8_data.event = "M8";
            m8_data.form = "ZHKJ00000000F";
            m8_data.order = mjc_malloc(JSON_ORDER_SIZE);
            sprintf(m8_data.order, "%04X", mjc_get_order());
            //m8_data.order = "1234";
            mjc_api_send(&m8_data,"M8");
            mjc_free(m8_data.order);
        }
        else if(!mjc_strncmp(cmd, "B2", sizeof("B2")))
        {
            B2_DATA B2_data;
            B2_data.event = "B2";
            B2_data.form = "ZHKJ0020000FF1";
            B2_data.order = mjc_malloc(JSON_ORDER_SIZE);
            sprintf(B2_data.order, "%04X", mjc_get_order());
            //B2_data.order = "1234";
            B2_data.sub = "B";
            B2_data.result = "1";
            B2_data.detail = "aaaaaa";
            mjc_api_send(&B2_data,"B2");
            mjc_free(B2_data.order);
        }
        else if(!mjc_strncmp(cmd, "B4", sizeof("B4")))
        {
            B4_DATA B4_data;
            B4_data.event = "B4";
            B4_data.form = "ZHKJ0020000FF1";
            B4_data.order = mjc_malloc(JSON_ORDER_SIZE);
            sprintf(B4_data.order, "%04X", mjc_get_order());
            //B4_data.order = "1234";
            B4_data.sub = "B";
            B4_data.user = "13812345678";
            B4_data.policy = "0";
            B4_data.time_len = "3";
            mjc_api_send(&B4_data,"B4");
            mjc_free(B4_data.order);
        }
        else if(!mjc_strncmp(cmd, "B6", sizeof("B6")))
        {
            B6_DATA B6_data;
            B6_data.event = "B6";
            B6_data.form = "ZHKJ0020000FF1";
            B6_data.order = mjc_malloc(JSON_ORDER_SIZE);
            sprintf(B6_data.order, "%04X", mjc_get_order());
            //B6_data.order = "1234";
            B6_data.sub = "B";
            B6_data.policy = "0";
            B6_data.value = "60";
            mjc_api_send(&B6_data,"B6");
            mjc_free(B6_data.order);
        }
        else if(!mjc_strncmp(cmd, "ID", sizeof("ID")))
        {
            U16 order = 0;
            char str[4] = {0};
            order = mjc_get_order();
            //将数值转化为16进制字符串输出
            sprintf(str, "%04X", order);
            printf("now order:%s\n", str);
        }
        else if(!mjc_strncmp(cmd, "EXIT", sizeof("EXIT")))
        {
            mjc_mqtt_sub_exit();
        }
        else
        {
            U16 data = 0;
            data = mjc_hex2dec_util(cmd);
            DBG_PRINTF("change after:%d\n",data);
        }
        //mjc_json_handle(text2);
        //sleep(3);
        //mjc_json_handle(text_big);
        //sleep(10);
    }

    return 0;
}
