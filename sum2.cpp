#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

  vector <int> parseToArr(int num) {
      vector <int> nums; 
      while (num) {
          nums.push_back(num % 10);
          num /= 10;
      }
      return nums;
  }

  int parseToInt(vector <int> nums) {
    int num = 0;
    for (int i = 0; i < nums.size(); ++i) {
        num = num * 10 + nums[i]; 
    }
    return num;
  }
  
  bool check(vector <int> kArr, vector <int> bArr) {
      int ch = 0;
      for (int i = 0; i < kArr.size(); i++) {
          for (int j = 0; j < bArr.size(); j++) {
              if (kArr[i] == bArr[j]) {
                  ch += 1;
              }
          }
      }
      if (ch == kArr.size()) {
          return true;
      } else {
          return false;
      }
  }
  
  int outPut(vector <int> num) {
  	if (num[0] == 0) {
  		for (int i = 1; i < num.size(); i++) {
  			return num[i];
		}
	} else {
	   	for (int i = 0; i < num.size(); i++) {
  			return num[i];
		}
	}
  }
   
  int main() {
      int a, b, c;
      cin >> a >> b >> c;
      vector <int> aArr = parseToArr(a);
      vector <int> bArr = parseToArr(b);
      vector <int> kArr;
      vector <int> xxx;
      do {
          int k = c - parseToInt(aArr);
          kArr = parseToArr(k);
		  if (check(kArr, bArr)) {
		  	xxx.push_back(parseToInt(aArr));
		  }
      } while(next_permutation(aArr.begin(), aArr.end()));
      
      if (check(kArr, bArr)) {
      	cout << "YES";
      	cout << endl;
      	int x = 1000000000;
      	for (int i = 0; i < xxx.size(); i++) {
		  	if (xxx[i] < x) {
			  x = xxx[i];	
			}
		}
		cout << outPut(parseToArr(x)) << " ";
		cout << outPut(kArr);
	  } else {
	  	cout << "NO";
	  }
      return 0;
  }