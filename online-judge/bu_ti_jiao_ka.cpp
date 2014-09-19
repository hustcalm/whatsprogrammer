#include <iostream>
using namespace std;

int main()
{
    int T;
    int N, M;
    int maxLen = 0;
    cin>>T;
    while(T--){
        maxLen = 0;

        cin>>N>>M;

        int arr[N+2];
        arr[0] = 0;
        arr[N+1] = 101;
        for(int i = 1; i <= N; i++)
            cin>>arr[i];

        if(N == 0 || N <= M)
        {
            //return 100;
            maxLen = 100;
            goto out;
        }

        // The longest is less than 100
        for(int i = 1; i <= N; i++) {
            int tmp = 0;
            tmp += arr[i] - arr[i-1] - 1;
            if(M >= 1) {
                tmp += arr[i+1] - arr[i];
            }
            int k = i + 1;
            for(int j = 1; j < M && k <= N && arr[k] == arr[k-1] + 1; j++,k++) {
                tmp += arr[k+1] - arr[k-1] - 1;
            }

            if(tmp >= maxLen)
                maxLen = tmp;
        }
        out:
        cout<<maxLen<<endl;
    }
    return 0;
}
