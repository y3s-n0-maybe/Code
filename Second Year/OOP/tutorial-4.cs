using System;
using System.Net;

namespace TutorialThree
{
    class OOPA
    {

        static bool Factor(int n, int i)
        {
            double dn = Convert.ToDouble(n);
            double di = Convert.ToDouble(i);

            double qout = dn / di;

            if(qout % 1.0 == 0.0){return true;}
            else{return false;}
            
        }
        static void PrimeFactors(int n, List<int> factors)
        {
            bool prime = true;
            int i = 2;
            while(i <= Math.Sqrt(n))
            {
                if(Factor(n, i) == true)
                {
                    factors.Add(i);
                    PrimeFactors(n/i, factors);
                    prime = false;
                    break;
                }
                i++;
            }
            if(prime == true)
            {
                factors.Add(n);
            }
        }

        static void PFInit()
        {
            Console.WriteLine("For what n?");
            int n = Convert.ToInt32(Console.ReadLine());
            List<int> factors = new List<int>();
            PrimeFactors(n, factors);
            foreach (int i in factors)
            {
                Console.Write("{0}, ", i);
            }            
        }

        static void Main()
        {
            PFInit();

            /* 
            int choic = 1;
            while(choice != 0){
                Console.WriteLine("What would you like to run?\n" + 
                                "0. Quit \n" + 
                                "1. Prime factors of n \n" + 
                                "\n3. Flip a Coin N times" + 
                                "\n4. Higher or Lower" + 
                                "\n5. Fibonacci (For Loop)" + 
                                "\n6. Fibonacci (While Loop)" + 
                                "\n7. Temperature Converter");
                choice = Convert.ToInt32(Console.ReadLine());

                switch (choice)
                {
                    case 0:
                        break;
                    case 1:
                        PFInit();
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
                }
            } */
        }
    }
}