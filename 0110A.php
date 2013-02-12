<?php

// Too simple...

function islucky($s) {
   if($s == 0) return false;
   while($s > 0) {
       if($s % 10 != 4 && $s % 10 != 7) 
           return false;
       $s = intval($s / 10);
   }
   return true;
}

fscanf(STDIN, "%s", $s);
echo islucky(substr_count($s, '4') + substr_count($s, '7')) ? "YES" : "NO";