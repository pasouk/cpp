#include <string>
#include <iostream>
#include <fstream>

std::string strreplace(std::string line, std::string s1, std::string s2)
{
    std::string replaced;
    size_t pos = 0;
    
    while ((pos = line.find(s1, pos)) != std::string::npos) 
    {
        line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
        pos += s1.length();
    }
    return line;

}

int readAndWrite(const char *input, const std::string s1 , const std::string s2 )
{
    //opning my 2 files and return error if fail
    std::ifstream in;
    in.open(input);
    if (!in)
    {
        std::cout << "Error : impossible to open input file";
        std::cerr << "Error : impossible to open input file";
        return 0;
    }


    std::ofstream out;

    out.open( (std::string(input) + ".replace").c_str() );
    if (!out)
    {
        std::cout << "Error : impossible to open output file";
        return 0;
    }

    std::string line;
    while (std::getline(in, line))
    {
        line = strreplace(line, s1, s2);
        out << line << "\n";
    }
    std::cout << "Traitement terminé avec succès.\n";
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Wrong format : expected 3 args (filename, str to replace and replacer str) " << std::endl;
        return 0;
    }
    else 
        readAndWrite(argv[1], argv[2], argv[3]);
}