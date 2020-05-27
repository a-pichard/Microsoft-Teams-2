/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** logging_client
*/

#ifndef __LOGGING_CLIENT_H__
#define __LOGGING_CLIENT_H__

#include <stdint.h>
#include <time.h>

int client_event_loggedin(char const *user_id, const char *user_name);

int client_event_loggedout(char const *user_id, const char *user_name);

int client_event_private_message_received(char const *user_id,
    char const *message_body);

int client_event_thread_message_received(char const *team_id,
    char const *thread_id, char const *user_id, char const *message);

int client_event_team_created(char const *team_id, char const *team_name,
    char const *team_description);

int client_event_channel_created(char const *channel_id,
    char const *channel_name, char const *channel_description);

int client_event_thread_created(char const *thread_id, char const *user_id,
    time_t thread_timestamp, char const *thread_title,
    char const *thread_body);

int client_print_users(char const *user_id, char const *user_name,
    int user_status);

int client_print_teams(char const *team_id, char const *team_name,
    char const *team_description);

int client_team_print_channels(char const *channel_id,
    char const *channel_name, char const *channel_description);

int client_channel_print_threads(char const *thread_id, char const *user_id,
    time_t thread_timestamp, char const *thread_title,
    char const *thread_body);

int client_thread_print_replies(char const *thread_id, char const *user_id,
    time_t reply_timestamp, char const *reply_body);

int client_private_message_print_messages(char const *sender_id,
    time_t timestamp, char const *message);

int client_error_unknown_team(char const *team_id);

int client_error_unknown_channel(char const *channel_id);

int client_error_unknown_thread(char const *thread_id);

int client_error_unknown_user(char const *user_id);

int client_error_unauthorized(void);

int client_error_already_exist(void);

int client_print_user(char const *user_id, char const *user_name,
    int user_status);

int client_print_team(char const *team_id, char const *team_name,
    char const *team_description);

int client_print_channel(char const *channel_id, char const *channel_name,
    char const *channel_description);

int client_print_thread(char const *thread_id, char const *user_id,
    time_t thread_timestamp, char const *thread_title,
    char const *thread_body);

int client_print_team_created(char const *team_id, char const *team_name,
    char const *team_description);

int client_print_channel_created(char const *channel_id,
    char const *channel_name, char const *channel_description);

int client_print_thread_created(char const *thread_id, char const *user_id,
    time_t thread_timestamp, char const *thread_title,
    char const *thread_body);

int client_print_reply_created(char const *thread_id, char const *user_id,
    time_t reply_timestamp, char const *reply_body);

int client_print_subscribed(char const *user_id, char const *team_id);

int client_print_unsubscribed(char const *user_id, char const *team_id);

#endif /* __LOGGING_CLIENT_H__ */
