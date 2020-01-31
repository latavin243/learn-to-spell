class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> res(num + 1, 0);
        if (num == 0)
            return res;
        res[1] = 1;
        for (int i = 2; i <= num; i++)
            res[i] = (i & 1) ? res[i - 1] + 1 : res[i / 2];
        return res;
    }
};

// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int>a;
//         int i,count=0,n;
//         for(i=0;i<=num;++i){
//             n=i;
//             count=0;
//             while(n>0){
//                 n&=(n-1);
//                 ++count;
//             }
//             a.push_back(count);
//         }
//         return a;
//     }
// };