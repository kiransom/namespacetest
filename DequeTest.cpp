#include <iostream>
#include <deque>
using namespace std;

int mainDequeTest() {
deque<char> aDeck;
for(size_t i = 0; i <5; i++)
aDeck.push_back(i + 'A');
cout << "Original sequence: ";
for(size_t i = 0; i <aDeck.size(); i++)
cout << aDeck[i] << " ";
cout << endl;
deque<char>::iterator It1 = aDeck.begin() + 2; // Note random access
deque<char>::iterator It2 = aDeck.begin() + 3; // iterators here
cout << "*It1: " << *It1 << ", ";
cout << "*It2: " << *It2 << endl;
cout << endl;
aDeck.insert(It1, 'X');
cout << "Sequence after insert: ";
for(size_t i = 0; i <aDeck.size(); i++)
cout << aDeck[i] << " ";
cout << endl;
// These iterator dereferences may cause the program to crash since STL
// does not implement “robust iterators”..
//cout << "*It1: " << *It1 << ", ";
//cout << "*It2: " << *It2 << endl;
return 0;
}