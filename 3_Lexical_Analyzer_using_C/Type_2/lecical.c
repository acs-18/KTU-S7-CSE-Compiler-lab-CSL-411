
#include <stdio.h>
#include <string.h>

void main() {
	char buffer[128], ch;
	FILE *fp;
	fp = fopen("D:\\Compiler\\input.txt", "r");
	int state = 0, bcount = 0;
	while(fscanf(fp, "%s", buffer) != EOF) {
		if(buffer[0] >= 48 && buffer[0] <= 57) 
			printf("Number: \t%s\n", buffer);
		else if(!strcmp(buffer, "void") || !strcmp(buffer, "main") || !strcmp(buffer, "int"))
			printf("Keyword: \t%s\n", buffer);
		else if(buffer[0] == '%' || buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
			printf("Operator: \t%s\n", buffer);
		else if(buffer[0] == '{' || buffer[0] == '}' || buffer[0] == '(' || buffer[0] == ')' || buffer[0] == ';')
			printf("Symbol: \t%s\n", buffer);
		else
			printf("Identifier: \t%s\n", buffer);
	}
	fclose(fp);
}