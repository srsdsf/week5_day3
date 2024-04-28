#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        vector<pair<char,int>> order;  //char abong oi character ar indx ta rakhbo
        char mn=min(s[0],s[n-1]); //first character abong last character ar moddhe minimum jeta
        char mx=max(s[0],s[n-1]);  //same just min ar poriborte max

        for(int i=0; i<n ; i++)
        {
            if(s[i]>=mn && s[i]<=mx)
            {
                order.push_back({s[i],i});  //akta akta kore character abong ter indx push kore dischi
            }
        }
        sort(order.begin(),order.end(),[&](pair<char,int>a,pair<char,int>b) //indx onujayi sort korlam
        {
            return a.second<b.second;  //second val ta choto hole sort hoba //hosche indx
        });
        if(order.size() > 2)  //aber ami vitorer ongshogula sort korbo character wise  //order ar size jodi 2 ar theke boro hoy ter mane vitore kichu val aceh
        {
            sort(order.begin()+1,order.begin()+order.size()-1,[&](pair<char,int>a,pair<char,int>b)
            {
                if(s[0]>s[n-1]) //first char ta boro hola boro theke choto chrome sajaite hoba
                {
                    return a.first>b.first;// boro char ta jate samne thake jodi first indx boro hoy
                }
                return a.first<b.first;
            });
        }
        vector<int> seq;
        ll moves=0;
        seq.push_back(1); //1 indx ta sequence ar moddhe push kore dibo
        for(int i=1; i<order.size(); i++)
        {
            moves+=abs(order[i-1].first-order[i].first);  //total koita move lagse
            seq.push_back(order[i].second+1);  //bortoman order ar indx ta dhukaiya dibo
        }
        cout<<moves<<" "<<seq.size()<<endl;
        for(auto i: seq)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}