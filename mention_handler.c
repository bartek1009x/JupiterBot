#include "mention_handler.h"
#include "constants.h"

void send_ping_message(struct discord *client, const struct discord_message *event) {
    char buffer[30];
    snprintf(buffer, sizeof(buffer), "jupiter\nping: %dms", discord_get_ping(client));
    struct discord_create_message params = { .content = buffer };
    discord_create_message(client, event->channel_id, &params, NULL);
}

void handle_mentions(struct discord *client, const struct discord_message *event) {
    if (event->mentions->size > 0) {
        for (int i = 0; i < event->mentions->size; i++) {
            struct discord_user mentionedUser = event->mentions->array[i];
            if (mentionedUser.id == ID) {
                send_ping_message(client, event);
                break;
            }
        }
    } else if (event->mention_roles->size > 0) {
        struct discord_roles roles;
        struct discord_ret_roles ret = { .sync = &roles };
        discord_get_guild_roles(client, event->guild_id, &ret);

        for (int i = 0; i < event->mention_roles->size; i++) {
            u64snowflake mentionedRole = event->mention_roles->array[i];

            bool shouldBreak = false;
            for (int j = 0; j < roles.size; j++) {
                if (roles.array[j].id == mentionedRole && roles.array[j].managed && strcmp(roles.array[j].name, "JupiterBot") == 0) {
                    send_ping_message(client, event);
                    shouldBreak = true;
                    break;
                }
            }
            if (shouldBreak) break;
        }
    }
}
