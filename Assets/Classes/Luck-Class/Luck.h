#pragma once
class LuckSet
{
private:
    static std::vector<int> LuckyNumbers;
public:
    static int SelectedNumber;
    static int FirstPrizeCount;//默认为10
    static int SecondPrizeCount;//默认为90
    static int ThirdPrizeCount;//默认为400
    static int FirstPrizeProbability;//默认为10%
    static int SecondPrizeProbability;//默认为30%
    static int ThirdPrizeProbability;//默认为60%
    static void Setup(int A, int B, int C);//TODO:在设置页面调用
    static void SetPrizeProbability(int A, int B, int C);//TODO:在设置页面调用
    static void Renew(int A, int B, int C);
    static int JudgePrize();
    static void FillLuckyNumbers();
};
