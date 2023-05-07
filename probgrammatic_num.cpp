#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   vector<string> findStrobogrammatic(int n) {
      vector<string> ret;
      if (n & 1) {
         ret.push_back("0");
         ret.push_back("1");
         ret.push_back("8");
      }
      else {
         ret.push_back("");
      }
      for (; n > 1; n -= 2) {
         vector<string> temp;
         for (int i = 0; i < ret.size(); i++) {
            string s = ret[i];
            if (n > 3) {
               temp.push_back("0" + s + "0");
            }
            temp.push_back("1" + s + "1");
            temp.push_back("8" + s + "8");
            temp.push_back("6" + s + "9");
            temp.push_back("9" + s + "6");
         }
         ret = temp;
      }
      return ret;
   }
   bool compare(string a, string b){
      return a.size() == b.size() ? a >= b : a.size() > b.size();
   }
   int strobogrammaticInRange(string low, string high) {
      int ret = 0;
      vector<string> v;
      for (int i = low.size(); i <= high.size(); i++) {
         v = findStrobogrammatic(i);
         for (int j = 0; j < v.size(); j++) {
            ret += compare(v[j], low) && compare(high, v[j]);
         }
      }
      return ret;
   }
};
main(){
   Solution ob;
   cout <<(ob.strobogrammaticInRange("50", "100"));
}