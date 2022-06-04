#include "share/atspre_staload.hats"

fun
factorial(n: int): int =
if n > 0 then n * factorial(n-1) else 1

implement main0 () = println!("factorial(5) = ", factorial(5))
