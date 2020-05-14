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
response = 200 sp user end | 300 end | 404 end
```

### send
```
request = 'send' user_uuid message_body
response = 200 end | 300 end | 404 sp user_uuid sp end 
```

### messages
```
request = 'messages' user_uuid
response = 200 (user_uuid time message_body)* end | 300 end | 404 sp user_uuid sp end
```

### subscribe
```
request = 'subscribe' team_uuid
response = 200 sp user_uuid sp team_uuid end | 300  end | 404 end
```

### subscribed
```
request = 'subscribed' [team_uuid]
response = 200 (team_uuid name description)* end | 200 (team_uuid name description) end | 300 end | 404 sp  end
```

### unsubscribe
```
request = 'unsubscribe' team_uuid
response = 200 (user_uuid team_uuid) end | 300 end | 404 end
```

### use 
```
request = 'use' [team_uuid | (team_uuid channel_uuid) | (team_uuid channel_uuid thread_uuid)]
response = 200 end |  300 end | 404 end
```

### create
- Not define
```
request = 'create' (name description) :  create a new team
response = 200 context (team_uuid name description) | 300 end | 404 end
```
- team 
```
request = 'create' (name description) : create a new channel
response = 200 context (channel_uuid name description) | 300 end | 404 end
```
- channel
```
request = 'create' (name message_body) :  create a new thread
response = 200 context (thread_uuid user_uuid time name thread_body) | 300 end | 404 end
```
- thread
```
request = 'create' (message_body) : create a new reply
response = 200 context (thread_uuid user_uuid time message_body) | 300 end | 404 end
```

### list
request = 'list' 
- Not define
```
response = 200 context (team_uuid name description)* end | 300 end
```
- team 
```
response = 200 context (channel_uuid name description)* end | 300 end
```
- channel
```
response = 200 context (thread_uuid user_uuid time name thread_body)* end | 300 end

```
- thread
```
response = 200 context (thread_uuid user_uuid time message_body)* end | 300 sp 
```

### info
request = 'info' 
- Not define
```
response = 200 context user end | 300 end
```
- team
```
response = 200 context (team_uuid name description) end | 300 end
```

- channel
```
response = 200 context (channel_uuid name description) end | 300 end
```

- thread
```
response = 200 sp (thread_uuid user_uuid time name message_body) end | 300 end
```

### code
```
2xx = success
3xx = not logged in
5xx = error
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
response = "event" "message" "thread" (team_uuid thread_uuid user_uuid message_body)
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

