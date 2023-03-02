#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* address sanitizer says this is dirty :( */

int cmp_arr(int *a, int *b, size_t sz){
	while (sz--)
		if (*a++ != *b++)
			return 0;
	return 1;
}

#define ALPHA 26
int* findAnagrams(char * s, char * p, int* returnSize){
	int* res;
	*returnSize = 0;

	int slen = strlen(s);
	int plen = strlen(p);

	if (plen > slen)
		return res;

	int pcnt[ALPHA];
	memset(pcnt, 0, sizeof(int)*ALPHA);
	int window[ALPHA];
	memset(window, 0, sizeof(int)*ALPHA);
	
	char* sp = s;
	char* pp = p;
	while (*pp){
		size_t p_chin = *pp - 'a';
		pcnt[p_chin]++;
		size_t s_chin = *sp - 'a';
		window[s_chin]++;
		sp++;
		pp++;
	}
	
	int i = 0;

	if (cmp_arr(pcnt, window, ALPHA)){
		res = realloc(res, (*returnSize)+1);
		res[(*returnSize)++] = i;
	}

	while (*sp){
		int start = *(sp-plen) - 'a';	
		int end = *sp - 'a';	
		window[start]--;
		window[end]++;
		if (cmp_arr(pcnt, window, ALPHA)){
			res = realloc(res, (*returnSize)+1);
			res[(*returnSize)++] = i+1;
		}
		sp++;
		i++;
	}


	return res;
}

int main(){
	// char* s = "cbaebabacd";
	// char* p = "abc";
	char* s = "abab";
	char* p = "ab";
	int n = 420;
	int* res = findAnagrams(s,p,&n);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%i ", res[i]);
	printf("\n");
}
