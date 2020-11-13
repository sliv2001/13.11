#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){
	int i = 0, k = 1;
	char* val;
	char* my_var;
	char* argv1[100] = {};
	char sep[] = "=", sep1[] = " ";
	if (argc<=1)
		return 0;
//	printf("%s\n %s", argv[1], argv[2]);
	for (i=2; i<argc; i++) {
		if (putenv(argv[i])==0) printf("OK\n");
		fflush(stdout);
	}
	argv1[0] = strtok(argv[1], sep1);
	while ((val = strtok(NULL, sep1))!=NULL) {
		//printf("%s\n", val);
		if (val[0]='$')
			argv1[k] = getenv(strtok(val, "$"));
		else
			argv1[k] = val;
		k++;
	}
	argv1[k+1] = NULL;
	k=0;
	while ((val = argv1[k])!=NULL){
		k++;
		//printf("%s\n", val);
	}
	fflush(stdout);
	execvp(argv1[0], argv1);
	return 0;
}
