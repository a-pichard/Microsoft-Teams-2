#include "linked_list.h"
#include <stdlib.h>
#include <string.h>


typedef void* (*parser_fn)(const char *string);
typedef void (*destructor_fn)(void *element);

typedef struct parser_result_s {
    char const * const *remainer;
    void *data;
} parser_result_t;
typedef enum {
    VALUE,
    AND,
    TAB,
    SUROUNDED,
    SEP,
} parser_type_t;

typedef struct parser_s {
    parser_type_t type;
    union {
        parser_fn parser_function;
        struct parser_s **parsers;
        struct parser_s *parser;
    };
    destructor_fn destructor;
    char sep;
} parser_t;

//general parse function
parser_result_t *parse_and(char const * const *token, parser_t *parser);
parser_result_t* parse(char const * const * token, parser_t *p);
parser_result_t *parse_tab(char const * const * token, parser_t *parser);

//create 
parser_result_t *create_result(void *data, char const * const * token);

//clean
void parser_result_clean(parser_t *p, parser_result_t *r);

//value parser
void *parse_int_function(const char *token);
void *parse_uuid_function(const char *token);
void *parse_string_function(const char *token);

//use full macro
#define UUID_PARSER {.type=VALUE, {.parser_function=parse_uuid_function}, .destructor=free}
#define INT_PARSER {.type=VALUE, {.parser_function=parse_int_function}, .destructor=free}
#define STRING_PARSER {.type=VALUE, {.parser_function=parse_string_function}, .destructor=free}

#define AND_PARSER(name, ...) parser_t *name##_parser_tab[] = {__VA_ARGS__, NULL};  \
parser_t name = {.type=AND, {.parsers=name##_parser_tab}};

#define TAB_PARSER(name, element_parser) parser_t name = {.type=TAB, {.parser=element_parser}, NULL}

#define SEP_PARSER(separateur, p) {.type=SEP, .parser=p, .sep=separateur}
#define SUROUNDE_PARSER(separateur, p) {.type=SUROUNDED, .parser=p, .sep=separateur}