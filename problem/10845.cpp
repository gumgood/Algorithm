#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _link{
	int data;
	struct _link *next;
}link;

typedef struct _queue{
	int _size;
	link *_front, *_rear;
	_queue(){
		_size = 0;
		_front = NULL;
		_rear = NULL;
	}
	void push(int x){
		link *_new = (link*)malloc(sizeof(link));
		*_new = {x,NULL};
		if(_size == 0)
			_front = _rear = _new;
		else{
			_rear->next = _new;
			_rear = _new;
		}
		_size++;
	}
	bool pop(){
		if(_size==0)
			return 1;
		else if(_size==1){
			_front = NULL;
			_rear = NULL;
		} else{
			link *t = _front;
			_front = _front->next;
			free(t);
		}
		_size --;
		return 0;
	}
	int size(){
		return _size;
	}
	bool empty(){
		return _size ? 0 : 1;
	}
	int front(){
		if(_size == 0) return -1;
		return _front->data;
	}
	int back(){
		if(_size == 0) return -1;
		return _rear->data;
	}
}queue;

int main(){
	char in[6];
	int n, x;
	scanf("%d", &n);

	queue q;
	while(n--){
		scanf("%s", in);
		if(!strcmp(in, "push")){
			scanf("%d", &x);
			q.push(x);
		} else if(!strcmp(in, "pop")){
			printf("%d\n", q.front());
			q.pop();
		} else if(!strcmp(in, "size")){
			printf("%d\n", q.size());
		} else if(!strcmp(in, "empty")){
			printf("%d\n", q.empty());
		} else if(!strcmp(in, "front")){
			printf("%d\n", q.front());
		} else if(!strcmp(in, "back")){
			printf("%d\n", q.back());
		}
	}
	return 0;
}
