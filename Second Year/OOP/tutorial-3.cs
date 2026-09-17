using System.Diagnostics;

namespace TutorialThree
{
    class OOPA
    {
        static void SumMethod()
        {
            Console.WriteLine("Value for n?");
            int n = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("1. Loop \n2. Formula \n3. Stopwatch");
            int choice = Convert.ToInt32(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    Console.WriteLine(SumLoop(n));
                    break;
                case 2:
                    Console.WriteLine(SumFormula(n));
                    break;
                case 3:
                    SumStopwatch(n);
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

        static void SumStopwatch(int n)
        {
            Stopwatch stopWatchLoop = new Stopwatch();
            Stopwatch stopWatchForm = new Stopwatch();

            stopWatchLoop.Start();
            for(int i = 0; i < 1000000; i++)
            {
                SumLoop(n);
            }
            stopWatchLoop.Stop();

            stopWatchForm.Start();
            for(int i = 0; i < 1000000; i++)
            {
                SumFormula(n);
            }
            stopWatchForm.Stop();

            Console.WriteLine("One Million Loops: " + stopWatchLoop.ElapsedMilliseconds);
            Console.WriteLine("One Million Formulae: " + stopWatchForm.ElapsedMilliseconds);

        }

        static void Quadratic()
        {
            Console.Write("A: ");
            double a = Convert.ToDouble(Console.ReadLine());

            Console.Write("B: ");
            double b = Convert.ToDouble(Console.ReadLine());

            Console.Write("C: ");
            double c = Convert.ToDouble(Console.ReadLine());

            double unsq = (b * b) - (4 * a * c);
            if(unsq > 0)
            {
               double d = Math.Sqrt(unsq);
               double bp = (d - b) / (2 * a);
               double bm = (0-(d + b)) / (2 * a);
               Console.WriteLine("Two Roots \n x = " + bm + "\n x = " + bp);
            }
            else if(Math.Abs(unsq) < 0.0001)
            {
                double root = b / (2 * a);
                Console.WriteLine("One Root: " + root);
            }
            else if(unsq < 0)
            {
                Console.WriteLine("Imaginary Roots");
            }
            else
            {
                Console.WriteLine("Error.");
            }
        }

        static void TossACoin(int n)
        {
            int heads = 0;
            var rnd = new Random();

            for(int i = 0; i < n; i++)
            {
                int flip = rnd.Next(2);
                if(flip == 1)
                {
                    heads++;
                }
            }

            int perc_h = ((heads*100)/(n));
            Console.WriteLine("No. Flips: " + n + 
                                "\nNo. Heads: " + heads + 
                                "\nNo. Tails: " + (n-heads) + 
                                "\n% Heads: " + perc_h + "%" +
                                "\n% Tails: " + (100-perc_h) + "%");
        }

        static void Main()
        {
            Console.WriteLine("What would you like to run?" + 
                            "\n1. Sum up to n" + 
                            "\n2. Quadratic Formula" + 
                            "\n3. Flip a Coin N times");
            int choice = Convert.ToInt32(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    SumMethod();
                    break;
                case 2:
                    Quadratic();
                    break;
                case 3:
                    Console.WriteLine("How many Flips?");
                    int n = Convert.ToInt32(Console.ReadLine());
                    TossACoin(n);
                    break;
            }
        }
    }
}