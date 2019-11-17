
/* PURPOSE: Find the nth Fibonacci number. 
   SPACE COMPLEXITY: O(1)    
   TIME COMPLEXITY: O(n)
   TYPE: Iterative
 */
int
nth_fibonacci(int n)
{
  
  int prev2 = 0;
  int prev1 = 1;
  int result = 0;
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;

  for (int index = 3; index <= n; index++)
  {
    result = (prev2 + prev1);
    prev2 = prev1;
    prev1 = result;
  }
  
  return result;
}

/* PURPOSE: Find the nth Fibonacci number. 
   SPACE COMPLEXITY: O(n)    
   TIME COMPLEXITY: O(2^n)
   TYPE: Recursive
 */
int
nth_fibonacci_recursive(int n)
{
  
  if (n == 2)
    return 1;
  if (n == 1)
    return 0;
  
  return nth_fibonacci_recursive(n - 1) + nth_fibonacci_recursive(n - 2);
}
