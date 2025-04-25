#include <iostream>
#include<deque>
#include<stdio.h>
using namespace std;
deque<int>value, mn;
int main()
{
    long long n,a,b,c,x,i,j,Res=0;
    scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&x);
    for(i = 1; i <= n; i ++)
    {
        x = ((1LL * a * x * x + 1LL * b * x + c) / 100) % 1000000LL;
        if (x % 5 < 2) // удалить из очереди
        {
            if (!value.empty())
            {
                if (value.front() == mn.front()) mn.pop_front();
                value.pop_front();
            }
        } else  {
            value.push_back(x);
            while(!mn.empty() && (x < mn.back())) mn.pop_back();
            mn.push_back(x);
        }
        if (!mn.empty()) Res += mn.front();
    }
    printf("%lld",Res);
}