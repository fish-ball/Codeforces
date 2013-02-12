// Just split the path string and apply the changes.


using System;
using System.Text;

class Program
{
   static void Main(string[] args)
   {
       string buf = Console.ReadLine();
       string path = "";
       for(int n = Convert.ToInt32(buf); n-- > 0;) {
           buf = Console.ReadLine();
           args = buf.Split(' ');
           if(args[0] == "pwd") Console.WriteLine(path + "/");
           else {
               string [] paths = args[1].Split('/');
               if(paths[0] == "") path = "";
               foreach(string s in paths) {
                   if(s == "..") {
                       path = path.Remove(path.LastIndexOf('/'));
                   }
                   else if(s != "") {
                       path += "/" + s;
                   }
               }
           }
       }
   }
}