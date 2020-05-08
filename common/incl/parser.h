#include "linked_list.h"
#include <stdlib.h>
#include <string.h>

typedef struct parser_result_s {
    const char **remainer;
    void *data;
} parser_result_t;

typedef void* (*parser_fn)(const char *string);
typedef void (*destructor_fn)(void *element);

typedef enum {
    VALUE,
    AND,
    TAB,
} parser_type_t;

typedef struct parser_s {
    parser_type_t type;
    union {
        parser_fn parser_function;
        struct parser_s **parser;
    };
    destructor_fn destructor;
} parser_t;

//general parse function
parser_result_t *parse_and(const char **token, parser_t *parser);
parser_result_t* parse(const char **token, parser_t *p);

//create 
parser_result_t *create_result(void *data, const char **token);

//value parser
void *parse_int_function(const char *token);
void *parse_uuid_function(const char *token);
void *parse_string_function(const char *token);

//use full macro
#define UUID_PARSER {.type=VALUE, {.parser_function=parse_uuid_function}, .destructor=free}
#define INT_PARSER {.type=VALUE, {.parser_function=parse_int_function}, .destructor=free}
#define STRING_PARSER {.type=VALUE, {.parser_function=parse_string_function}, .destructor=free}

#define AND_PARSER(name, ...) parser_t *name##_parser_tab[] = {__VA_ARGS__, NULL};  \
parser_t name = {.type=AND, {.parser=name##_parser_tab}};
