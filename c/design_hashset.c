#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SET_SIZE 1000

typedef struct {
	int *keys[SET_SIZE];   	 
	size_t hash_cnt[SET_SIZE];
	size_t hash_sz[SET_SIZE];
} MyHashSet;


MyHashSet* myHashSetCreate() {
	MyHashSet* set = (MyHashSet*) malloc(sizeof(MyHashSet)); 
	for (int i = 0; i < SET_SIZE; i++){
		set->hash_cnt[i] = 0;
		set->hash_sz[i] = 10;
		set->keys[i] = (int*)malloc(sizeof(int)*set->hash_sz[i]);
	}

	return set;
}

void myHashSetAdd(MyHashSet* set, int key) {
 	size_t i = key % SET_SIZE; 

	if (set->hash_cnt[i] >= set->hash_sz[i]){
		set->hash_sz[i] += 10;
		set->keys[i] = realloc(set->keys[i], sizeof(int)*set->hash_sz[i]);
	}

	for (int itr = 0; itr < set->hash_cnt[i]; itr++)
		if (set->keys[i][itr] == key) // Already exists, ignore
			return;

	set->keys[i][set->hash_cnt[i]++] = key;
}

void myHashSetRemove(MyHashSet* set, int key) {
 	size_t i = key % SET_SIZE; 
	for (int itr = 0; itr < set->hash_cnt[i]; itr++){
		if (set->keys[i][itr] == key){
			for (int j = itr; j < set->hash_cnt[i]-1; j++)
				set->keys[i][j] = set->keys[i][j+1];
			set->hash_cnt[i]--;
			return;
		}
	}
}

bool myHashSetContains(MyHashSet* set, int key) {
 	size_t i = key % SET_SIZE; 
	for (int itr = 0; itr < set->hash_cnt[i]; itr++)
		if (set->keys[i][itr] == key)
			return true;
	return false;
}

void myHashSetFree(MyHashSet* set) {
   	for (int i = 0; i < SET_SIZE; i++)
		free(set->keys[i]);
	free(set->keys);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* set = myHashSetCreate();
 * myHashSetAdd(set, key);
 
 * myHashSetRemove(set, key);
 
 * bool param_3 = myHashSetContains(set, key);
 
 * myHashSetFree(set);
*/

int main(){

}
