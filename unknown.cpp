
/* PURPOSE: How many squares of water can be trapped between walls.
   SPACE COMPLEXITY: O(1)
   TIME COMPLEXITY: O(n)
   TYPE: Iterative
 */
int trap_rain_water(int* wall_height, int wall_count)
{
  int result = 0;
  int left_wall = 0, right_wall = wall_count - 1, left_height = 0, right_height = -1;
  
  while (left_wall < right_wall)
  {
    if (wall_height[left_wall] < wall_height[right_wall])
    {
      if (wall_height[left_wall] >= left_height)
	left_height = wall_height[left];
      else
        result += left_height - wall_height[left_wall];
      left_wall++;
      
    }
    else
    {
      if (wall_height[right_wall] >= right_height)
	right_height = wall_height[right_wall];
      else
        result += right_height - wall_height[right_wall];
      right_wall--;
    }
  }
  
  return result;
}
