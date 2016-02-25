/*
   https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2830
   time limit: 1s
   
   S에서 T로 가는 가장 적은 회수를 찾아라.
   A -> B transform (A + x) -> B
   x는 A의 소인수이다. (1은 제외)
   
   S (1 <= S <= 100) & T (1 <= T <= 1000)
   
   6 > 9 > 12 (Transform Sample)
   
   Sample Input
   6 12
   6 13
   0 0
   
   Sample Output
   Case 1: 2
   Case 2: -1
*/

//#define MINJUNG

#include <iostream>
#include <vector>
#include <limits>
#include <map>

#ifdef MINJUNG
#include <time.h>
#define STOPWATCH_ON(tag)  clock_t tStart##tag = clock()
#define STOPWATCH_OFF(tag, min) clock_t tCost##tag=(double)(clock() - tStart##tag);\
    if(tCost##tag > min)cout << #tag" time.." << tCost##tag << endl;
#else
#define STOPWATCH_ON(tag)
#define STOPWATCH_OFF(tag, min)
#endif

using namespace std;

const int MAX_S = 100;
const int MAX_T = 1000;
const int NotMemo = numeric_limits<int>::max();

int StepMemo[MAX_T][MAX_T];
vector<int> PrimeFactorMap[MAX_T];
bool PrimeMap[MAX_T] = {false, false, true,};      // 0, 1 is not prime number

void findFactor(int n, vector<int>& factor)
{
    for(int i = 2; i <= n/2; ++i)
    {
        if(n%i == 0)
        {
            int f1 = i;
            int f2 = n/i;
            if(f2 < f1)
                break;
            
            factor.push_back(f1);
            if(f1 != f2)
                factor.push_back(f2);
        }
    }
    // factor.sort();
}

void findPrimeFactor(int n, vector<int>& primeFactor)
{
    for(int i = 1; i <= n/2; ++i)
    {
        if(n%i == 0)
        {
            int f1 = i;
            int f2 = n/i;
            if(f2 < f1)
                break;
            
            if(PrimeMap[f1])
                primeFactor.push_back(f1);
            if(f1 != f2 && PrimeMap[f2])
                primeFactor.push_back(f2);
        }
    }
    
    if(primeFactor.empty())
    	for(int i = 0; i < MAX_T; ++i)
    		StepMemo[n][i] = -1;
    
    // primeFactor.sort();
}

bool isPrimeNumber(int n)
{
    vector<int> factor;
    findFactor(n, factor);
    return factor.empty();
}

void Memo(int S, int T, int step)
{
	if(step == -1 && StepMemo[S][T] == NotMemo)
		StepMemo[S][T] = step;
	else if(StepMemo[S][T] == -1)
		StepMemo[S][T] = step;
	else
		StepMemo[S][T] = min(StepMemo[S][T], step);
	/*cout << "Memo0.." << "S: " << S << " T: " << T << " step: " << step 
		<< " re: " << StepMemo[S][T] << endl;*/
}

bool transform(const int S, const int T, int step_S = 0, int step = 0)
{
	if(step_S == 0)
		step_S = S;

    if(StepMemo[step_S][T] != NotMemo)
    {
	    //cout << "It's Memo! " << step_S << ',' << T << endl;
        if(StepMemo[step_S][T] == -1)
            return false;
        
        step_S = T;
        step += StepMemo[step_S][T];
        //return true;
    }
	
	if(step_S == T)
	{
		Memo(S, T, step);
        return true;
    }
    else if (step_S > T)
    {
		Memo(S, T, -1);
        return false;
    }
    
    bool r = false;
    for(const int& n: PrimeFactorMap[step_S])
    {
        if(transform(S, T, step_S + n, step +1))
        {
			Memo(step_S, step_S + n, 1);
			r = true;
		}
    }
    
    return r;
}

int main()
{
	//memset(StepMemo, NotMemo, sizeof(StepMemo));
	for(int i = 0; i < MAX_T; ++i)
		for(int j = 0; j < MAX_T; ++j)
			StepMemo[i][j] = NotMemo;

    // Making PrimeMap
    for(int i = 2; i < MAX_T; ++i)
    {
        if(PrimeMap[i])
            continue;
        else if (isPrimeNumber(i))
            PrimeMap[i] = true;
        
        for(int j = i+i; j <= MAX_T; j+=i)
            PrimeMap[j] = false;
    }
    
    // Making PrimeFactorMap under MAX_T
    for(int i = 0; i < MAX_T; ++i)
        findPrimeFactor(i, PrimeFactorMap[i]);
    
    for(int i = 1; true; ++i)
    {
        int S, T;
        cin >>S >>T;
        
        if(S == 0 && T == 0)
            break;
        
        STOPWATCH_ON(step);
        transform(S, T);
        cout << "Case " << i << ": " << StepMemo[S][T] << endl;
        STOPWATCH_OFF(step, 500);
    }
    
    return 0;
}