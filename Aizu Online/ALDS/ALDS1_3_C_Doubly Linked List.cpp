#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef struct _node{
	int value;
	struct _node* next;
	struct _node* prev;
}node;
node* nil;

void printNodes(){
	node* p=nil;
	while(p->next->next!=nil){
		p=p->next;
		cout<<p->value<<" ";
	}
	p=p->next;
	cout<<p->value<<"\n";
}

void insertNode(int value){
	node* p= new node;
	p->value=value;
	p->next=nil->next;
	p->next->prev=p;
	p->prev=nil;
	nil->next=p;
}

node* searchNode(int value){ 
	node* curr=nil->next;
	while(curr!=nil&&curr->value!=value){
		curr=curr->next;
	}
	return curr;
}
void deleteNode(node* d){
	if(d!=nil){
		d->next->prev=d->prev;
		d->prev->next=d->next;
		delete d;
	}
}

void deleteValue(int v){
	node* d=searchNode(v);
	deleteNode(d);
}
void deleteFirst(){
	deleteNode(nil->next);
}
void deleteLast(){
	deleteNode(nil->prev);
}

int main(){
	nil=new node;
	nil->prev=nil;
	nil->next=nil;
	int n;
	cin>>n;
	char command[20];
	int v;
	for(int i=0;i<n;i++){
		scanf("%s",command);
		if(strlen(command)>6){
			if(command[6]=='F')deleteFirst();
			else deleteLast();
		}
		else{
			scanf("%d",&v);
			if(command[0]=='i') insertNode(v);
			else deleteValue(v);
		}
	}
	printNodes();
}
