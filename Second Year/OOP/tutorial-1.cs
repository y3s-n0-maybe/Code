namespace TutorialOne
{
    class OOPA
    {
        static void DayTemp()
        {
            Console.WriteLine("Day\tTemp");
            double[,] temps = {{0, 15.678}, {10, 20.23345}, {20, 24.5963}};
            for(int i = 0; i < 3; i++)
            {
                Console.WriteLine("{0}\t{1}", temps[i, 0], temps[i, 1]); 
            }     
        }

        static void RealNumbers()
        {
            double[] numbers = new double[3];
            Console.WriteLine("3 Real Numbers:");
            for(int i = 0; i < numbers.Length; i++)
            {
                numbers[i] = Convert.ToDouble(Console.ReadLine());
            }
            for(int i = 0; i < numbers.Length; i++)
            {
                Console.WriteLine("{0, 15:F3}", numbers[i]);
            }
            
        }

        static void Main()
        {
            Console.WriteLine("1. Real Numbers\n2. Day Temp");
            int choice = Convert.ToInt32(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    RealNumbers();
                    break;
                case 2:
                    DayTemp();
                    break;
            }
        }

    }
}