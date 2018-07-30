#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MQTTClient.h"
#if !defined(WIN32)
#include <unistd.h>
#else
#include <windows.h>
#endif

#define NUM_THREADS 2
#define ADDRESS     "tcp://localhost:1883" //更改此处地址
#define CLIENTID    "aaabbbccc" //更改此处客户端ID
#define TOPIC_PUB       "ZHKJ00000000F"  //更改发送的话题
#define QOS         0
#define TIMEOUT     500L

static char *text[] = {"{\"E\":\"M1\",\"T\":\"abc123\", \"O\":\"666\", \"K\":\"60\"}",
                "{\"E\":\"M3\",\"T\":\"abc123\", \"O\":\"666\"}",
                "{\"E\":\"M5\",\"T\":\"abc123\", \"O\":\"666\"}",
                "{\"E\":\"M6\",\"T\":\"X\", \"O\":\"666\", \"B\":{\"P\":\"192.168.1.1\", \"V\":\"1\"}}",
                "{\"E\":\"M9\",\"T\":\"abc123\", \"O\":\"666\"}",
                "{\"E\":\"M12\",\"T\":\"X\", \"O\":\"666\"}",
                "{\"E\":\"B0\",\"T\":\"X\", \"O\":\"666\", \"B\":{\"U\":\"192.168.1.1\", \"P\":\"1\", \"T\":\"1\"}}",
                "{\"E\":\"B3\",\"T\":\"abc123\", \"O\":\"666\"}",
                "{\"E\":\"B5\",\"T\":\"X\", \"O\":\"666\", \"B\":{\"R\":\"192.168.1.1\"}}",
                "{\"E\":\"B7\",\"T\":\"abc123\", \"O\":\"666\"}",
                "{\"E\":\"B8\",\"T\":\"abc123\", \"O\":\"666\"}"
};

int main()
{
    int i = 0;
    //声明一个MQTTClient
    MQTTClient client;
    //初始化MQTT Client选项
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    //#define MQTTClient_message_initializer { {'M', 'Q', 'T', 'M'}, 0, 0, NULL, 0, 0, 0, 0 }
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    //声明消息token
    MQTTClient_deliveryToken token;
    int rc;
    //使用参数创建一个client，并将其赋值给之前声明的client
    MQTTClient_create(&client, ADDRESS, CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
     //使用MQTTClient_connect将client连接到服务器，使用指定的连接选项。成功则返回MQTTCLIENT_SUCCESS
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
    for(i = 0; text[i] != NULL; i++)
    {
    pubmsg.payload = text[i];
    pubmsg.payloadlen = strlen(text[i]);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;
    
    MQTTClient_publishMessage(client, TOPIC_PUB, &pubmsg, &token);
    printf("Waiting for up to %d seconds for publication of %s\n"
            "on topic %s for client with ClientID: %s\n",
            (int)(TIMEOUT/1000), text[i], TOPIC_PUB, CLIENTID);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message with delivery token %d delivered\n", token);
    usleep(3000000L);
    }
    
    
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
}
