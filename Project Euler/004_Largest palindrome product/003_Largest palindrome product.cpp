/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

main(){
  
  vector<double> v;

  double d;
  while(cin>>d) v.push_back(d);  // read elements
  if (!cin.eof()){               // check if input failed
    cerr << "format error\n";
    return 1;
  }

  cout << "read " << v.size() << " elements\n";

  reverse(v.begin(), v.end());
  cout << "elements in reverse order:\n";
  for (int i = 0; i < v.size(); ++i) cout << v[i] << '\n';
  

  return 0;

}

  
