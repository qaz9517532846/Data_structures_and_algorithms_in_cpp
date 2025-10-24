#include "LinkedStack.h"
#include <iostream>
#include <fstream>

vector<string> getHtmlTags(const string& filename) {
    vector<string> tags;

    ifstream file(filename);  // 打開檔案
    if (!file.is_open()) {
        cerr << "File not Open: " << filename << endl;
        return tags;
    }

    string line;
    while(getline(file, line)) {
        int pos = 0;
        int ts = line.find("<", pos);
        while(ts != string::npos) {
            int te = line.find(">", ts + 1);
            tags.push_back(line.substr(ts, te - ts + 1));
            pos = te + 1;
            ts = line.find("<", pos);
        }
    }
    return tags;
}

bool isHtmlMatched(const vector<string>& tags) {
    LinkedStack S;
    typedef vector<string>::const_iterator Iter;

    for(Iter p = tags.begin(); p != tags.end(); ++p) {
        if(p->at(1) != '/')
            S.push(*p);
        else {
            if(S.empty())   return false;
            string open = S.top().substr(1);
            string close = p->substr(2);
            if(open.compare(close) != 0) return false;
            else S.pop();
        }
    }

    if(S.empty())   return true;
    else            return false;
}

int main()
{
    if(isHtmlMatched(getHtmlTags("test.html")))
        cout << "The input file is a matched HTML document." << endl;
    else
        cout << "The input file is not a matched HTML document." << endl;

    return EXIT_SUCCESS;
}