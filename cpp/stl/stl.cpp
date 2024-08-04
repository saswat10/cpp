#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
  vector<int> v = {10, 20, 30, 40, 50};
  v.push_back(11);
  v.push_back(21);

  for (int x : v)
    cout << x << " ";

  vector<int>::iterator itr;
  cout << "\nUsing Iterator function" << endl;
  for (itr = v.begin(); itr != v.end(); itr++)
    cout << *itr << " ";

  map<int, string> m;
  m.insert(pair<int, string>(1, "Ravi"));
  m.insert(pair<int, string>(2, "Ram"));
  m.insert(pair<int, string>(3, "Rahul"));

  map<int, string>::iterator ptr;
  for (ptr = m.begin(); ptr != m.end(); ptr++)
    cout << ptr->first << " " << ptr->second << endl;

  return 0;
}