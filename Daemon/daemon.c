#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <paho-mqtt/MQTTClient.h>

char espInput;

int check_for_input()
{
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message message = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;

    MQTTClient_create(&client, server_url, client_id, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    MQTTClient_connect(client, &conn_opts);
    MQTTClient_subscribe(client, "my/topic", 0)

        int loop = 0;
    while (loop == 0)
    {
        MQTTClient_receive(client, &message, 1000)

            char pass = (char *)message.payload;

        if (pass != null)
        {
            loop++;
            espInput = pass;
        }

        MQTTClient_freeMessage(&message);
        MQTTClient_free(message.payload);
        sleep(1);
    }

    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);

    return 0;
}

void run_cpu()
{
    char path[1024];
    sprintf(path, "%s/%s", "folder_location", "cpu.c");
    strcpy(path, " " + espInput);
    system(path);
}

int main()
{
    while (1)
    {
        if (0 == system("pidof -x player.c > folder_location"))
        {
            check_for_input();
        }else{
            run_cpu();
            check_for_input();
        }
    }
    return 0;
}
