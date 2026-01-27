#include <iostream>
using namespace std;

const int LIMIT = 100000;
int timer = 0;

typedef struct _task {
	int time;
	char name[11];
}task;

task queue[LIMIT];
int front = 0;
int back = 0;// Back is on the next candidate position
// int count = 0; 

void enqueue(task t) {
	queue[back] = t;
	back++;
	if (back == LIMIT) back = 0;
}

task dequeue() {
	task t = queue[front];
	front++;
	if (front == LIMIT) front = 0;
	return t;
}

bool isEmpty(){
	return back==front;
}
void doTask(int slide) {
	task t = dequeue();
	if (t.time <= slide) {
		timer += t.time;
		cout << t.name << " " << timer << endl;
	}
	else {
		t.time -= slide;
		timer+=slide;
		enqueue(t);
	}
}

int main() {
	int n;
	int slide;
	cin >> n >> slide;
	for (int i = 0; i < n; i++) {
		task t;
		cin >> t.name >> t.time;
		enqueue(t);
	}
	while(!isEmpty()){
		doTask(slide);
	} 
}