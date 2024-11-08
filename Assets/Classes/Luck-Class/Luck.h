#pragma once
class LuckSet
{
private:
	//static List<int> LuckyNumbers = new List<int>();
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
        
        private static void FillLuckyNumbers()
        {
            LuckyNumbers.Clear();
            LuckyNumbers = Enumerable.Range(1, 100).ToList();
            Random random = new Random();
            LuckyNumbers = LuckyNumbers.OrderBy(x => random.Next()).ToList();
        }
    }
};

