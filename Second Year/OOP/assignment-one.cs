using System;
using System.Dynamic;
using System.Runtime.InteropServices;
using System.Xml.Schema;

namespace ComplexAssignment;
class Program
{
    static void Main(string[] args)
    {
        // ---- constructors ----
        Complex z0 = new Complex();
        Complex z1 = new Complex(3, 4);
        Complex z2 = new Complex(1, -2);
        Complex z3 = new Complex(0, 1);
        Complex z4 = new Complex(-2.5, 0);
        // ---- ToString() ----
        Console.WriteLine("z0 = {0}", z0);
        Console.WriteLine("z1 = {0}", z1);
        Console.WriteLine("z2 = {0}", z2);
        Console.WriteLine("z3 = {0}", z3);
        Console.WriteLine("z4 = {0}", z4);
        // ---- unary operators ----
        Console.WriteLine("+z1 = {0}", +z1);
        Console.WriteLine("-z1 = {0}", -z1);
        Console.WriteLine("-z2 = {0}", -z2);
        // ---- binary operators ----
        Console.WriteLine("({0}) + ({1}) = {2}", z1, z2, z1 + z2);
        Console.WriteLine("({0}) - ({1}) = {2}", z1, z2, z1 - z2);
        Console.WriteLine("({0}) * ({1}) = {2}", z1, z2, z1 * z2);
        Console.WriteLine("({0}) / ({1}) = {2}", z1, z2, z1 / z2);
        Console.WriteLine("({0}) / ({1}) = {2}", z2, z1, z2 / z1);
        Console.WriteLine("({0}) * ({1}) = {2}", z4, z2, z4 * z2);
        Console.WriteLine("({0}) * ({1}) = {2}", z3, z3, z3 * z3);
        // ---- a compound expression ----
        Complex w = z1 * z2 - z2 / z3;
        Console.WriteLine("z1 * z2 - z2 / z3 = {0}", w);
        // ---- the operands must not have been changed by the operators ----
        Console.WriteLine("z1 = {0}, z2 = {1} (unchanged)", z1, z2);
    }
}
public class Complex
{
    private double real;
    public double Real
    {
        get { return real; }
        set { real = value; }
    }
    private double imag;
    public double Imag
    {
        get{ return imag;}
        set{ imag = value;}
    }

    public Complex()
    {
        real = 0;
        imag = 0;
    }
    public Complex(double a, double b)
    {
        real = a;
        imag = b;
    }

    public Complex Conjugate()
    {
        return new Complex(real, -imag);
    }

    public override string ToString()
    {
        if(imag < 0)
        {
            return $"{real} - {0 - imag}i";
        }else
        {
            return $"{real} + {imag}i";
        }
    }

    public static Complex operator +(Complex operand) => operand;
    public static Complex operator -(Complex operand) => new Complex(-operand.Real, -operand.Imag);

    public static Complex operator +(Complex left, Complex right) => new Complex(left.Real + right.Real, left.Imag + right.Imag);
    public static Complex operator -(Complex left, Complex right) => new Complex(left.Real - right.Real, left.Imag - right.Imag);

    public static Complex operator *(Complex left, Complex right) => new Complex((left.Real * right.Real) - (left.Imag * right.Imag), (left.Imag * right.Real) + (right.Imag * left.Real));
    public static Complex operator /(Complex left, Complex right)
    {
        double rrc = (right * right.Conjugate()).Real;
        Complex lrc = left * right.Conjugate();

        return new Complex(lrc.Real / rrc, lrc.Imag / rrc);
    }
}