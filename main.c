#include <concord/discord_codecs.h>
#include <concord/discord.h>
#include <concord/log.h>
#include <stdlib.h>
#include "mention_handler.h"
#include "command_handler.h"

void on_ready(struct discord *client, const struct discord_ready *event) {
    log_info("Logged in as %s!", event->user->username);
}

void on_message(struct discord *client, const struct discord_message *event) {
    if (handle_mentions(client, event)) return;

    handle_command(client, event);
}

int main() {
    struct discord *client = discord_init(getenv("JupiterBot_Token"));
    discord_add_intents(client, DISCORD_GATEWAY_MESSAGE_CONTENT);
    discord_set_on_ready(client, &on_ready);
    discord_set_on_message_create(client, &on_message);
    discord_run(client);
}
