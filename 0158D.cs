/*
  Using a brute force algorithm and make a good enough time complexity.
*/


using System;
using System.Text;

class Program {
   public static void Main(string[] args) {
       string buf;
       buf = Console.ReadLine();
       int n = Convert.ToInt32(buf);
       buf = Console.ReadLine();
       string [] vals = buf.Split(' ');
       int [] scores = new int[n];
       for(int i = 0; i < n; ++i) {
           scores[i] = Convert.ToInt32(vals[i]);
       }
       int result = -999999999;
       for(int k = 1; k * 3 <= n; ++k) {
           if(n % k == 0) {
               for(int i = 0; i < k; ++i) {
                   int score = 0;
                   for(int j = i; j < n; j += k) {
                       score += scores[j];
                   }
                   if(score > result) result = score;
               }
           }
       }
       Console.WriteLine(result);
   }
}