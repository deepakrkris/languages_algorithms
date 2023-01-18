#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int editDistance(std::string& str1, std::string& str2) {
    int dp[str1.size() + 1][str2.size() + 1];
   
    for (int i = 0; i <= str1.size(); i++) {
        for (int j = 0; j <= str2.size(); j++) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else {
                dp[i][j] = std::min(dp[i - 1][j - 1],   std::min( dp[i - 1][j], dp[i][j - 1] )  );
                if (str1[i - 1] != str2[j - 1]) {
                    dp[i][j] += 1;
                }
            }
        }
    }

    return dp[str1.size()][str2.size()];
}

int main()
{
    cout << endl << endl << " START " <<  " Edit distance " << endl;
    cout << "------------------------------------------------------- " << endl;

    std::string str1 = "march";
    std::string str2 = "cart";

    std::cout << str1 << " , " << str2 << "   Edit distance : " << editDistance(str1, str2) << endl;

    str1 = "abadacada";
    str2 = "abcad";

    std::cout << str1 << " , " << str2 << "   Edit distance : " << editDistance(str1, str2) << endl;

    cout << "------------------------------------------------------- " << endl << endl ; 
    cout << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
