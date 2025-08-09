#include "Vector.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cout << "============Finally All The Other Functions Of Both Containers============" << endl;
    cout << "===Built-in vector===" << endl;
    vector<string>arr{ "Ali","Ahmad","Aslam","Akram","Kamran" };
    for (string s : arr)
        cout << s << " ";
    cout << endl << "After Erasing An Element: " << endl;
    arr.erase(arr.begin() + 1);
    for (string s : arr)
        cout << s << " ";
    cout << endl << "After Erasing A Range of Elements: " << endl;
    arr.erase(arr.begin() + 1, arr.end() - 1);
    for (string s : arr)
        cout << s << " ";
    cout << endl << "After inserting at 1th-index: " << endl;
    arr.insert(arr.begin() + 1, "Ahmad");
    for (string s : arr)
        cout << s << " ";
    arr.push_back("Imran");
    cout << endl << "After push_back: " << endl;
    for (string s : arr)
        cout << s << " ";
    arr.pop_back();
    cout << endl << "After pop back: " << endl;
    for (string s : arr)
        cout << s << " ";
    arr.clear();
    cout << endl << "After Clearing every Entry: " << endl;
    for (string s : arr)
        cout << s << " ";
    cout << "===Custom Built vector===" << endl;
    Vector<string>vec{ "Ali","Ahmad","Aslam","Akram","Kamran" };
    for (string s : vec)
        cout << s << " ";
    cout << endl << "After Erasing An Element: " << endl;
    vec.erase(vec.begin() + 1);
    for (string s : vec)
        cout << s << " ";
    cout << endl << "After Erasing A Range of Elements: " << endl;
    vec.erase(vec.begin() + 1, vec.end() - 1);
    for (string s : vec)
        cout << s << " ";
    cout << endl << "After inserting at 1th-index: " << endl;
    vec.insert(vec.begin() + 1, "Ahmad");
    for (string s : vec)
        cout << s << " ";
    vec.push_back("Imran");
    cout << endl << "After push_back: " << endl;
    for (string s : vec)
        cout << s << " ";
    cout << endl << "After pop back: " << endl;
    vec.pop_back();
    for (string s : vec)
        cout << s << " ";
    vec.clear();
    cout << endl << "After Clearing every Entry: " << endl;
    for (string s : vec)
        cout << s << " ";
}














/*
cout << "===Built-in vector==="<<endl;
    vector<int>arr{ 1,2 };
    cout << "Size: "<<arr.size() << " " << "Capacity: "<<arr.capacity() << endl;
    arr.push_back(3);
    cout << "Size: " << arr.size() << " " << "Capacity: " << arr.capacity() << endl;
    arr.push_back(3);
    cout << "Size: " << arr.size() << " " << "Capacity: " << arr.capacity() << endl;
    cout <<  endl;
    cout << "===Custom Built vector===" << endl;
    Vector<int>vec{ 1,2 };
    cout << "Size: "<<vec.size() << " " << "Capacity: "<<vec.capacity() << endl;
    vec.push_back(3);
    cout << "Size: " << vec.size() << " " << "Capacity: " << vec.capacity() << endl;
    vec.push_back(3);
    cout << "Size: " << vec.size() << " " << "Capacity: " << vec.capacity() << endl;
    cout<<"============Analyzing Iterators for Both Containers(Both Forward and Reverse)============"<<endl;
    cout << "===Built-in vector==="<<endl;
    vector<char>arr{'a','b','c','d','e','f','g','h'};
    cout<<"Forward Iterator: ";
    for(vector<char>::iterator it1=arr.begin();it1!=arr.end();it1++)
        cout<<*it1<<" ";
    cout <<  endl;
    cout<<"Reverse Iterator: ";
    for(vector<char>::reverse_iterator it2=arr.rbegin(); it2!=arr.rend();it2++)
        cout<<*it2<<" ";
    cout <<  endl;
    cout << "===Custom Built vector===" << endl;
    vector<char>vec{'a','b','c','d','e','f','g','h'};
    cout<<"Forward Iterator: ";
    for(vector<char>::iterator it3=vec.begin();it3!=vec.end();it3++)
        cout<<*it3<<" ";
    cout <<  endl;
    cout<<"Reverse Iterator: ";
    for(vector<char>::reverse_iterator it4=vec.rbegin(); it4!=vec.rend();it4++)
        cout<<*it4<<" ";
    cout <<  endl;
    cout << "============Finally All The Other Functions Of Both Containers============" << endl;
    cout << "===Built-in vector===" << endl;
    vector<string>arr{ "Ali","Ahmad","Aslam","Akram","Kamran" };
    for (string s : arr)
        cout << s << " ";
    cout << endl << "After Erasing An Element: " << endl;
    arr.erase(arr.begin() + 1);
    for (string s : arr)
        cout << s << " ";
    cout << endl << "After Erasing A Range of Elements: " << endl;
    arr.erase(arr.begin() + 1, arr.end() - 1);
    for (string s : arr)
        cout << s << " ";
    cout << endl << "After inserting at 1th-index: " << endl;
    arr.insert(arr.begin() + 1, "Ahmad");
    for (string s : arr)
        cout << s << " ";
    arr.push_back("Imran");
    cout << endl << "After push_back: " << endl;
    for (string s : arr)
        cout << s << " ";
    arr.pop_back();
    cout << endl << "After pop back: " << endl;
    for (string s : arr)
        cout << s << " ";
    arr.clear();
    cout << endl << "After Clearing every Entry: " << endl;
    for (string s : arr)
        cout << s << " ";
    cout << "===Custom Built vector===" << endl;
    Vector<string>vec{ "Ali","Ahmad","Aslam","Akram","Kamran" };
    for (string s : vec)
        cout << s << " ";
    cout << endl << "After Erasing An Element: " << endl;
    vec.erase(vec.begin() + 1);
    for (string s : vec)
        cout << s << " ";
    cout << endl << "After Erasing A Range of Elements: " << endl;
    vec.erase(vec.begin() + 1, vec.end() - 1);
    for (string s : vec)
        cout << s << " ";
    cout << endl << "After inserting at 1th-index: " << endl;
    vec.insert(vec.begin() + 1, "Ahmad");
    for (string s : vec)
        cout << s << " ";
    vec.push_back("Imran");
    cout << endl << "After push_back: " << endl;
    for (string s : vec)
        cout << s << " ";
    cout << endl << "After pop back: " << endl;
    vec.pop_back();
    for (string s : vec)
        cout << s << " ";
    vec.clear();
    cout << endl << "After Clearing every Entry: " << endl;
    for (string s : vec)
        cout << s << " ";
*/