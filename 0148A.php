<?php


// Using the Inclusion–exclusion principle.
// See also http://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle


function gcd($m, $n) {
   return $n > 0 ? gcd($n, $m % $n) : $m;
}

function lcm($m, $n) {
   return $m / gcd($m, $n) * $n;
}


fscanf(STDIN, "%d", $k);
fscanf(STDIN, "%d", $l);
fscanf(STDIN, "%d", $m);
fscanf(STDIN, "%d", $n);
fscanf(STDIN, "%d", $d);
$result = intval($d/$k) 
     + intval($d/$l) 
     + intval($d/$m) 
     + intval($d/$n)
     - intval($d/lcm($k, $l))
     - intval($d/lcm($k, $m))
     - intval($d/lcm($k, $n))
     - intval($d/lcm($l, $m))
     - intval($d/lcm($l, $n))
     - intval($d/lcm($m, $n))
     + intval($d/lcm(lcm($k, $l), $m))
     + intval($d/lcm(lcm($k, $l), $n))
     + intval($d/lcm(lcm($k, $m), $n))
     + intval($d/lcm(lcm($l, $m), $n))
     - intval($d/lcm(lcm($k, $l), lcm($m, $n)));
echo $result."\n";