<?php

// Too simple...

fscanf(STDIN, "%s", $s);
echo (strpos($s, '0000000') !== false || 
    strpos($s, '1111111') !== false) ? "YES" : "NO";