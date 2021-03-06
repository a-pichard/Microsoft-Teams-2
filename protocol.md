# my_teams protocol
## user request:

```
request = command [sp data]* end;
response = code (sp data)* end;
```

```
command = value;
code = (digit){3};
data = string | uuid;
digit = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;
string = '"' value '"';
charactere = printable ascii caractère
uuid = ('0' .. '9' | 'a' .. 'f' | '-'){36};
end = '\r\n';
sp = ' '
time = ('0' .. '9' | 'a' .. 'f'){8}

user_id = uuid
name = """ charactere{32} """
user_status = ("0" | "1")
user_name = name
user (user_id sp user_name sp user_status)
message_body = """ charactere{512} """
description = """ charactere{255} """
team_uuid = uuid
channel_uuid = uuid
thread_uuid = uuid
```

### help
```
request = 'help' end
response = 200 sp helper end
helper = string
```

### login
```
request = 'login' sp name end
response = 200 sp user end | 300 sp '"user already logged"' end
```

### logout
```
request = 'logout' end
response = 200 sp user end | 300 end
```

### users
```
request = 'users' end
response = 200 sp user* end | 300 end
```

### user
```
request = 'user' end
response = 200 sp user end | 300 end | 4xx end
```

### send
```
request = 'send' user_uuid message_body
response = 200 end | 300 end | 4xx sp user_uuid sp end 
```

### messages
```
request = 'messages' user_uuid
response = 200 (user_uuid time message_body)* end | 300 end | 4xx sp user_uuid sp end
```

### subscribe
```
request = 'subscribe' team_uuid
response = 200 sp user_uuid sp team_uuid end | 300  end | 4xx end
```

### subscribed
```
request = 'subscribed' [team_uuid]
response = 200 (team_uuid name description)* end | 200 (team_uuid name description) end | 300 end | 4xx sp  end
```

### unsubscribe
```
request = 'unsubscribe' team_uuid
response = 200 (user_uuid team_uuid) end | 300 end | 4xx end
```

### use 
```
request = 'use' [team_uuid | (team_uuid channel_uuid) | (team_uuid channel_uuid thread_uuid)]
response = 200 end |  300 end | 4xx end
```

### create
- Not define (team created)
```
request = 'create' (name description) :  create a new team
response = 200 (team_uuid name description) | 300 end | 4xx end
```
- team (channel created)
```
request = 'create' (name description) : create a new channel
response = 201 (channel_uuid name description) | 300 end | 4xx end
```
- channel (thread created)
```
request = 'create' (name message_body) :  create a new thread
response = 202 (thread_uuid user_uuid time name thread_body) | 300 end | 4xx end
```
- thread (reply created)
```
request = 'create' (message_body) : create a new reply
response = 203 (thread_uuid reply_uuid user_uuid time message_body) | 300 end | 4xx end
```

### list
request = 'list' 
- Not define (ask for teams)
```
response = 200 (team_uuid name description)* end | 300 end
```
- team (ask for channels)
```
response = 201 (channel_uuid name description)* end | 300 end
```
- channel (ask for threads)
```
response = 202 (thread_uuid user_uuid time name thread_body)* end | 300 end

```
- thread (ask for replies)
```
response = 203 (thread_uuid user_uuid time message_body)* end | 300 sp 
```

### info
request = 'info' 
- Not define (ask for teams)
```
response = 200 context user end | 300 end
```
- team (ask for channels)
```
response = 201 (team_uuid name description) end | 300 end
```

- channel (ask for threads)
```
response = 202 (channel_uuid name description) end | 300 end
```

- thread (ask for replies)
```
response = 203 (thread_uuid user_uuid time name message_body) end | 300 end
```

### code
```
2xx = success
200 = normal
201 = use est dans un team
202 = use est dans un channe
203 = use est dans un thread

300 = not logged in

4xx uuid =  uuid not found
400 = user not foud
401 = team not found
402 = channel not found
403 = thread not found

5xx = error

6xx = already exist

```

## event

### login
```
response = "event" "login" user
```
### logout
```
response = "event" "logout" user
```

### message
- private message
```
response = "event" "message" "user" (user_uuid message_body)
```
- thread 
```
response = "event" "message" "thread" (team_uuid thread_uuid comment_uuid user_uuid time message_body)
```

### creation
- team
```
response = "event" "create" "team" (team_uuid name description)
```

- channel
```
response = "event" "create" "channel" (channel_uuid channel name channel_description)
```

- thread
```
response = "event" "create" "thread" (tread_uuid user_uuid time name message_body)
```

