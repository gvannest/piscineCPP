#include <iostream>
#include <fstream>

void    stringToUpper(std::string &str){
    for (unsigned int i = 0; i < str.length(); i++){
        str[i] = std::toupper(str[i]);
    }
}

void    ft_replace(char **argv){
    //input file opening and checking
    std::string filename(argv[1]);
    std::ifstream ifs(filename);
    if (!ifs.is_open()){
        std::cout << "Error: opening of file " << filename << " failed." << std::endl;
        return;
    }

    //output file naming and creation
    std::string filename_upper = filename;
    stringToUpper(filename_upper);
    std::ofstream ofs(filename_upper + ".replace");

    //Convertions s1 and s2 to string type to use string built-in methods
    std::string     s1(argv[2]);
    std::string     s2(argv[3]);

    if (ifs.good()){
        std::string str;
        size_t      idx;
        size_t len_s1 = s1.length();
        while(std::getline(ifs, str)){
            if (len_s1){
                idx = 0;
                while ((idx = str.find(s1, idx)) != std::string::npos){
                    str.replace(idx, len_s1, s2);
                    idx += len_s1;
                }
            }
            ofs << str << std::endl;
        }
        ifs.close();
        ofs.close();
    }
}

int     main(int argc, char **argv){
    if (argc != 4)
        std::cout << "Error: Wrong number of arguments." << std::endl;
    else
        ft_replace(argv);
    return 0;
}