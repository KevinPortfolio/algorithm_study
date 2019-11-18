
int
helper_palindrome_expand(char* start_left, char* start_right, char* start_bound)
{
  int count = 0;
      
  while ((start_left >= start_bound) && (*start_right) && (*start_right == *start_left))
  {
    start_left--;
    start_right++;
    count++;
  }
  return count;
}

unsigned int
char_str_length_null_term(char* char_str)
{
  unsigned int result = 0;
  char* str_itr = char_str;
  
  if (char_str)
    while(*(str_itr++))
      result++;
  
  return result;
}

char*
longest_common_prefix(char **strs, int strs_size)
{ 
  char* result;
  unsigned int min_str_length = 0;
  
  if (!strs_size)
    return 0;

  min_str_length = char_str_length_null_term(strs[0]);
  
  for (unsigned int strs_index = 0; strs_index < strs_size; strs_index++)
  {
    int str_length = char_str_length_null_term(strs[strs_index]);
    if (min_str_length > str_length)
      min_str_length = str_length;
  }

  unsigned int prefix_count = 0;
  for (unsigned int str_pos = 0; str_pos < min_str_length; str_pos++)
  {
    char current_char = strs[0][str_pos];
    for (unsigned int strs_index = 1; strs_index < strs_size; strs_index++)
    {
      if (strs[strs_index][str_pos] != current_char)
      {
	str_pos = min_str_length;
        strs_index = strs_size;
        prefix_count--;
      }
    }
    prefix_count++;
  }  

  result = (char*)malloc(prefix_count);
  for (unsigned int index = 0; index < prefix_count; index++)
    result[index] = strs[0][index];
  
  return result;
}

char*
longest_palindrome(char *str)
{
  int max_count = 1, odd_count = 0, even_count = 0;
  char *result = 0;
  char *str_itr = str;
  char *pal_pos = str;
  bool even = false;
  
  if (str)
  {
    
    while (*str_itr)
    {
      odd_count = helper_palindrome_expand(str_itr, str_itr, str);
      even_count = helper_palindrome_expand(str_itr, str_itr + 1, str);

      
      if (odd_count > max_count)
      {
	max_count = odd_count;
	pal_pos = str_itr;
	even = false;
      }
      
      if (!even && (even_count >= max_count))
      {
	max_count = even_count;
	pal_pos = str_itr;
	even = true;
      }
      else if (even_count > max_count)
      {
	max_count = even_count;
	pal_pos = str_itr;
	even = true;
      }
     
      str_itr++;
    }
    
    if (max_count == 1)
    {
      if (even)
      {
        result = (char*)malloc(3);
        result[0] = pal_pos[0];
        result[1] = pal_pos[1];
        result[2] = 0;
	return result;
      }
      else
      {
        result = (char*)malloc(2);
        result[0] = str[0];
        result[1] = 0;
	return result;
      }
    }
    
    int arr_size;
    if (!even)
    {
      arr_size = (max_count - 1) * 2 + 2;  // note, +2 is one for center and 1 for null
      str_itr = pal_pos - (max_count - 1);
    }
    else
    {
      arr_size = max_count * 2 + 1;
      str_itr = pal_pos - (max_count - 1);
    }
    
    result = (char*)malloc(arr_size);
    result[arr_size - 1] = 0;
    char* result_itr = result;
    
    for (int i = 0; i < (arr_size - 1); i++)
    {
      *result_itr = *str_itr;
      result_itr++;
      str_itr++;
    }
    return result;
       
  }
  else
  {
    return 0;
  }
}

bool
str_compare_null_term(char* str_a, char* str_b)
{  
  if (!str_a && !str_b)
    return 1;
  if (!str_a || !str_b)
    return 0;
  
  while (*str_a && *str_b)
  {
    if (*(str_a++) != *(str_b++))
      return 0;
  }
  
  if (!(*str_a) && !(*str_b))
    return 1;
  return 0;
}
