namespace TutorialTwo
{
    class OOPA
    {
        static void A2I()
        {
            Console.Write("Character: ");
            char Ascii = Convert.ToChar(Console.ReadLine());
            Console.Write((int)Ascii);

        }

        static void I2A()
        {
            Console.Write("Integer: ");
            int Ascii = Convert.ToInt32(Console.ReadLine());
            if(Ascii < 128)
            {
                Console.Write((char)Ascii);
            }
            else
            {
                Console.WriteLine("Too Big.");
            }
            
        }

        static void Main()
        {
            Console.WriteLine("What would you like to run?\n1. ASCII to Integer\n2. Integer to Ascii");
            int choice = Convert.ToInt32(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    A2I();
                    break;
                case 2:
                    I2A();
                    break;
            }
        }
    }
}