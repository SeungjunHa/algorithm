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

int student_cnt;

void check(string name)
{
	bool photo = false, link = false, list = false, table = false;
	int link_cnt = 0;
	fstream fh;
	fh.open(name);
	string pname;
	pname.assign(name, 5);
	if(fh.is_open()) {
		cout << "Student [" << pname << "]\n";
		vector<string> c_info;
		string line;
		while(getline(fh, line)) {
			if(pname[14] == '6') {
				cout << "Line : " << line << endl;
			}
			if(string::npos != line.find("photo.png")) 
				photo = true;
			if(string::npos != line.find("<a")) 
				link_cnt++;
			if(string::npos != line.find("<table")) 
				table = true;
			if(string::npos != line.find("<ul")) 
				list = true;
			if(string::npos != line.find("<ol")) 
				list = true;
			if(line.find("class=") != string::npos) {
				int start = line.find("class="), last;
				int t = 0, i;
				for(i=start; i<line.size(); i++) {
					if(line[i] == '\"') {
						if(!t)
							start = i+1;
						t++;
						if(t == 2) {
							last = i;
							break;
						}
					} 
				}
				string temp;
				temp.assign(line, start, last-start);
				c_info.push_back(temp);
			}
		}
		if(link_cnt >= 3)
			link = true;
		cout << pname << "'s result : [" << photo << " " << link << " ";
		cout << table << " " << list << "]\n";
		cout << pname << " clase info : [ ";
		vector<string> temp;
		for(int i=0;i<c_info.size();i++) {
			vector<string> v = split(c_info[i], "=, ,\"");
			for(string i : v) 
				if(i.compare("class") != 0 && i[0] != '<' && i[0] != '>') 
					temp.push_back(i);
		}
		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()), temp.end());
		for(int i=0;i<temp.size();i++) 
			cout << temp[i] << " ";
		cout << "]\n";
		student_cnt++;
		fh.close();
	}
}

int main(int argc, char *argv[])
{
	fstream fh;
	string name = "pure_list.txt";
	fh.open(name);
	if(fh.is_open()) {
		bool photo = false;
		bool link = false;
		int link_cnt = 0;
		bool table = false;
		bool list = false;
		string line, nline;
		vector<string> c_info;
		cout << name << " is open\n";	
		while(getline(fh, line)) {
			nline = "pure/" + line;
			check(nline);
		}		
		fh.close();
	}

	cout << "Checking : " << student_cnt << "\n";
	return 0;
}
