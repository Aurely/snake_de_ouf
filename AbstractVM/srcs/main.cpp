#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include "../headers/Exec.hh"

std::string	openFile(const char *fileName)
{
  std::fstream		file;
  std::stringstream	content;

  file.open(fileName);
  if (file.is_open())
    content << file.rdbuf();
  file.close();
  return content.str();
}

int	main(int ac, char **av)
{
  Exec			avmEx;
  std::stringstream	content;
  std::string		input_line;
  int			nb = 1;

  if (ac == 1)
    {
      while (std::getline(std::cin, input_line, '\n'))
	{
	  content << input_line << std::endl;
	  if (input_line == ";;")
	    break;
	}
      try {
	avmEx.avm_exec(content);
      }
      catch (std::exception &e)
	{
	  std::cerr << "ERROR : " << e.what() << std::endl;
	  avmEx.resetStack();
	}
    }
  else
    {
      while (av[nb])
	{
	  content << openFile(av[nb]);
	  try {
	    avmEx.avm_exec(content);
	  }
	  catch (std::exception &e)
	    {
	      std::cerr << "ERROR : " << e.what() << std::endl;
	      avmEx.resetStack();
	    }
	  ++nb;
	  content.str("");
	  content.clear();
	}
    }
  return (0);
}
