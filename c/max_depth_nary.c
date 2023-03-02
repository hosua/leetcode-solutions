#include <stdio.h>
#include <stdlib.h>

// Definition for a Node.
struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

struct Node* newNode(int val){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->val = val;
	new_node->numChildren = 0;
	new_node->children = NULL;
	return new_node;
}

void addChildren(struct Node** node, int* children, int numChildren){
	(*node)->numChildren = numChildren;
	(*node)->children = (struct Node**) malloc(sizeof(struct Node*) * numChildren);
	for (int i = 0; i < numChildren; i++)
		(*node)->children[i] = newNode(children[i]);
}

// #define max(a,b) ((a)>(b) ? (a) : (b))
// DFS results in TLE
// int maxDepth(struct Node* root) {
// 	if (!root)
// 		return 0;
// 	int curr_max = 0;
// 	for (int i = 0; i < root->numChildren; i++)
// 		curr_max = max(curr_max, maxDepth(root->children[i]));
// 	return curr_max+1;		
// }

struct QNode {
	struct Node* val;
	struct QNode* next;
};

struct Queue {
	struct QNode* head;
	struct QNode* tail;
	size_t sz;
};

struct QNode* newQNode(struct Node* node){
	struct QNode* new_q_node = (struct QNode*) malloc(sizeof(struct QNode));
	new_q_node->next = NULL;
	new_q_node->val = node;
	return new_q_node;
};

struct Queue* initQueue(){
	struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
	q->head = q->tail =  NULL;
	q->sz = 0;
	return q;
}

void push(struct Node* node, struct Queue** q){
	struct QNode* new_q_node = newQNode(node);
	if (!(*q)->head)
		(*q)->head = (*q)->tail = new_q_node;
	else
		(*q)->tail = (*q)->tail->next = new_q_node;
	(*q)->sz++;
}

struct QNode* front(struct Queue q){
	return q.head;
}

void pop(struct Queue** q){
	if ((*q)->head){
		struct QNode* temp = (*q)->head;
		(*q)->head = (*q)->head->next;
		free(temp);
		if (!(*q)->head)
			(*q)->tail = NULL;
		(*q)->sz--;
	}
}

int qEmpty(struct Queue q){
	return (q.head) ? 0 : 1;
}

size_t qSize(struct Queue q){
	return q.sz;
}

// Idk why BFS would be better but lets try it 
int maxDepth(struct Node* root) {
	if (!root)
		return 0;

	int level = 0;
	struct Queue* q = initQueue();
	push(root, &q);	
	while (!qEmpty(*q)){
		size_t breadth = qSize(*q);		
		while (breadth--){
			struct QNode* node = front(*q);
			for (int i = 0; i < node->val->numChildren; i++)
				push(node->val->children[i], &q);
			pop(&q);
		}
		level++;
	}
	return level;
}

void print_preorder(struct Node* node){
	if (!node)
		return;
	
	printf("%i->", node->val);
	for (int i = 0; i < node->numChildren; i++)
		print_preorder(node->children[i]);
}

int main(){
	
	struct Node* one = newNode(1);
	struct Node* three = newNode(3);
	struct Node* two = newNode(2);
	struct Node* four = newNode(4);
	int one_numChildren = 3;
	int one_children[] = {3,2,4};
	addChildren(&one, one_children, one_numChildren);
	free(one->children[0]);
	one->children[0] = three;
	int three_numChildren = 2;
	int three_children[] = {5,6};
	addChildren(&three, three_children, three_numChildren);
	//print_preorder(one);

	int res = maxDepth(one);
	printf("res: %i\n", res);
}
