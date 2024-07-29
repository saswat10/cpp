#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
  int sum = 0, sign = 1;
  bool updated = false;
  for (int i = 0; i < s.length(); i++)
  {
    if (s.at(i) == '-' && !updated)
    {
      sign = -1;
      updated = true;
    }
    else if (s.at(i) == 32)
    {
      continue;
    }
    else if (s.at(i) >= 48 && s.at(i) <= 57)
    {
      sum = sum * 10 + int(s.at(i) - 48);
      updated = true;
    }
    else
      break;
  }
  return sum * sign;
}

int main()
{
  string x;
  cin >> x;
  cout << myAtoi(x);
  return 0;
}