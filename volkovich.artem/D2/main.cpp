#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
  if (argc > 2 || (argc == 2 && strcmp(argv[1], "reverse") != 0))
  {
    std::cerr << "Invalid args";
    return 1;
  }
  char symb;
  char *symbs = nullptr;
  char *tmp_symbs = nullptr;
  size_t *symbs_size = nullptr;
  size_t *tmp_symbs_size = nullptr;
  if (std::cin >> symb) {
    try
    {
      symbs = new char[1];
      symbs_size = new size_t[1];
      symbs[0] = symb;
    }
    catch (...)
    {
      std::cerr << "Bad alloc";
      std::cout << "\n";
      return 2;
    }
  } else
  {
    std::cout << '\n';
    return 0;
  }
  size_t all_count = 1;

  symbs_size[0] = 1;

  while (std::cin >> symb)
  {
    if (symb == symbs[all_count - 1])
    {
      symbs_size[all_count - 1] += 1;
    }
    else
    {
      try
      {
        tmp_symbs = new char[all_count + 1];
        tmp_symbs_size = new size_t[all_count + 1];
        for (size_t i = 0; i < all_count; i++)
        {
          tmp_symbs[i] = symbs[i];
          tmp_symbs_size[i] = symbs_size[i];
        }
        delete[] symbs;
        delete[] symbs_size;

        symbs = tmp_symbs;
        symbs_size = tmp_symbs_size;

        symbs[all_count] = symb;
        symbs_size[all_count] = 1;
        all_count++;
      }
      catch (...)
      {
        delete[] symbs;
        delete[] symbs_size;
        delete[] tmp_symbs;
        delete[] tmp_symbs_size;
        std::cerr << "Bad alloc";
        std::cout << "\n";
        return 2;
      }
    }
  }
  if (argc == 2)
  {
    for (size_t i = all_count; i-- > 0;)
    {
      std::cout << symbs_size[i] << ' ' << symbs[i] << '\n';
    }
  }
  else
  {
    for (size_t i = 0; i < all_count; i++)
    {
      std::cout << symbs_size[i] << ' ' << symbs[i] << '\n';
    }
  }
  delete[] symbs;
  delete[] symbs_size;
  return 0;
}
