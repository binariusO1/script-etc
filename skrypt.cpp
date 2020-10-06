#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

void fun(vector<long long> & vsum, const vector<long long>& vnum)
{
	vector<bool> binary(vnum.size(), false);
	long long n = 2;
	for (long long i = 1; i < vnum.size(); ++i)
	{
		n *= 2;
	}
	string w;
	int sumOfsum = 0;
	for (int i = 1; i <= n; ++i)
	{
		long long sum = 0;
		// convert i to 8-bit binary number
		bitset<32> binary(i);
		w = binary.to_string();
		string ww(w.rbegin(), w.rend());
		for (int j = vnum.size()-1; j >= 0; --j)
		{
			sum += (ww[j] - 48) * vnum[j];
		}
		
		for (int k = 0; k < vsum.size(); ++k)
		{
			if (sum == vsum[k])
			{
				cout << "suma: " << vsum[k] << endl;
				for (int j = vnum.size() - 1; j >= 0; --j)
				{
					if ((ww[j] - 48) * vnum[j]) {
						cout << vnum[j] << endl;
					}
				}
				vsum[k] = 0;
				sumOfsum++;
				if (sumOfsum == vsum.size())
					return;
			}

		}
		
	}

}




int main()
{
	vector<long long> vsum;
	vector<long long> vnum;
	long long number;
	long long sum;
	int ts,tn;
	
	cout << "Podaj liczbe sum: ";
	cin >> ts;
	cout << "Podaj liczbe liczb wchodzacych w sklad sum: ";
	cin >> tn;
	cout << "Podaj sumy: \n";
	while (ts--)
	{
		cin >> sum;
		vsum.push_back(sum);
	}
	cout << "Podaj liczby wchodzace w sklad sum: \n";
	while (tn--)
	{
		cin >> number;
		vnum.push_back(number);
	}
	
	vsum = { 153,12 };
	vnum = { 150,1,2,7,5 };
	fun(vsum, vnum);
}