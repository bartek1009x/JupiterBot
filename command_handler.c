#include "command_handler.h"
#include "constants.h"
#include <stdlib.h>

char *jupiter_responses[] = {
    "nuh uh",
    "what did you say?",
    ">:(",
    "you uncultured being",
    "you jello with no moral spine how could you call me that",
    "you twat",
    "get back to playing, drummer boy",
    "i'm gonna kill you",
    "IP. 92.28.211.23\nN: 43.7462\nW: 12.4893 SS\nNumber: 6979191519182043\nIPv6: fe80:5dcd.:ef69:fb22::d9\nUPP: Enabled DMZ: 10.112.42\nMAC: 5A:78:3:7E:00\nDNS: 8.8.8.8\nALT DNS: 1.1.1.8.1\nDNS SUFFIX:\nDink WAN: 100.236\nGATEWAY: 192.168\nUDP OPEN PORT: 8080.80",
    "shut up soyboy",
    "ts not tuff 🥀🥀",
    "https://tenor.com/dSBMv5dRyM.gif"
};

const int MIN_REPONSE_INDEX = 0;
const int MAX_RESPONSE_INDEX = 11;

void handle_command(struct discord *client, const struct discord_message *event) {
    if (strcmp(event->content, "CLANKER") == 0 && event->author->id == REAL_JUPITER_ID) {
        int random_response_index = rand() % (MAX_RESPONSE_INDEX - MIN_REPONSE_INDEX + 1) + MIN_REPONSE_INDEX;
        struct discord_message_reference ref = {
            .message_id = event->id,
            .channel_id = event->channel_id,
            .guild_id = event->guild_id
        };
        struct discord_create_message params = {
            .content = jupiter_responses[random_response_index],
            .message_reference = &ref
        };
        discord_create_message(client, event->channel_id, &params, NULL);
    }
}
