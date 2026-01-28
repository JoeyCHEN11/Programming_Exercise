#include <cstdio>
#include <cstring>
using namespace std;
const int maxLen = 14;
const int N = 1000001;
char table[N][maxLen];

int getCharKey(char c) {
	if (c == 'A') return 1;
	if (c == 'C') return 2;
	if (c == 'G') return 3;
	if (c == 'T') return 4;
	return 0;
}
//计算字符串key
long long getKey(char str[]) {
	//五进制低位起算
	long long key = 0;
	int p = 1;
	for (int i = 0; i < strlen(str); i++) {
		key += p* getCharKey(str[i]);
		p *= 5;
	}
	return key;
}

int h1(long long strKey) { return strKey % N; }
int h2(long long strKey) { return 1 + (strKey % (N - 1)); }
//返回哈希值
int H(long long strKey, int i) {
	return (h1(strKey) + i * h2(strKey)) % N;
}
//插入
void insert(char str[]) {
	long long strKey = getKey(str);
	int hash;
	for (int i = 0;; i++) {
		hash = H(strKey, i);
		if (table[hash][0] == '\0') {
			strcpy(table[hash], str);
			return;
		}
	}
}
//查询
int search(char str[]) {
	long long strKey = getKey(str);
	int hash;
	
	for (int i = 0;; i++) {
		hash = H(strKey, i);
		if (table[hash][0] == '\0') return 0;
		else if (strcmp(table[hash], str)==0) return 1;
	}
}

int main(){
	int n;
	char command[7];
	char str[maxLen];
	for (int i = 0; i < N; i++) table[i][0] = '\0';
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%s%s", command, str);
		//cin >> command >> str;
		if (command[0] == 'i')insert(str);
		else if (command[0] == 'f') {
			if (search(str)==1) printf("yes\n");
			else  printf("no\n");
		}
    }
	return 0;
}

/*复健

#include <iostream>
#include <string>

using namespace std;
const int MODNUM = 1e9+7;
const int MODNUM1 = 1e9+9;
const int MODNUM2 = 998244353;
const int M1e4 = 10499;
const int M1e5 = 100019;
const int M1e6 = 1000003;
const int M1e7 = 10000019;
const int M1e8 = 100000007;
const int M = 1000003;
string dic[M];

int c_to_i(char c){
    switch(c){
    case 'A':
        return 1;
    case 'C':
        return 2;
    case 'G':
        return 3;
    case 'T':
        return 4;
    default:
        return -1;
    }
}

long long getKey(string str){
    long long key = 0;
    for(char c : str){//C++11 new for feature
        key *= 5;
        key += c_to_i(c);
    }
    return key;
}

int h1(long long key){
    return key%M;
}

int h2(long long key){
    return 1+key%(M-1);
}

int H(long long key, int i){
    return (h1(key)+i*h2(key)) % M;
}

void insert(string str){
    
    long long key = getKey(str);
    int pos = H(key, 0);
    for(int i = 1; dic[pos]!=""; i++) pos = H(key, i);
    dic[pos] = str;
}

bool find(string str){
    long long key = getKey(str);
    for(int i = 0, pos = H(key, i); dic[pos] != "" && i<M; pos = H(key, ++i)){
        if(dic[pos] == str) return true;
    }
    return false;
}

int main(){
    string str, command;
    int n;
    for(string & s: dic) s = ""; 
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>command>>str;
        if(command[0] == 'i'){
            insert(str);
        }
        else if(command[0] == 'f'){
            if(find(str)) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
    }
}

*/

/* 复健-优化

#include <cstdio>
#include <cstring>

using namespace std;
const int MODNUM = 1e9+7;
const int MODNUM1 = 1e9+9;
const int MODNUM2 = 998244353;
const int M1e4 = 10499;
const int M1e5 = 100019;
const int M1e6 = 1000003;
const int M1e7 = 10000019;
const int M1e8 = 100000007;
const int M = 1000003;
const int MAXLEN = 15;
char dic[M][MAXLEN];

int c_to_i(char c){
    switch(c){
    case 'A':
        return 1;
    case 'C':
        return 2;
    case 'G':
        return 3;
    case 'T':
        return 4;
    default:
        return -1;
    }
}

long long getKey(char str[]){
    long long key = 0;
    for(int i = 0; i<strlen(str); i++){
        key *= 5;
        key += c_to_i(str[i]);
    }
    return key;
}

int h1(long long key){
    return key%M;
}

int h2(long long key){
    return 1+key%(M-1);
}

int H(long long key, int i){
    return (h1(key)+i*h2(key)) % M;
}

void insert(char str[]){
    long long key = getKey(str);
    int pos = H(key, 0);
    for(int i = 1; dic[pos][0]!='\0'; i++) pos = H(key, i);
    strcpy(dic[pos],str);
}

bool find(char str[]){
    long long key = getKey(str);
    for(int i = 0, pos = H(key, i); dic[pos][0]!='\0' && i<M; pos = H(key, ++i)){
        if(!strcmp(dic[pos],str)) return true;
    }
    return false;
}

int main(){
    char str[MAXLEN], command[10];
    int n;
    for(int i = 0; i<M; i++) dic[i][0] = '\0'; 
    scanf("%d",&n);
    for(int i = 0; i<n; i++){
        scanf("%s %s", command, str);
        if(command[0] == 'i'){
            insert(str);
        }
        else if(command[0] == 'f'){
            if(find(str)) printf("yes\n");
            else printf("no\n");
        }
    }
}


*/