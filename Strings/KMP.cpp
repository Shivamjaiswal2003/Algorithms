#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

vector<int> lps_find(string s){


  vector<int> lps(s.length(), 0);
  int first =0;
  int second =1;

  while(second<s.length()){
       
       if(s[first]==s[second]){

        lps[second]=first+1;

        first++;
        second++;
       }else{
        if(first==0){
            second++;
        }else{
              first=lps[first-1];
        }
       }
  }

  return lps;

}
    int strStr(string haystack, string needle) {
        

        vector<int> lps=lps_find(needle);

        int n=haystack.size();
        int m=needle.size();
      
      int first = 0;
      int second=0;


        while(first<n && second<m){

            if(haystack[first]==needle[second]){
                first++;
                second++;
            }else{
                if(second==0){
                    first++;
                }else{
                    second=lps[second-1];
                }
            }
        }

        if(second==m){
            return first-second;
        }

        return -1;
    }
};