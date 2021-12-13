#include <bits/stdc++.h>
using namespace std;

int arr[100001][100];
int MIN_SUP =2877 ;
int Tcnt=0;
int cnt = 0 ;
map< vector <int>, int > C;
map< vector <int>, int > L;

void C1()
{
	ifstream fin;
	fin.open("input.txt");
	if(!fin)
		{
			cout<<"Input file opening error\n";
			exit(0);
		}

	int n;
	vector<int> v;
	while(fin>>n)
	{
		v.clear();
		if (n==-1)
		{
			continue;
		}
		v.push_back(n);
		if(C.count(v)>0)
			C[v]++;
		else
			C[v]=1;
	}
	fin.close();
}

void print(map< vector <int>, int > T)
{
	vector<int> v;
	for(map< vector <int>, int >::iterator (ii)=(T).begin();(ii)!=(T).end();(ii)++)
	{
		v.clear();
		if(ii->second<MIN_SUP)continue;
		v=ii->first;
		for (int i = 0; i < v.size(); ++i)
		{
			cout<<v[i]<<" ";
		}

		cout<<"  ==>>  "<<ii->second;
		cnt ++;
		cout<<"\n";

	}
}

void L1()
{
    for(map< vector <int>, int >::iterator (ii)=(C).begin();(ii)!=(C).end();(ii)++)
	{
		if (ii->second >= MIN_SUP)
		{
			L[ii->first]=ii->second;
		}
	}

}
bool check(vector<int> a,vector<int> b)
{
	bool compatible=true;
	for (int i = 0; i < a.size()-1; ++i)
	{
		if (a[i]!=b[i])
		{
			compatible=false;
			break;
		}
	}

	return compatible;
}

void newC()
{
	//clean(C);
	C.clear();
	for(map< vector <int>, int >::iterator (ii)=(L).begin();(ii)!=(L).end();(ii)++)
	{
        for(map< vector <int>, int >::iterator (jj)=(ii);(jj)!=(L).end();(jj)++)
		{
			if(jj==ii)
				continue;
			vector<int> a,b;
			a.clear();
			b.clear();
			a=ii->first;
			b=jj->first;
			if(check(a,b))
			{
				a.push_back(b.back());
				sort(a.begin(), a.end());
				C[a]=0;
			}
		}

	}


}

void prune()
{
	vector<int> a,b;
    for(map< vector <int>, int >::iterator (ii)=(C).begin();(ii)!=(C).end();(ii)++)
	{
		a.clear();
		b.clear();

		a=ii->first;
		for(int i = 0;i<a.size();i++)
		{
			b.clear();
			for (int j = 0; j < a.size(); ++j)
			{
				if(j==i)
					continue;
				b.push_back(a[j]);
			}
			if(L.find(b)==L.end())
				{
					ii->second=-1;
					break;
				}

		}


	}

	map< vector <int>, int > temp;
	temp.clear();
	for(map< vector <int>, int >::iterator (ii)=(C).begin();(ii)!=(C).end();(ii)++)
	{
		if (ii->second != -1)
		{
			temp[ii->first]=ii->second;
		}
	}

	C.clear();
	C=temp;
	temp.clear();
}

void set_count(vector<int> a)
{
    for(map< vector <int>, int >::iterator (ii)=(C).begin();(ii)!=(C).end();(ii)++)
	{
		vector<int> b;
		b.clear();
		b=ii->first;
		int true_count=0;
		if (b.size()<=a.size())
		{
			for (int i = 0; i < b.size(); ++i)
			{
				for (int j = 0; j < a.size(); ++j)
				{
					if(b[i]==a[j])
					{
						true_count++;
						break;
					}
				}
			}
		}

		if (true_count==b.size())
		{
			ii->second++;
		}
	}
}


void scan_D()
{
	ifstream fin;
	fin.open("input.txt");
	if(!fin)
		{
			cout<<"Input file opening error\n";
			exit(0);
		}

	int n;
	vector<int> a;
	while(fin>>n)
	{
		if(n==-1 && a.size()>0)
		{
			set_count(a);
			a.clear();
		}else if(n!=-1)
		{
			a.push_back(n);
		}

	}
	fin.close();
}

void newL()
{
	L.clear();
    for(map< vector <int>, int >::iterator (ii)=(C).begin();(ii)!=(C).end();(ii)++)
	{
		if(ii->second >= MIN_SUP)
		{
			L[ii->first]=ii->second;
		}
	}
}
int main()
{
	C.clear();
	L.clear();
    FILE *fp;
    fp=fopen("input.txt","r");
    int i=0,j=0;
    map <int,int> m;
    while( fscanf(fp,"%d",&arr[i][j])!=EOF )
    {
        ///cout << arr[i][j] << " " ;
        if(arr[i][j]==-1)
        {
            ///cout << endl;
            i++;
            ///j=-1;
        }
        else
        {
            m[arr[i][j]]++;
        }
        j++;
    }
    Tcnt=i;
    double pt;
    cin >> pt;
    MIN_SUP=Tcnt*pt;
    if(!MIN_SUP%100)
    {
        MIN_SUP/=100;
    }
    else
    {
        MIN_SUP/=100;
        MIN_SUP++;
    }
    cout << Tcnt << endl;
    cout << MIN_SUP << endl;
    ///while(1);
	bool mv=true;
	int index=2;
	while(true)
	{
		if (mv)
		{
			C1();
			L1();
			print(L);
			mv=0;
		}
		else
		{
			newC();
			if(C.size()==0)
				break;
			prune();
			if (C.size()==0)
			{
				break;
			}
			scan_D();
			newL();
			if (L.size()==0)
			{
				break;
			}
			print(L);
			index++;
		}
	}
	cout << "Frequency = " << cnt << endl;
	return 0;
}
