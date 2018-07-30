#include <stdlib.h>
#include "mjc.h"
#include "mjc_mqtt.h"
#include "log.h"
#include "mjc_json.h"

static MQTTClient client;
static int g_sub_en;

void mjc_delivered(void *context, MQTTClient_deliveryToken dt)
{
    printf("Message with token value %d delivery confirmed\n", dt);
}

int mjc_msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    int i;
    char *payloadptr;
    DBG_PRINTF("=======================> mjc_msgarrvd IN\n");
    printf("Message arrived\n");
    printf("     topic: %s\n", topicName);
    printf("   message: ");

    payloadptr = message->payload;
    payloadptr = mjc_malloc(strlen(message->payload)+1);
    mjc_strncpy(payloadptr, message->payload, strlen(message->payload)+1);

    for (i = 0; i < message->payloadlen; i++)
    {
        //putchar(*payloadptr++);
    }
    printf("\n");

    //mjc_json_handle(message->payload);
    mjc_json_handle(payloadptr);
    //sleep(3);

    mjc_free(payloadptr);
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    DBG_PRINTF("<====================== mjc_msgarrvd  OUT\n");
    return 1;
}

void mjc_connlost(void *context, char *cause)
{
    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);
}

int mjc_mqtt_sub()
{
    /* code */
    //MQTTClient client;
    /** 这里还需要一个获取，订阅的topic来确定应该订阅哪一个topic */
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;

    int rc;

    MQTTClient_create(&client, ADDRESS, CLIENTID,
                      MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    conn_opts.username = USERNAME;
    conn_opts.password = PASSWORD;
    MQTTClient_setCallbacks(client, NULL, mjc_connlost, mjc_msgarrvd, mjc_delivered);

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        //exit(EXIT_FAILURE);
    }
    printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n"
           "Press Q<Enter> to quit\n\n",
           TOPIC_SUB, CLIENTID, QOS_SUB);
    MQTTClient_subscribe(client, TOPIC_SUB, QOS_SUB);

    do
    {
        sleep(1);
    } while (g_sub_en);

    MQTTClient_unsubscribe(client, TOPIC_SUB);
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    return 0;
}

void *mjc_get_client ()
{
    return &client;
}

int mjc_mqtt_sub_init()
{
    DBG_PRINTF("============================>  mjc_mqtt_sub_init\n");
    pthread_t threadID;
    int rc;
    rc = pthread_create(&threadID, NULL, (void *)&mjc_mqtt_sub, NULL);

    if(rc)
    {
        DBG_PRINTF("creat sub pthread error!!!");
    }
    else
    {
        DBG_PRINTF("creat sub pthread success!!! ID:%ld\n",threadID);
        g_sub_en = 1;
        pthread_detach(threadID);
    }

    DBG_PRINTF("<============================  mjc_mqtt_sub_init\n");
    //未进行出错检查

    return 0;
}

int mjc_mqtt_sub_exit()
{
    DBG_PRINTF("============================>  mjc_mqtt_sub_exit\n");
    g_sub_en = 0;
    DBG_PRINTF("kill sub pthread!!!\n");

    DBG_PRINTF("<============================  mjc_mqtt_sub_exit\n");
    return 0;
}