// Use the vector multiple to figure out the direction.


using System;
using System.Text;

class Program
{
   static void Main(string[] args)
   {
       long x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
       string buf = Console.ReadLine();
       string[] vals = buf.Split(' ');
       x1 = Convert.ToInt32(vals[0]);
       y1 = Convert.ToInt32(vals[1]);

       buf = Console.ReadLine();
       vals = buf.Split(' ');
       x2 = Convert.ToInt32(vals[0]);
       y2 = Convert.ToInt32(vals[1]);

       buf = Console.ReadLine();
       vals = buf.Split(' ');
       x3 = Convert.ToInt32(vals[0]);
       y3 = Convert.ToInt32(vals[1]);

       long crs = (x2-x1)*(y3-y2)-(y2-y1)*(x3-x2);
       if(crs == 0) {
           Console.WriteLine("TOWARDS");
       }
       else if(crs < 0) {
           Console.WriteLine("RIGHT");
       }
       else if(crs > 0) {
           Console.WriteLine("LEFT");
       }
   }
}