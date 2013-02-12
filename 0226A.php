<?
// It’s not difficult to find that the recursion formula of the result is:
// f(n) = 3 * f(n-1) + 2, f(0) = 0
// So, let matrix A = {{3, 0}, {2, 1}}, x = {f(0), 1}
// Then x(n) = {f(n), 1} = x A^n, 
// where A^n can be obtain within O(log(n)) time.

function mat2mul($A, $B, $m) {
   return array(
       array(
           bcmod(bcadd(bcmul($A[0][0],$B[0][0]),bcmul($A[0][1],$B[1][0])),$m),
           bcmod(bcadd(bcmul($A[0][0],$B[0][1]),bcmul($A[0][1],$B[1][1])),$m)
       ), 
       array(
           bcmod(bcadd(bcmul($A[1][0],$B[0][0]),bcmul($A[1][1],$B[1][0])),$m),
           bcmod(bcadd(bcmul($A[1][0],$B[0][1]),bcmul($A[1][1],$B[1][1])),$m)
       )
   );
}

function mat2pow($A, $n, $m) {
   if($n == 0) return array(array(1, 0), array(0, 1));
   $B = mat2pow($A, $n >> 1, $m);
   $B = mat2mul($B, $B, $m);
   if($n % 2 == 1) {
       $B = mat2mul($B, $A, $m);
   }
   return $B;
}

function _main() {
   fscanf(STDIN, "%d%d", $n, $m);
   $MAT = mat2pow(array(array(3, 0), array(2, 1)), $n, $m);
   echo $MAT[1][0];
}

_main();