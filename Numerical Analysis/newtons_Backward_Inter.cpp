#include<bits/stdc++.h>
#include <cstdio>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f0(i,n) for(int i=0;i<=n;i++)
#define first_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define in_buffer cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define zero (int)0
#define int long long
#define double long double
#define pb push_back
#define goto_hell return 0
#define newline cout  << "\n"
#define endl "\n"
using namespace __gnu_pbds;
using namespace std;

void newton_Forward_Interpolation()
{
    vector<double>x(100),y(100),p(100),diff(100);
    double X,f2=0,u,h;
    int n;
    newline;
    cout << "Enter the number of Observation: ";cin >> n;
    newline;
    cout << "Enter the values of x and f(x): \n";
    for(int i=1;i<=n;i++)
    {
        cin >> x[i] >> y[i];
    }
    cout<<"\nEnter the value of x at which you want to interpolate: ";
    cin >> X;
    h=x[2]-x[1];
    u=(X-x[n])/h;
    int nn=n;
    double ans= y[n];
    cout << fixed << setprecision(4);
    cout << "Forward Difference table\n";
    int cnt = 1;
    while(nn>1)
    {
        cout << "Del(y)";if(cnt>1)cout << "^"<<cnt;cout << endl;
        cout << "-------\n";
        vector<double>tem(nn);
        for(int i=1;i<nn;i++)
        {
            tem[i]=y[i+1]-y[i];
            cout << tem[i] << endl;
            y[i]=tem[i];
        }
        diff[cnt]=tem[nn-1];
        nn--;
        cnt++;
        newline;
    }
    double df = u;
    int fact = 1;
    for(int i=1;i<n;i++)
    {
        ans+=df*diff[i];
        u+=1.0;
        df*=u;
        fact*=(i+1);
        df/=fact;
    }
    cout << "f("<< X << ") = " << ans << endl;
}

int32_t main()
{
    //first_IO;
    int test=1;
    //cin >> test;
    //cout << "Test = " << test << endl;
    //in_buffer;
    for(int t=1;t<=test;t++)newton_Forward_Interpolation();
    goto_hell;
}