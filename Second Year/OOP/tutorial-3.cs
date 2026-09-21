using System.ComponentModel;
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
            var rnd = new Random();
            int heads = 0;

            for(int i = 0; i < n; i++)
            {
                int flip = rnd.Next(2);
                if(flip == 1)
                {
                    heads++;
                }
            }

            int perc_h = (heads*100)/ n;
            Console.WriteLine("No. Flips: " + n + 
                                "\nNo. Heads: " + heads + 
                                "\nNo. Tails: " + (n-heads) + 
                                "\n% Heads: " + perc_h + "%" +
                                "\n% Tails: " + (100-perc_h) + "%");
        }

        static void HigherOrLower()
        {
            var rnd = new Random();
            bool loss = false;
            int i = 0;
            int prev = rnd.Next(13);
            bool bet;

            while(loss == false && i < 5)
            {
                int res = rnd.Next(1, 13);

                Console.WriteLine("\nPrevious: " + prev);
                Console.WriteLine("Higher (0) or Lower (1)? ");
                bet = Convert.ToBoolean(Convert.ToInt32(Console.ReadLine()));
                Console.WriteLine("Result: " + res);
                
                if(bet == false)
                {
                    if(res > prev)
                    {
                        Console.WriteLine("You Win! :D");
                        i++;
                    }
                    else if(res <= prev)
                    {
                        Console.WriteLine("You Lose! :C");
                        loss = true;
                    }
                }
                else if(bet == true)
                {
                    if(res < prev)
                    {
                        Console.WriteLine("You Win! :D");
                        i++;
                    }
                    else if(res >= prev)
                    {
                        Console.WriteLine("You Lose :C");
                        loss = true;
                    }
                }
                prev = res;
            }
            if(i == 5)
            {
                Console.WriteLine("You win the game!! You get nothing :D");
            }
        }

        static void ForFib()
        {
            short crnt = 1;
            short prev1 = 1;
            short prev2;

            Console.Write(crnt);
            prev2 = prev1;
            prev1 = crnt;
            crnt = Convert.ToInt16(crnt + prev1);


            for(int i = 0; crnt < (short.MaxValue - prev2); i++)
            {
                Console.Write(", " + crnt);
                prev2 = prev1;
                prev1 = crnt;
                crnt = Convert.ToInt16(prev2 + prev1);

            }
        }

        static void WhileFib()
        {
            short crnt = 1;
            short prev1 = 1;
            short prev2;

            Console.Write(crnt);
            prev2 = prev1;
            prev1 = crnt;
            crnt = Convert.ToInt16(crnt + prev1);


            while(crnt < (short.MaxValue - prev2))
            {
                Console.Write(", " + crnt);
                prev2 = prev1;
                prev1 = crnt;
                crnt = Convert.ToInt16(prev2 + prev1);

            }
        }

        static double TempConvert(double n, char m)
        {
            double conv;
            if(m == 'F')
            {
                conv = 9.0/5.0;
                double far = ( n * (conv) ) + 32.0;
                return far;
            }
            else if(m == 'C')
            {
                conv = 5.0/9.0;
                double cel = (n - 32.0) * (conv);
                return cel;
            }
            else
            {
                throw new ArgumentException("Invalid Arg");
            }
        }

        static void TempConvertMenu()
        {
            double n;
            int choice = 0;
            while(choice != 3){
                Console.WriteLine("1. Farenheit to Celsius" + 
                                "\n2. Celsius to Farenheit" + 
                                "\n3. Exit");
                choice = Convert.ToInt32(Console.ReadLine());

                switch (choice)
                {
                    case 1:
                        Console.WriteLine("Farenheit Value: ");
                        n = Convert.ToDouble(Console.ReadLine());
                        Console.WriteLine("{0}°F = {1}°C", n, TempConvert(n, 'C'));
                        break;
                    case 2:
                        Console.WriteLine("Celsius Value: ");
                        n = Convert.ToDouble(Console.ReadLine());
                        Console.WriteLine(n + "°C = " + TempConvert(n, 'F') + "°F");
                        break;
                    case 3:
                        break;
                }
            }
        }

        static void Main()
        {
            Console.WriteLine("What would you like to run?" + 
                            "\n1. Sum up to n" + 
                            "\n2. Quadratic Formula" + 
                            "\n3. Flip a Coin N times" + 
                            "\n4. Higher or Lower" + 
                            "\n5. Fibonacci (For Loop)" + 
                            "\n6. Fibonacci (While Loop)" + 
                            "\n7. Temperature Converter" + 
                            "\n8. Exit");
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
                case 4:
                    HigherOrLower();
                    break;
                case 5:
                    ForFib();
                    break;
                case 6:
                    WhileFib();
                    break;
                case 7:
                    TempConvertMenu();
                    break;
                case 8:
                    break;
            }
        }
    }
}