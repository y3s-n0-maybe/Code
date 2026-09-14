namespace TutorialThree
{
    class OOPA
    {
        static void SumMethod()
        {
            Console.WriteLine("Value for n?");
            int n = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Method 1 or 2?");
            int choice = Convert.ToInt32(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    Console.WriteLine(SumLoop(n));
                    break;
                case 2:
                    Console.WriteLine(SumFormula(n));
                    break;
            }
        }

        static int SumLoop(int n)
        {
            int sum = 0;
            for(int i = 1; i <= n; i++)
                {
                sum += i;
                }
            return sum;
        }
        
        static int SumFormula(int n)
        {
            int sum = (n*(n+1))/2;
            return sum;
        }

        static void Main()
        {
            Console.WriteLine("What would you like to run?\n1. Sum up to n\n2. Integer to Ascii");
            int choice = Convert.ToInt32(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    SumMethod();
                    break;
                case 2:
                    break;
            }
        }
    }
}