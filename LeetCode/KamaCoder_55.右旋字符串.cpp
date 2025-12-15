/**
 * KamaCoder_55.右旋字符串
 * 
 * 题目描述
 *  字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。给定一个字符串 s 和一个正整数 k，
 *  请编写一个函数，将字符串中的后面 k 个字符移到字符串的前面，实现字符串的右旋转操作。 
 *
 *  例如，对于输入字符串 "abcdefg" 和整数 2，函数应该将其转换为 "fgabcde"。 
 * 
 *  输出共一行，为进行了右旋转操作后的字符串
 * 
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int k;
    string s;
    cin>>k>>s;
    int n = s.size();
    k = k%n;
    // s = s+s;
    // cout<<s.substr(n - k, n);
    

    reverse(s.begin(), s.end());
    
    reverse(s.begin(), s.begin() + k);
    reverse(s.begin() + k, s.end());
    cout<<s;
}