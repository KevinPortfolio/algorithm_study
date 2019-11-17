
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

/* PURPOSE: Find the median of two sorted arrays. 
   SPACE COMPLEXITY: O(1)    
   TIME COMPLEXITY: O(n)
   TYPE: Iterative

   // NOTE: This is the brute force method.
   // TODO: Solve using the O(log(min(m,n))) method later.
 */
double
median_of_two_sorted_arrays(int* array_a, int array_a_size, int* array_b, int array_b_size)
{
  double result = 0.0;
  int middle_position = ((array_a_size + array_b_size) / 2) + 1;
  int prev_result = 0, a_itr = 0, b_itr = 0;
  bool even = true;
  
  if ((array_a_size + array_b_size) % 2) 
    even = false;
 
  for (unsigned int first_half_itr = 0; first_half_itr < middle_position; first_half_itr++)
  {
    prev_result = result;
    
    if ((a_itr < array_a_size) && (b_itr < array_b_size)) // NOTE: If both arrays have more
    {
      if (array_a[a_itr] <= array_b[b_itr]) 
	result = array_a[a_itr++];
      else
	result = array_b[b_itr++];
    }
    else if ((a_itr < array_a_size)) // NOTE: If array a has more but b does not
    {
      result = array_a[a_itr++];
    }
    else                             // NOTE: If array b has more but a does not
    {
      result = array_b[b_itr++];
    }
  }
  
  if (even)
    result = (prev_result + result) / 2.0;
  return result;
}
