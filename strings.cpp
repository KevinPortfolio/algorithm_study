
char* longest_palindrome(char *str)
{
  char *str_itr = str;
  char *pal_pos = str;
  bool even = false;
  int max_count = 1;
  if (str)
  {
    while (*str_itr)
    {
      char *temp_left;
      char *temp_right;
      
      temp_left = str_itr;
      temp_right = str_itr;
      int temp_count = 0;
      while ((temp_left >= str) && (*temp_right) && (*temp_right == *temp_left))
      {
	temp_left--;
	temp_right++;
	temp_count++;
      }
      if (temp_count > max_count)
      {
	max_count = temp_count;
	pal_pos = str_itr;
	even = false;
      }
      temp_count = 0;
      temp_left = str_itr;
      temp_right = str_itr + 1;
      while ((temp_left >= str) && (*temp_right) && (*temp_right == *temp_left))
      {
	temp_left--;
	temp_right++;
	temp_count++;
      }
      if ((temp_count == 1) && (pal_pos == str))
      {
	pal_pos = str_itr;
	even = true;
      }
      if (!even)
      {
	if (temp_count >= max_count)
	{
	  max_count = temp_count;
	  pal_pos = str_itr;
	  even = true;
	}
      }
      else
      {
	if (temp_count > max_count)
	{
	  max_count = temp_count;
	  pal_pos = str_itr;
	  even = true;
	}
      }
      str_itr++;
    }
    
    if (max_count == 1)
    {
      if (even)
      {
	char* test = (char*)malloc(3);
	test[0] = pal_pos[0];
	test[1] = pal_pos[1];
	test[2] = 0;
	return test;
      }
      else
      {
	char* test = (char*)malloc(2);
	test[0] = str[0];
	test[1] = 0;
	return test;
      }
    }
    else
    {
      int arr_size;
      if (!even)
	arr_size = (max_count - 1) * 2 + 2;  // note, +2 is one for center and 1 for null
      else
	arr_size = max_count * 2 + 1;
      char* new_str = (char*)malloc(arr_size);
      new_str[arr_size - 1] = 0;
      char* new_str_itr = new_str;
      char* old_str_itr;
      if (!even)
	old_str_itr = pal_pos - (max_count - 1);
      else
	old_str_itr = pal_pos - (max_count - 1);
      //else
      //   old_str_itr = str[pal_pos - ((max_count - 1)];
      
      for (int i = 0; i < (arr_size - 1); i++)
      {
	*new_str_itr = *old_str_itr;
	new_str_itr++;
	old_str_itr++;
      }
      return new_str;
    }    
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
