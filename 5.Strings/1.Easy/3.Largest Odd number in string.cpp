
class Solution {
public:
    std::string largestOddNumber(std::string num) {
        string res = "";

        int i = 0;
        int j = num.size() - 1;

        while (j >= 0 && num[j] % 2 != 1) {
            j--;
        }

        while (i <= j) {
            res += num[i];
            i++;
        }

        return res;
    }
};
