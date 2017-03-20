#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <cstdlib>

using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	string buff_1;
	string buff_2;
	string fname_1;
	string fname_2;
	list<string> list_1;
	list<string> list_2;
	list<string> list_3;
	list<string> list_4;
	list<string>::iterator iter;
	cin >> fname_1;
	cin >> fname_2;
	int n = 1 , k = 1 ;
	ifstream file_1(fname_1);
	ifstream file_2(fname_2);
	cout << endl;
	cout << fname_1 << endl;
	while (!file_1.eof()){
		file_1 >> buff_1;
		cout << n << ")" << buff_1 << endl;
		n++;
	}cout << endl;
	/*copy(list_.begin(), list_.end(), ostream_iterator<string>(cout, " "));*/
	cout << fname_2 << endl;
	while (!file_2.eof()){
		file_2 >> buff_2;
		cout << k << ")" << buff_2 << endl;
		k++;
	}
	cout << endl;
	/*copy(list_0.begin(), list_0.end(), ostream_iterator<string>(cout, " "));*/
	file_1.clear();
	file_1.seekg(0, ios_base::beg);
	file_2.clear();
	file_2.seekg(0, ios_base::beg);
		while (!file_1.eof()){
			file_1 >> buff_1;
			list_1.push_back(buff_1);
			while (getline(file_2, buff_2)){
				//cout << endl;
				//cout << "buff_2=" << buff_2 << endl;
				list_2.push_back(buff_2);
				if (buff_1 == buff_2){
					list_1.pop_back();
					list_2.pop_back();
				}
				//cout << "buff_1= " << buff_1 << endl;
			}
			file_2.clear();
			file_2.seekg(0, ios_base::beg);
		}
		file_1.clear();
		file_1.seekg(0, ios_base::beg);
		file_2.clear();
		file_2.seekg(0, ios_base::beg);
		while (!file_2.eof()){
			file_2 >> buff_2;
			list_4.push_back(buff_2);
			while (getline(file_1, buff_1)){
				//cout << endl;
				//cout << "buff_1=" << buff_1 << endl;
				list_3.push_back(buff_1);
				if (buff_1 == buff_2){
					list_3.pop_back();
					list_4.pop_back();
				}
				//cout << "buff_2= " << buff_2 << endl;
			}
			file_1.clear();
			file_1.seekg(0, ios_base::beg);
		}
	list_1.sort();
	list_1.unique();
	/*cout << "список 1)";
	copy(list_1.begin(), list_1.end(), ostream_iterator<string>(cout, " "));*/
	list_4.sort();
	list_4.unique();
	/*cout << "список 2)";
	copy(list_4.begin(), list_4.end(), ostream_iterator<string>(cout, " "));*/
	list_4.merge(list_1);
	cout << endl << "file_3"<< endl;
	copy(list_4.begin(), list_4.end(), ostream_iterator<string>(cout, " "));
	system("pause");
}