# fastJsonParser

This is another json parser! but more improved. Inspired by zserge's jsmn (https://github.com/zserge/jsmn) but with some changes. Basically this don't have any tokens which are filled in array unlike jsmn but instead will give data according to type <code/>JSON_Type</code> on each call. Currently there is no implementation of any validation logic to validate JSON according to spec, but soon I will be adding it. 

This is very minimalistic and light weight which is easy to use. Only static memory allocation is used hence it can be used on small embedded systems too. Unlike jsmn which fills a array of <code/>jsmn_tokens</code> this returns a <code/>fast_json_parser</code> type struct on each call of <code/>json_parse()</code> which has following details: 
```
typedef struct {
	JSON_Type parsed_type;
	uint8_t *Start;
	uint8_t *End;
} fast_json_parser;
```
The <code/>parsed_type</code> will have enum of different JSON data types:
```
JSON_OBJ,
JSON_STRING,
JSON_ARRAY,
JSON_BOOL,
JSON_PRIMITIVE,
JSON_END,
JSON_UNDEFINED
```
The <code/>JSON_END</code> is not a typical JSON type data but it indicates the end of JSON string which can be useful. So instead of filling a array of different JSON type data, this parser parses it on the go! If you still need a pre-parsed array of parser type then you can loop through the JSON string and add each parsed <code/>fast_json_parser</code> to the array of that type or else you can use jsmn! 

# Contributing
Contribution is welcome!

# Contact

You can contact me on <Email/>mrunalahirrao@yahoo.com</Email>

# License

This has free license, so you can use it even commercially!
