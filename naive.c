#include <stdio.h>
#include <string.h>
void search(char *pat,char *txt){
	int M = strlen(pat);
	int N = strlen(txt);
	int i;
	for (i = 0; i <= N-M; i++){
		int j = 0;
		for (j = 0; j < M; j++){
			if(txt[i+j] != pat[j])
				break;
		}
	//check whether the pattern was found
		if(j == M){
			printf("Pattern found at: %d\n",i);
		}
		else{
			printf("Pattern not found\n");
		}
	}
}	
int main()
{
	char txt[] = "AABAACAADAABAAAABAA"; 
	char pat[] = "AABA";
	search(pat,txt);

	//test 2
	char txt2[] = "AAAAAAAA";
	char pat2[] = "AAA";
	search(pat,txt);
	return 0;
}
