#include<iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    string s;
    cin>>s;
    
    int c=0, ans = 0;
    for(int i=0; i<(int)s.size(); i++)
    {
        if(s[i]=='('){
            c++;
        }
        else if(s[i]==')')
        {
            c--;
        }
        else if(c==(x+1) && s[i-1]=='(')
        {
            string temp;
            while(s[i]!='(' && s[i]!=')')
            {
                temp.push_back(s[i]);
                i++;
            }
            i--;
            int num=0;
            for(int j=0; j<(int)temp.size(); j++)
            {
                num = num*10+(temp[j]-'0');
            }
            ans = ans + num;
        }
    }
    cout<<ans<<endl;
}