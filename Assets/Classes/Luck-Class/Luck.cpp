#include "pch.h"
#include "Luck.h"
#include <random>
std::vector<int> LuckSet::LuckyNumbers;
int LuckSet::SelectedNumber = 0;
int LuckSet::FirstPrizeCount;//默认为10
int LuckSet::SecondPrizeCount;//默认为90
int LuckSet::ThirdPrizeCount;//默认为400
int LuckSet::FirstPrizeProbability;//默认为10%
int LuckSet::SecondPrizeProbability;//默认为30%
int LuckSet::ThirdPrizeProbability;//默认为60%
void LuckSet::Setup(int A, int B, int C)//TODO:在设置页面调用
{
    FirstPrizeCount = A; SecondPrizeCount = B; ThirdPrizeCount = C;
}

void LuckSet::SetPrizeProbability(int A, int B, int C)//TODO:在设置页面调用
{
    FirstPrizeProbability = A; SecondPrizeProbability = B; ThirdPrizeProbability = C;
}

void LuckSet::Renew(int A, int B, int C)
{
    SelectedNumber = 0;
    FirstPrizeCount = A; SecondPrizeCount = B; ThirdPrizeCount = C;
    FillLuckyNumbers();
}

int LuckSet::JudgePrize()
{
    FillLuckyNumbers();
    if( SelectedNumber == 0) { return 0; }
    else
    {
        if (FirstPrizeCount <= 0)
        {
            FirstPrizeProbability = 0;
        }
        if (SecondPrizeCount <= 0)
        {
            SecondPrizeProbability = 0;
        }
        if (ThirdPrizeCount <= 0)
        {
            ThirdPrizeProbability = 0;
        }
        //重新计算概率
        //设为double避免结果为0
        double TotalPrizeProbability = FirstPrizeProbability + SecondPrizeProbability + ThirdPrizeProbability;
        if (TotalPrizeProbability != 0)
        {
            FirstPrizeProbability = (int)(FirstPrizeProbability / TotalPrizeProbability * 100);
            SecondPrizeProbability = (int)(SecondPrizeProbability / TotalPrizeProbability * 100);
            ThirdPrizeProbability = 100 - FirstPrizeProbability - SecondPrizeProbability;
            std::vector<int> FirstPrizeList(LuckyNumbers.begin(), LuckyNumbers.begin() + FirstPrizeProbability);
            std::vector<int> SecondPrizeList(LuckyNumbers.begin() + FirstPrizeProbability, LuckyNumbers.begin() + FirstPrizeProbability + SecondPrizeProbability);
            std::vector<int> ThirdPrizeList(LuckyNumbers.begin() + FirstPrizeProbability + SecondPrizeProbability, LuckyNumbers.end());
            if (std::find(FirstPrizeList.begin(), FirstPrizeList.end(), SelectedNumber) != FirstPrizeList.end())
            {
                return 1;
            }
            else if (std::find(SecondPrizeList.begin(), SecondPrizeList.end(), SelectedNumber) != SecondPrizeList.end())
            {
                return 2;
            }
            else if (std::find(ThirdPrizeList.begin(), ThirdPrizeList.end(), SelectedNumber) != ThirdPrizeList.end())
            {
                return 3;
            }
        }
        return -1;//TODO:所有奖已抽完
    }
}

void LuckSet::FillLuckyNumbers()
{
    LuckyNumbers.clear();
    for (int i = 1; i <= 100; ++i)
    {
        LuckyNumbers.push_back(i);
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(LuckyNumbers.begin(), LuckyNumbers.end(), g);
}