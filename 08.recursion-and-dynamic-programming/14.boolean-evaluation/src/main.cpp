#include <bits/stdc++.h>

using namespace std;

class BoolResults
{
public:
    int falseCnt;
    int trueCnt;
    
    BoolResults() : BoolResults(0, 0) {}
    BoolResults(int falseCnt, int trueCnt) : falseCnt(falseCnt), trueCnt(trueCnt) {}
};

void readExpression(vector<bool>& terms, vector<char>& signs);
BoolResults possibleEvaluations(const vector<bool>& terms, const vector<char>& signs);
BoolResults possibleEvaluations(const vector<bool>& terms, const vector<char>& signs, 
                                unordered_map<string, BoolResults>& cache, int start, int end);
bool applyOperation(char op, bool left, bool right);

static inline void rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(),
            [] (char ch) { return ch != ' '; }).base(), s.end());
}

int main()
{
    vector<bool> terms;
    vector<char> signs;
    readExpression(terms, signs);

    BoolResults res = possibleEvaluations(terms, signs);
    cout << res.falseCnt << endl;
    cout << res.trueCnt << endl;
}

void readExpression(vector<bool>& terms, vector<char>& signs)
{
    string line;
    getline(cin, line);
    rtrim(line);

    istringstream iss(line);

    bool term;
    char sign;
    
    iss >> term;
    terms.push_back(term);
    while (!iss.eof())
    {
        iss >> sign >> term;   
        terms.push_back(term);
        signs.push_back(sign);
    }
}

BoolResults possibleEvaluations(const vector<bool>& terms, const vector<char>& signs)
{
    unordered_map<string, BoolResults> cache;
    return possibleEvaluations(terms, signs, cache, 0, terms.size());
}

BoolResults possibleEvaluations(const vector<bool>& terms, const vector<char>& signs, 
                                unordered_map<string, BoolResults>& cache, int start, int end)
{
    string cacheKey = "" + std::to_string(start) + std::to_string(end);
    if (cache.find(cacheKey) != cache.end()) return cache[cacheKey];

    if (end - start == 1) 
    {
        if (terms[start]) return BoolResults(0, 1);
        else return BoolResults(1, 0);
    }

    BoolResults results;
    for (int i = start + 1; i < end; i++)
    {
        assert(i - 1 >= 0 && i - 1 < signs.size());

        BoolResults leftResults = possibleEvaluations(terms, signs, cache, start, i);
        BoolResults rightResults = possibleEvaluations(terms, signs, cache, i, end);

        bool ttResult = applyOperation(signs[i - 1], true, true);
        bool tfResult = applyOperation(signs[i - 1], true, false);
        bool ftResult = applyOperation(signs[i - 1], false, true);
        bool ffResult = applyOperation(signs[i - 1], false, false);

        results.trueCnt += ttResult * leftResults.trueCnt * rightResults.trueCnt;
        results.falseCnt += !ttResult * leftResults.trueCnt * rightResults.trueCnt;

        results.trueCnt += tfResult * leftResults.trueCnt * rightResults.falseCnt;
        results.falseCnt += !tfResult * leftResults.trueCnt * rightResults.falseCnt;

        results.trueCnt += ftResult * leftResults.falseCnt * rightResults.trueCnt;
        results.falseCnt += !ftResult * leftResults.falseCnt * rightResults.trueCnt;

        results.trueCnt += ffResult * leftResults.falseCnt * rightResults.falseCnt;
        results.falseCnt += !ffResult * leftResults.falseCnt * rightResults.falseCnt;
    }
    
    cache[cacheKey] = results;

    return results;
}

bool applyOperation(char op, bool left, bool right)
{
    switch (op)
    {
        case '&':
            return left & right;
        case '|':
            return left | right;
        case '^':
            return left ^ right;
        default:
            assert(false);
    }
}

