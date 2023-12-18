 
 #include <iostream>

 int main (int argc, char **argv)
 {

	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for(int i = 1;argv[i];i++)
		{
			for(int n = 0; argv[i][n];n++)
				std::cout << (char) toupper(argv[i][n]);
			if (i < argc - 1)
				std::cout << ' ';
		}
	}
	std::cout << std::endl;
	return (0);
}