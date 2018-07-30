#include "mjc_mqtt.h"
#include "log.h"

int mjc_mqtt_pub(char *payload)
{
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    int rc = 0;
    if(payload == NULL)
    {
        DBG_PRINTF("payload is NULL\n");
        goto TAG_EXIT;
    }

    MQTTClient_create(&client, ADDRESS, SUB_CLIENTID,
                      MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(-1);
    }
    pubmsg.payload = payload;
    pubmsg.payloadlen = strlen(payload);
    pubmsg.qos = QOS_PUB;
    pubmsg.retained = 0;
    MQTTClient_publishMessage(client, TOPIC_PUB, &pubmsg, &token);
    printf("Waiting for up to %d seconds for publication of %s\n"
           "on topic %s for client with ClientID: %s\n",
           (int)(TIMEOUT / 1000), payload, TOPIC_PUB, CLIENTID);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message with delivery token %d delivered\n", token);
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
TAG_EXIT:
    return rc;
}

int mjc_mqtt_resp_pub(char *payload)
{
    DBG_PRINTF("===============> mjc_mqtt_resp_pub IN\n");
    MQTTClient *client = NULL;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    int rc = 0;
    if(payload == NULL)
    {
        DBG_PRINTF("payload is NULL\n");
        goto TAG_EXIT;
    }

    client = (MQTTClient *)mjc_get_client();
    if(client == NULL)
    {
        DBG_PRINTF("get client fail\n");
        goto TAG_EXIT;
    }

    pubmsg.payload = payload;
    pubmsg.payloadlen = strlen(payload);
    pubmsg.qos = QOS_PUB;
    pubmsg.retained = 0;
    MQTTClient_publishMessage(*client, TOPIC_PUB, &pubmsg, &token);

    printf("Waiting for up to %d seconds for publication of %s\n"
           "on topic %s for client with ClientID: %s\n",
           (int)(TIMEOUT / 1000), payload, TOPIC_PUB, CLIENTID);
    rc = MQTTClient_waitForCompletion(*client, token, TIMEOUT);
    printf("Message with delivery token %d delivered\n", token);
    printf("RC :%d",rc);
    //MQTTClient_disconnect(client, 10000);
    //MQTTClient_destroy(&client);
    DBG_PRINTF("<=============== mjc_mqtt_resp_pub OUT\n");
TAG_EXIT:
    return rc;
}