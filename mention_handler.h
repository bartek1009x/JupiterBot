#include <concord/discord_codecs.h>
#include <string.h>
#include <concord/discord.h>

void send_ping_message(struct discord *client, const struct discord_message *event);
void handle_mentions(struct discord *client, const struct discord_message *event);
