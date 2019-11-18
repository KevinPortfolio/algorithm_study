#include <stdlib.h>
#include <stdio.h>

#include "math.cpp"
#include "strings.cpp"
#include "trees.cpp"


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

int main()
{
  int fib_num = nth_fibonacci_recursive(9);

  char* test_pal = longest_palindrome("aaaa");
  
  char test_label[7] = "Mooser";
  bool str_test = str_compare_null_term(test_label, "Moose");
  
  TreeNode Test;
  TreeNode Cow;
  TreeNode Cow2;
  TreeNode Cow3;
  TreeNode Test2;
  TreeNode Test3;

  Cow.right = &Cow2;
  Cow.value = 3;
  Cow2.right = &Cow3;
  Cow2.value = 1;
  Cow.left = 0;
  Cow2.left = 0;
  Cow3.left = 0;
  Cow3.right = 0;
  Cow3.value = 10;

  Test.right = &Test2;
  Test.value = 3;
  Test2.right = &Test3;
  Test2.value = 1;
  Test2.left = 0;
  Test.left = 0;
  Test3.left = 0;
  Test3.right = 0;
  Test3.value = 10;
  
  
  int tree_count = number_of_unqiue_binary_search_trees(4);
  if (is_same_binary_tree_recursive(&Test, &Cow))
  {
    printf("%d", tree_count);
  }

  bool running = true;
  while (running)
  {
    
  }
  
  return 0;
}
