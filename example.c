#include<stdio.h>
#include<string.h>

#include "fastJsonParser.h"

char *JSON_STRING_data =
		"{\"user\":\"johndoe\",\"admin\":false,\"uid\":1000,\"groups\":[\"users\",\"wheel\",\"audio\",\"video\"]}";

char *newjson =
		"{\"user\":{\"ListOfIDUs\":[1,2,3,4,5],\"IDU_Info\":[{\"IDU_Num\":1,\"Fan speed\":\"High\",\"TSC\":1},{\"IDU_Num\":2,\"Fan speed\":\"High\",\"TSC\":1},{\"IDU_Num\":3,\"Fan speed\":\"High\",\"TSC\":1},{\"IDU_Num\":4,\"Fan speed\":\"High\",\"TSC\":1}]}}";

char *smalljson = "{\"data\":{\"List\":[1,2,3,4,5]}}";

fast_json_parser parser;

uint8_t someBuff[1000],cntr = 0;

int main(void) {
	StartAddr = (uint8_t*) newjson;
	EndAddr = StartAddr + 212;
	json_parser_init();
	while(1) {
		parser = json_parse();

		while(parser.Start<parser.End + 1){
			someBuff[cntr] = *parser.Start;
			parser.Start++;
			cntr++;
		};

		if(parser.parsed_type == JSON_OBJ){
			printf("JSON OBJECT is:%s\n",someBuff);
		}else if(parser.parsed_type == JSON_STRING){
			printf("JSON STRING is:%s\n",someBuff);
		}else if(parser.parsed_type == JSON_ARRAY){
			printf("JSON ARRAY is:%s\n",someBuff);
		}else if(parser.parsed_type == JSON_BOOL){
			printf("JSON BOOLEAN is:%s\n",someBuff);
		}else if(parser.parsed_type == JSON_PRIMITIVE){
			printf("JSON PRIMITIVE is:%s\n",someBuff);
		}else if(parser.parsed_type == JSON_END){
			printf("JSON Ended here %s\n",someBuff);
		}


		cntr = 0;
		memset(someBuff,0,1000);

		if(parser.parsed_type == JSON_END)break;
	}
	return 0;
}
