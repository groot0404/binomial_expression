#include <iostream>
#include<iomanip>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename S>
ostream& operator<<(ostream& os,
                    const vector<S>& vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector) {
        os << element << " ";
    }
    return os;
}

long fact(long n){
   int i, fact = 1;
   for(i = n; i>1; i--)
      fact *= i;
   return fact;//factorial of given number
}

long nCr(long n, long r){
   long nume = 1, i;
   for(i = n; i>r; i--)
      nume *= i;
   return long(nume/fact(n-r));//generate result of nCr
}

vector<long> genPascalsTriangle(long n){
    vector<long> a;
   for(int i = 0; i<n; i++){
      for(int j = 0; j<(i+1); j++)
      {
        long t=nCr(i, j);
        if(i==n-1)
        {
           a.push_back(t);
        }
      }
      cout << endl;
   }
   return a;
}

void print(std::vector <long> const &a , std::vector <string> const &b) {
   //std::cout << "The vector elements are : ";

   for(int i=0; i < a.size(); i++)
   std::cout << a.at(i) <<b.at(i)<< ' ';
}

int main() {
    vector<char> s;
    s.push_back('a');
    s.push_back('b');
    long e;
    cout<<"Enter the exponent ";
    cin>>e;
    vector<string> f;
    for(int i=0;i<=e;i++)
    {
        f.push_back(s[0]+to_string(e-i)+s[1]+to_string(i)+" +");
    }
    vector<long> r = genPascalsTriangle(e+1);
    print(r,f);
    return 0;
}
