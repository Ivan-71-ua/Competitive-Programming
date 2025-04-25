#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::string text, word;
    std::cin >> text >> word;
    std::string temp = word;
    temp += "#" + text + text;
    std::vector <int> pip(temp.size(), 0);
    for (int i = 1; i < temp.size(); i++) {
        int j = pip[i - 1];
        while (j > 0 && temp[i] != temp[j]) {
            j = pip[j - 1];
        }
        if(temp[i] == temp[j]) {
            j++;
            pip[i] = j;
        }
    }
    for (int i = 0; i < pip.size(); i++)

    {
        if(pip[i] != word.size())
            pip[i] = 0;
    }

    int maxm = 0, tpq =  word.size() + 1,  tpm =0;
    for (int i = word.size() + 1; i < temp.size(); i++)
    {
        if(i < (text.size() - word.size() + 1) + word.size() + 1 ) {
            if(pip[i] == word.size())  {maxm++; tpm++;}

        }
        else  {

            if(pip[tpq] == word.size())
                tpm--;
            if(pip[i] == word.size())
                tpm++;
            tpq++;
            maxm = std::max(maxm, tpm);
        }

    }
    std::cout << maxm;
}