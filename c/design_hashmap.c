#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAP_SIZE 1000

typedef struct {
	int key, val;	
} KV;

typedef struct {
   	KV *kv[MAP_SIZE]; 
	size_t hash_cnt[MAP_SIZE];
	size_t hash_sz[MAP_SIZE];
} MyHashMap;

MyHashMap* myHashMapCreate();
void myHashMapPut(MyHashMap* map, int key, int value);
int myHashMapGet(MyHashMap* map, int key);
void myHashMapRemove(MyHashMap* map, int key);
void myHashMapFree(MyHashMap* map);

MyHashMap* myHashMapCreate() {
	MyHashMap* map = (MyHashMap*) malloc(sizeof(MyHashMap));    
	for (int i = 0; i < MAP_SIZE; i++){
		map->hash_cnt[i] = 0;
		map->hash_sz[i] = 10;
		map->kv[i] = (KV*) malloc(sizeof(KV)*map->hash_sz[i]);
	}
	return map;
}

void myHashMapPut(MyHashMap* map, int key, int value) {
	size_t i = key % MAP_SIZE; 
	if (map->hash_cnt[i] >= map->hash_sz[i]){ // Allocate more memory if necessary
		map->hash_sz[i] += 10;
		map->kv[i] = (KV*)realloc(map->kv[i], sizeof(KV)*map->hash_sz[i]);
	}
	KV new_kv = { key, value };
	
	for (int itr = 0; itr < map->hash_cnt[i]; itr++){
		if (map->kv[i][itr].key == key){
			map->kv[i][itr].val = value;
			return;
		}
	}
	map->kv[i][map->hash_cnt[i]++] = new_kv;
}

int myHashMapGet(MyHashMap* map, int key) {
 	size_t i = key % MAP_SIZE;
	KV* kv_list = map->kv[i];
	for (int itr = 0; itr < map->hash_cnt[i]; itr++)
		if (map->kv[i][itr].key == key)
			return map->kv[i][itr].val;
	return -1;
}

void myHashMapRemove(MyHashMap* map, int key) {
 	size_t i = key % MAP_SIZE; 
	for (int itr = 0; itr < map->hash_cnt[i]; itr++){
		if (map->kv[i][itr].key == key){
			// shift elements left (linked list would be better for this)
			for (int j = itr; j < map->hash_cnt[i]-1; j++)
				map->kv[i][j] = map->kv[i][j+1]; 
			map->hash_cnt[i]--;
			break;
		}
	}
}

void myHashMapFree(MyHashMap* map) {
   	for (int i = 0; i < MAP_SIZE; i++)
		free(map->kv[i]);
	free(map->kv);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/

int main(){
	MyHashMap* map = myHashMapCreate();

	for (int i = 0; i < 1000; i++){
		myHashMapPut(map, 5, i/2);
		printf("got: %i\n", myHashMapGet(map, 5));
	}
	myHashMapRemove(map, 2);

}
