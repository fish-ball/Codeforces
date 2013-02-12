<?php


// Quite straight forward implementation...

fscanf(STDIN, "%s", $a);
fscanf(STDIN, "%s", $b);

$a = strtolower($a);
$b = strtolower($b);

if($a == $b) echo 0;
else if($a > $b) echo 1;
else if($a < $b) echo -1;