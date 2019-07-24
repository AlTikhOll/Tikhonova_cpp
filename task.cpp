
#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;



int main(int argc, char* argv[])
{
	
	ifstream file("myfile.txt");
	//ifstream file(argv[1]);
	int mas[1000][2];

	int i,k,j,ex,max,min, ser;
	float middle;
	bool flag;

	if (!file.is_open()) {
		cerr << "Error: file" << argv[1] << "is not open\n";
		return 1;
	}
	else
	{
		i = 0; 
		k = 0;
		max = 0;
		min = 0;
		middle = 0.0;

		while (i<=1000) {
			if (!file.eof()) {
				file >> ex;
				flag = false;
				for (j = 0; j < i; j++) { 
					if (mas[j][0] == ex) {
						mas[j][1]++;
						flag = true;
					}
						
				}
				if (flag == false) {
					mas[i][0] = ex;
					mas[i][1] = 1;


					//cout << ex << endl;
					if (ex > max) {
						max = ex;
					}
					if (ex < min) {
						min = ex;
					}
					i++;
				}
			}
			else
			{
				k = i;
				int *med = new int[k];
				for (j = 0; j < k; j++) {
					middle += mas[j][0] * mas[j][1] / k;
					med[j] = mas[j][0];
				}
				sort(med, med + k);
				if (k % 2 == 0) { cout << "медианы нет" << endl; }
				else
				{
					ser = med[((k - 1) / 2) + 1];
				}
				cout << "no"<<endl;
				cout << ser << endl;
				cout << max << endl;
				cout << min << endl;
				cout << middle << endl;
				break;
			}
		}
		
	}
	
	
	file.close();
	
}
