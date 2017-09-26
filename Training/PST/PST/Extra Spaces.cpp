#include <bits/stdc++.h>
//freopen("myfile.txt", "w", stdout);
using namespace std;
int main()
{
	//freopen("myfile.txt", "w", stdout);
    int t,kk=1,n,sl;
    cin>>t;
    //char s[510];
    string s;
  //  freopen("myfile.txt", "w", stdout);
    while(t--)
    {
        cin>>n;
        getchar();
        if(kk!=1)
            cout<<endl;
        cout<<"Case "<<kk++<<":"<<endl;

        for(int i=0;i<n;i++)
        {
            getline(cin,s);
            sl=s.length();
            s+="#";
            for(int j=0;j<sl;j++)
                if(!(s[j]==' ' && s[j+1]==' '))
                    cout<<s[j];
            cout<<endl;
        }
    }
return 0;
}
