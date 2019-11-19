#include <stdlib.h>
#include <stdio.h>

#include "math.cpp"
#include "strings.cpp"
#include "trees.cpp"

/*
  TYPES
  - permutations
  - math to target (sum 3 = 0, sum 2 = target)
  - substrings
  - water buckets
  - merge lists
  - rotate matrix


 */


int main()
{
  int fib_num = nth_fibonacci_recursive(9);

  int perm = permutations(3);
  
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
