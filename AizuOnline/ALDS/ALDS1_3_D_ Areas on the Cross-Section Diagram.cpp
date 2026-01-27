#include <iostream>
#include <stack>
#include <vector>
//#include <algorithm>

using namespace std;
stack<int> downSlope;
//这里可以直接用vector，用size()访问末尾元素，在计算阶段当作栈使用，在输出阶段当作常规数组使用
//但由于这里是为了演示栈的使用，为避免混用，故分成两个部分存放
stack< pair<int, int> > puddlesArea;


int main() {
	char c;
	int A = 0;
	//puddlesArea.push(make_pair(0,0));
	for (int i = 0; cin >> c; i++) {
		if (c == '\\') downSlope.push(i);
		else if (!downSlope.empty() && c == '/') {
			int right = i;
			int left = downSlope.top(); downSlope.pop();
			int singlePuddleArea = right - left;
			A += singlePuddleArea;
			//寻找并合并下方的积水面积
			while (!puddlesArea.empty() && puddlesArea.top().first > left) {
				singlePuddleArea += puddlesArea.top().second; puddlesArea.pop();
			}
			//再次压入
			puddlesArea.push(make_pair(left, singlePuddleArea));
		}
	}

	vector<int> areas;
	while (!puddlesArea.empty()) {
		areas.push_back(puddlesArea.top().second);
		//vector<int>::iterator i;
		puddlesArea.pop();
	}
	cout << A << endl;
	//如果第一个数据输入的不是数据结构中的元素，后面输出各项元素的时候可以不考虑是否输出空格
	cout << areas.size();
	//可以倒转后常规输出
	//reverse(areas.begin(), areas.end());
	//这里因为没有倒转所以可读性较差
	for (int i = areas.size(); i > 0 ; i--) {
		cout << ' ' << areas[i-1] ;
	}
	cout << endl;
}

/* 复健：

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;



int main(){
    stack<int> lowerSlopePos;
    vector<pair<int,int> > areaLeftSide;
    int totalArea = 0;
    string terrain;
    cin>>terrain;
    
    
    for(int i = 0; i<terrain.size(); i++){
        if(terrain[i]=='\\'){
            lowerSlopePos.push(i);
        }
        else if(terrain[i]=='/' && !lowerSlopePos.empty()){
            int leftSidePos = lowerSlopePos.top(); lowerSlopePos.pop();
            int newArea = i - leftSidePos;
            totalArea += newArea;
            while(!areaLeftSide.empty()&&(areaLeftSide.back().second>leftSidePos)){
                newArea += areaLeftSide.back().first; 
                areaLeftSide.pop_back();
            }
            areaLeftSide.push_back(make_pair(newArea,leftSidePos));
        }
    }

    cout<<totalArea<<endl;
    cout<<areaLeftSide.size();
    for(int i = 0; i<areaLeftSide.size(); i++){
        cout<<" " << areaLeftSide[i].first;
    }
    cout<<endl;
}

*/