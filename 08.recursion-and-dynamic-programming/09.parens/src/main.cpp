#include <bits/stdc++.h>

using namespace std;

void genParens(vector<string>& results, int n);
void genParens(vector<string>& results, 
               string&& parens,
               int openingParensCnt, 
               int closingParensCnt);
void genParens(vector<string>& results, 
               string& parens,
               int openingParensCnt, 
               int closingParensCnt);

int main()
{
    int n;
    cin >> n;

    vector<string> results;
    genParens(results, n);

    for (string& str : results)
    {
        cout << str << endl;
    }
}

void genParens(vector<string>& results, int n)
{
    genParens(results, "", n, n);
}

void genParens(vector<string>& results, 
               string&& parens,
               int openingParensCnt, 
               int closingParensCnt)
{
    genParens(results, parens, openingParensCnt, closingParensCnt);
}

void genParens(vector<string>& results, 
               string& parens,
               int openingParensCnt, 
               int closingParensCnt)
{
    assert(openingParensCnt >= 0 && closingParensCnt >= 0);
    if (openingParensCnt == 0 && closingParensCnt == 0)
    {
        results.push_back(parens);
    }
    
    if (openingParensCnt > 0)
    {
        parens += '(';
        genParens(results, parens, openingParensCnt - 1, closingParensCnt);
        parens.erase(parens.size() - 1, 1);
    }

    if (closingParensCnt > 0 && closingParensCnt > openingParensCnt)
    {
        parens += ')';
        genParens(results, parens, openingParensCnt, closingParensCnt - 1);
        parens.erase(parens.size() - 1, 1);
    }
}

