#include "pch.h"
#include "Luck.h"

void LuckSet::Setup(int A, int B, int C)//TODO:在设置页面调用
{
    FirstPrizeCount = A; SecondPrizeCount = B; ThirdPrizeCount = C;
}

int LuckSet::SelectedNumber = 0;

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
    if (SelectedNumber == 0) { return 0; }
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
        //设为double避免答案为0
        double TotalPrizeProbability = FirstPrizeProbability + SecondPrizeProbability + ThirdPrizeProbability;
        if (TotalPrizeProbability != 0)
        {
            FirstPrizeProbability = (int)(FirstPrizeProbability / TotalPrizeProbability * 100);
            SecondPrizeProbability = (int)(SecondPrizeProbability / TotalPrizeProbability * 100);
            ThirdPrizeProbability = 100 - FirstPrizeProbability - SecondPrizeProbability;
            List<int> FirstPrizeList = LuckyNumbers.Take(FirstPrizeProbability).ToList();//默认第1-10个
            List<int> SecondPrizeList = LuckyNumbers.Skip(FirstPrizeProbability).Take(SecondPrizeProbability).ToList();//默认第11-40个
            List<int> ThirdPrizeList = LuckyNumbers.Skip(FirstPrizeProbability + SecondPrizeProbability).Take(ThirdPrizeProbability).ToList();//默认第41-100个
            ///----------Contains判断集合是否包含元素-------------///
            if (FirstPrizeList.Contains(SelectedNumber))
            {
                return 1;
            }
            else if (SecondPrizeList.Contains(SelectedNumber))
            {
                return 2;
            }
            else if (ThirdPrizeList.Contains(SelectedNumber))
            {
                return 3;
            }
        }
        return -1;//TODO:所有奖已抽完
    }
}
