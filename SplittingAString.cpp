#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

int mainSplittingAString() {
    using namespace std;
    string sentence = "DeployNet 3 2 1";
    istringstream iss(sentence);
    
    copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             ostream_iterator<string>(cout, "\n"));
    /*do
    {
        string sub;
        iss >> sub;
        cout << "Substring: " << sub << endl;
    } while (iss);*/
    cout << sentence.compare("DeployNet") << endl;

    return 0;

}
