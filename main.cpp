#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
int filenumber;
string filename;
string temp;

cout<<"Which input file would you like to read?"<<endl;
cout<<"Enter 1, 2, 3"<<endl;
cout<<"1 short.txt"<<endl;
cout<<"2 anna_karenina.txt"<<endl;
cout<<"3 don_quixote.txt"<<endl;
cin>>filenumber;
ifstream inputfile;
if(filenumber==1){
/*
    filename="short.txt";
    */
    inputfile.open("short.txt");
}
else if (filenumber ==2){
    inputfile.open("anna_karenina.txt");
}
else{
    inputfile.open("don_quixote.txt");
}

/*
ifstream inputfile;
inputfile (filename);
*/

if(inputfile.fail()){
    cout<<"You messed up"<<endl;
        exit(1);
}

//make map that has integer and string
map<string, int> words;

while(inputfile>>temp){
    words[temp]++;
}
vector<pair<int, string>> v;
for (auto element: words)
    v.push_back(pair<int, string>(element.second, element.first));

sort(v.rbegin(), v.rend());

for (unsigned int i=0; i<v.size() && i < 20; i++){
    pair <int, string> p = v.at(i);
    cout<<p.first<<" "<<p.second<<endl;
}
return 0;
}


