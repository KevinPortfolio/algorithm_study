

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
