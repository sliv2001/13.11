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
	for (i=2; i<argc; i++) {
		my_var = strtok(argv[i], sep);
		val = strtok(argv[i], sep);
		setenv(my_var, val, 1);
	}
	argv1[0] = strtok(argv[1], sep1);
	while ((val = strtok(argv[1], sep1))!=NULL) {
		argv1[k] = val;
		k++;
	}
	argv1[k+1] = NULL;
	execvp(argv1[0], argv1);
	return 0;
}
