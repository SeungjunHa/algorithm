#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <fstream>

using namespace std;

vector<string> split(string s, string divid) {
    vector<string> v;
    char *c = strtok((char*)s.c_str(), divid.c_str());
    while (c) {
        v.push_back(c);
        c = strtok(NULL, divid.c_str());
    }
    return v;
}
int wget;
void person_file(string target)
{
	fstream fh;
	string line;
	string name;
	vector<string>temp = split(target, "_");
	name.assign(temp[0], 5);
	fh.open(target);
	if(fh.is_open()) {
		vector<string> temp;
		string target;
		getline(fh, line);
		temp = split(line, "\"");	
		string command = "cd dump && wget -O ../pure/" + name + " " + temp[1];
		if(command.find("https") != string::npos) {
			cout << "command : " << command << endl;
			system(command.c_str());
			wget++;
		}
		fh.close();
	}
}
int main(int argc, char *argv[])
{
	system("rm -rf dump_list.txt");
	system("rm -rf pure_list.txt");
	system("rm -rf dump");
	system("rm -rf pure");
	system("ls ../student > dump_list.txt");
	system("mkdir dump");
	system("mkdir pure");
	fstream fh, person_fh;
	string list = "dump_list.txt";
	fh.open(list);
	int err;
	if(fh.is_open()) {
		string line;
		while(getline(fh, line)) {
			//cout << line << endl;
			string temp = "cat ../student/" + line;
			temp += " | grep href";
			temp += " > dump/" + line;
			err = system(temp.c_str());
			if(err)
				break;
			string nline = "dump/" + line;
			person_file(nline);
		}	
		system("echo -n \"Total Student Number : \"");
		system("ls -l dump/ | grep html | wc -l");
		fh.close();
	}
	system("ls pure > pure_list.txt");
	cout << "Parsing Checking : " << wget << endl;
	return 0;
}
