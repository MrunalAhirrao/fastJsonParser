#include<stdio.h>

#include "fastJsonParser.h"

char *JSON_STRING_data =
		"{\"user\":\"johndoe\",\"admin\":false,\"uid\":1000,\"groups\":[\"users\",\"wheel\",\"audio\",\"video\"]}";

char *newjson =
		"{\"user\":{\"ListOfIDUs\":[1,2,3,4,5],\"IDU_Info\":[{\"IDU_Num\":1,\"Fan speed\":\"High\",\"TSC\":1},{\"IDU_Num\":2,\"Fan speed\":\"High\",\"TSC\":1},{\"IDU_Num\":3,\"Fan speed\":\"High\",\"TSC\":1},{\"IDU_Num\":4,\"Fan speed\":\"High\",\"TSC\":1}]}}";

char *smalljson = "{\"data\":{\"List\":[1,2,3,4,5]}}";

fast_json_parser parser;

int main(void) {
	StartAddr = (uint8_t*) smalljson;
	EndAddr = StartAddr + 28;
	json_parser_init();
	while(1) {
		parser = json_parse();
		if(parser.parsed_type == JSON_END)break;
	}
	return 0;
}
