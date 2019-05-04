#include <limits.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <list>
#include <queue>
#include <set>

using namespace std;

    class ErasedNumber
    {
    public:
        
        int findErased( int N, int sum )
        {
            int number = sum / (N - 1);
            int ret = 1e9 + 10;
            for(int i = max(0, number - 100); i <= number + 100; ++i) {
                int tmp = 0;
                vector<int> v;
                for(int j = i; j < i + N; ++j) {
                    tmp += j;
                    v.push_back(j);
                }
                if(tmp >= sum) {
                    for(int j = 0; j < (int) v.size(); ++j) {
                        int current_sum = 0;
                        for(int k = 0; k < (int)v.size(); ++k) {
                            if(k == j) continue;
                            current_sum += v[k];
                        }
                        if(current_sum == sum) {
                            ret = min(ret, v[j]);
                        }
                    }
                }
            }
            return ret;
        }
    };
