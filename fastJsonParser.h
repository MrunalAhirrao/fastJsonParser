/*
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 and associated documentation files (the "Software"), to deal in the Software without restriction,
 including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:

 This permission notice shall be included in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
 NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 * Author: Mrunal Ahirrao
 * Email: mrunalahirrao@yahoo.com
 */

#ifndef FASTJSONPARSER_H_
#define FASTJSONPARSER_H_

#include <stdint.h>

/*
 * JSON types typedef used to indicate the data indicated is of what type of JSON.
 */
typedef enum {
	JSON_OBJ,
	JSON_STRING,
	JSON_ARRAY,
	JSON_BOOL,
	JSON_NUM,
	JSON_END,
	JSON_UNDEFINED
} JSON_Type;

/*
 * The parser typedef which gives following information:
 * 1. The JSON type
 * 2. The start and End pointers of memory for the given JSON Type
 */
typedef struct {
	JSON_Type parsed_type;
	uint8_t *Start;
	uint8_t *End;
} fast_json_parser;

extern uint8_t *StartAddr;
extern uint8_t *EndAddr;

/*Function prototypes of json parser*/

/*This function will initialize the variables used in the parser*/
void json_parser_init();

/*This function will parse the JSON in memory and will return the next microcDB_json_parser type on each call. The type JSON_END indicates
 * the memory within which the search needs to be done is completed or the parsing has reached the last address of microcDB memory*/
fast_json_parser json_parse();

/*Function prototypes of json parser*/

#endif /* FASTJSONPARSER_H_ */
