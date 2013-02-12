<?php

// Using permutation index to figure out the position in order to get the comparison count.

fscanf(STDIN, "%d", $n);
$index = array();

$vars = explode(' ', fgets(STDIN));

for($i = 0; $i < $n; ++$i) {
   $index[intval($vars[$i]) - 1] = $i;
}

fscanf(STDIN, "%d", $k);
$x = $y = 0;

$vars = explode(' ', fgets(STDIN));

for($i = 0; $i < $k; ++$i) {
   $v = intval($vars[$i]) - 1;
   $x += $index[$v] + 1;
   $y += $n - $index[$v];
}

echo $x.' '.$y;