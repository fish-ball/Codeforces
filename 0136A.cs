// Just rearrange the indexes, simple.


using System;
using System.Text;

class Program {
   public static void Main(string[] args) {
       int n = Convert.ToInt32(Console.ReadLine());
       string[] vals = Console.ReadLine().Split(' ');
       int[] ans = new int[n];
       for(int i = 0; i < n; ++i) {
           ans[Convert.ToInt32(vals[i]) - 1] = i;
       }
       for(int i = 0; i < n; ++i) {
           if(i > 0) Console.Write(' ');
           Console.Write(ans[i] + 1);
       }
   }
}