#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    //priority_queue 检查父值 插入值的关系，即 parent comp(默认less<T>) node, true时节点上浮，因此默认为最大堆
    //最小堆：声明
    priority_queue<pair<int,string>> PQ;
    

    PQ.push(make_pair(1,"item 1"));
    PQ.push(make_pair(99,"important task 1"));
    PQ.push(make_pair(9,"item 9"));
    PQ.push(make_pair(99,"important task 2"));
    PQ.push(make_pair(999,"really important task "));
    PQ.push(make_pair(15,"item 15"));
    PQ.push(make_pair(16,"item 16"));
    //compare first, then second
    string s1 = "important task 1   ";
    string s2 = "important task 2";
    cout<<(s1<s2)<<endl;
    

    cout<<PQ.top().second<<endl; PQ.pop();
    cout<<PQ.top().second<<endl; PQ.pop();
    cout<<PQ.top().second<<endl; PQ.pop();
    cout<<PQ.top().second<<endl; PQ.pop();
}
