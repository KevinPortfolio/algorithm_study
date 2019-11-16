/* GENERAL DEFINITIONS
   
   Binary Tree: A tree where every node has at most two branches.
   Binary Search Tree: A Binary Tree where all left sub-trees only have nodes with key values less than
                       the parent node and all right sub-trees only have nodes with key values greater
		       than the parent.


 */
struct TreeNode
{
  int value;
  TreeNode* left;
  TreeNode* right;
};

/* PURPOSE: Find the count of unique binary search trees given n nodes. 
   SPACE COMPLEXITY: O(n)    
   TIME COMPLEXITY: O(n^2)
   TYPE: Dynamic Programming

   NOTES: This solution takes advantage of the fact that solutions can be
   reused for every sub-tree of the current node when the current node is
   thought of as the root. Meaning if the smallest case is known, which it
   is, its solution can be saved and used to solve for the next node count
   in the iteration. With node count 1 having only 1 possible tree, it can
   be used as the base case to solve the answer for node count 2. 
 */
int
number_of_unqiue_binary_search_trees(int node_count)
{
  
  unsigned int* unique_tree_count = new unsigned int[node_count + 1];
  unique_tree_count[0] = 1;
  unique_tree_count[1] = 1;
  
  for (int current_node_count = 2; current_node_count <= node_count; current_node_count++)
  {
    unique_tree_count[current_node_count] = 0; // NOTE: This line is here for languages or libraries where the
                                               // allocated memory is not gauranteed to be initialized to 0.
    for (int node_itr = 0; node_itr < current_node_count; node_itr++)
    {
      unique_tree_count[current_node_count] +=
	unique_tree_count[node_itr] * unique_tree_count[current_node_count - node_itr - 1];
    }    
  }
  
  unsigned int result = unique_tree_count[node_count];
  delete[] unique_tree_count;
  return result;
}

/* PURPOSE: Find if two Binary Trees are structurally identical and contain the same node values.
   SPACE COMPLEXITY: O(n)  // NOTE: A balanced tree could have O(log(n))
   TIME COMPLEXITY: O(n)
   TYPE: Recursion

   NOTES: Order of if statement checks is important here to avoid access violations.
*/
bool
is_same_binary_tree_recursive(TreeNode* tree_a, TreeNode* tree_b)
{
  
  if ((tree_a == 0) && (tree_b == 0))
  {
    return true;
  }
  if ((tree_a == 0) || (tree_b == 0))
  {
    return false;
  }
  if (tree_a->value != tree_b->value)
  {
    return false;
  }
  return (is_same_binary_tree_recursive(tree_a->right, tree_b->right)) &&
         (is_same_binary_tree_recursive(tree_a->left, tree_b->left));
}

/* PURPOSE: Find if two Binary Trees are structurally identical and contain the same node values.
   SPACE COMPLEXITY: O(n)  // NOTE: A balanced tree could have O(log(n))
   TIME COMPLEXITY: O(n)
   TYPE: Iterative

   NOTES: Order of if statement checks is important here to avoid access violations.
 */

bool
is_same_binary_tree(TreeNode* tree_a, TreeNode* tree_b)
{
  if ((tree_a == 0) && (tree_b == 0))
  {
    return true;
  }
  if ((tree_a == 0) || (tree_b == 0))
  {
    return false;
  }
  if (tree_a->value != tree_b->value)
  {
    return false;
  }

  return false;
}
