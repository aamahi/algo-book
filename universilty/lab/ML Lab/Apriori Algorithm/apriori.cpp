#include <bits/stdc++.h>
using namespace std;

int array[100001];
int Pcnt=0;

struct Candidate
{
    vector< set <int> > csets;
};

struct Frequent
{
    vector< set <int> > fsets;
    bool isNull;
};

Candidate C[10000];
Frequent L[10000];
int now;

vector < set <int> > Database;

int min_sup;


Frequent findFrequentItemset(Candidate cd)
{
    int i,j;
    Frequent fr;
    fr.isNull = true;

    for(i = 0; i< cd.csets.size(); i++)
    {
        set < int > cdItem = cd.csets[i];
        int support = 0;
        for(j = 0; j< Database.size(); j++)
        {
            set < int > dataItem = Database[j];

            vector < int > intersecSet;

            set_intersection(cdItem.begin(), cdItem.end(), dataItem.begin(), dataItem.end(), back_inserter(intersecSet));

            if(intersecSet.size() >= cdItem.size())
                support+= 1;

            intersecSet.clear();
            dataItem.clear();
        }
        if(support >= min_sup)
        {
            fr.fsets.push_back(cdItem);
            fr.isNull = false;


            ///printf("{ ");
            set<int> :: iterator it;
            for(it = cdItem.begin(); it != cdItem.end();it++)
            {
                    ///printf("%d ", *it);
            }
            ///printf("} -> %d\n", support);
            Pcnt++;
        }
        cdItem.clear();

    }

    return fr;
}

bool checkJoinAbility( set <int> a, set <int> b)
{
    set<int>::iterator it(a.begin());
    advance(it,b.size()-1);
    if(equal(a.begin(),it,b.begin()))
        return true;
    return false;
}
int cnt;
Candidate apriori_gen(Frequent fr)
{
    cnt=0;
    int i,j;
    Candidate cd;


    vector < set <int> > l1 = fr.fsets;
    vector < set <int> > l2 = fr.fsets;

    for(i = 0; i< l1.size(); i++)
    {
        for(j = i+1; j < l2.size(); j++)
        {

            set < int > sj;
            if(l1[i].size() == 1)
            {
                set<int>::iterator it;
                it = l1[i].begin();
                sj.insert(*it);
                it = l2[j].begin();
                sj.insert(*it);

                cd.csets.push_back(sj);
            }
            else
            {
                if(checkJoinAbility(l1[i], l2[j]))
                {
                    set<int>::iterator it;

                    for(set<int> :: iterator it = l1[i].begin(); it != l1[i].end(); ++it)
                    {
                        sj.insert(*it);
                    }

                    for(set<int> :: iterator it = l2[j].begin(); it != l2[j].end(); ++it)
                    {
                        sj.insert(*it);
                    }
                    int support=0;
                    ///cout << L[now-1].fsets.size() << endl;
                    for(int k = 0; k< L[now-1].fsets.size() ; k++)
                    {
                        set < int > dataItem = L[now-1].fsets[k];
                        ///cout << dataItem.size()<<sj.size() << endl;
                        vector < int > intersecSet;

                        set_intersection(  dataItem.begin(), dataItem.end(), sj.begin(), sj.end(),back_inserter(intersecSet));
                        ///cout << intersecSet.size() << endl;
                        if(intersecSet.size() >= dataItem.size())
                            support+= 1;

                        intersecSet.clear();
                        dataItem.clear();
                    }
                    ///cout << support << endl;
                    if( support >= now+1 )
                    cd.csets.push_back(sj);
                    else cnt++;
                }
            }
        }
    }
    cout << endl;

    return cd;

}

void apriori()
{
    L[0] = findFrequentItemset(C[0]);
    cout << "C0"  << " : " <<  C[0].csets.size() << endl;
    cout << "L0"  << " : " <<  L[0].fsets.size() << endl;
    int k;
    for(k = 1; L[k-1].isNull != true; k++)
    {
        now=k;
        C[k] = apriori_gen(L[k-1]);
        cout << "C" << k << " : " << C[k].csets.size()+cnt << endl;
        cout << "Cp" << k << " : " << C[k].csets.size() << endl;
        L[k] = findFrequentItemset(C[k]);
        cout << "L" << k << " : " << L[k].fsets.size() << endl;
    }

}

int main()
{
    FILE *fp;
    char buf[1000];

    scanf("%d",&min_sup);

    int tcnt=0;
    fp = fopen("input.txt", "r");

    while(fgets(buf, sizeof(buf), fp))
    {
        set < int > db;
        db.clear();
        char *ch;
        ch = strtok(buf," \n");
        while(ch != NULL)
        {
            int num = atoi(ch);
            db.insert(num);

            if(array[num] == 0)
            {
                set < int > a;
                a.clear();
                a.insert(num);
                C[0].csets.push_back(a);
                array[num] += 1;
            }
            else array[num] += 1;
            ch = strtok(NULL," \n");
        }
        sort(C[0].csets.begin(),C[0].csets.end());
        Database.push_back(db);
        tcnt++;

    }
    min_sup=min_sup*tcnt;
    if(min_sup%100)
    {
        min_sup/=100;
        min_sup++;
    }
    else min_sup/=100;
    cout << "Minimun Support count = "<<min_sup << endl;
    fclose(fp);

    apriori();

    cout << "Pattern count = " << Pcnt  << endl;

    return 0;
}
